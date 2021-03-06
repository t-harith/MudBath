//
//  mudBathEngine.cpp
//  Mud Bath
//
//  Created by Tejas Harith on 5/13/18.
//  Copyright © 2018 Tejas Harith. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "MudBathEngine.h"
#include "ConfigReader/ConfigFile.hpp"

#ifndef ASSERT_debug
    #define ASSERT_debug
    #define ASSERT(x) if(!x) { __asm__("int $3"); }
#endif

// Errors
class gladLoadingError
{
public:
    std::string errMsg = "Error in loading GLAD";
};

class glfwLoadingError
{
public:
    std::string errMsg = "Error in loading GLFW";
};

class windowLoadingError
{
public:
    std::string errMsg = "Error in Initializing Window";
};

class configFileReadError
{
public:
    std::string errMsg = "Error in reading config file";
};

///////////////////////
/*    Public Funcs   */
///////////////////////
// Engine Constructor
MBEngine::MBEngine(std::string configFname,
                   std::string outputFname)
: mbeState(EngineState::IDLE), mbeCommand(EngineCommand::START), windowManager(0), basicRend(0), basicPhys(0), basicAI(0), mbLogger(0)
{
    windowManager = new engineWindow();
    readConfig(configFname);
    
    // initialize single instance of each subsystem
    loadSubsystems(outputFname);
}

// Engine Destructor
MBEngine::~MBEngine()
{
    // clear subsystems
    clearSubsystems();
    clearAssets();
}


///////////////////////

///////////////////////
/*    MAIN LOOP      */
///////////////////////
void MBEngine::init()
{
    try
    {
        subsystemsInit();
    }
    catch(gladLoadingError & ge)
    {
        mbLogger->error(ge.errMsg);
        /*Handle ERROR*/
        /*Attempt Recovery*/
        ASSERT(false);
    }
    catch(windowLoadingError & wle)
    {
        mbLogger->error(wle.errMsg);
        /*Handle ERROR*/
        /*Attempt Recovery*/
        ASSERT(false);
    }
    
    // Necessary to be done after gl is initialized
    basicRend->prepareDraw();
    
    ///
    
    // GAME LOOP
    int exit = 0;
    while(!exit){
        
        if(glfwWindowShouldClose(windowManager->window))
        {
            // publish event here/ command OVC
            mbeCommand = EngineCommand::EXIT;
            mbeState = EngineState::ABORTED;
        }
        
        switch(mbeState){
            case IDLE:
                break;
            case ACTIVE:
                /* Render here */
                basicRend->prepareBackground(Pixel_POD{0.12f, 0.12f, 0.12f, 1.0f});
                basicRend->draw();
                
                /* Swap front and back buffers */
                glfwSwapBuffers(windowManager->window);
                mbeState = EngineState::IDLE;
                break;
            case PAUSED:
                break;
            case FAULTED:
                break;
            case ABORTED:
                exit = 1;
                break;
        }

        /* Wait for and process events */
        // glfwPollEvents() results in high cpu usage
        glfwWaitEvents();
    
    }
    
    subsystemsTerminate();
}
///////////////////////

void MBEngine::loadRenderableObjs(std::vector<RenderableObject*> &r_objs_vec)
{
    for( RenderableObject* robj : r_objs_vec)
    {
        // stores object internally in renderer
        basicRend->loadObj(robj);
    }
    
}

///////////////////////
/*  Helper Functions */
///////////////////////


// Window Funcs
// Window Display
void MBEngine::windowInit(int version_maj, int version_min, unsigned int profile, bool forward_compat)
{
    // GLFW init
    if(!glfwInit())
        throw glfwLoadingError();
    
    // Window Setup
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, version_maj);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, version_min);
    glfwWindowHint(GLFW_OPENGL_PROFILE, profile);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, forward_compat);
    
    mbLogger->log("GLFW initialized");
}

// Window Display
void MBEngine::window_close_callback(GLFWwindow* window, int key, int scanncode, int action, int mods)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void MBEngine::setWindowParams(std::string name, int width, int height, bool full_screen, GLFWwindow* share)
{
    // disable shared context objects functionality
    ASSERT(!share);
    
    GLFWwindow * tempWin;
    full_screen ?
        tempWin = glfwCreateWindow(width, height, name.c_str(), glfwGetPrimaryMonitor(), share) :
        tempWin = glfwCreateWindow(width, height, name.c_str(), NULL, share);
    
    windowManager->window = tempWin;
    
    if(!windowManager->window)
    {
        glfwTerminate();
        // Break
        throw windowLoadingError();
    }
    
    glfwMakeContextCurrent(windowManager->window);
    
    glfwSetKeyCallback(windowManager->window, MBEngine::window_close_callback);
}

void MBEngine::readConfig(std::string configFname)
{
    
    ConfigFile cf(configFname.c_str());
    
    windowManager->version_maj = 3;
    windowManager->version_min = 3;
    windowManager->profile = Profile::CORE;
    windowManager->forward_compat = true ;
    windowManager->name = "Riverbank 2D Sandbox" ;
    windowManager->width = 640;
    windowManager->height = 480;
    windowManager->full_screen = false;
    windowManager->share = NULL;
    windowManager->close_key = GLFW_KEY_ESCAPE;
    
    windowManager->version_maj   = cf.Value("window_params","Version_Major"  );
    windowManager->version_min = cf.Value("window_params","Version_Minor");
    
    if((std::string)cf.Value("window_params","Profile" ) == "CORE")
    {
        windowManager->profile  = Profile::CORE;
    }
    else if((std::string)cf.Value("window_params","Profile" ) == "COMPAT")
    {
        windowManager->profile  = Profile::COMPAT;
    }
    else
    {
        ASSERT(0);
    }
    
    windowManager->forward_compat = cf.Value("window_params","Forward_Compat" );
    windowManager->name = (std::string)cf.Value("window_params","Name" );
    windowManager->width = cf.Value("window_params","Width" );
    windowManager->height = cf.Value("window_params","Height" );
    windowManager->full_screen = cf.Value("window_params","Full_Screen" );
    windowManager->share = NULL;
    windowManager->close_key = cf.Value("window_params","Close_Key" );
}

void MBEngine::loadSubsystems(std::string outputFname)
{
    
    std::string engineLogLoc = "engineLogs/" + outputFname;
    if(mbLogger == NULL){
        mbLogger = new Logger("MBE", engineLogLoc, false);
    }
    if(basicRend == NULL){
        basicRend = new Renderer();
    }
    if(basicPhys == NULL){
        basicPhys = new PhysicsModule();
    }
    if(basicAI == NULL){
        basicAI = new AILogic();
    }
}

void MBEngine::clearSubsystems()
{
    if(mbLogger != NULL){
        delete mbLogger;
    }
    if(basicRend != NULL){
        delete basicRend;
    }
    if(basicPhys != NULL){
        delete basicPhys;
    }
    if(basicAI != NULL){
        delete basicAI;
    }
}

void MBEngine::clearAssets()
{
    // clear assets
    // RenderableObjects
    for (RenderableObject* ro : RenderableObject::ROList())
    {
        delete ro;
    }
}

void MBEngine::subsystemsInit()
{
    
    // Setup Window
    windowInit(windowManager->version_maj, windowManager->version_min, windowManager->profile, windowManager->forward_compat);
    setWindowParams(windowManager->name, windowManager->width, windowManager->height, windowManager->full_screen, windowManager->share);
    
    // Setup GLAD
    if( !gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        throw gladLoadingError();
    }
    
    glfwMakeContextCurrent(windowManager->window);
    
    mbeState = EngineState::ACTIVE;
}

void MBEngine::subsystemsTerminate()
{
    // GLFW Terminate
    glfwDestroyWindow(windowManager->window);
    glfwTerminate();
}
///////////////////////


/*
 
 switch (mbeCommand)
 {
 case START:
 break;
 case PAUSE:
 break;
 case EXIT:
 break;
 case RESTART:
 break;
 }
 
 */

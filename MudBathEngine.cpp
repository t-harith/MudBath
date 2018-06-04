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

#define ASSERT(x) if(!x) { __asm__("int $3"); }

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
    
    
    
    // GAME LOOP
    int exit = 0;
    while(!exit){
        
        switch(mbeState){
            case IDLE:
                break;
            case ACTIVE:
                if(glfwWindowShouldClose(windowManager->window))
                {
                    // implemented command on value changed
                    mbeCommand = EngineCommand::EXIT;
                    mbeState = EngineState::ABORTED;
                    break;
                }
                
                /* Render here */
                glClear(GL_COLOR_BUFFER_BIT);
                // basicRend.draw(objectsBuffer);
                
                /* Swap front and back buffers */
                glfwSwapBuffers(windowManager->window);
                break;
            case PAUSED:
                break;
            case FAULTED:
                break;
            case ABORTED:
                exit = 1;
                break;
        }

        /* Poll for and process events */
        glfwPollEvents();
    
    }
    
    subsystemsTerminate();
}
///////////////////////


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
    std::ifstream configStream(configFname.c_str());
    if(configStream.fail())
        throw configFileReadError();
    
    std::string verMaj, verMin, prof, fc, n, w, h, fs, sh, ck;
    configStream >> verMaj;
    configStream >> verMin;
    configStream >> prof;
    configStream >> fc;
    configStream >> n;
    configStream >> w;
    configStream >> h;
    configStream >> fs;
    configStream >> sh;
    configStream >> ck;
    
    windowManager->version_maj = 3; //stoi(verMaj);
    windowManager->version_min = 3; //stoi(verMin);
    windowManager->profile = Profile::CORE; //stoi(prof);
    windowManager->forward_compat = true ;//(fc == "true") ? true : false;
    windowManager->name = "Riverbank 2dsb" ;//n;
    windowManager->width = 640; //stoi(w);
    windowManager->height = 480; //stoi(h);
    windowManager->full_screen = false; //(fs == "true") ? true : false;
    windowManager->share = NULL;
    windowManager->close_key = GLFW_KEY_ESCAPE;
    
}

void MBEngine::loadSubsystems(std::string outputFname)
{
    
    if(mbLogger == NULL){
        mbLogger = new Logger("MBE", outputFname);
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

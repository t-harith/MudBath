//
//  mudBathEngine.h
//  Mud Bath
//
//  Created by Tejas Harith on 5/13/18.
//  Copyright © 2018 Tejas Harith. All rights reserved.
//

#ifndef mudBathEngine_h
#define mudBathEngine_h


#endif /* mudBathEngine_h */

#include "deps/glad/glad.h"
#include "deps/GLFW/glfw3.h"

#include "engineAssets/Renderer.h"
#include "engineAssets/PhysicsModule.h"
#include "engineAssets/AILogic.h"

#ifndef Logger_h
    #include "Logging/Logger.h"
#endif

enum EngineState
{
    IDLE = 0,
    ACTIVE = 1,
    PAUSED = 2,
    ABORTED = 3,
    FAULTED = 4
};

enum EngineCommand
{
    START = 0,
    PAUSE = 1,
    EXIT = 2,
    RESTART = 3,
};

enum Profile
{
    CORE=GLFW_OPENGL_CORE_PROFILE,
    COMPAT=GLFW_OPENGL_COMPAT_PROFILE
};

class MBEngine
{
public:
    struct engineWindow
    {
        GLFWwindow* window;
        
        unsigned int version_maj;
        unsigned int version_min;
        unsigned int profile;
        bool forward_compat;
        std::string name;
        unsigned int width;
        unsigned int height;
        bool full_screen;
        GLFWwindow* share;
        int close_key;
    };

private:
    EngineState mbeState;
    EngineCommand mbeCommand;
    
    engineWindow* windowManager;
    
    Renderer* basicRend;
    PhysicsModule* basicPhys;
    AILogic* basicAI;
    
    Logger* mbLogger;
    
public:
    MBEngine(std::string configFname,
             std::string outputFname);
    ~MBEngine();
    void init();
    
private:
    /* State Management Funcs */
    void MoveToState(EngineState e);
    void SendCMD(EngineCommand c);
    
    /* Subsystems Management Funcs */
    void loadSubsystems(std::string outputFname);
    void clearSubsystems();
    void subsystemsInit();
    void subsystemsTerminate();
    
    /* Window Setup Funcs */
    void windowInit(int version_maj, int version_min, unsigned int profile, bool forward_compat);
    static void window_close_callback(GLFWwindow* window, int key, int scanncode, int action, int mods);
    void setWindowParams(std::string name, int width, int height, bool full_screen, GLFWwindow* share);
    
    /* General Helpers */
    void readConfig(std::string configFname);
    
};


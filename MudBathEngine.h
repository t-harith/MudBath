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
    FAULT = -1,
    INIT = 0,
    ACTIVE = 1,
    PAUSE = 2,
    HALTED = 3
};

enum Profile
{
    CORE=GLFW_OPENGL_CORE_PROFILE,
    COMPAT=GLFW_OPENGL_COMPAT_PROFILE
};

class MBEngine
{
private:
    EngineState state;
    GLFWwindow* window;
    
    Renderer* basicRend;
    PhysicsModule* basicPhys;
    AILogic* basicAI;
    
    Logger* mbLogger;
    
    void loadSubsystems();
    void clearSubsystems();
    
public:
    MBEngine(/* config options  */
             /* output filename */);
    ~MBEngine();
    void init();
    
    /* Window Setup Funcs */
    void windowInit(int version_maj, int version_min, unsigned int profile, bool forward_compat);
    static void key_callback(GLFWwindow* window, int key, int scanncode, int action, int mods);
    void setWindowParams(std::string name, int width, int height, bool full_screen, GLFWwindow* share);
    
};


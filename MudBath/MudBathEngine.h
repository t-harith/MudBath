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

#include "../engineAssets/Renderer.h"
#include "../engineAssets/PhysicsModule.h"
#include "../engineAssets/AILogic.h"

enum Profile
{
    CORE=GLFW_OPENGL_CORE_PROFILE,
    COMPAT=GLFW_OPENGL_COMPAT_PROFILE
};

class MBEngine
{
private:
    int state;
    GLFWwindow* window;
    
    Renderer basicRend;
    PhysicsCompute basicPhys;
    AILogic basicAI;
    
public:
    MBEngine()
    : state(-1) {
        std::cout << "MBEngine Constructor" << std::endl;
    }
    ~MBEngine()
    {
        std::cout << "MBEngine Destructor" << std::endl;
    }
    void init();
    
    /* Window Setup Funcs */
    void windowInit(int version_maj, int version_min, unsigned int profile, bool forward_compat);
    static void key_callback(GLFWwindow* window, int key, int scanncode, int action, int mods);
    void setWindowParams(std::string name, int width, int height, bool full_screen, GLFWwindow* share);
    
};


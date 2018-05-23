//
//  mudBathEngine.cpp
//  Mud Bath
//
//  Created by Tejas Harith on 5/13/18.
//  Copyright © 2018 Tejas Harith. All rights reserved.
//

// Errors
class gladLoadingError{};
class windowLoadingError{};

#include <iostream>
#include "MudBathEngine.h"

#define ASSERT(x) if(!x) { __asm__("int $3"); }


void MBEngine::windowInit(int version_maj, int version_min, unsigned int profile, bool forward_compat)
{
    // GLFW init
    ASSERT(glfwInit());
    
    // Window Setup
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, version_maj);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, version_min);
    glfwWindowHint(GLFW_OPENGL_PROFILE, profile);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, forward_compat);
    
    std::cout << "GLFW initialized" << std::endl;
    
}

void MBEngine::key_callback(GLFWwindow* window, int key, int scanncode, int action, int mods)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void MBEngine::setWindowParams(std::string name, int width, int height, bool full_screen, GLFWwindow* share)
{
    // disable shared context objects functionality
    ASSERT(!share);
    
    full_screen ?
    window = glfwCreateWindow(width, height, name.c_str(), glfwGetPrimaryMonitor(), share) :
    window = glfwCreateWindow(width, height, name.c_str(), NULL, share);
    
    if(!window)
    {
        glfwTerminate();
        // Break
        throw windowLoadingError();
    }
    
    glfwMakeContextCurrent(window);
    
    glfwSetKeyCallback(window, MBEngine::key_callback);
    
    std::cout << " Window creation goes here " << std::endl;
}

void MBEngine::init()
{
    // Setup GLAD
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        printf("Something went wrong!\n");
        throw gladLoadingError();
    }
    
    glfwMakeContextCurrent(window);
    
    // Create Window
    while(!glfwWindowShouldClose(window)){
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        
        /* Poll for and process events */
        glfwPollEvents();
        
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
}




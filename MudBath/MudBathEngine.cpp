//
//  mudBathEngine.cpp
//  Mud Bath
//
//  Created by Tejas Harith on 5/13/18.
//  Copyright © 2018 Tejas Harith. All rights reserved.
//

#include <iostream>
#include "MudBathEngine.h"


void MBEngine::init()
{
    // Setup GLFW and GLAD
    // MBengine::initLibs();
    
    // Create Window
    
    std::cout << " In engine run loop " << std::endl;
}

void MBEngine::setWindowParams(std::string name, int width, int height, bool full_screen)
{
    /*
     full_screen ?
     window = glfwCreateWindow(width, height, name, getPrimaryMonitor(), NULL) :
     window = glfwCreateWindow(width, height, name, NULL, NULL)
     */
    std::cout << " Window creation goes here " << std::endl;
}


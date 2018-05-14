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

#include "../engineAssets/Renderer.h"
#include "../engineAssets/PhysicsModule.h"
#include "../engineAssets/AILogic.h"


class MBEngine
{
private:
    int state;
    //GLFWwindow window;
    
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
    void setWindowParams(std::string name, int width, int height, bool full_screen);
    
};


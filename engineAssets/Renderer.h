
//
//  Renderer.h
//  Mud Bath
//
//  Created by Tejas Harith on 5/13/18.
//  Copyright © 2018 Tejas Harith. All rights reserved.
//

#ifndef Renderer_h
#define Renderer_h


#endif /* Renderer_h */

#include <iostream>

class Renderer
{
private:
    int state;
public:
    Renderer()
    :state(-1){
        std::cout << "Renderer Constructor" << std::endl;
    }
    ~Renderer()
    {
        std::cout << "Renderer Destructor" << std::endl;
    }
};

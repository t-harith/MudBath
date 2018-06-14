
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
#include <fstream>

#include "deps/glad/glad.h"
#include "deps/GLFW/glfw3.h"

#ifndef Logger_h
    #include "Logging/Logger.h"
#endif

#include "engineAssets/Objects/RenderableObject.h"


class Renderer
{
private:
    int state;
    Logger* renLogger;
    std::vector<RenderableObject*> r_objs;
    
    void prepareObjBuffers();
    void setupBlending();
    
public:
    Renderer();
    ~Renderer();
    
    void draw();
    void prepareDraw();
    void prepareBackground(Pixel_POD);
    void loadObj(RenderableObject* ro);
};

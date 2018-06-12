//
//  Renderer.cpp
//  MudBathEngine
//
//  Created by Tejas Harith on 6/10/18.
//  Copyright © 2018 Tejas Harith. All rights reserved.
//

#include <stdio.h>
#include "Renderer.h"

Renderer::Renderer()
:state(-1), renLogger(0)
{
    std::string outputLogFile = "engineLogs/MBE_renderer_log";
    if(renLogger == NULL)
        renLogger = new Logger("REN", outputLogFile, false);
    renLogger->log("Renderer Constructor");
}

Renderer::~Renderer()
{
    renLogger->log("Renderer Destructor");
}

void Renderer::draw(RenderableObject &ro)
{
    renLogger->log("Rendering Draw Call");
    ro.loadVAO();
    glDrawElements(GL_TRIANGLES, ro.getIBOsize(), GL_UNSIGNED_INT, nullptr );
}

void Renderer::prepareBackground(Pixel_POD p)
{
    glClearColor(p.r, p.g, p.b, p.a); // Background Color
    glClear(GL_COLOR_BUFFER_BIT);
}

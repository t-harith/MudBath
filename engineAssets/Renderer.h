
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

#ifndef Logger_h
    #include "Logging/Logger.h"
#endif

class Renderer
{
private:
    int state;
    Logger* renLogger;
    
public:
    Renderer()
    :state(-1), renLogger(0){
        if(renLogger == NULL)
            renLogger = new Logger("REN");
        renLogger->log("Renderer Constructor");
    }
    ~Renderer()
    {
        renLogger->log("Renderer Destructor");
    }
};

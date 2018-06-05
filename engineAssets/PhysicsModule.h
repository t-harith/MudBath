
//
//  PhysicsCompute.h
//
//
//  Created by Tejas Harith on 5/13/18.
//

#ifndef PhysicsModule_h
#define PhysicsModule_h


#endif /* PhysicsModule_h */

#include <iostream>

#ifndef Logger_h
    #include "Logging/Logger.h"
#endif

class PhysicsModule
{
private:
    int state;
    Logger* pmLogger;
    
public:
    PhysicsModule()
    :state(-1), pmLogger(0)
    {
        std::string outputLogFile = "engineLogs/MBE_physicsModule_log";
        if(pmLogger == NULL)
            pmLogger = new Logger("PM", outputLogFile, false);
        pmLogger->log("PhysicsModule Constructor");
    }
    ~PhysicsModule()
    {
        pmLogger->log("PhysicsModule Destructor");
    }
};

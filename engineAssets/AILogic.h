
//
//  AILogic.h
//
//
//  Created by Tejas Harith on 5/13/18.
//

#ifndef AILogic_h
#define AILogic_h


#endif /* AILogic_h */

#ifndef Logger_h
    #include "Logging/Logger.h"
#endif

class AILogic
{
private:
    int state;
    Logger* aiLogger;
    
public:
    AILogic()
    :state(-1), aiLogger(0)
    {
        std::string outputLogFile = "engineLogs/MBE_aiLogic_log";
        if(aiLogger == NULL)
            aiLogger = new Logger("AI", outputLogFile, false);
        aiLogger->log("AILogic Constructor");
    }
    ~AILogic()
    {
        aiLogger->log("AILogic Destructor");
    }
};

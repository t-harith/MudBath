// MB2D Simulation Sandbox

#include <iostream>
#include <fstream>

#include "MudBathEngine.h"
#ifndef Logger_h
    #include "Logging/Logger.h"
#endif

enum RiverbankStates {
    Exit = -1,
    Menu = 0,
    Game = 1,
    Pause = 2,
};

RiverbankStates rbState = Menu;

int main()
{
    std::string outputLogFile = "execLogs/_riverbankLog.txt";
    std::ofstream test(outputLogFile.c_str());
    Logger* rbLogger = new Logger("RB", outputLogFile, false);
    
    rbLogger->log("Initializing Riverbank Test Environment");
    
    // Create Engine Object
    MBEngine* engine = new MBEngine("config/defaultConfig.txt", "_engineLog.txt");
    
    //RenderableObject* riverbank_ro = new RenderableObject();
    //Material rbTest();
    //riverbank_ro.addMaterial(rbTest);
    //engine->loadObjects(renderable_objects_vec);
    
    engine->init();
    
/*   // Load Assets
 *   engine.loadMap();
 *   engine.loadPlayer();
 *   engine.loadNonPlayerEntities();
 *   engine.loadGUI();
 */
    
    // Riverbank FSM
    switch(rbState){
        case Exit:
            //DO SOMETHING
            break;
        case Menu:
            //DO SOMETHING
            break;
        case Game:
            //DO Something
            //Game SM
            break;
        case Pause:
            //DO Something
            break;
        default:
            rbLogger->error(" invalid state");
    }
    
    rbLogger->log("Closing Riverbank Test Environment");
    delete rbLogger;
    return 0;
}

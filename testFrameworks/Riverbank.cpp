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
    std::string outputLogFile = "/Users/dev/OpenGL/MudBath/MudBath/logs/riverbankLog.txt";
    std::ofstream test(outputLogFile.c_str());
    Logger* rbLogger = new Logger("RB", outputLogFile);
    
    rbLogger->log("Initializing Riverbank Test Environment");
    
    // Create Engine Object
    MBEngine* engine = new MBEngine("/Users/dev/OpenGL/MudBath/MudBath/config/defaultConfig.txt", "outputFile.txt");
    
    // Open Window
    //engine->windowInit(3, 3, Profile::CORE, true);
    //engine->setWindowParams("Riverbank 2D Sandbox", 640, 480, false, NULL);
    
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

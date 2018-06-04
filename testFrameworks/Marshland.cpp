// Simulation Sandbox

#include "MudBathEngine.h"
#include <iostream>

enum MarshlandStates {
    Exit = -1,
    Menu = 0,
    Game = 1,
    Pause = 2,
};

MarshlandStates mlState = Menu;

int main()
{
    std::string outputLogFile = "/Users/dev/OpenGL/MudBath/MudBath/logs/marshlandLog.txt";
    std::ofstream test(outputLogFile.c_str());
    Logger* mlLogger = new Logger("ML", outputLogFile);
    
    mlLogger->log("Initializing Marshland Test Environment");
    
    // Create Engine Object
    MBEngine* engine = new MBEngine("/Users/dev/OpenGL/MudBath/MudBath/config/configFile.txt", "outputFile.txt");
    
    engine->init();
    
    /*   // Load Assets
     *   engine.loadMap();
     *   engine.loadPlayer();
     *   engine.loadNonPlayerEntities();
     *   engine.loadGUI();
     */
    
    // Marshland FSM
    switch(mlState){
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
            std::cout << " invalid state" << std::endl;
    }
    
    return 0;
}

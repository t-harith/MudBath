// MBED Simulation Sandbox

#include "MudBathEngine.h"
#include <iostream>

enum CentrifudgeStates {
    Exit = -1,
    MouseManip = 0,
    Animated = 1,
    Pause = 2,
};

CentrifudgeStates cfState = Animated;

int main()
{
    std::string outputLogFile = "/Users/dev/OpenGL/MudBath/MudBath/logs/centrifudgeLog.txt";
    Logger* cfLogger = new Logger("CF", outputLogFile);
    
    cfLogger->log("Initializing Centrifudge Test Environment");
    
    // Create Engine Object
    MBEngine* engine = new MBEngine("/Users/dev/OpenGL/MudBath/MudBath/config/defaultConfig.txt", "outputFile.txt");
    engine->init();
    
    /*   // Load Assets
     *   engine.loadMap();
     *   engine.loadPlayer();
     *   engine.loadNonPlayerEntities();
     *   engine.loadGUI();
     */
    
    // Centrifudge FSM
    switch(cfState){
        case Exit:
            //DO SOMETHING
            break;
        case MouseManip:
            //DO SOMETHING
            break;
        case Animated:
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

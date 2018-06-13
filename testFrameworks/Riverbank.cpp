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
    
    RenderableObject* riverbank_ro = new RenderableObject();
    float positions[] = {
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.5f, 0.5f,
        -0.5f, 0.5f
    };
    
    unsigned int indices[] = {
        0, 1, 2, 2, 3, 0
    };
    Material rbTest("-");
    rbTest.addShader("/Users/dev/OpenGL/MudBath/MudBath/testFrameworks/res/shaders/Default.shader");
    riverbank_ro->addMaterial(rbTest);
    riverbank_ro->setVertexArray(positions, 8);
    riverbank_ro->setIndexArray(indices, 6);
    std::vector<RenderableObject*> r_objs_vec;
    r_objs_vec.push_back(riverbank_ro);
    
    engine->loadRenderableObj(r_objs_vec);
    
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

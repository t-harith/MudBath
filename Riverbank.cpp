// Simulation Sandbox

#include "MudBathEngine.h"
#include <iostream>

int main()
{
    // Create Engine Object
    MBEngine engine;
    
    // Open Window
    try{
        engine.windowInit(3, 3, CORE, true);
        engine.setWindowParams("Riverbank Sandbox", 640, 480, false, NULL);
    } catch(...) {
        std::cout << "Error Handling Goes Here" << std::endl;
        std::cout << "Trying to Recover Goes Here" << std::endl;
    }
    
    
    engine.init();
    
    return 0;
}

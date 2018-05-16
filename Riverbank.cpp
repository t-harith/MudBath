// Simulation Sandbox

#include "MudBathEngine.h"
#include <iostream>

int main()
{
    // Create Engine Object
    MBEngine engine;
    
    // Open Window
    engine.windowInit(3, 3, CORE, true);
    engine.setWindowParams("Riverbank Sandbox", 640, 480, false, NULL);
    
    engine.init();
    
    return 0;
}

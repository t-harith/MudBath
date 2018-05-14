// Simulation Sandbox

#include "MudBathEngine.h"
#include <iostream>

int main()
{
    // Create Engine Object
    MBEngine engine;
    
    // Open Window
    engine.setWindowParams("Riverbank Sandbox", 640, 480, false);
    
    engine.init();
    
    return 0;
}

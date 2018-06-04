//
//  Logger.h
//  MudBath
//
//  Created by Tejas Harith on 6/2/18.
//  Copyright © 2018 Tejas Harith. All rights reserved.
//

#ifndef Logger_h
#define Logger_h


#endif /* Logger_h */

#include <iostream>
#include <fstream>

class Logger
{
private:
    std::string prefix;
    std::ofstream outputStream;
    
public:
    Logger( std::string p, std::string outputFname );
    ~Logger();
    
    void log(const std::string logMsg);
    
    void warn(const std::string warningMsg);
    
    void error(const std::string errorMsg);
};

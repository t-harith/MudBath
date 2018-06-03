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

class Logger
{
private:
    std::ostream & outputStream;
    std::string prefix;
public:
    Logger(std::string p);
    Logger(std::ostream & os, std::string p);
    ~Logger();
    
    void log(const std::string logMsg);
    
    void warn(const std::string warningMsg);
    
    void error(const std::string errorMsg);
};

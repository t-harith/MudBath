//
//  Logger.cpp
//  MudBath
//
//  Created by Tejas Harith on 6/3/18.
//  Copyright © 2018 Tejas Harith. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <ctime>
#include "Logger.h"


Logger::Logger(const std::string & p, const std::string & outputFname, bool newLogs)
{
    std::size_t found = outputFname.find_last_of("/\\");
    std::string path = outputFname.substr(0,found);
    std::string file = outputFname.substr(found+1);
    
    prefix = p;
    
    std::stringstream s;
    s << path << "/";
    
    if(newLogs)
    {
        std::time_t t = std::time(nullptr);
        std::tm * tim = std::localtime(&t);
        
        s << tim->tm_mon << "-" << tim->tm_mday << "-" << tim->tm_year+1900 << "_";
        s << doubleDig(tim->tm_hour) << "\ua789" << doubleDig(tim->tm_min) << "\ua789" << doubleDig(tim->tm_sec) << "_";
    }
    
    s << file;
    outputStream.open(s.str());
}

Logger::~Logger()
{
//    std::cout << prefix << "-Logger Destructor" << std::endl;
}

void Logger::log(const std::string & logMsg)
{
    outputStream << prefix << "-LOG: " << logMsg << "\n";
    outputStream.flush();
}

void Logger::warn(const std::string & warningMsg)
{
    outputStream << prefix << "-WARN: " << warningMsg << "\n";
    outputStream.flush();
}

void Logger::error(const std::string & errorMsg)
{
    outputStream << prefix << "-ERROR: " << errorMsg + "\n";
    outputStream.flush();
}

std::string Logger::doubleDig(const int timeVar)
{
    std::string returnStr;
    (timeVar < 10) ?
        returnStr = "0" + std::to_string(timeVar) :
        returnStr = std::to_string(timeVar);
    return returnStr;
}

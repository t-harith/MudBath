//
//  Logger.cpp
//  MudBath
//
//  Created by Tejas Harith on 6/3/18.
//  Copyright © 2018 Tejas Harith. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Logger.h"


Logger::Logger( std::string p, std::string outputFname )
{
    prefix = p;
    outputStream.open(outputFname.c_str());
    std::cout << "Custom " + prefix + "-Logger Constructor" << std::endl;
}

Logger::~Logger()
{
    std::cout << prefix + "-Logger Destructor" << std::endl;
}

void Logger::log(const std::string logMsg)
{
    outputStream << prefix + "-LOG: " + logMsg + "\n";
}

void Logger::warn(const std::string warningMsg)
{
    outputStream << prefix + "-WARNING: " + warningMsg + "\n";
}

void Logger::error(const std::string errorMsg)
{
    outputStream << prefix + "-ERROR: " + errorMsg + "\n";
}

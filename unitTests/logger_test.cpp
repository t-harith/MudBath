//
//  logger_test.cpp
//  MudBath
//
//  Created by Tejas Harith on 6/5/18.
//  Copyright © 2018 Tejas Harith. All rights reserved.
//

#include <stdio.h>
#include "Logging/Logger.h"
#include <ctime>
#include <sstream>
#include <stdlib.h>

void debuGTestfunc(std::ofstream & out);

int main()
{
    Logger* testLogger = new Logger("TEST_LOG", "testLogs/test_log_output.txt", false);
    
//    std::ofstream out("./test_log_output.txt");
//    out << "BLAH" << "\n" ;
//    out << "Sic" << "\n" ;
//    debuGTestfunc(out);
    testLogger->log("Initiating TEST_LOG");
    testLogger->warn("Warn Test");
    testLogger->error("Error Test");
//    std::time_t t = std::time(nullptr);
//    std::tm * tim = std::localtime(&t);
//    std::stringstream s;
//    s << tim->tm_mon << "-" << tim->tm_mday << "-" << tim->tm_year+1900 << "_";
//    s << tim->tm_hour << ":" << tim->tm_min << ":" << tim->tm_sec << "_";
//    std::cout<< s.str() << std::endl;
    
}

void debuGTestfunc(std::ofstream & out)
{
    out << "Next" << "\n" ;
}


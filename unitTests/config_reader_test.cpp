//
//  config_reader_test.cpp
//  MudBath
//
//  Created by Tejas Harith on 6/4/18.
//  Copyright © 2018 Tejas Harith. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "ConfigReader/ConfigFile.hpp"


int main()
{
    std::string configFname = "testConfig/testDefaultConfig.txt";
    ConfigFile cf(configFname.c_str());
    
    std::cout << (unsigned int)cf.Value("window_params","Version_Major" ) << std::endl;
    std::cout << (unsigned int)cf.Value("window_params","Version_Minor" ) << std::endl;
    std::cout << (std::string)cf.Value("window_params","Profile" ) << std::endl;
    std::cout << (bool)cf.Value("window_params","Forward_Compat" ) << std::endl;
    std::cout << (std::string)cf.Value("window_params","Name" ) << std::endl;
    std::cout << (unsigned int)cf.Value("window_params","Width" ) << std::endl;
    std::cout << (unsigned int)cf.Value("window_params","Height" ) << std::endl;
    std::cout << (bool) cf.Value("window_params","Full_Screen" ) << std::endl;
    std::cout << (unsigned int)cf.Value("window_params","Close_Key" ) << std::endl;
}


/*
 <Profile> Profile = prof
 <bool> Forward_Compat = true
 <string> Name = Riverbank 2D Sandbox
 <uint> Width = 640
 <uint> Height = 480
 <bool> Full_Screen = false
 <uint> Close_Key = 256
 */

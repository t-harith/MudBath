/*
 
 Altered by Tejas Harith
 
 */

#include "ConfigFile.hpp"

#include <fstream>

std::string trim(std::string const& source, char const* delims = " \t\r\n") {
    std::string result(source);
    std::string::size_type index = result.find_last_not_of(delims);
    if(index != std::string::npos)
        result.erase(++index);
    
    index = result.find_first_not_of(delims);
    if(index != std::string::npos)
        result.erase(0, index);
    else
        result.erase();
    return result;
}

ConfigFile::ConfigFile(std::string const& configFile) {
    std::ifstream file(configFile.c_str());
    if(file.fail())
        throw "bad stuff";
    std::string line;
    std::string name;
    std::string value;
    std::string inSection;
    unsigned long posEqual;
    while (std::getline(file,line)) {
        
        if (! line.length()) continue;
        
        if (line[0] == '#') continue;
        if (line[0] == ';') continue;
        
        if (line[0] == '[') {
            inSection=trim(line.substr(1,line.find(']')-1));
            continue;
        }
        
        unsigned long posTypeS = line.find('<');
        unsigned long posTypeE = line.find('>');
        std::string type = trim(line.substr(posTypeS+1,posTypeE-2));
        posEqual = line.find('=');
        name  = trim(line.substr(posTypeE+1,posEqual-posTypeE-1));
        value = trim(line.substr(posEqual+1));
        
        content_[inSection+'/'+name]=Chameleon(value, type);
    }
}

Chameleon const& ConfigFile::Value(std::string const& section, std::string const& entry) const {
    
    std::map<std::string,Chameleon>::const_iterator ci = content_.find(section + '/' + entry);
    
    if (ci == content_.end()) throw "does not exist";
    
    return ci->second;
}

//Chameleon const& ConfigFile::Value(std::string const& section, std::string const& entry, double value) {
//    try {
//        return Value(section, entry);
//    } catch(const char *) {
//        std::string type = "double";
//        return content_.insert(std::make_pair(section+'/'+entry, Chameleon(value, type))).first->second;
//    }
//}

Chameleon const& ConfigFile::Value(std::string const& section, std::string const& entry, std::string const& value) {
    try {
        return Value(section, entry);
    } catch(const char *) {
        std::string type = "string";
        return content_.insert(std::make_pair(section+'/'+entry, Chameleon(value, type))).first->second;
    }
}

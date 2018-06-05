/*
 Chameleon.cpp
 
 Copyright (C) 2002-2004 René Nyffenegger
 
 This source code is provided 'as-is', without any express or implied
 warranty. In no event will the author be held liable for any damages
 arising from the use of this software.
 
 Permission is granted to anyone to use this software for any purpose,
 including commercial applications, and to alter it and redistribute it
 freely, subject to the following restrictions:
 
 1. The origin of this source code must not be misrepresented; you must not
 claim that you wrote the original source code. If you use this source code
 in a product, an acknowledgment in the product documentation would be
 appreciated but is not required.
 
 2. Altered source versions must be plainly marked as such, and must not be
 misrepresented as being the original source code.
 
 3. This notice may not be removed or altered from any source distribution.
 
 René Nyffenegger rene.nyffenegger@adp-gmbh.ch
 */

/*
 
 Altered by Tejas Harith
 
 */

#include <string>
#include <sstream>

#include "Chameleon.hpp"

Chameleon::Chameleon(std::string const& value, std::string const& type) {
    type_ = type;
    value_=value;
}

#include <iostream>

Chameleon::Chameleon(const char* c, std::string const& type) {
    type_ = type;
    value_=c;
}

//Chameleon::Chameleon(double d) {
//    std::stringstream s;
//    s<<d;
//    value_=s.str();
//}

Chameleon::Chameleon(Chameleon const& other) {
    type_=other.type_;
    value_=other.value_;
}

Chameleon& Chameleon::operator=(Chameleon const& other) {
    if(type_ == other.type_ && value_ == other.value_)
        return *this;
    
    type_=other.type_;
    value_=other.value_;
    return *this;
}

Chameleon& Chameleon::operator=(double i) {
    type_ = "double";
    value_ = std::to_string(i);
    return *this;
}

Chameleon& Chameleon::operator=(std::string const& s) {
    type_ = "string";
    value_=s;
    return *this;
}


// Casting
Chameleon::operator std::string() const
{
    return value_;
}

Chameleon::operator unsigned int() const
{
    int iV = stoi(value_);
    return (iV >= 0) ? iV : -iV;
}

Chameleon::operator int() const
{
    return stoi(value_);
}

Chameleon::operator bool() const
{
    return (value_ == "true");
}

Chameleon::operator double() const
{
    return atof(value_.c_str());
}


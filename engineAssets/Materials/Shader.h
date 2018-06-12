//
//  Shader.h
//  MudBath
//
//  Created by Tejas Harith on 6/11/18.
//  Copyright © 2018 Tejas Harith. All rights reserved.
//

#ifndef Shader_h
#define Shader_h


#endif /* Shader_h */

#include <sstream>
#include <fstream>
#include <map>

class Shader
{
private:
    std::string vertexSource;
    std::string fragmentSource;
    
public:
    unsigned int program_num = 0;
    std::map<std::string, unsigned int> u_locations;
    
public:
    Shader(const std::string& filename)
    {
        ParseShader(filename);
        
        GLint program_ok;
        // Create
        program_num = glCreateProgram();
        
        // Compile
        unsigned int vs =  CompileShader(GL_VERTEX_SHADER, vertexSource);
        unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);
        
        // Link
        glAttachShader(program_num, vs);
        glAttachShader(program_num, fs);
        glLinkProgram(program_num);
        glValidateProgram(program_num);
        
        glGetProgramiv(program_num, GL_LINK_STATUS, &program_ok);
        if(program_ok != GL_TRUE){
            std::cout << "ERROR, failed to link shader program" << std::endl;
        }
        
        // Clean
        glDeleteShader(vs);
        glDeleteShader(fs);
        
    }
    
    ~Shader()
    {
        glDeleteShader(program_num);
    }
    
    void setPropertyValue(const char* property_name, float val1, float val2, float val3, float val4)
    {
        // To be templated in the future
        int location = glGetUniformLocation(program_num, "u_Color");
        if(location == -1)
            std::cout << "shader property name: " << property_name << " not found"  << std::endl;
        glUniform4f(location, val1, val2, val3, val4);
    }
    
private:
    void ParseShader( const std::string &filename)
    {
        std::ifstream in(filename);
        
        enum class ShaderType
        {
            NONE = -1, VERTEX = 0, FRAGMENT = 1
        };
        
        ShaderType type = ShaderType::NONE;
        std::string line;
        std::stringstream ss[2];
        while(getline(in, line)){
            if(line.find("#shader") != line.npos){
                if(line.find("vertex") != line.npos){
                    type = ShaderType::VERTEX;
                } else if (line.find("fragment") != line.npos){
                    type = ShaderType::FRAGMENT;
                }
            }
            else
            {
                ss[(int)type] << line << "\n";
            }
        }
        
        vertexSource = ss[0].str();
        fragmentSource = ss[1].str();
    }
    
    unsigned int CompileShader(const unsigned int type, const std::string & source)
    {
        unsigned int _id = glCreateShader(type);
        const char * src = source.c_str();
        glShaderSource(_id, 1, &src, NULL);
        glCompileShader(_id);
        
        // Error Handling
        int shaderCompileState;
        glGetShaderiv(_id, GL_COMPILE_STATUS, &shaderCompileState);
        if(!shaderCompileState)
        {
            int length;
            glGetShaderiv(_id, GL_INFO_LOG_LENGTH, &length);
            char * message = new char[length];
            glGetShaderInfoLog(_id, length, &length, message);
            std::cout<< "Compilation Error with " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment" ) << " shader" << std::endl;
            std::cout<< message << std::endl;
            glDeleteShader(_id);
            delete[] message;
            return 0;
        }
        
        return _id;
    }
    
    
    
};

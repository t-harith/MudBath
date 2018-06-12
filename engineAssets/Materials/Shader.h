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

class Shader
{
private:
    std::string vertexSource;
    std::string fragmentSource;
    
public:
    unsigned int program_num;
    
public:
    void CreateShader(const std::string& filename)
    {
        ParseShader(filename);
        
        GLint program_ok;
        // Create
        unsigned int program = glCreateProgram();
        
        // Compile
        unsigned int vs =  CompileShader(GL_VERTEX_SHADER, vertexSource);
        unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);
        
        // Link
        glAttachShader(program, vs);
        glAttachShader(program, fs);
        glLinkProgram(program);
        glValidateProgram(program);
        
        glGetProgramiv(program, GL_LINK_STATUS, &program_ok);
        if(program_ok != GL_TRUE){
            std::cout << "ERROR, failed to link shader program" << std::endl;
        }
        
        // Clean
        glDeleteShader(vs);
        glDeleteShader(fs);
        
        program_num = program;
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

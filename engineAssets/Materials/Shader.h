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

struct Pixel_POD
{
    float r;
    float g;
    float b;
    float a;
};

class Shader
{
private:
    std::string filename;
    std::string vertexSource;
    std::string fragmentSource;
    std::vector<std::pair<std::string, float*>> pnames;
    Pixel_POD color;
    
public:
    unsigned int program_num = 0;
    
    
public:
    Shader(const std::string& file)
    {
        filename = file;
    }
    
    ~Shader()
    {
        glDeleteShader(program_num);
    }
    
    void CreateShader()
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
    
    void setPropertyValue(const char* property_name, float val1, float val2, float val3, float val4)
    {
        // To be templated in the future
        int location = glGetUniformLocation(program_num, "u_Color");
        if(location == -1)
            std::cout << "shader property name: " << property_name << " not found"  << std::endl;
        glUniform4f(location, val1, val2, val3, val4);
    }
    
    void addProperty(std::string prop_name, float* flo_ptr)
    {
        pnames.push_back({prop_name, flo_ptr});
    }
    
    void loadPropertyVals()
    {
        // To be templated in the future
        for( int i = 0; i < pnames.size(); ++i )
        {
            int location = glGetUniformLocation(program_num, pnames[i].first.c_str());
            if(location == -1)
                std::cout << "shader property name: " << pnames[i].first << " not found"  << std::endl;
            glUniform4f(location, pnames[i].second[0], pnames[i].second[1], pnames[i].second[2], pnames[i].second[3]);
        }
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

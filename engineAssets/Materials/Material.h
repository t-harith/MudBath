//
//  Material.h
//  MudBath
//
//  Created by Tejas Harith on 6/11/18.
//  Copyright © 2018 Tejas Harith. All rights reserved.
//

#ifndef Material_h
#define Material_h


#endif /* Material_h */
#include <vector>
#include "Shader.h"
#include "Texture.h"

class Material
{
    std::vector<Shader*> shaderPrograms;
    Texture* tex;
    
public:
    Material(const std::string textureFname)
    {
        tex = nullptr;
    }
    ~Material()
    {
        for (Shader * s : shaderPrograms)
        {
            delete s;
        }
        delete tex;
    }
    unsigned int addShader(Shader *shad)
    {
        shaderPrograms.push_back(shad);
        return static_cast<unsigned int>(shaderPrograms.size());
    }
    void addTexture()
    {
        tex = new Texture();
    }
    void enableShaderPrograms()
    {
        for (Shader* s : shaderPrograms)
        {
            s->CreateShader();
            glUseProgram(s->program_num);
            s->loadPropertyVals();
        }
    }
};

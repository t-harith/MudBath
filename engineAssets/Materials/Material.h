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
    Texture tex;
    
public:
    Material(const std::string textureFname)
    {
        if(textureFname != "-")
        {
            tex = Texture();
        }
    }
    void addShader(const std::string shaderFname)
    {
        shaderPrograms.push_back(new Shader(shaderFname));
    }
    void addTexture()
    {
        tex = Texture();
    }
    void enableShaderPrograms()
    {
        for (Shader* s : shaderPrograms)
        {
            s->CreateShader();
            glUseProgram(s->program_num);
            s->setPropertyValue("u_Color", 0.5f, 0.5f, 0.1f, 0.1f);
        }
    }
};

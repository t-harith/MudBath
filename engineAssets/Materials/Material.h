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
    std::vector<Shader> shaderPrograms;
    Texture tex;
    
public:
    void addShader()
    {
        
    }
    void addTexture()
    {
        tex = Texture();
    }
    ~Material()
    {
        for(Shader s : shaderPrograms)
        {
            glDeleteShader(s.program_num);
        }
    }
};

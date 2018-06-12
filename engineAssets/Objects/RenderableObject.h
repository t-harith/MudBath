//
//  RenderableObject.h
//  MudBath
//
//  Created by Tejas Harith on 6/10/18.
//  Copyright © 2018 Tejas Harith. All rights reserved.
//

#ifndef RenderableObject_h
#define RenderableObject_h


#endif /* RenderableObject_h */

#include <vector>
#include "MoveableObject.h"
#include "../Materials/Material.h"

class RenderableObject : MoveableObject
{
public:
    RenderableObject()
    {
        m_renderID = (unsigned int)renderable_objects_list.size()+1;
        renderable_objects_list.push_back(this);
    }
    unsigned int m_renderID;
    static std::vector<RenderableObject*> renderable_objects_list;
    
    void loadVAO()
    {
        glGenVertexArrays(1, &m_renderID);
        glBindVertexArray(m_renderID);
        linkVBO();
        linkIBO();
        linkMaterial();
        glEnableVertexAttribArray(m_renderID);
    }
    
    unsigned int getIBOsize()
    {
        return size_mesh_indx;
    }
private:
    float* mesh_vertx;
    unsigned int size_mesh_vertx;
    float* mesh_indx;
    unsigned int size_mesh_indx;
    
    const Material mat;
    
    void addMaterial(const Material & mater)
    {
//        mat = mater;
    }
    void linkIBO()
    {
        unsigned int IBO;
        glGenBuffers(1, &IBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_mesh_indx, mesh_indx, GL_STATIC_DRAW);
    }
    void linkVBO()
    {
        unsigned int VBO;
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, size_mesh_vertx, mesh_vertx, GL_STATIC_DRAW);
    }
    void linkMaterial()
    {
        return;
    }
    
};

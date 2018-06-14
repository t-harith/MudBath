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
    :mat(nullptr)
    {
        m_renderID = 0;
        ROList().push_back(this);
    }
    ~RenderableObject()
    {
        delete mat;
    }
    unsigned int m_renderID;
    static std::vector<RenderableObject*>& ROList()
    {
        static std::vector<RenderableObject*> renderable_objects_list;
        return renderable_objects_list;
    }
        
    void loadVAO()
    {
        glGenVertexArrays(1, &m_renderID);
        glBindVertexArray(m_renderID);
        linkVBO();
        linkIBO();
//        linkMaterial();
        genVAPointer();
        glEnableVertexAttribArray(0);
    }
    void enableShad()
    {
         mat->enableShaderPrograms();
    }
    
    unsigned int getIBOsize()
    {
        return size_mesh_indx;
    }
    
    void addMaterial(Material* mater)
    {
        mat = mater;
    }
    
    bool draw_flag = 1;
    void setVertexArray(float* vArr, unsigned int size)
    {
        mesh_vertx = vArr;
        size_mesh_vertx = size;
    }
    void setIndexArray(unsigned int* iArr, unsigned int size)
    {
        mesh_indx = iArr;
        size_mesh_indx = size;
    }
    
private:
    float* mesh_vertx;
    unsigned int size_mesh_vertx;
    unsigned int* mesh_indx;
    unsigned int size_mesh_indx;
    
    Material* mat;
    
    void linkIBO()
    {
        unsigned int IBO;
        glGenBuffers(1, &IBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_mesh_indx*sizeof(unsigned int), mesh_indx, GL_STATIC_DRAW);
    }
    void linkVBO()
    {
        unsigned int VBO;
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, size_mesh_vertx * sizeof(float), mesh_vertx, GL_STATIC_DRAW);
    }
    void linkMaterial()
    {
        return;
    }
    void genVAPointer()
    {
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
    }
    
};

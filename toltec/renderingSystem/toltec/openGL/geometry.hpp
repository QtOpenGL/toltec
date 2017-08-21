#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       16 I 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       tgl::Geometry class holds all vertex and index buffers needed to render
*       all visual aspects of an object (faces, wireframe, vertices, etc.).
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <memory>
#include <vector>

#include <glbinding/gl/types.h>

#include "renderingSystem/openGL/indexBuffer.hpp"
#include "renderingSystem/openGL/vertexBuffer.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   GEOMETRY
*-----------------------------------------------------------------------------*/
class Geometry
{
public:
    //CTOR DTOR
                    Geometry();
    virtual         ~Geometry() {}

    //ADD
    void            addVertexBuffer(std::unique_ptr<gl::VertexBuffer> p_vertexBuffer);
    void            addIndexBuffer(std::unique_ptr<gl::IndexBuffer> p_indexBuffer);

    //GET
    gl::GLuint      getVAOID() const;

private:
    gl::GLuint                                      m_vaoID;
    std::vector<std::unique_ptr<gl::VertexBuffer>>  m_vertexBufferList;
    std::vector<std::unique_ptr<gl::IndexBuffer>>   m_indexBufferList;
};

/*----------------------------------------------------------------------------*/

inline gl::GLuint Geometry::getVAOID() const
{
    return m_vaoID;
}
} //NAMESPACE: TGL

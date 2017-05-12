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
        //CONSTRUCTORS
                        Geometry();
        virtual         ~Geometry() {}

        //ADD
        void            addVertexBuffer(const gl::VertexBuffer& vertexBuffer);
        void            addIndexBuffer(const gl::IndexBuffer& indexBuffer);

        //GET
        gl::GLuint      getVAOID() const;

    private:
        gl::GLuint                      m_vaoID;
        std::vector<gl::VertexBuffer>   m_vertexBufferList;
        std::vector<gl::IndexBuffer>    m_indexBufferList;
    };

    /*----------------------------------------------------------------------------*/

    inline gl::GLuint Geometry::getVAOID() const
    {
        return m_vaoID;
    }
} //NAMESPACE: TGL
/*-----------------------------------------------------------------------------
*   CREATED:
*       12 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "geometry.hpp"

#include <glbinding/gl/boolean.h>
#include <glbinding/gl/enum.h>
#include <glbinding/gl/functions.h>

/*-----------------------------------------------------------------------------
*   NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *-----------------------------------------------------------------------------*/
    Geometry::Geometry()
        :
        m_vaoID(0)
    {
        //INITIALZE
        gl::glGenVertexArrays(1, &m_vaoID);
    }

    /*-----------------------------------------------------------------------------
    *   ADD VERTEX BUFFER
    *-----------------------------------------------------------------------------*/
    void Geometry::addVertexBuffer(const gl::VertexBuffer& vertexBuffer)
    {
        gl::GLuint  index;
        gl::GLint   size;
        gl::GLenum  type;

        //CHECK
        //semantic
        switch (vertexBuffer.getSemantic())
        {
            case gl::VertexBuffer::Semantic::POSITION:
            {
                index = 0;
                size = 3;
                break;
            }
            case gl::VertexBuffer::Semantic::UV:
            {
                index = 1;
                size = 2;
                break;
            }
            case gl::VertexBuffer::Semantic::NORMAL:
            {
                index = 2;
                size = 3;
                break;
            }
            case gl::VertexBuffer::Semantic::TANGENT:
            {
                index = 2;
                size = 3;
                break;
            }
            case gl::VertexBuffer::Semantic::BITANGENT:
            {
                index = 2;
                size = 3;
                break;
            }
        }
        //data type
        switch (vertexBuffer.getDataType())
        {
            case gl::VertexBuffer::DataType::FLOAT:
            {
                type = gl::GLenum::GL_FLAT;
                break;
            }
            case gl::VertexBuffer::DataType::DOUBLE:
            {
                type = gl::GLenum::GL_DOUBLE;
                break;
            }
            case gl::VertexBuffer::DataType::INT:
            {
                type = gl::GLenum::GL_INT;
                break;
            }
            case gl::VertexBuffer::DataType::UINT:
            {
                type = gl::GLenum::GL_UNSIGNED_INT;
                break;
            }
        }

        //SETUP
        gl::glBindVertexArray(m_vaoID);
        vertexBuffer.bind();

        gl::glEnableVertexAttribArray(index);
        gl::glVertexAttribPointer(index, size, type, gl::GL_FALSE, 0, (gl::GLvoid*)0);

        vertexBuffer.unbind();
        gl::glBindVertexArray(0);

        //ADD
        m_vertexBufferList.push_back(vertexBuffer);
    }

    /*-----------------------------------------------------------------------------
    *   ADD INDEX BUFFER
    *-----------------------------------------------------------------------------*/
    void Geometry::addIndexBuffer(const gl::IndexBuffer& indexBuffer)
    {
        m_indexBufferList.push_back(indexBuffer);
    }
} //NAMESPACE: TGL

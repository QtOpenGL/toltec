#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       06 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <cstdint>
#include <cstdlib>
#include <string>
#include <vector>

#include <glbinding/gl/enum.h>
#include <glbinding/gl/functions.h>
#include <glbinding/gl/types.h>

/*-----------------------------------------------------------------------------
*   NAMESPACE: GL (OPENGL)
*-----------------------------------------------------------------------------*/
namespace gl
{
/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   INDEX BUFFER
*-----------------------------------------------------------------------------*/
class IndexBuffer
{
public:
    //TYPES
    enum DataType {
        UINT_32
    };

    //CONSTRUCTORS
    explicit        IndexBuffer(IndexBuffer::DataType dataType);
    virtual         ~IndexBuffer() {};

    //GET
    gl::GLuint              getID() const;
    gl::GLenum              getGLDataType() const;
    const std::uint32_t&    getIndexCount() const;

    //OTHER
    void            bind() const;
    void            unbind() const;

    template<typename T>
    void            updateData(const std::vector<T>& data);

private:
    gl::GLuint                  m_id;
    IndexBuffer::DataType       m_dataType;
    gl::GLenum                  m_glDataType;
    std::size_t                 m_sizeInBytes;
    std::uint32_t               m_indexCount;
};

/*----------------------------------------------------------------------------*/

inline gl::GLuint IndexBuffer::getID() const
{
    return m_id;
}

inline gl::GLenum IndexBuffer::getGLDataType() const
{
    return m_glDataType;
}

inline const std::uint32_t& IndexBuffer::getIndexCount() const
{
    return m_indexCount;
}

inline void IndexBuffer::bind() const
{
    glBindBuffer(GLenum::GL_ELEMENT_ARRAY_BUFFER, m_id);
}

inline void IndexBuffer::unbind() const
{
    glBindBuffer(GLenum::GL_ELEMENT_ARRAY_BUFFER, 0);
}
} //NAMESPACE: GL

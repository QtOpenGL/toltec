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
#include <glm/glm.hpp>

/*-----------------------------------------------------------------------------
*   NAMESPACE: GL (OPENGL)
*-----------------------------------------------------------------------------*/
namespace gl
{
    /*-----------------------------------------------------------------------------
    *   CLASS DECLARATIONS
    *   VERTEX BUFFER
    *-----------------------------------------------------------------------------*/
    class VertexBuffer
    {
    public:
        //TYPES
        enum DataType {
            FLOAT,
            DOUBLE,
            INT,
            UINT
        };
        enum Semantic {
            POSITION,
            UV,
            NORMAL,
            TANGENT,
            BITANGENT
        };

        //CTOR DTOR
                    VertexBuffer(VertexBuffer::DataType m_dataType, VertexBuffer::Semantic m_semantic);
        virtual     ~VertexBuffer() {};

        //GET
        VertexBuffer::DataType      getDataType() const;
        VertexBuffer::Semantic      getSemantic() const;

        //OTHER
        void        bind() const;
        void        unbind() const;

        template<typename T>
        void        updateData(const std::vector<T>& data);

    private:
        GLuint                      m_id;
        VertexBuffer::DataType      m_dataType;
        VertexBuffer::Semantic      m_semantic;
        std::size_t                 m_sizeInBytes;
        std::uint32_t               m_vertexCount;
    };

    /*----------------------------------------------------------------------------*/

    inline VertexBuffer::DataType VertexBuffer::getDataType() const
    {
        return m_dataType;
    }

    inline VertexBuffer::Semantic VertexBuffer::getSemantic() const
    {
        return m_semantic;
    }

    inline void VertexBuffer::bind() const
    {
        glBindBuffer(GLenum::GL_ARRAY_BUFFER, m_id);
    }

    inline void VertexBuffer::unbind() const
    {
        glBindBuffer(GLenum::GL_ARRAY_BUFFER, 0);
    }
} //NAMESPACE: GL

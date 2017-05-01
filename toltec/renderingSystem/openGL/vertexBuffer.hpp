#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		06 II 2017
*	CONTRIBUTORS:
*		Piotr Makal
*	INFO:
*		...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <cstdint>
#include <cstdlib>
#include <string>
#include <vector>

#include <glbinding/gl/types.h>
#include <glm/glm.hpp>

/*-----------------------------------------------------------------------------
*	NAMESPACE: GL (OPENGL)
*-----------------------------------------------------------------------------*/
namespace gl
{
    /*-----------------------------------------------------------------------------
    *	CLASS DECLARATIONS
    *	VERTEX BUFFER
    *-----------------------------------------------------------------------------*/
    class VertexBuffer
    {
    public:
        //TYPES
        enum DataType {
            FLOAT,
            DOUBLE,
            INT_32,
            UINT_32
        };
        enum Semantic {
            POSITION,
            UV,
            NORMAL,
            TANGENT,
            BITANGENT
        };

        //CONSTRUCTORS
                    VertexBuffer(VertexBuffer::DataType m_dataType, VertexBuffer::Semantic m_semantic);
        virtual		~VertexBuffer() {};

        //OTHER
        template<typename T>
        void		updateData(const std::vector<T>& data);

    private:
        GLuint						m_id;
        VertexBuffer::DataType		m_dataType;
        VertexBuffer::Semantic		m_semantic;
        std::size_t					m_sizeInBytes;
        std::uint32_t				m_vertexCount;
    };
} //NAMESPACE: GL
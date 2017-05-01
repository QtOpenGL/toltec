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

/*-----------------------------------------------------------------------------
*	NAMESPACE: GL (OPENGL)
*-----------------------------------------------------------------------------*/
namespace gl
{
    /*-----------------------------------------------------------------------------
    *	CLASS DECLARATIONS
    *	INDEX BUFFER
    *-----------------------------------------------------------------------------*/
    class IndexBuffer
    {
    public:
        //TYPES
        enum DataType {
            UINT_32
        };

        //CONSTRUCTORS
        explicit	IndexBuffer(IndexBuffer::DataType dataType);
        virtual		~IndexBuffer() {};

        //OTHER
        template<typename T>
        void		updateData(const std::vector<T>& data);

    private:
        gl::GLuint					m_id;
        IndexBuffer::DataType		m_dataType;
        std::size_t					m_sizeInBytes;
    };
} //NAMESPACE: GL
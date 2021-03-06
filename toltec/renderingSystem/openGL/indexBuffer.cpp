/*-----------------------------------------------------------------------------
*   CREATED:
*       12 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "indexBuffer.hpp"

#include <type_traits>
#include "utils.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: GL (OPENGL)
*-----------------------------------------------------------------------------*/
namespace gl
{
/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*   (IndexBuffer::DataType)
*-----------------------------------------------------------------------------*/
gl::IndexBuffer::IndexBuffer(IndexBuffer::DataType dataType)
    :
    m_id(0),
    m_dataType(dataType),
    m_sizeInBytes(0)
{
    //INITIALIZE
    switch (m_dataType)
    {
        case IndexBuffer::DataType::UINT_32:    m_glDataType = gl::GLenum::GL_UNSIGNED_INT;     break;
    }

    //SETUP
    glGenBuffers(1, &m_id);
    glBindBuffer(GLenum::GL_ELEMENT_ARRAY_BUFFER, m_id);
    glBufferData(GLenum::GL_ELEMENT_ARRAY_BUFFER, m_sizeInBytes, nullptr, GLenum::GL_DYNAMIC_DRAW);
    glBindBuffer(GLenum::GL_ARRAY_BUFFER, 0);
}

/*-----------------------------------------------------------------------------
*   UPDATE DATA
*   (const std::vector<T>& data)
*-----------------------------------------------------------------------------*/
//FORWARD DECLARATIONS
template void IndexBuffer::updateData<std::uint32_t>(const std::vector<uint32_t>& data);

//DEFINITION
template<typename T>
void IndexBuffer::updateData(const std::vector<T>& data)
{
    //CHECK
    switch (m_dataType)
    {
        case IndexBuffer::DataType::UINT_32:
        {
            if (std::is_same<T, std::uint32_t>::value == false)
            {
                DEBUG_ERR("Passed data missmatched the definied type (uint32)!");
                return;
            }
            break;
        }
    }
    //-->

    m_indexCount = data.size();
    std::size_t dataSizeInBytes = sizeof(T) * m_indexCount;

    //UPDATE DATA
    glBindBuffer(GLenum::GL_ELEMENT_ARRAY_BUFFER, m_id);

    if (dataSizeInBytes != m_sizeInBytes)
        glBufferData(GLenum::GL_ELEMENT_ARRAY_BUFFER, dataSizeInBytes, &data[0], GLenum::GL_DYNAMIC_DRAW);
    else
        glBufferSubData(GLenum::GL_ELEMENT_ARRAY_BUFFER, 0, dataSizeInBytes, &data[0]);

    glBindBuffer(GLenum::GL_ELEMENT_ARRAY_BUFFER, 0);
    //-->

    m_sizeInBytes = dataSizeInBytes;
}
} //NAMESPACE: GL

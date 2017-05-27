/*-----------------------------------------------------------------------------
*   CREATED:
*       06 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "vertexBuffer.hpp"

#include <type_traits>
#include "utils.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: GL (OPENGL)
*-----------------------------------------------------------------------------*/
namespace gl
{
/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*   (VertexBuffer::DataType, VertexBuffer::Semantic)
*-----------------------------------------------------------------------------*/
VertexBuffer::VertexBuffer(VertexBuffer::DataType dataType, VertexBuffer::Semantic semantic)
    :
    m_id(0),
    m_dataType(dataType),
    m_semantic(semantic),
    m_sizeInBytes(0),
    m_vertexCount(0)
{
    //INITIALIZE
    glGenBuffers(1, &m_id);
    glBindBuffer(GLenum::GL_ARRAY_BUFFER, m_id);
    glBufferData(GLenum::GL_ARRAY_BUFFER, m_sizeInBytes, nullptr, GLenum::GL_DYNAMIC_DRAW);
    glBindBuffer(GLenum::GL_ARRAY_BUFFER, 0);
}

/*-----------------------------------------------------------------------------
*   UPDATE DATA
*   (const std::vector<T>& data)
*-----------------------------------------------------------------------------*/
//FORWARD DECLARATIONS
template void VertexBuffer::updateData<float>(const std::vector<float>& data);
template void VertexBuffer::updateData<double>(const std::vector<double>& data);
template void VertexBuffer::updateData<std::int32_t>(const std::vector<int32_t>& data);
template void VertexBuffer::updateData<std::uint32_t>(const std::vector<uint32_t>& data);

//DEFINITION
template<typename T>
void VertexBuffer::updateData(const std::vector<T>& data)
{
    //CHECK
    switch (m_dataType)
    {
        case VertexBuffer::DataType::FLOAT:
        {
            if (std::is_same<T, float>::value == false)
            {
                DEBUG_ERR("Passed data missmatched the definied type (float)!");
                return;
            }
            break;
        }

        case VertexBuffer::DataType::DOUBLE:
        {
            if (std::is_same<T, double>::value == false)
            {
                DEBUG_ERR("Passed data missmatched the definied type (double)!");
                return;
            }
            break;
        }

        case VertexBuffer::DataType::INT:
        {
            if (std::is_same<T, std::int32_t>::value == false)
            {
                DEBUG_ERR("Passed data missmatched the definied type (int32)!");
                return;
            }
            break;
        }

        case VertexBuffer::DataType::UINT:
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

    m_vertexCount =                 data.size();
    std::size_t dataSizeInBytes =   sizeof(T) * m_vertexCount;

    //UPDATE DATA
    glBindBuffer(GLenum::GL_ARRAY_BUFFER, m_id);

    if (dataSizeInBytes != m_sizeInBytes)
        glBufferData(GLenum::GL_ARRAY_BUFFER, dataSizeInBytes, &data[0], GLenum::GL_DYNAMIC_DRAW);
    else
        glBufferSubData(GLenum::GL_ARRAY_BUFFER, 0, dataSizeInBytes, &data[0]);

    glBindBuffer(GLenum::GL_ARRAY_BUFFER, 0);
    //-->

    m_sizeInBytes = dataSizeInBytes;
}
} //NAMESPACE: GL
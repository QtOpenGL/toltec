/*-----------------------------------------------------------------------------
*	CREATED:
*		12 II 2017
*	CONTRIBUTORS:
*		Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "geometry.hpp"

/*-----------------------------------------------------------------------------
*	NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
    /*-----------------------------------------------------------------------------
    *	ADD VERTEX BUFFER
    *-----------------------------------------------------------------------------*/
    void Geometry::addVertexBuffer(const gl::VertexBuffer& vertexBuffer)
    {
        m_vertexBufferList.push_back(vertexBuffer);
    }

    /*-----------------------------------------------------------------------------
    *	ADD INDEX BUFFER
    *-----------------------------------------------------------------------------*/
    void Geometry::addIndexBuffer(const gl::IndexBuffer& indexBuffer)
    {
        m_indexBufferList.push_back(indexBuffer);
    }
} //NAMESPACE: TGL
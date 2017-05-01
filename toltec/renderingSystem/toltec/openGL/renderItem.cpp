/*-----------------------------------------------------------------------------
*	CREATED:
*		08 II 2017
*	CONTRIBUTORS:
*		Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderItem.hpp"

/*-----------------------------------------------------------------------------
*	NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *-----------------------------------------------------------------------------*/
    RenderItem::RenderItem(gl::GLuint vaoID, gl::GLuint indexBufferID, ShaderInstance* p_shaderInstance, 
        RenderItem::DrawMode drawMode)
        :
        m_vaoID(vaoID),
        m_indexBufferID(indexBufferID),
        mp_shaderInstance(p_shaderInstance),
        m_drawMode(drawMode)
    {
    }
} //NAMESPACE: TGL
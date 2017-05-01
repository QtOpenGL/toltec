/*-----------------------------------------------------------------------------
*	CREATED:
*		08 II 2017
*	CONTRIBUTORS:
*		Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderableObject.hpp"

#include "renderingSystem/toltec/openGL/renderItem.hpp"

/*-----------------------------------------------------------------------------
*	NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
    /*-----------------------------------------------------------------------------
    *	DESTRUCTOR
    *-----------------------------------------------------------------------------*/
    RenderableObject::~RenderableObject()
    {
        for (RenderItem* p_renderItem : m_renderItemList)
            delete p_renderItem;
    }

    /*-----------------------------------------------------------------------------
    *	ADD RENDER ITEM
    *-----------------------------------------------------------------------------*/
    void RenderableObject::addRenderItem(RenderItem* p_renderItem)
    {
        m_renderItemList.push_back(p_renderItem);
    }

    /*-----------------------------------------------------------------------------
    *	SET MODEL MATRIX
    *-----------------------------------------------------------------------------*/
    void RenderableObject::setModelMatrix(const glm::mat4& modelMatrix)
    {
        m_modelMatrix = modelMatrix;
    }
} //NAMESPACE: TGL
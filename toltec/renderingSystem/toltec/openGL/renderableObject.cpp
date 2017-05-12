/*-----------------------------------------------------------------------------
*   CREATED:
*       08 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderableObject.hpp"

#include "renderingSystem/toltec/openGL/renderItem.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *-----------------------------------------------------------------------------*/
    RenderableObject::RenderableObject()
        :
        m_modelMatrixUniform("g_modelMatrix")
    {
    }

    /*-----------------------------------------------------------------------------
    *   ADD RENDER ITEM
    *-----------------------------------------------------------------------------*/
    void RenderableObject::addRenderItem(std::unique_ptr<RenderItem> p_renderItem)
    {
        m_renderItemList.push_back(std::move(p_renderItem));
    }

    /*-----------------------------------------------------------------------------
    *   SET MODEL MATRIX
    *-----------------------------------------------------------------------------*/
    void RenderableObject::setModelMatrix(const glm::mat4& modelMatrix)
    {
        m_modelMatrixUniform.setValue(modelMatrix);
    }
} //NAMESPACE: TGL
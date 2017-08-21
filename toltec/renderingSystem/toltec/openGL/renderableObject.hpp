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
#include <memory>
#include <vector>

#include <glm/glm.hpp>

#include "renderingSystem/openGL/uniformUnit.hpp"
#include "renderingSystem/toltec/openGL/geometry.hpp"

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
namespace tgl 
{
    class RenderItem;
}

/*-----------------------------------------------------------------------------
*   NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
    /*-----------------------------------------------------------------------------
    *   CLASS DECLARATIONS
    *   RENDERABLE OBJECT
    *-----------------------------------------------------------------------------*/
    class RenderableObject
    {
    public:
        //CTOR DTOR
                    RenderableObject();
        virtual     ~RenderableObject() {}

        //ADD
        void        addRenderItem(std::unique_ptr<RenderItem> p_renderItem);

        //SET
        void        setModelMatrixValue(const glm::mat4& modelMatrix);

        //GET
        Geometry&                                       getGeometry();
        const std::vector<std::unique_ptr<RenderItem>>& getRenderItemList() const;

    private:
        Geometry                                    m_geometry;
        std::vector<std::unique_ptr<RenderItem>>    m_renderItemList;
        gl::UniformMat4                             m_modelMatrixUniform;
    };

    /*----------------------------------------------------------------------------*/

    inline Geometry& RenderableObject::getGeometry()
    {
        return m_geometry;
    }

    inline const std::vector<std::unique_ptr<RenderItem>>& RenderableObject::getRenderItemList() const
    {
        return m_renderItemList;
    }
} //NAMESPACE: TGL

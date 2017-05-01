#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		06 II 2017
*	CONTRIBUTORS:
*		Piotr Makal
*	INFO:
*		...
*
*	RAW POINTER MANAGER:
*		- m_renderItemList		(std::vector<RenderItem*>)
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <vector>
#include <glm/glm.hpp>
#include "renderingSystem/toltec/openGL/geometry.hpp"

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
namespace tgl 
{
    class RenderItem;
}

/*-----------------------------------------------------------------------------
*	NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
    /*-----------------------------------------------------------------------------
    *	CLASS DECLARATIONS
    *	RENDERABLE OBJECT
    *-----------------------------------------------------------------------------*/
    class RenderableObject
    {
    public:
        //CONSTRUCTORS
        virtual		~RenderableObject();

        //ADD
        void		addRenderItem(RenderItem* p_renderItem);

        //SET
        void		setModelMatrix(const glm::mat4& modelMatrix);

        //GET
        Geometry*		getGeometry();

    private:
        Geometry					m_geometry;
        std::vector<RenderItem*>	m_renderItemList;
        glm::mat4					m_modelMatrix;
    };

    /*----------------------------------------------------------------------------*/

    inline Geometry* RenderableObject::getGeometry()
    {
        return &m_geometry;
    }
} //NAMESPACE: TGL
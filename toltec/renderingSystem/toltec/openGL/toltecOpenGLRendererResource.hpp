#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       04 VIII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <cstdint>
#include <map>
#include <vector>

#include <glm/glm.hpp>

#include "nodes/node.hpp"
#include "renderingSystem/abstractRendererResource.hpp"
#include "renderingSystem/toltec/openGL/shaders/shaderProgram.hpp"

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
namespace tgl
{
    class RenderableObject;
    class RenderItem;
    class ShaderInstance;
}

class PolygonMeshNode;
class TransformNode;

/*-----------------------------------------------------------------------------
*   NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
    /*-----------------------------------------------------------------------------
    *   CLASS DECLARATIONS
    *   TOLTEC OPENGL RENDERER RESOURCE
    *-----------------------------------------------------------------------------*/
    class ToltecOpenGLRendererResource : public AbstractRendererResource
    {
    public:
        //CONSTRUCTORS
        virtual         ~ToltecOpenGLRendererResource();

        //OTHER
        virtual void    initializeResources();
        virtual void    updateResources() {};
        virtual void    deleteResources();

    private:
        void            initializeShaderProgramMap();

        virtual void    scanSceneTree(
                            TransformNode*          p_transformNode,
                            int&                    treeDepthLevel,
                            std::vector<glm::mat4>* p_modelMatrixList,
                            bool&                   calculateFinalModelMatrixFlag,
                            const bool&             initializeRendererResourceFlag);

        void            processPolygonMeshNode(
                            PolygonMeshNode*        p_polygonMeshNode, 
                            RenderableObject*       p_renderableObject,
                            const bool&             initializeRendererResourceFlag);

    private:
        std::map<Node::Type, ShaderProgram>         m_shaderProgramMap;

        std::map<std::uint32_t, RenderableObject*>  m_renderableObjectMap;
        std::map<std::uint32_t, ShaderInstance*>    m_shaderInstanceMap;

        std::vector<RenderItem*>                    m_finalRenderItemList;
    };
} //NAMESPACE: TGL
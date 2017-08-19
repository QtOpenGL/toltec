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
    class CameraData;
    class RenderableObject;
    class RenderItem;
    class ShaderInstance;
}

namespace core
{
    namespace nodes
    {
        class CameraNode;
        class PolygonMeshNode;
        class TransformNode;
    }
}

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
    //STRUCTS
    struct ResourcePerViewport {
        std::map<core::nodes::Type, std::unique_ptr<ShaderProgram>> shaderProgramMap;
        std::map<node_id, std::unique_ptr<ShaderInstance>>          shaderInstanceMap;

        std::map<node_id, std::unique_ptr<CameraData>>              cameraDataMap;
        std::map<node_id, std::unique_ptr<RenderableObject>>        renderableObjectMap;

        std::vector<RenderItem*>                                    finalRenderItemList;  //cleared after every render sequence
    };

    //CONSTRUCTORS
                    ToltecOpenGLRendererResource();
    virtual         ~ToltecOpenGLRendererResource();

    //ADD
    void            addToFinalRenderItemList(RenderItem* p_renderItem, unsigned int viewportIndex);

    //GET
    const std::map<node_id, std::unique_ptr<RenderableObject>>&
                    getRenderableObjectMap(unsigned int viewportIndex) const;
    const std::vector<RenderItem*>&
                    getFinalRenderItemList(unsigned int viewportIndex) const;

    //OTHER
    virtual void    initializeResources();
    virtual void    updateResources() {}
    virtual void    deleteResources();

    void            clearFinalRenderItemList(const int& viewportIndex = -1);
    void            clearAllFinalRenderItemLists();

private:
    void            initializeShaderProgramMap();

    virtual void    scanUserShaderProgramNodeList(const bool& initializeRendererResourceFlag);
    virtual void    scanSceneTree(
                        core::nodes::TransformNode&     transformNode,
                        int&                            treeDepthLevel,
                        std::vector<glm::mat4>*         p_modelMatrixList,
                        bool&                           calculateFinalModelMatrixFlag,
                        const bool&                     initializeRendererResourceFlag);
    void            processCameraNode(
                        core::nodes::CameraNode*        p_CameraNode,
                        RenderableObject*               p_renderableObject,
                        const bool&                     initializeRendererResourceFlag);
    void            processPolygonMeshNode(
                        core::nodes::PolygonMeshNode*   p_polygonMeshNode,
                        RenderableObject*               p_renderableObject,
                        const bool&                     initializeRendererResourceFlag);

private:
    std::vector<std::unique_ptr<ToltecOpenGLRendererResource::ResourcePerViewport>> m_resourcePerViewportList;
    unsigned int    m_activeViewportIndex;
};
} //NAMESPACE: TGL

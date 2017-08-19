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
#include <memory>
#include <vector>

#include <glm/glm.hpp>

#include "renderingSystem/abstractViewport.hpp"

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
namespace core
{
    namespace nodes
    {
        class TransformNode;
    }
}

/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   ABSTRACT RENDERER RESOURCE
*-----------------------------------------------------------------------------*/
class AbstractRendererResource
{
public:
    //CONSTRUCTORS
                    AbstractRendererResource();
    virtual         ~AbstractRendererResource() {}

    //?
    bool            areResourcesInitialized();

    //ADD
    void            addViewport(AbstractViewport* p_viewport);

    //GET
    std::vector<AbstractViewport*>& getViewportList();

    //OTHER
    virtual void    initializeResources() = 0;
    virtual void    updateResources() = 0;
    virtual void    deleteResources() = 0;

protected:
    virtual void    scanUserShaderProgramNodeList(const bool& initializeRendererResourceFlag) = 0;
    virtual void    scanSceneTree(
                        core::nodes::TransformNode& transformNode,
                        int&                        treeDepthLevel,
                        std::vector<glm::mat4>*     p_modelMatrixList,
                        bool&                       calculateFinalModelMatrixFlag,
                        const bool&                 initializeRendererResourceFlag) = 0;

protected:
    bool                            m_areResourcesInitialized;
    std::vector<AbstractViewport*>  m_viewportList;

private:
    //...
};

/*----------------------------------------------------------------------------*/

inline bool AbstractRendererResource::areResourcesInitialized()
{
    return m_areResourcesInitialized;
}

inline std::vector<AbstractViewport*>& AbstractRendererResource::getViewportList()
{
    return m_viewportList;
}

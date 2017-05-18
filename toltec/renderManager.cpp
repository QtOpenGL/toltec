/*-----------------------------------------------------------------------------
*   CREATED:
*       06 VIII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderManager.hpp"

#include <algorithm>

#include "nodes/node.hpp"
#include "ui/gui/viewportPanel.hpp"
#include "renderingSystem/abstractRenderer.hpp"
#include "renderingSystem/abstractRendererResource.hpp"
#include "renderingSystem/abstractViewport.hpp"
#include "renderingSystem/renderingSystem.hpp"
#include "resourceManager.hpp"
#include "utils.hpp"

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*-----------------------------------------------------------------------------*/
RenderManager::RenderManager()
{
}

/*-----------------------------------------------------------------------------
*   ADD RENDERING SYSTEM
*-----------------------------------------------------------------------------*/
void RenderManager::addRenderingSystem(RenderingSystem* p_renderingSystem)
{
    //Perform a check if object already exists in a vector to prevent duplicates.
    auto endIter =      std::end(m_renderingSystemList);
    auto findIter =     std::find(std::begin(m_renderingSystemList), endIter, p_renderingSystem);

    if (findIter != endIter)
        return;
    else
        m_renderingSystemList.push_back(p_renderingSystem);
}

/*-----------------------------------------------------------------------------
*   RENDER CALL
*   (AbstractViewport*)
*-----------------------------------------------------------------------------*/
void RenderManager::renderCall(AbstractViewport* p_viewport)
{
    p_viewport->getRenderer()->requestRender(p_viewport);
    this->finishRenderCall();
}

/*-----------------------------------------------------------------------------
*   RENDER CALL
*   (RenderingSystem*)
*-----------------------------------------------------------------------------*/
void RenderManager::renderCall(RenderingSystem* p_renderingSystem)
{
    const auto& viewportList = p_renderingSystem
        ->getActiveRenderingAPI()
        .getActiveRenderer()
        .getRendererResource()
        .getViewportList();

    for (const auto& p_viewport : viewportList)
        p_viewport->getRenderer()->requestRender(p_viewport.get());

    this->finishRenderCall();
}

/*-----------------------------------------------------------------------------
*   RENDER CALL
*   (RenderingSystem*)
*-----------------------------------------------------------------------------*/
void RenderManager::renderCall(const std::string& renderingSystemName)
{
    RenderingSystem* p_renderingSystem =    nullptr;

    //RETRIVE RENDERING SYSTEM
    for (auto p_renderingSystemListItem : m_renderingSystemList)
    {
        if (p_renderingSystemListItem->getName() == renderingSystemName)
        {
            p_renderingSystem = p_renderingSystemListItem;
            break;
        }
    }
    if (p_renderingSystem == nullptr)
    {
        DEBUG_ERR("Rendering system not found!");
        return;
    }

    //REQUEST RENDERER
    const auto& viewportList = p_renderingSystem
        ->getActiveRenderingAPI()
        .getActiveRenderer()
        .getRendererResource()
        .getViewportList();

    for (const auto& p_viewport : viewportList)
        p_viewport->getRenderer()->requestRender(p_viewport.get());
    //-->

    this->finishRenderCall();
}

/*-----------------------------------------------------------------------------
*   RENDER CALL
*   ()
*-----------------------------------------------------------------------------*/
void RenderManager::renderCall()
{
    //...

    this->finishRenderCall();
}

/*-----------------------------------------------------------------------------
*   FINISH RENDER CALL
*-----------------------------------------------------------------------------*/
void RenderManager::finishRenderCall()
{
    //SET TO FALSE INITIALIZE AND UPDATE FLAGS ON ALL NODES
    const std::vector<Node*>* p_allNodeList = ResourceManager::getInstance().getAllNodeList();
    for (auto p_node : *p_allNodeList)
    {
        p_node->setInitializeFlag(false);
        p_node->setUpdateFlag(false);
    }
}

/*-----------------------------------------------------------------------------
*   CREATED:
*       04 VIII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderingSystem.hpp"

#include <cstdlib>
#include <glbinding/Binding.h>

#include "renderingSystem/abstractRenderer.hpp"
#include "renderingSystem/abstractRendererResource.hpp"
#include "renderingSystem/openGL/openGLViewport.hpp"
#include "ui/gui/viewportPanel.hpp"
#include "utils.hpp"

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*   (const std::string&)
*-----------------------------------------------------------------------------*/
RenderingSystem::RenderingSystem(const std::string& name)
    :
    m_name(name),
    mp_activeRenderingAPI(nullptr)
{
}

/*-----------------------------------------------------------------------------
*   ADD RENDERING API
*-----------------------------------------------------------------------------*/
void RenderingSystem::addRenderingAPI(RenderingAPI* p_renderingAPI)
{
    RenderingAPI::Type renderingAPIType = p_renderingAPI->getType();

    //If this is the first rendering API, make it to be the active one.
    if (m_renderingAPIMap.size() == 0)
        mp_activeRenderingAPI = p_renderingAPI;

    //Prevent overwrite.
    auto iterator = m_renderingAPIMap.find(renderingAPIType);
    if (iterator == m_renderingAPIMap.end())
        m_renderingAPIMap[renderingAPIType] = p_renderingAPI;
}

/*-----------------------------------------------------------------------------
*   SWITCH TO RENDERING API
*-----------------------------------------------------------------------------*/
void RenderingSystem::switchToRenderingAPI(RenderingAPI::Type renderingAPIType)
{
    //CHECK
    //if exists
    auto iter = m_renderingAPIMap.find(renderingAPIType);
    if (iter == m_renderingAPIMap.end())
    {
        DEBUG_ERR("Specified API type could not be found!");
        return;
    }

    //if already assigned
    if (mp_activeRenderingAPI->getType() == renderingAPIType)
        return;

    //CLEAR OLD RESOURCES
    mp_activeRenderingAPI->getRenderer()->getRendererResource()->deleteResources();

    //SET NEW
    mp_activeRenderingAPI = iter->second;
    mp_activeRenderingAPI->getRenderer()->getRendererResource()->initializeResources();
}

/*-----------------------------------------------------------------------------
*   CREATE VIEWPORT
*-----------------------------------------------------------------------------*/
AbstractViewport* RenderingSystem::createViewport()
{
    switch (mp_activeRenderingAPI->getType())
    {
    case RenderingAPI::OPENGL_API:
        gl::OpenGLViewport* p_viewport = new gl::OpenGLViewport();
        p_viewport->setRenderer(mp_activeRenderingAPI->getRenderer());

        //set opengl
        p_viewport->makeCurrent();
        glbinding::Binding::initialize();
        p_viewport->doneCurrent();

        return p_viewport;
    }
}

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
#include <glbinding/gl/gl.h>
#include <glbinding/ContextInfo.h>

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
*   ADD VIEWPORT PANEL
*-----------------------------------------------------------------------------*/
void RenderingSystem::addViewportPanel(ViewportPanel* p_viewportPanel)
{
    m_viewportPanelList.push_back(p_viewportPanel);
}

/*-----------------------------------------------------------------------------
*   REMOVE VIEWPORT PANEL
*-----------------------------------------------------------------------------*/
void RenderingSystem::removeViewportPanel(ViewportPanel* p_viewportPanel)
{
    std::size_t numViewportPanels = m_viewportPanelList.size();
    for (std::size_t i = 0; i < numViewportPanels; i++)
    {
        if (m_viewportPanelList[i] == p_viewportPanel)
            m_viewportPanelList.erase(m_viewportPanelList.begin() + i);
    }
}

/*-----------------------------------------------------------------------------
*   SWITCH TO RENDERING API
*-----------------------------------------------------------------------------*/
void RenderingSystem::switchToRenderingAPI(RenderingAPI::Type renderingAPIType)
{
    //CHECK
    //if exists
    auto iterator = m_renderingAPIMap.find(renderingAPIType);
    if (iterator == m_renderingAPIMap.end())
    {
        DEBUG_MSG("ERROR : Specified API type could not be found!");
        return;
    }

    //if already assigned
    if (mp_activeRenderingAPI->getType() == renderingAPIType)
        return;

    //CLEAR OLD RESOURCES
    mp_activeRenderingAPI->getRenderer()->getRendererResource()->deleteResources();

    //SET NEW
    mp_activeRenderingAPI = iterator->second;
    mp_activeRenderingAPI->getRenderer()->getRendererResource()->initializeResources();
}

/*-----------------------------------------------------------------------------
*   PRINT OPENGL DATA
*-----------------------------------------------------------------------------*/
void RenderingSystem::printOpenGLData() const
{
    //CHECK
    if (mp_activeRenderingAPI->getType() != RenderingAPI::OPENGL_API || m_viewportPanelList.size() == 0)
        return;

    //FETCH
    gl::OpenGLViewport* p_openGLViewport = static_cast<gl::OpenGLViewport*>(m_viewportPanelList[0]->getViewport());

    //PRINT
    p_openGLViewport->makeCurrent();

    //fetch data
    int data[10];
    gl::glGetIntegerv(gl::GLenum::GL_MAX_UNIFORM_LOCATIONS, &data[0]);
    gl::glGetIntegerv(gl::GLenum::GL_MAX_VERTEX_UNIFORM_COMPONENTS, &data[1]);
    gl::glGetIntegerv(gl::GLenum::GL_MAX_FRAGMENT_UNIFORM_COMPONENTS, &data[2]);

    //print data
    std::cout << "OpenGL ver.:\t" << gl::glGetString(gl::GLenum::GL_VERSION) << std::endl
        << "GLSL ver.:\t" << gl::glGetString(gl::GLenum::GL_SHADING_LANGUAGE_VERSION) << std::endl
        << "Lib. vendor:\t" << gl::glGetString(gl::GLenum::GL_VENDOR) << std::endl
        << "Renderer:\t" << gl::glGetString(gl::GLenum::GL_RENDERER) << "\n\n"

        << "Max uniform locations:\t\t" << data[0] << std::endl
        << "Max vert uniform components:\t" << data[1] << std::endl
        << "Max frag uniform components:\t" << data[2] << "\n\n";

    p_openGLViewport->doneCurrent();
}

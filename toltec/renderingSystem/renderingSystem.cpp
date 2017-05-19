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
    mp_activeRenderingAPI->getActiveRenderer().getRendererResource().deleteResources();

    //SET NEW
    mp_activeRenderingAPI = iter->second;
    mp_activeRenderingAPI->getActiveRenderer().getRendererResource().initializeResources();
}

/*-----------------------------------------------------------------------------
*   CREATE VIEWPORT
*-----------------------------------------------------------------------------*/
AbstractViewport* RenderingSystem::createViewport()
{
    switch (mp_activeRenderingAPI->getType())
    {
        case RenderingAPI::OPENGL_API:
        {
            gl::OpenGLViewport* p_viewport = new gl::OpenGLViewport();
            p_viewport->setRenderer(&(mp_activeRenderingAPI->getActiveRenderer()));

            p_viewport->makeCurrent();
            glbinding::Binding::initialize();
            p_viewport->doneCurrent();

            mp_activeRenderingAPI->getRendererResource().addViewport(p_viewport);

            return p_viewport;
        }

        default:
        {
            return nullptr;
        }
    }
}

/*-----------------------------------------------------------------------------
*   PRINT CONTEXT INFO
*-----------------------------------------------------------------------------*/
void RenderingSystem::printContextInfo() const
{
    ////PRINT
    //this->makeCurrent();

    ////fetch data
    //int data[10];
    //glGetIntegerv(GLenum::GL_MAX_UNIFORM_LOCATIONS, &data[0]);
    //glGetIntegerv(GLenum::GL_MAX_VERTEX_UNIFORM_COMPONENTS, &data[1]);
    //glGetIntegerv(GLenum::GL_MAX_FRAGMENT_UNIFORM_COMPONENTS, &data[2]);

    ////print data
    //std::cout << "OpenGL ver.:\t" << glGetString(GLenum::GL_VERSION) << std::endl
    //  << "GLSL ver.:\t" << glGetString(GLenum::GL_SHADING_LANGUAGE_VERSION) << std::endl
    //  << "Lib. vendor:\t" << glGetString(GLenum::GL_VENDOR) << std::endl
    //  << "Renderer:\t" << glGetString(GLenum::GL_RENDERER) << "\n\n"

    //  << "Max uniform locations:\t\t" << data[0] << std::endl
    //  << "Max vert uniform components:\t" << data[1] << std::endl
    //  << "Max frag uniform components:\t" << data[2] << "\n\n";

    //this->doneCurrent();
}

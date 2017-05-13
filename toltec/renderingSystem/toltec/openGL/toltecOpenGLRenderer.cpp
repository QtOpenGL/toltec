/*-----------------------------------------------------------------------------
*   CREATED:
*       07 VIII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "toltecOpenGLRenderer.hpp"

#include <iostream>
#include <QtCore/qcoreapplication.h>

#include <glbinding/gl/gl.h>

#include "events/renderEvent.hpp"
#include "guiManager.hpp"
#include "renderingSystem/abstractViewport.hpp"
#include "renderingSystem/openGL/openGLViewport.hpp"
#include "renderingSystem/renderingAPI.hpp"
#include "renderingSystem/toltec/openGL/toltecOpenGLRendererResource.hpp"
#include "utils.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *-----------------------------------------------------------------------------*/
    ToltecOpenGLRenderer::ToltecOpenGLRenderer()
    {
        //INITIALIZE
        mp_rendererResource = std::move(
            std::unique_ptr<ToltecOpenGLRendererResource>(new ToltecOpenGLRendererResource()));
    }

    /*-----------------------------------------------------------------------------
    *   EVENT
    *-----------------------------------------------------------------------------*/
    bool ToltecOpenGLRenderer::event(QEvent* p_event)
    {
        if (p_event->type() == RenderEvent::TYPE)
        {
            RenderEvent* p_rednerEvent =        static_cast<RenderEvent*>(p_event);
            AbstractViewport* p_viewport =      p_rednerEvent->getViewport();

            this->prepareForRendering();
            this->render(p_viewport);
            return true;
        }
        else
        {
            return QObject::event(p_event);
        }
    }

    /*-----------------------------------------------------------------------------
    *   REQUEST RENDER
    *-----------------------------------------------------------------------------*/
    void ToltecOpenGLRenderer::requestRender(AbstractViewport* p_viewport)
    {
        //SEND EVENT
        RenderEvent renderEvent(p_viewport);
        QCoreApplication::sendEvent(this, &renderEvent);
    }

    /*-----------------------------------------------------------------------------
    *   PREPARE FOR RENDERING
    *-----------------------------------------------------------------------------*/
    void ToltecOpenGLRenderer::prepareForRendering()
    {
        //INITIALIZE OR UPDATE RENDER RESOURCES
        if (mp_rendererResource->areResourcesInitialized() == false)
            mp_rendererResource->initializeResources();
        else
            mp_rendererResource->updateResources();

        //RENDER ITEM PRUNING
        //...
    }

    /*-----------------------------------------------------------------------------
    *   RENDER
    *-----------------------------------------------------------------------------*/
    void ToltecOpenGLRenderer::render(AbstractViewport* p_viewport)
    {
        /*-----------------------------------------------------------------------------
        *   CHECK
        *-----------------------------------------------------------------------------*/
        if (p_viewport->getType() != RenderingAPI::OPENGL_API)
        {
            GUIManager::getInstance().displayError("Viewport type is not matching renderer type!");
            return;
        }

        /*-----------------------------------------------------------------------------
        *   CAST
        *-----------------------------------------------------------------------------*/
        gl::OpenGLViewport* p_openGLViewport = static_cast<gl::OpenGLViewport*>(p_viewport);

        /*-----------------------------------------------------------------------------
        *   MAKE OPENGL CONTEXT CURRENT AGAINST GIVEN SURFACE
        *-----------------------------------------------------------------------------*/
        p_openGLViewport->makeCurrent();

        /*-----------------------------------------------------------------------------
        *   BUFFERS
        *-----------------------------------------------------------------------------*/
        //SET BACKGROUND COLOR
        gl::glClearColor(1.5f, 0.5f, 0.5f, 1.0f);

        //CLEAR BUFFERS
        gl::glClear(gl::GL_COLOR_BUFFER_BIT | gl::GL_DEPTH_BUFFER_BIT);

        /*-----------------------------------------------------------------------------
        *   SWAP BUFFERS
        *-----------------------------------------------------------------------------*/
        p_openGLViewport->swapBuffers();

        /*-----------------------------------------------------------------------------
        *   DONE CURRENT
        *   Convenience function for calling makeCurrent with a 0 surface.
        *-----------------------------------------------------------------------------*/
        p_openGLViewport->doneCurrent();
    }
} //NAMESPACE: TGL
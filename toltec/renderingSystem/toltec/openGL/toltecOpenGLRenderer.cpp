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
#include "renderingSystem/toltec/openGL/renderableObject.hpp"
#include "renderingSystem/toltec/openGL/renderItem.hpp"
#include "renderingSystem/toltec/openGL/toltecOpenGLRendererResource.hpp"
#include "utils.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*   (AbstractRendererResource*)
*-----------------------------------------------------------------------------*/
ToltecOpenGLRenderer::ToltecOpenGLRenderer(AbstractRendererResource* p_abstractRendererResource)
    :
    AbstractRenderer(p_abstractRendererResource)
{
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

        //GET VIEWPORT INDEX
        unsigned int viewportIndex = 0;
        for (const auto p_viewportListElement : mp_rendererResource->getViewportList())
        {
            if (p_viewportListElement == p_viewport)
                break;

            viewportIndex++;
        }

        //CAST
        gl::OpenGLViewport* p_openGLViewport = dynamic_cast<gl::OpenGLViewport*>(p_viewport);

        //RENDER
        if (p_openGLViewport != nullptr)
        {
            this->prepareForRendering(viewportIndex);
            this->render(p_openGLViewport);
        }

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
void ToltecOpenGLRenderer::prepareForRendering(const unsigned int& viewportIndex)
{
    //INITIALIZE/UPDATE RENDER RESOURCES
    if (mp_rendererResource->areResourcesInitialized() == false)
        mp_rendererResource->initializeResources();
    else
        mp_rendererResource->updateResources();

    //CAST
    ToltecOpenGLRendererResource* p_renderResource =
        static_cast<ToltecOpenGLRendererResource*>(mp_rendererResource);

    //RESET
    p_renderResource->clearFinalRenderItemList(viewportIndex); //temporary?? no need to clear it every render

    //RENDER ITEM PRUNING
    const auto& renderableObjectMap = p_renderResource->getRenderableObjectMap(viewportIndex);
    for (const auto& kv : renderableObjectMap)
    {
        //for now no pruning at all...
        const auto& renderItemList = kv.second->getRenderItemList();
        for (const auto& p_renderItem : renderItemList)
        {
            p_renderResource->addToFinalRenderItemList(p_renderItem.get(), viewportIndex);
        }
    }
}

/*-----------------------------------------------------------------------------
*   RENDER
*-----------------------------------------------------------------------------*/
void ToltecOpenGLRenderer::render(gl::OpenGLViewport* p_viewport)
{
    /*-----------------------------------------------------------------------------
    *   PREPARATION
    *-----------------------------------------------------------------------------*/
    //CAST
    ToltecOpenGLRendererResource* p_renderResource = 
        static_cast<ToltecOpenGLRendererResource*>(mp_rendererResource);

    /*-----------------------------------------------------------------------------
    *   MAKE CURRENT (OPENGL CONTEXT) AGAINST GIVEN SURFACE
    *-----------------------------------------------------------------------------*/
    p_viewport->makeCurrent();

    /*-----------------------------------------------------------------------------
    *   BUFFERS
    *-----------------------------------------------------------------------------*/
    //SET BACKGROUND COLOR
    gl::glClearColor(1.5f, 0.5f, 0.5f, 1.0f);

    //CLEAR BUFFERS
    gl::glClear(gl::GL_COLOR_BUFFER_BIT | gl::GL_DEPTH_BUFFER_BIT);

    /*-----------------------------------------------------------------------------
    *   RENDER
    *----------------------------------------------------------------------------*/
    //...

    /*-----------------------------------------------------------------------------
    *   SWAP BUFFERS
    *-----------------------------------------------------------------------------*/
    p_viewport->swapBuffers();

    /*-----------------------------------------------------------------------------
    *   DONE CURRENT
    *   Convenience function for calling makeCurrent with a 0 surface.
    *-----------------------------------------------------------------------------*/
    p_viewport->doneCurrent();
}
} //NAMESPACE: TGL
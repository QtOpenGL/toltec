/*-----------------------------------------------------------------------------
*	CREATED:
*		11 VIII 2016
*	CONTRIBUTORS:
*		PIOTR MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "openGLViewport.hpp"

#include <QtGui/qsurfaceformat.h>
#include <QtGui/qopenglcontext.h>

#include "renderingSystem/renderingAPI.hpp"

/*-----------------------------------------------------------------------------
*	NAMESPACE: GL (OPENGL)
*-----------------------------------------------------------------------------*/
namespace gl
{
    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *-----------------------------------------------------------------------------*/
    OpenGLViewport::OpenGLViewport()
        :
        mp_openGLContext(nullptr)
    {
        //INITIALIZE
        m_type = RenderingAPI::OPENGL_API;
        this->initializeOpenGLContext();
    }

    /*-----------------------------------------------------------------------------
    *	EXPOSE EVENT
    *-----------------------------------------------------------------------------*/
    void OpenGLViewport::exposeEvent(QExposeEvent* p_exposeEvent)
    {
        Q_UNUSED(p_exposeEvent);
        if (this->isExposed())
            mp_renderer->requestRender(this);
    }

    /*-----------------------------------------------------------------------------
    *	MAKE CURRENT
    *-----------------------------------------------------------------------------*/
    void OpenGLViewport::makeCurrent()
    {
        mp_openGLContext->makeCurrent(this);
    }

    /*-----------------------------------------------------------------------------
    *	DONE CURRENT
    *-----------------------------------------------------------------------------*/
    void OpenGLViewport::doneCurrent()
    {
        mp_openGLContext->doneCurrent();
    }

    /*-----------------------------------------------------------------------------
    *	SWAP BUFFERS
    *-----------------------------------------------------------------------------*/
    void OpenGLViewport::swapBuffers()
    {
        mp_openGLContext->swapBuffers(this);
    }

    /*-----------------------------------------------------------------------------
    *	INITIALIZE OPENGL CONTEXT
    *-----------------------------------------------------------------------------*/
    void OpenGLViewport::initializeOpenGLContext()
    {
        //SURFACE FORMAT
        QSurfaceFormat qSurfaceFormat;
        qSurfaceFormat.setRedBufferSize(8);				//8-BIT RED
        qSurfaceFormat.setGreenBufferSize(8);			//8-BIT GREEN
        qSurfaceFormat.setBlueBufferSize(8);			//8-BIT BLUE
        qSurfaceFormat.setAlphaBufferSize(8);			//8-BIT ALPHA
        qSurfaceFormat.setDepthBufferSize(24);			//24-BIT DEPTH
        qSurfaceFormat.setSamples(8);					//8-BIT MULTISAMPLING

        //SET WINDOW PROPERTIES
        this->setSurfaceType(QWindow::OpenGLSurface);
        this->setFormat(qSurfaceFormat);

        //OPENGL CONTEXT
        mp_openGLContext = new QOpenGLContext(this);
        mp_openGLContext->setFormat(qSurfaceFormat);
        mp_openGLContext->create();
    }
}; //NAMESPACE: GL

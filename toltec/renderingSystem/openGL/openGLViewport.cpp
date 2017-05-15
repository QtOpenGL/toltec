/*-----------------------------------------------------------------------------
*   CREATED:
*       11 VIII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "openGLViewport.hpp"

#include <iostream>

#include <glbinding/gl/gl.h>        //include glbinding before qt headers!
#include <glbinding/Binding.h>
#include <glbinding/ContextInfo.h>
#include <QtGui/qsurfaceformat.h>
#include <QtGui/qopenglcontext.h>

#include "renderingSystem/renderingAPI.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: GL (OPENGL)
*-----------------------------------------------------------------------------*/
namespace gl
{
    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
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
    *   EXPOSE EVENT
    *-----------------------------------------------------------------------------*/
    void OpenGLViewport::exposeEvent(QExposeEvent* p_exposeEvent)
    {
        Q_UNUSED(p_exposeEvent);
        if (this->isExposed())
            mp_renderer->requestRender(this);
    }

    /*-----------------------------------------------------------------------------
    *   MAKE CURRENT
    *-----------------------------------------------------------------------------*/
    void OpenGLViewport::makeCurrent()
    {
        mp_openGLContext->makeCurrent(this);
        glbinding::Binding::useCurrentContext();
    }

    /*-----------------------------------------------------------------------------
    *   DONE CURRENT
    *-----------------------------------------------------------------------------*/
    void OpenGLViewport::doneCurrent()
    {
        mp_openGLContext->doneCurrent();
    }

    /*-----------------------------------------------------------------------------
    *   SWAP BUFFERS
    *-----------------------------------------------------------------------------*/
    void OpenGLViewport::swapBuffers()
    {
        mp_openGLContext->swapBuffers(this);
    }

    /*-----------------------------------------------------------------------------
    *   PRINT OPENGL INFO
    *-----------------------------------------------------------------------------*/
    void OpenGLViewport::printOpenGLInfo()
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

    /*-----------------------------------------------------------------------------
    *   INITIALIZE OPENGL CONTEXT
    *-----------------------------------------------------------------------------*/
    void OpenGLViewport::initializeOpenGLContext()
    {
        //SURFACE FORMAT
        QSurfaceFormat qSurfaceFormat;
        qSurfaceFormat.setRedBufferSize(8);             //8-BIT RED
        qSurfaceFormat.setGreenBufferSize(8);           //8-BIT GREEN
        qSurfaceFormat.setBlueBufferSize(8);            //8-BIT BLUE
        qSurfaceFormat.setAlphaBufferSize(8);           //8-BIT ALPHA
        qSurfaceFormat.setDepthBufferSize(24);          //24-BIT DEPTH
        qSurfaceFormat.setSamples(8);                   //8-BIT MULTISAMPLING

        //SET WINDOW PROPERTIES
        this->setSurfaceType(QWindow::OpenGLSurface);
        this->setFormat(qSurfaceFormat);

        //OPENGL CONTEXT
        mp_openGLContext = new QOpenGLContext(this);
        mp_openGLContext->setFormat(qSurfaceFormat);
        mp_openGLContext->create();
    }
}; //NAMESPACE: GL

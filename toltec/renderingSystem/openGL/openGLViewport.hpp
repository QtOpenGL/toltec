#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       06 VIII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "abstractViewport.hpp"

#include "renderingSystem/abstractRenderer.hpp"

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class QOpenGLContext;

/*-----------------------------------------------------------------------------
*   NAMESPACE: GL (OPENGL)
*-----------------------------------------------------------------------------*/
namespace gl
{
    /*-----------------------------------------------------------------------------
    *   CLASS DECLARATIONS
    *   OPENGL VIEWPORT
    *-----------------------------------------------------------------------------*/
    class OpenGLViewport : public AbstractViewport
    {
        Q_OBJECT

    public:
        //CTOR DTOR
                        OpenGLViewport();
        virtual         ~OpenGLViewport() {}

        //EVENTS
        virtual void    exposeEvent(QExposeEvent* p_exposeEvent);

        //OTHERS
        void            makeCurrent();
        void            doneCurrent();
        void            swapBuffers();

    private:
        void            initializeOpenGLContext();

    private:
        QOpenGLContext*     mp_openGLContext;
    };
}; //NAMESPACE: GL

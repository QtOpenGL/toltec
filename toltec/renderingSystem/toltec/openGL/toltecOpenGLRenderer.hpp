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
#include <string>
#include <QtCore/qobject.h>
#include "renderingSystem/abstractRenderer.hpp"

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
namespace gl
{
    class OpenGLViewport;
}
class QEvent;
class AbstractViewport;

/*-----------------------------------------------------------------------------
*   NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   TOLTEC OPENGL RENDERER
*-----------------------------------------------------------------------------*/
class ToltecOpenGLRenderer : public AbstractRenderer
{
    Q_OBJECT

public:
    //CTOR DTOR
    explicit        ToltecOpenGLRenderer(AbstractRendererResource* p_abstractRendererResource);
    virtual         ~ToltecOpenGLRenderer() {}

    //EVENTS
    virtual bool    event(QEvent* p_event);

    //OTHER
    virtual void    requestRender(AbstractViewport* p_viewport);

private:
    void            prepareForRendering(const unsigned int& viewportIndex);
    void            render(gl::OpenGLViewport* p_viewport, const unsigned int& viewportIndex);
};
} //NAMESPACE: TGL

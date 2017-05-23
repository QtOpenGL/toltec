#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       30 VII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       AbstractRenderer class is a base class for all renderers inside program.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <memory>
#include <vector>

#include <QtCore/qobject.h>

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class AbstractViewport;
class AbstractRendererResource;

/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   ABSTRACT RENDERER
*-----------------------------------------------------------------------------*/
class AbstractRenderer : public QObject
{
    Q_OBJECT

public:
    //CONSTRUCTORS
    explicit        AbstractRenderer(AbstractRendererResource* p_abstractRendererResource);
    virtual         ~AbstractRenderer() {}

    //EVENTS
    virtual bool    event(QEvent* p_event) = 0;

    //GET
    AbstractRendererResource&   getRendererResource();

    //OTHER
    virtual void    requestRender(AbstractViewport* p_viewport) = 0;

protected:
    AbstractRendererResource*   mp_rendererResource;
};

/*----------------------------------------------------------------------------*/

inline AbstractRendererResource& AbstractRenderer::getRendererResource()
{
    return *mp_rendererResource;
}
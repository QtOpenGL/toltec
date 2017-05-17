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

#include "renderingSystem/abstractRendererResource.hpp"

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class AbstractViewport;

/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   ABSTRACT RENDERER
*-----------------------------------------------------------------------------*/
class AbstractRenderer : public QObject
{
    Q_OBJECT

public:
    //CONSTRUCTORS
                    AbstractRenderer();
    virtual         ~AbstractRenderer() {}

    //EVENTS
    virtual bool    event(QEvent* p_event) = 0;

    //GET
    AbstractRendererResource&   getRendererResource();

    //OTHER
    virtual void    requestRender(AbstractViewport* p_viewport) = 0;

protected:
    virtual void    prepareForRendering() = 0;
    virtual void    render(AbstractViewport* p_viewport) = 0;

protected:
    std::unique_ptr<AbstractRendererResource>   mp_rendererResource;
};

/*----------------------------------------------------------------------------*/

inline AbstractRendererResource& AbstractRenderer::getRendererResource()
{
    return *mp_rendererResource;
}
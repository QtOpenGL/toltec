#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       27 VII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       Render event is send whenever we want to add render request into Qt
*       event loop.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <QtGui/qevent.h>

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class AbstractViewport;

/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   RENDER EVENT
*-----------------------------------------------------------------------------*/
class RenderEvent : public QEvent
{
public:
    //CONSTRUCTORS
                RenderEvent(AbstractViewport* p_viewport = nullptr);
    virtual     ~RenderEvent() {}

    //GET
    AbstractViewport*   getViewport() const;

public:
    static const QEvent::Type TYPE;

private:
    AbstractViewport*   mp_viewport;
};

/*----------------------------------------------------------------------------*/

inline AbstractViewport* RenderEvent::getViewport() const
{
    return mp_viewport;
}
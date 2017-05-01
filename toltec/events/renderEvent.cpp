/*-----------------------------------------------------------------------------
*	CREATED:
*		30 VII 2016
*	CONTRIBUTORS:
*		PIOTR MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderEvent.hpp"

#include "../renderingSystem/abstractViewport.hpp"

/*-----------------------------------------------------------------------------
*	STATIC CLASS MEMBERS
*-----------------------------------------------------------------------------*/
//PUBLIC
const QEvent::Type RenderEvent::TYPE = static_cast<QEvent::Type>(QEvent::registerEventType());

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*	(Viewport*)
*-----------------------------------------------------------------------------*/
RenderEvent::RenderEvent(AbstractViewport* p_viewport)
    :
    QEvent(RenderEvent::TYPE),
    mp_viewport(p_viewport)
{
    //...
}

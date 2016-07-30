/*-----------------------------------------------------------------------------
*	CREATED:
*		30 VII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "toltecRenderer.hpp"

#include <QtCore/qobject.h>
#include <QtGui/qevent.h>

/*-----------------------------------------------------------------------------
*	EVENT
*-----------------------------------------------------------------------------*/
bool ToltecRenderer::event(QEvent* p_event)
{
	if (p_event->type() == RenderEvent::type)
	{
		RenderEvent* p_rednerEvent = static_cast<RenderEvent*>(p_event);
		Viewport* p_viewport = p_rednerEvent->getViewport();

		//RENDER INTO ONE VIEWPORT
		if (p_viewport != nullptr)
		{
			this->render(p_viewport);
		}
		//RENDER INTO MULTIPLE VIEWPORTS
		else
		{
			//...
		}

		return true;
	}
	else
	{
		return QObject::event(p_event);
	}
}

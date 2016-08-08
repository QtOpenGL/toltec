/*-----------------------------------------------------------------------------
*	CREATED:
*		07 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "toltecOpenGLRenderer.hpp"

#include <QtCore/qcoreapplication.h>
#include "events/renderEvent.hpp"
#include "renderingSystem/abstractViewport.hpp"

/*-----------------------------------------------------------------------------
*	EVENT
*-----------------------------------------------------------------------------*/
bool ToltecOpenGLRenderer::event(QEvent* p_event)
{
	if (p_event->type() == RenderEvent::TYPE)
	{
		RenderEvent* p_rednerEvent =		static_cast<RenderEvent*>(p_event);
		AbstractViewport* p_viewport =		p_rednerEvent->getViewport();

		this->render(p_viewport);
		return true;
	}
	else
	{
		return QObject::event(p_event);
	}
}

/*-----------------------------------------------------------------------------
*	REQUEST RENDER
*-----------------------------------------------------------------------------*/
void ToltecOpenGLRenderer::requestRender(AbstractViewport* p_viewport)
{
	QCoreApplication::postEvent(this, new RenderEvent(p_viewport));
}

/*-----------------------------------------------------------------------------
*	RENDER
*-----------------------------------------------------------------------------*/
void ToltecOpenGLRenderer::render(AbstractViewport* p_viewport)
{
	//...
}

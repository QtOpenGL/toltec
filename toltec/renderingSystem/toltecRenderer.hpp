#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		30 VII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		Toltec renderer is a default renderer inside the program.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <QtCore/qcoreapplication.h>

#include "abstractRenderer.hpp"
#include "events/renderEvent.hpp"

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class QEvent;
class Viewport;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	TOLTEC RENDERER
*-----------------------------------------------------------------------------*/
class ToltecRenderer : public AbstractRenderer
{
	Q_OBJECT

public:
	//CONSTRUCTORS
	virtual			~ToltecRenderer() {}

	//EVENTS
	virtual bool	event(QEvent* p_event);

	//OTHER
	virtual void	requestRender(Viewport* p_viewport = nullptr);
	virtual void	render(Viewport* p_viewport);

private:
	//...
};

/*----------------------------------------------------------------------------*/

inline void ToltecRenderer::requestRender(Viewport* p_viewport)
{
	QCoreApplication::postEvent(this, new RenderEvent(p_viewport));
}

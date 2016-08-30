#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		04 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <string>
#include <QtCore/qobject.h>
#include "renderingSystem/abstractRenderer.hpp"

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class QEvent;
class AbstractViewport;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	TOLTEC OPENGL RENDERER
*-----------------------------------------------------------------------------*/
class ToltecOpenGLRenderer : public AbstractRenderer
{
	Q_OBJECT

public:
	//CONSTRUCTORS
	virtual			~ToltecOpenGLRenderer() {}

	//EVENTS
	virtual bool	event(QEvent* p_event);

	//OTHER
	virtual void	requestRender(AbstractViewport* p_viewport);

private:
	virtual void	render(AbstractViewport* p_viewport);
};
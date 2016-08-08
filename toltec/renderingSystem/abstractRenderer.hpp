#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		30 VII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		AbstractRenderer class is a base class for all renderers inside program.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <vector>

#include <QtCore/qobject.h>

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class AbstractViewport;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	ABSTRACT RENDERER
*-----------------------------------------------------------------------------*/
class AbstractRenderer : public QObject
{
	Q_OBJECT

public:
	//CONSTRUCTORS
	virtual			~AbstractRenderer() {}

	//EVENTS
	virtual bool	event(QEvent* p_event) = 0;

	//OTHER
	virtual void	requestRender(AbstractViewport* p_viewport) = 0;

protected:
	virtual void	render(AbstractViewport* p_viewport) = 0;
};
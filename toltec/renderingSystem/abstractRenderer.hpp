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
#include <QtCore/qobject.h>

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class Viewport;

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
	virtual bool	event(QEvent* event) = 0;

	//OTHER
	virtual void	requestRender(Viewport* p_viewport = nullptr) = 0;

protected:
	virtual void	render(Viewport* p_viewport = nullptr) = 0;
};
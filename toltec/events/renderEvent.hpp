#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		27 VII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		Render event is send whenever we want to add render request into Qt
*		event loop.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <QtGui/qevent.h>

#include "renderingSystem/viewport.hpp"

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	RENDER EVENT
*-----------------------------------------------------------------------------*/
class RenderEvent : public QEvent
{
public:
	//CONSTRUCTORS
				RenderEvent(Viewport* p_viewport = nullptr);
	virtual		~RenderEvent() {}

	//GET
	Viewport*	getViewport() const;

public:
	static const QEvent::Type type;

private:
	Viewport*	mp_viewport;
};

/*----------------------------------------------------------------------------*/

inline Viewport* RenderEvent::getViewport() const
{
	return mp_viewport;
}
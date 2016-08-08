#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		02 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		AbstractViewport class is a base class for all viewports and holds
*		common interface for them.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <QtWidgets/qopenglwidget.h>

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class AbstractRenderer;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	VIEWPORT
*-----------------------------------------------------------------------------*/
class AbstractViewport : public QOpenGLWidget //THIS INHARITANCE SHOULD BE CHANGE IN THE FUTURE!
{
public:
	//CONSTRUCTORS
	virtual		~AbstractViewport() {}

	//SET
	void				setRenderer(AbstractRenderer* p_renderer);

	//GET
	AbstractRenderer*	getRenderer() const;

private:
	AbstractRenderer*	mp_renderer;
};

/*----------------------------------------------------------------------------*/

inline AbstractRenderer* AbstractViewport::getRenderer() const
{
	return mp_renderer;
}
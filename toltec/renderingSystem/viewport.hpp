#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		27 VII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		Viewport class inherits QOpenGLWidget and adds additional render logic
*		into it. It holds information about renderer and camera it's using.
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
class Viewport : public QOpenGLWidget
{
	Q_OBJECT

public:
	//CONSTRUCTORS
					Viewport();
	virtual			~Viewport() {}

	//SET
	void			setRenderer(AbstractRenderer* p_renderer);

	//GET
	AbstractRenderer*	getRenderer() const;

	//OTHER
	virtual	void	paintGL();
	virtual void	resizeGL();

private:
	AbstractRenderer*	mp_renderer;
	//<camera>
};

/*----------------------------------------------------------------------------*/

inline AbstractRenderer* Viewport::getRenderer() const
{
	return mp_renderer;
}

inline void Viewport::paintGL()
{
	//request render //-what type of a render?
}

inline void Viewport::resizeGL()
{
	//request render //-what type of a render?
}
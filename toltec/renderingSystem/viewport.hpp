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
#include <QtGui/qsurfaceformat.h>

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

	//OTHER
	void			renderCall();
	virtual	void	paintGL();
	virtual void	resizeGL();

private:
	//<render>
	//<camera>
};

/*----------------------------------------------------------------------------*/

inline void Viewport::paintGL()
{
	//request render //-what type of a render?
}

inline void Viewport::resizeGL()
{
	//request render //-what type of a render?
}
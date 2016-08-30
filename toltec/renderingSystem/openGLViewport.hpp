#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		06 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "abstractViewport.hpp"

#include "renderingSystem/abstractRenderer.hpp"

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class QOpenGLContext;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	OPENGL VIEWPORT
*-----------------------------------------------------------------------------*/
class OpenGLViewport : public AbstractViewport
{
public:
	//(CON/DE)STRUCTORS
					OpenGLViewport();
	virtual			~OpenGLViewport() {}

	//EVENTS
	virtual void	exposeEvent(QExposeEvent*);

	//OTHERS
	void			makeCurrent();
	void			doneCurrent();
	void			swapBuffers();

private:
	void			initializeOpenGLContext();

private:
	QOpenGLContext*		mp_openGLContext;
};
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
*	CLASS DECLARATIONS
*	OPENGL VIEWPORT
*-----------------------------------------------------------------------------*/
class OpenGLViewport : public AbstractViewport
{
public:
	//(CON/DE)STRUCTORS
					OpenGLViewport();
	virtual			~OpenGLViewport() {}

	//OTHER
	virtual	void	paintGL();
	virtual void	resizeGL();

private:
	//...
};

/*---------------------------------------------------------------------------*/

inline void OpenGLViewport::paintGL()
{
	mp_renderer->requestRender(this);
}

inline void OpenGLViewport::resizeGL()
{
	mp_renderer->requestRender(this);
}
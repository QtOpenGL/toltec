/*-----------------------------------------------------------------------------
*	CREATED:
*		07 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "toltecOpenGLRenderer.hpp"

#include <iostream>
#include <QtCore/qcoreapplication.h>

#include <glbinding/gl/gl.h>

#include "events/renderEvent.hpp"
#include "guiManager.hpp"
#include "renderingSystem/abstractViewport.hpp"
#include "renderingSystem/openGLViewport.hpp"
#include "renderingSystem/renderingAPI.hpp"

/*-----------------------------------------------------------------------------
*	EVENT
*-----------------------------------------------------------------------------*/
bool ToltecOpenGLRenderer::event(QEvent* p_event)
{
	if (p_event->type() == RenderEvent::TYPE)
	{
		RenderEvent* p_rednerEvent =		static_cast<RenderEvent*>(p_event);
		AbstractViewport* p_viewport =		p_rednerEvent->getViewport();

		this->render(p_viewport);
		return true;
	}
	else
	{
		return QObject::event(p_event);
	}
}

/*-----------------------------------------------------------------------------
*	REQUEST RENDER
*-----------------------------------------------------------------------------*/
void ToltecOpenGLRenderer::requestRender(AbstractViewport* p_viewport)
{
	//SEND EVENT
	RenderEvent renderEvent(p_viewport);
	QCoreApplication::sendEvent(this, &renderEvent);
}

/*-----------------------------------------------------------------------------
*	RENDER
*-----------------------------------------------------------------------------*/
void ToltecOpenGLRenderer::render(AbstractViewport* p_viewport)
{
	/*-----------------------------------------------------------------------------
	*	CHECK
	*-----------------------------------------------------------------------------*/
	if (p_viewport->getType() != RenderingAPI::OPENGL_API)
	{
		GUIManager::getInstance().displayError(
			"Rendering error! Viewport type is not matching renderer type.");
		return;
	}

	/*-----------------------------------------------------------------------------
	*	CAST
	*-----------------------------------------------------------------------------*/
	OpenGLViewport* p_openGLViewport = static_cast<OpenGLViewport*>(p_viewport);

	/*-----------------------------------------------------------------------------
	*	MAKE OPENGL CONTEXT CURRENT AGAINST GIVEN SURFACE
	*-----------------------------------------------------------------------------*/
	p_openGLViewport->makeCurrent();

	/*-----------------------------------------------------------------------------
	*	BUFFERS
	*-----------------------------------------------------------------------------*/
	//SET BACKGROUND COLOR
	gl::glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	//CLEAR BUFFERS
	gl::glClear(gl::GL_COLOR_BUFFER_BIT | gl::GL_DEPTH_BUFFER_BIT);

	/*-----------------------------------------------------------------------------
	*	SWAP BUFFERS
	*-----------------------------------------------------------------------------*/
	p_openGLViewport->swapBuffers();

	/*-----------------------------------------------------------------------------
	*	DONE CURRENT
	*	Convenience function for calling makeCurrent with a 0 surface.
	*-----------------------------------------------------------------------------*/
	p_openGLViewport->doneCurrent();
}

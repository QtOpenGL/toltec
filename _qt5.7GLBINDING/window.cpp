/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "window.hpp"

#include <QtGui/qopenglcontext.h>

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*	(const std::string&, int, int)
*-----------------------------------------------------------------------------*/
Window::Window(const std::string& name, int width, int height)
{
	//INITIALIZE
	this->setTitle(name.c_str());
	this->resize(width, height);

	//SURFACE FORMAT
	QSurfaceFormat qSurfaceFormat;
	qSurfaceFormat.setRedBufferSize(8);				//8-BIT RED
	qSurfaceFormat.setGreenBufferSize(8);			//8-BIT GREEN
	qSurfaceFormat.setBlueBufferSize(8);			//8-BIT BLUE
	qSurfaceFormat.setAlphaBufferSize(8);			//8-BIT ALPHA
	qSurfaceFormat.setDepthBufferSize(24);			//24-BIT DEPTH
	qSurfaceFormat.setSamples(8);					//8-BIT MULTISAMPLING

	//SET WINDOW PROPERTIES
	this->setSurfaceType(QWindow::OpenGLSurface);
	this->setFormat(qSurfaceFormat);

	//OPENGL CONTEXT
	mp_openGLContext = new QOpenGLContext(this);
	mp_openGLContext->setFormat(qSurfaceFormat);
	mp_openGLContext->create();

	//SHOW	
	this->show();
}

void Window::getWindowSize(int* p_width, int* p_height) 
{
	*p_width = this->width();
	*p_height = this->height();
}

/*-----------------------------------------------------------------------------
*	MAKE CURRENT
*-----------------------------------------------------------------------------*/
void Window::makeCurrent()
{
	mp_openGLContext->makeCurrent(this);
}

/*-----------------------------------------------------------------------------
*	DONE CURRENT
*-----------------------------------------------------------------------------*/
void Window::doneCurrent()
{
	mp_openGLContext->doneCurrent();
}

/*-----------------------------------------------------------------------------
*	SWAP BUFFERS
*-----------------------------------------------------------------------------*/
void Window::swapBuffers()
{
	mp_openGLContext->swapBuffers(this);
}
/*-----------------------------------------------------------------------------
*	CREATED:
*		27 VII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "viewport.hpp"

#include <QtGui/qsurfaceformat.h>
#include "abstractRenderer.hpp"

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*-----------------------------------------------------------------------------*/
Viewport::Viewport()
{
	//INITIALIZE
	mp_renderer = nullptr;	//CHANGE! USE RENDER MANAGER TO ASSING DEFAULT RENDERER ON CREATION.

	//SETUP
	//format
	QSurfaceFormat qSurfaceFormat;
	qSurfaceFormat.setRedBufferSize(8);				//8-BIT RED
	qSurfaceFormat.setGreenBufferSize(8);			//8-BIT GREEN
	qSurfaceFormat.setBlueBufferSize(8);			//8-BIT BLUE
	qSurfaceFormat.setAlphaBufferSize(8);			//8-BIT ALPHA
	qSurfaceFormat.setDepthBufferSize(24);			//24-BIT DEPTH
	qSurfaceFormat.setSamples(8);					//8-BIT MULTISAMPLING

	this->setFormat(qSurfaceFormat);
}

/*-----------------------------------------------------------------------------
*	SET RENDERER
*-----------------------------------------------------------------------------*/
void Viewport::setRenderer(AbstractRenderer* p_renderer)
{
	//REMOVE VIEWPORT FROM PREVIOUS RENDERER
	if (mp_renderer != nullptr)
		mp_renderer->removeViewport(this);

	//SET
	mp_renderer = p_renderer;

	//ADD VIEWPORT TO CURRENT RENDERER
	mp_renderer->addViewport(this);
}
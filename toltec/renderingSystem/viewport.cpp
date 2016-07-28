/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "viewport.hpp"

/*-----------------------------------------------------------------------------
*	PUBLIC METHODS
*	CONSTRUCTOR
*-----------------------------------------------------------------------------*/
Viewport::Viewport()
{
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
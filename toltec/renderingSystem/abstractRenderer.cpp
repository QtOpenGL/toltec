/*-----------------------------------------------------------------------------
*	CREATED:
*		30 VII 2016
*	CONTRIBUTORS:
*		PIOTR MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "abstractRenderer.hpp"

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*-----------------------------------------------------------------------------*/
AbstractRenderer::AbstractRenderer()
	:
	mp_rendererResource(nullptr)
{
}

/*-----------------------------------------------------------------------------
*	DESTRUCTOR
*-----------------------------------------------------------------------------*/
AbstractRenderer::~AbstractRenderer()
{
	delete mp_rendererResource;
}

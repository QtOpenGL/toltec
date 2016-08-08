/*-----------------------------------------------------------------------------
*	CREATED:
*		05 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderingAPI.hpp"

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*	(RenderingAPI::Type, AbstractRenderer*, AbstractRendererResource*)
*-----------------------------------------------------------------------------*/
RenderingAPI::RenderingAPI(RenderingAPI::Type type, AbstractRenderer* p_renderer,
	AbstractRendererResource* p_rendererReource)
{
	//INITIALIZE
	m_type =				type;
	mp_renderer =			p_renderer;
	mp_rendererResource =	p_rendererReource;
}

/*-----------------------------------------------------------------------------
*	DESTRUCTOR
*-----------------------------------------------------------------------------*/
RenderingAPI::~RenderingAPI()
{
	//CLEAN-UP
	delete mp_renderer;
	delete mp_rendererResource;
}

/*-----------------------------------------------------------------------------
*	SET RENDERER
*-----------------------------------------------------------------------------*/
void RenderingAPI::setRenderer(AbstractRenderer* p_renderer)
{
	delete mp_renderer;
	mp_renderer = p_renderer;
}

/*-----------------------------------------------------------------------------
*	SET RENDERER RESOURCE
*-----------------------------------------------------------------------------*/
void RenderingAPI::setRendererResource(AbstractRendererResource* p_rendererReource)
{
	delete mp_rendererResource;
	mp_rendererResource = p_rendererReource;
}
/*-----------------------------------------------------------------------------
*	CREATED:
*		05 VIII 2016
*	CONTRIBUTORS:
*		PIOTR MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderingAPI.hpp"

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*	(RenderingAPI::Type, AbstractRenderer*)
*-----------------------------------------------------------------------------*/
RenderingAPI::RenderingAPI(RenderingAPI::Type type, AbstractRenderer* p_renderer)
	:
	m_type(type),
	mp_renderer(p_renderer)
{
}

/*-----------------------------------------------------------------------------
*	DESTRUCTOR
*-----------------------------------------------------------------------------*/
RenderingAPI::~RenderingAPI()
{
	delete mp_renderer;
}

/*-----------------------------------------------------------------------------
*	SET RENDERER
*-----------------------------------------------------------------------------*/
void RenderingAPI::setRenderer(AbstractRenderer* p_renderer)
{
	delete mp_renderer;
	mp_renderer = p_renderer;
}
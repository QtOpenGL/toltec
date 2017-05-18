/*-----------------------------------------------------------------------------
*   CREATED:
*       05 VIII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderingAPI.hpp"

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*   (RenderingAPI::Type, std::unique_ptr<AbstractRendererResource>,
*   std::unique_ptr<AbstractRenderer>)
*-----------------------------------------------------------------------------*/
RenderingAPI::RenderingAPI(
    RenderingAPI::Type                          type, 
    std::unique_ptr<AbstractRendererResource>   p_abstractRendererResource,
    std::unique_ptr<AbstractRenderer>           p_renderer)
    :
    m_type(type),
    mp_rendererResource(std::move(p_abstractRendererResource)),
    mp_activeRenderer(p_renderer.get())
{
    //SETUP
    mp_rendererList.push_back(std::move(p_renderer));
}

/*-----------------------------------------------------------------------------
*   ADD RENDERER
*-----------------------------------------------------------------------------*/
void RenderingAPI::addRenderer(std::unique_ptr<AbstractRenderer> p_renderer)
{
    mp_rendererList.push_back(std::move(p_renderer));
}
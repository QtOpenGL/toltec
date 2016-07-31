/*-----------------------------------------------------------------------------
*	CREATED:
*		30 VII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderManager.hpp"

#include "abstractRenderer.hpp"
#include "viewport.hpp"
#include "utils.hpp"

/*-----------------------------------------------------------------------------
*	STATIC CLASS MEMBERS
*-----------------------------------------------------------------------------*/
//PUBLIC
const RenderManager::RendererID RenderManager::DEFAULT_RENDERER = RenderManager::TOLTEC_RENDERER;

/*-----------------------------------------------------------------------------
*	ADD RENDERER
*-----------------------------------------------------------------------------*/
void RenderManager::addRenderer(AbstractRenderer* p_renderer, RendererID rendererID)
{
	m_rendererDict[rendererID] = p_renderer;
}

/*-----------------------------------------------------------------------------
*	GET RENDERER
*-----------------------------------------------------------------------------*/
AbstractRenderer* RenderManager::getRenderer(RendererID rendererID) const
{
	return m_rendererDict.at(rendererID);
}

/*-----------------------------------------------------------------------------
*	RENDER CALL
*	(Viewport*)
*-----------------------------------------------------------------------------*/
void RenderManager::renderCall(Viewport* p_viewport)
{
	p_viewport->getRenderer()->requestRender(p_viewport);
}

/*-----------------------------------------------------------------------------
*	RENDER CALL
*	(AbstractRenderer*)
*-----------------------------------------------------------------------------*/
void RenderManager::renderCall(AbstractRenderer* p_renderer)
{
	p_renderer->requestRender();
}

/*-----------------------------------------------------------------------------
*	RENDER CALL
*	(RendererID)
*-----------------------------------------------------------------------------*/
void RenderManager::renderCall(RendererID rendererID)
{
	m_rendererDict[rendererID]->requestRender();
}

/*-----------------------------------------------------------------------------
*	RENDER CALL
*-----------------------------------------------------------------------------*/
void RenderManager::renderCall()
{
	for (const auto& rendererDictElement : m_rendererDict)
		rendererDictElement.second->requestRender();
}
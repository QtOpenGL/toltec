/*-----------------------------------------------------------------------------
*	CREATED:
*		06 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderManager.hpp"

#include <algorithm>

#include "ui/gui/viewportPanel.hpp"
#include "renderingSystem/abstractRenderer.hpp"
#include "renderingSystem/abstractViewport.hpp"
#include "renderingSystem/renderingSystem.hpp"

/*-----------------------------------------------------------------------------
*	ADD RENDERING SYSTEM
*-----------------------------------------------------------------------------*/
void RenderManager::addRenderingSystem(RenderingSystem* p_renderingSystem)
{
	//Perform a check if object already exists in a vector to prevent duplicates.
	auto endIter =		std::end(m_renderingSystemList);
	auto findIter =		std::find(std::begin(m_renderingSystemList), endIter, p_renderingSystem);

	if (findIter != endIter)
		return;
	else
		m_renderingSystemList.push_back(p_renderingSystem);
}

/*-----------------------------------------------------------------------------
*	RENDER CALL
*	(AbstractViewport*)
*-----------------------------------------------------------------------------*/
void RenderManager::renderCall(AbstractViewport* p_viewport)
{
	p_viewport->getRenderer()->requestRender(p_viewport);
}

/*-----------------------------------------------------------------------------
*	RENDER CALL
*	(RenderingSystem*)
*-----------------------------------------------------------------------------*/
void RenderManager::renderCall(RenderingSystem* p_renderingSystem)
{
	AbstractViewport* p_viewport = nullptr;

	auto p_viewportPanelList = p_renderingSystem->getViewportPanelList();
	for (auto p_viewportPanel : *p_viewportPanelList)
	{
		p_viewport = p_viewportPanel->getViewport();
		p_viewport->getRenderer()->requestRender(p_viewport);
	}
}

/*-----------------------------------------------------------------------------
*	RENDER CALL
*	(RenderingSystem*)
*-----------------------------------------------------------------------------*/
void RenderManager::renderCall(const std::string& renderingSystemName)
{
	AbstractViewport* p_viewport =			nullptr;
	RenderingSystem* p_renderingSystem =	nullptr;

	//RETIVE RENDERING SYSTEM
	for (auto p_renderingSystemListItem : m_renderingSystemList)
	{
		if (p_renderingSystemListItem->getName() == renderingSystemName)
		{
			p_renderingSystem = p_renderingSystemListItem;
			break;
		}
	}

	//RENDER CALL
	auto p_viewportPanelList = p_renderingSystem->getViewportPanelList();
	for (auto p_viewportPanel : *p_viewportPanelList)
	{
		p_viewport = p_viewportPanel->getViewport();
		p_viewport->getRenderer()->requestRender(p_viewport);
	}
}

/*-----------------------------------------------------------------------------
*	RENDER CALL
*	()
*-----------------------------------------------------------------------------*/
void RenderManager::renderCall()
{
	//...
}

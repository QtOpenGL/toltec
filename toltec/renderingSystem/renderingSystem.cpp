/*-----------------------------------------------------------------------------
*	CREATED:
*		04 VIII 2016
*	CONTRIBUTORS:
*		PIOTR MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderingSystem.hpp"

#include <cstdlib>

#include "renderingSystem/abstractRenderer.hpp"
#include "renderingSystem/abstractRendererResource.hpp"
#include "utils.hpp"

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*	(const std::string&)
*-----------------------------------------------------------------------------*/
RenderingSystem::RenderingSystem(const std::string& name)
	:
	m_name(name),
	mp_activeRenderingAPI(nullptr)
{
}

/*-----------------------------------------------------------------------------
*	ADD RENDERING API
*-----------------------------------------------------------------------------*/
void RenderingSystem::addRenderingAPI(RenderingAPI* p_renderingAPI)
{
	RenderingAPI::Type renderingAPIType = p_renderingAPI->getType();

	//If this is the first rendering API, make it to be the active one.
	if (m_renderingAPIMap.size() == 0)
		mp_activeRenderingAPI = p_renderingAPI;

	//Prevent overwrite.
	auto iterator = m_renderingAPIMap.find(renderingAPIType);
	if (iterator == m_renderingAPIMap.end())
		m_renderingAPIMap[renderingAPIType] = p_renderingAPI;
}

/*-----------------------------------------------------------------------------
*	ADD VIEWPORT PANEL
*-----------------------------------------------------------------------------*/
void RenderingSystem::addViewportPanel(ViewportPanel* p_viewportPanel)
{
	m_viewportPanelList.push_back(p_viewportPanel);
}

/*-----------------------------------------------------------------------------
*	REMOVE VIEWPORT PANEL
*-----------------------------------------------------------------------------*/
void RenderingSystem::removeViewportPanel(ViewportPanel* p_viewportPanel)
{
	std::size_t numViewportPanels = m_viewportPanelList.size();
	for (std::size_t i = 0; i < numViewportPanels; i++)
	{
		if (m_viewportPanelList[i] == p_viewportPanel)
			m_viewportPanelList.erase(m_viewportPanelList.begin() + i);
	}
}

/*-----------------------------------------------------------------------------
*	SWITCH TO RENDERING API
*-----------------------------------------------------------------------------*/
void RenderingSystem::switchToRenderingAPI(RenderingAPI::Type renderingAPIType)
{
	//CHECK
	//if exists
	auto iterator = m_renderingAPIMap.find(renderingAPIType);
	if (iterator == m_renderingAPIMap.end())
	{
		DEBUG_MSG("ERROR : Specified API type could not be found!");
		return;
	}

	//if already assigned
	if (mp_activeRenderingAPI->getType() == renderingAPIType)
		return;

	//CLEAR OLD RESOURCES
	mp_activeRenderingAPI->getRenderer()->getRendererResource()->deleteResources();

	//SET NEW
	mp_activeRenderingAPI = iterator->second;
	mp_activeRenderingAPI->getRenderer()->getRendererResource()->initializeResources();
}

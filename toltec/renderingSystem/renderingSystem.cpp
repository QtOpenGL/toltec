/*-----------------------------------------------------------------------------
*	CREATED:
*		04 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderingSystem.hpp"

#include <cstdlib>
#include "utils.hpp"

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*	(const std::string&)
*-----------------------------------------------------------------------------*/
RenderingSystem::RenderingSystem(const std::string& name)
{
	//INITIALIZE
	m_name =					name;
	mp_activeRenderingAPI =		nullptr;
}

/*-----------------------------------------------------------------------------
*	DESTRUCTOR
*-----------------------------------------------------------------------------*/
RenderingSystem::~RenderingSystem()
{
	//CLEAN-UP
	for (auto& kv : m_renderingAPIList)
		delete kv.second;
}

/*-----------------------------------------------------------------------------
*	ADD RENDERING API
*-----------------------------------------------------------------------------*/
void RenderingSystem::addRenderingAPI(RenderingAPI* p_renderingAPI)
{
	RenderingAPI::Type renderingAPIType = p_renderingAPI->getType();

	//If this is the first rendering API, make it to be the active one.
	if (m_renderingAPIList.size() == 0)
		mp_activeRenderingAPI = p_renderingAPI;

	//Prevent overwrite.
	auto iterator = m_renderingAPIList.find(renderingAPIType);
	if (iterator == m_renderingAPIList.end())
		m_renderingAPIList[renderingAPIType] = p_renderingAPI;
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
*	SET ACTIVE RENDERING API
*-----------------------------------------------------------------------------*/
void RenderingSystem::setActiveRenderingAPI(RenderingAPI::Type type)
{
	auto iterator = m_renderingAPIList.find(type);
	if (iterator != m_renderingAPIList.end())
		mp_activeRenderingAPI = iterator->second;
	else
		DEBUG_MSG("ERROR : Specified API type could not be found!");
}

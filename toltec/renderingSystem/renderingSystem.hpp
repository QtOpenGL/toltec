#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		02 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		...
*	RAW POINTER MANAGER FOR:
*		- m_renderingAPIList (RenderingAPI*)
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <map>
#include <string>
#include <vector>

#include "renderingAPI.hpp"

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class ViewportPanel;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	RENDERING SYSTEM
*-----------------------------------------------------------------------------*/
class RenderingSystem
{
public:
	//CONSTRUCTORS
	explicit		RenderingSystem(const std::string& name);
	virtual			~RenderingSystem();

	//ADD
	void			addRenderingAPI(RenderingAPI* p_renderingAPI);
	void			addViewportPanel(ViewportPanel* p_viewportPanel);

	//REMOVE
	void			removeViewportPanel(ViewportPanel* p_viewportPanel);

	//SET
	void			setActiveRenderingAPI(RenderingAPI::Type type);

	//GET
	const std::string&					getName() const;
	const std::vector<ViewportPanel*>*	getViewportPanelList() const;
	RenderingAPI*						getActiveRenderingAPI() const;

protected:
	std::string						m_name;
	std::vector<ViewportPanel*>		m_viewportPanelList;

	std::map<RenderingAPI::Type, RenderingAPI*>		m_renderingAPIList;
	RenderingAPI*									mp_activeRenderingAPI;
};

/*----------------------------------------------------------------------------*/

inline const std::string& RenderingSystem::getName() const
{
	return m_name;
}

inline const std::vector<ViewportPanel*>* RenderingSystem::getViewportPanelList() const
{
	return &m_viewportPanelList;
}

inline RenderingAPI* RenderingSystem::getActiveRenderingAPI() const
{
	return mp_activeRenderingAPI;
}
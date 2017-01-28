#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		06 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		Render Manager is responsible for managing renderering systems and 
*		redner calls.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <cstdint>
#include <string>
#include <vector>

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class RenderingSystem;
class AbstractViewport;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	RENDER MANAGER
*-----------------------------------------------------------------------------*/
class RenderManager
{
public:
	//SINGLETON
	static RenderManager& getInstance()
	{
		static RenderManager instance;
		return instance;
	}
	RenderManager(const RenderManager&) = delete;
	void operator=(const RenderManager&) = delete;

	//ADD
	void		addRenderingSystem(RenderingSystem* p_renderingSystem);

	//GET
	RenderingSystem*	getDefaultRenderingSystem() const;

	//OTHER
	void		renderCall(AbstractViewport* p_viewport);				//VIEWPORT CALL
	void		renderCall(RenderingSystem* p_renderingSystem);			//RENDERING SYSTEM CALL
	void		renderCall(const std::string& renderingSystemName);		//RENDERING SYSTEM CALL
	void		renderCall();											//GLOBAL CALL

private:
	//SINGLETON
	RenderManager();

	//OTHER
	void		finishRenderCall();

private:
	std::vector<RenderingSystem*>	m_renderingSystemList;
	std::uint64_t					m_renderCycleNumber;
};

/*----------------------------------------------------------------------------*/

inline RenderingSystem* RenderManager::getDefaultRenderingSystem() const
{
	return m_renderingSystemList[0];
}
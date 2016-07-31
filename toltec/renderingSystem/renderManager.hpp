#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		30 VII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		Render Manager is responsible for managing renderers and redner calls.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <map>

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class AbstractRenderer;
class Viewport;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	RENDER MANAGER
*-----------------------------------------------------------------------------*/
class RenderManager 
{
public:
	//TYPES
	enum RendererID {
		TOLTEC_RENDERER
	};

	//SINGLETON
	static RenderManager& getInstance()
	{
		static RenderManager instance;
		return instance;
	}
	RenderManager(const RenderManager&) = delete;
	void operator=(const RenderManager&) = delete;

	//ADD
	void		addRenderer(AbstractRenderer* p_renderer, RendererID rendererID);

	//GET
	AbstractRenderer* getRenderer(RendererID rendererID) const;

	//OTHERS
	void		renderCall(Viewport* p_viewport);				//VIEWPORT CALL
	void		renderCall(AbstractRenderer* p_renderer);		//RENDERER CALL
	void		renderCall(RendererID rendererID);				//RENDERER CALL
	void		renderCall();									//GLOBAL CALL

public:
	static const RendererID DEFAULT_RENDERER;

private:
	//SINGLETON
	RenderManager() {}

	//RENDERER DICTIONARY
	std::map<RendererID, AbstractRenderer*> m_rendererDict;
};
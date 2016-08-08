#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		02 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		RenderingAPI class acts like a container for 2 basic components that 
*		are connected together: renderer (rendering pipeline) and renderer 
*		resource. This class always represent specific rendering API:
*		OpenGL, Vulkan, Direct3D, etc.
*	RAW POINTER MANAGER FOR:
*		- mp_renderer				(AbstractRenderer*)
*		- mp_rendererResource		(AbstractRendererResource*)
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <vector>

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class AbstractRenderer;
class AbstractRendererResource;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	ABSTRACT RENDERING SYSTEM
*-----------------------------------------------------------------------------*/
class RenderingAPI
{
public:
	//TYPES
	enum Type {
		OPENGL_API,
		VULKAN_API,
		DIRECT3D_API,
		METAL_API
	};

	//CONSTRUCTORS
				RenderingAPI(
					RenderingAPI::Type type,
					AbstractRenderer* p_renderer, 
					AbstractRendererResource* p_rendererReource);
	virtual		~RenderingAPI();

	//SET
	void		setRenderer(AbstractRenderer* p_renderer);
	void		setRendererResource(AbstractRendererResource* p_rendererReource);

	//GET
	RenderingAPI::Type				getType() const;
	AbstractRenderer*				getRenderer() const;
	AbstractRendererResource*		getRendererResource() const;

private:
	RenderingAPI::Type				m_type;
	AbstractRenderer*				mp_renderer;
	AbstractRendererResource*		mp_rendererResource;
};

/*----------------------------------------------------------------------------*/

inline RenderingAPI::Type RenderingAPI::getType() const
{
	return m_type;
}

inline AbstractRenderer* RenderingAPI::getRenderer() const
{
	return mp_renderer;
}

inline AbstractRendererResource* RenderingAPI::getRendererResource() const
{
	return mp_rendererResource;
}
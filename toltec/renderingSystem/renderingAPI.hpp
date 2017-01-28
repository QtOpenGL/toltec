#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		02 VIII 2016
*	CONTRIBUTORS:
*		PIOTR MAKAL
*	INFO:
*		RenderingAPI class defines specific rendering API: OpenGL, Vulkan, 
*		Direct3D, etc.
*
*	RAW POINTER MANAGER:
*		- mp_renderer	(AbstractRenderer*)
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <vector>

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class AbstractRenderer;

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
		METAL_API,
		UNSPECIFIED_API
	};

	//CONSTRUCTORS
				RenderingAPI(RenderingAPI::Type type, AbstractRenderer* p_renderer);
	virtual		~RenderingAPI();

	//SET
	void		setRenderer(AbstractRenderer* p_renderer);

	//GET
	RenderingAPI::Type				getType() const;
	AbstractRenderer*				getRenderer();

private:
	RenderingAPI::Type				m_type;
	AbstractRenderer*				mp_renderer;
};

/*----------------------------------------------------------------------------*/

inline RenderingAPI::Type RenderingAPI::getType() const
{
	return m_type;
}

inline AbstractRenderer* RenderingAPI::getRenderer()
{
	return mp_renderer;
}
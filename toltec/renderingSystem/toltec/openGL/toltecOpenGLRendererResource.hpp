#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		04 VIII 2016
*	CONTRIBUTORS:
*		PIOTR MAKAL
*	INFO:
*		...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <vector>

#include "renderingSystem/abstractRendererResource.hpp"

/*-----------------------------------------------------------------------------
*	NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
	/*-----------------------------------------------------------------------------
	*	CLASS DECLARATIONS
	*	TOLTEC OPENGL RENDERER RESOURCE
	*-----------------------------------------------------------------------------*/
	class ToltecOpenGLRendererResource : public AbstractRendererResource
	{
	public:
		//CONSTRUCTORS
		virtual			~ToltecOpenGLRendererResource() {}

		//OTHER
		virtual void	initializeResources() {};
		virtual void	updateResources() {};
		virtual void	deleteResources() {};

	private:
		//std::vector<RenderableObject*>		m_renderableObjectList;
		//std::vector<ShaderInstance*>		m_shaderInstanceList;
	};
} //NAMESPACE: TGL
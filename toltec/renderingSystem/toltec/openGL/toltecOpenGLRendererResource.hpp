#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		04 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <string>
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

	private:
		//...
	};
} //NAMESPACE: TGL
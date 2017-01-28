#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		16 I 2017
*	CONTRIBUTORS:
*		PIOTR MAKAL
*	INFO:
*		tgl::Geometry class holds all vertex and index buffers needed to render
*		all visual aspects of an object (faces, wireframe, vertices, etc.).
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
	*	GEOMETRY
	*-----------------------------------------------------------------------------*/
	class Geometry
	{
	public:
		//CONSTRUCTORS
		virtual			~Geometry() {}

	private:
		//...
	};
} //NAMESPACE: TGL
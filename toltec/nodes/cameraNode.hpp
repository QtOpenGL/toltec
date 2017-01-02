#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		18 IX 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		Camera node is responsible for storing information about camera (local
*		z, y and z axes, field of view, z near and far clipping, target, etc.).
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderableObjectNode.hpp"

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	CAMERA NODE
*-----------------------------------------------------------------------------*/
class CameraNode : public RenderableObjectNode
{
public:
	//CONSTRUCTORS
	virtual			~CameraNode() {}

private:
	//...
};
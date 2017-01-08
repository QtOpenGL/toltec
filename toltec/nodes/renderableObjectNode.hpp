#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		12 IX 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		RenderableObjectNode is a base class for all nodes that can be 
*		rendered inside the viewport.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "sceneNode.hpp"

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	RENDERABLE OBJECT NODE
*-----------------------------------------------------------------------------*/
class RenderableObjectNode : public SceneNode
{
public:
	//CONSTRUCTORS
					RenderableObjectNode();
	virtual			~RenderableObjectNode() {}

private:
	//...
};
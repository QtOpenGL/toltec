#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		30 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		TransformNode class holds main model matrix that any vertex of a
*		partcular object can be multiply with to place it in world coordinates. 
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "scene3DNode.hpp"

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	SCENE 3D NODE
*-----------------------------------------------------------------------------*/
class TransformNode : public Scene3DNode
{
public:
	//CONSTRUCTORS
	virtual ~TransformNode() {}

private:
	//...
};
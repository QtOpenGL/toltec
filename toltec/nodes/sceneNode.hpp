#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		30 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		SceneNode class represnet base class for all nodes that will be 
*		placed and rendered in the viewport.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "node.hpp"

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	SCENE NODE
*-----------------------------------------------------------------------------*/
class SceneNode : public Node
{
public:
	//CONSTRUCTORS
					SceneNode();
	virtual			~SceneNode() {}

	//SET
	virtual void	setParent(SceneNode* p_parent);

	//GET
	SceneNode*		getParent();

protected:
	SceneNode*		mp_parent;
};

/*----------------------------------------------------------------------------*/

inline SceneNode* SceneNode::getParent()
{
	return mp_parent;
}
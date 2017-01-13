#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		13 I 2017
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		SurfaceNode is a base class for all surface type nodes (polygon meshes,
*		NURBS-es, t-splines, etc.).
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderableObjectNode.hpp"

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATION
*-----------------------------------------------------------------------------*/
class SurfaceShaderProgramNode;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	SURFACE NODE
*-----------------------------------------------------------------------------*/
class SurfaceNode : public RenderableObjectNode
{
public:
	//CONSTRUCTORS
				SurfaceNode();
	virtual		~SurfaceNode() {}

	//SET
	void		setSurfaceShaderProgram(SurfaceShaderProgramNode* p_surfaceShaderProgram);

	//GET
	SurfaceShaderProgramNode*	getSurfaceShaderProgram();

private:
	SurfaceShaderProgramNode*	mp_surfaceShaderProgram;
};

/*----------------------------------------------------------------------------*/

inline SurfaceShaderProgramNode* SurfaceNode::getSurfaceShaderProgram()
{
	return mp_surfaceShaderProgram;
}
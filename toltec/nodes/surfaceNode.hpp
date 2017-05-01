#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		13 I 2017
*	CONTRIBUTORS:
*		PIOTR MAKAL
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
    void		setSurfaceShaderProgramNode(SurfaceShaderProgramNode* p_surfaceShaderProgramNode);

    //GET
    SurfaceShaderProgramNode*	getSurfaceShaderProgramNode();

private:
    SurfaceShaderProgramNode*	mp_surfaceShaderProgramNode;
};

/*----------------------------------------------------------------------------*/

inline SurfaceShaderProgramNode* SurfaceNode::getSurfaceShaderProgramNode()
{
    return mp_surfaceShaderProgramNode;
}
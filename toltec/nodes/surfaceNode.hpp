#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       13 I 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       SurfaceNode is a base class for all surface type nodes (polygon meshes,
*       NURBS-es, t-splines, etc.).
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderableObjectNode.hpp"

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATION
*-----------------------------------------------------------------------------*/
namespace core
{
    namespace nodes
    {
        class SurfaceShaderProgramNode;
    }
}

/*-----------------------------------------------------------------------------
*   NAMESPACE: CORE
*-----------------------------------------------------------------------------*/
namespace core
{
/*-----------------------------------------------------------------------------
*   NAMESPACE: NODES
*-----------------------------------------------------------------------------*/
namespace nodes
{
/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   SURFACE NODE
*-----------------------------------------------------------------------------*/
class SurfaceNode : public RenderableObjectNode
{
public:
    //CONSTRUCTORS
                SurfaceNode();
    virtual     ~SurfaceNode() {}

    //SET
    void        setSurfaceShaderProgramNode(SurfaceShaderProgramNode* p_surfaceShaderProgramNode);

    //GET
    SurfaceShaderProgramNode*   getSurfaceShaderProgramNode();

private:
    SurfaceShaderProgramNode*   mp_surfaceShaderProgramNode;
};

/*----------------------------------------------------------------------------*/

inline SurfaceShaderProgramNode* SurfaceNode::getSurfaceShaderProgramNode()
{
    return mp_surfaceShaderProgramNode;
}
} //NAMESPACE: NODES
} //NAMESPACE: CORE
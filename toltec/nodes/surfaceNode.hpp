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
        class ShaderProgramNode;
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
    void        setShaderProgramNode(ShaderProgramNode* p_shaderProgramNode);

    //GET
    ShaderProgramNode*  getShaderProgramNode();

private:
    ShaderProgramNode*  mp_shaderProgramNode;
};

/*----------------------------------------------------------------------------*/

inline ShaderProgramNode* SurfaceNode::getShaderProgramNode()
{
    return mp_shaderProgramNode;
}
} //NAMESPACE: NODES
} //NAMESPACE: CORE

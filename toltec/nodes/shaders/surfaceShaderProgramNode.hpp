#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       11 I 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       SurfaceShaderProgramNode is a base class for all shaders programs that
*       apply to surfaces (ie. meshes, NURBS-es, t-splines, etc.).
*       This class holds reference to all surfaces that are using this class
*       instance as shader program.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <vector>

#include "shaderProgramNode.hpp"

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
namespace core
{
    namespace nodes
    {
        class SurfaceNode;
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
*   SURFACE SHADER PROGRAM NODE
*-----------------------------------------------------------------------------*/
class SurfaceShaderProgramNode : public ShaderProgramNode
{
public:
    //CTOR DTOR
                SurfaceShaderProgramNode();
    virtual     ~SurfaceShaderProgramNode() {}

    //ADD
    void        addSurface(SurfaceNode* p_surfaceNode, const bool hardAdd = false);

    //REMOVE
    void        removeSurface(SurfaceNode* p_surfaceNode, const bool hardRemove = false);

private:
    std::vector<SurfaceNode*>   m_surfaceNodeList;
};
} //NAMESPACE: NODES
} //NAMESPACE: CORE

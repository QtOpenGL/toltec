#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       09 I 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       Base class for all shader programs.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "nodes/node.hpp"

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
*   SHADER PROGRAM NODE
*-----------------------------------------------------------------------------*/
class ShaderProgramNode : public Node
{
public:
    //TYPES
    enum DrawMode {
        POINTS,
        LINES,
        TRIANGLES
    };

    //CONSTRUCTORS
                ShaderProgramNode();
    virtual     ~ShaderProgramNode() {}

    //SET
    void        setDrawMode(const ShaderProgramNode::DrawMode& drawMode);

    //GET
    const ShaderProgramNode::DrawMode&  getDrawMode() const;

private:
    ShaderProgramNode::DrawMode     m_drawMode;
};

/*----------------------------------------------------------------------------*/

inline const ShaderProgramNode::DrawMode& ShaderProgramNode::getDrawMode() const
{
    return m_drawMode;
}

} //NAMESPACE: NODES
} //NAMESPACE: CORE

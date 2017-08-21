#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       13 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "nodes/shaders/componentShaderProgramNode.hpp"

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
*   POINT COMPONENT SHADER PROGRAM NODE
*-----------------------------------------------------------------------------*/
class PointCSPNode : public ComponentShaderProgramNode
{
public:
    //CTOR DTOR
                PointCSPNode();
    virtual     ~PointCSPNode() {}

    //SET
    void        setSize(unsigned int size);

    //GET
    unsigned int    getSize() const;

private:
    unsigned int    m_size;
};

/*----------------------------------------------------------------------------*/

inline unsigned int PointCSPNode::getSize() const
{
    return m_size;
}
} //NAMESPACE: NODES
} //NAMESPACE: CORE

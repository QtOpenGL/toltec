#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		13 II 2017
*	CONTRIBUTORS:
*		Piotr Makal
*	INFO:
*		...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "nodes/shaders/componentShaderProgramNode.hpp"

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	POINT COMPONENT SHADER PROGRAM NODE
*-----------------------------------------------------------------------------*/
class PointCSPNode : public ComponentShaderProgramNode
{
public:
    //CONSTRUCTORS
                PointCSPNode();
    virtual		~PointCSPNode() {}

    //SET
    void		setSize(unsigned int size);

    //GET
    unsigned int	getSize() const;

private:
    unsigned int	m_size;
};

/*----------------------------------------------------------------------------*/

inline unsigned int	PointCSPNode::getSize() const
{
    return m_size;
}
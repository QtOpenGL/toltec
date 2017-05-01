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
*	LINE COMPONENT SHADER PROGRAM NODE
*-----------------------------------------------------------------------------*/
class LineCSPNode : public ComponentShaderProgramNode
{
public:
    //CONSTRUCTORS
                LineCSPNode();
    virtual		~LineCSPNode() {}

    //SET
    void		setThickness(unsigned int thickness);

    //GET
    unsigned int	getThickness() const;

private:
    unsigned int	m_thickness;
};

/*----------------------------------------------------------------------------*/

inline unsigned int	LineCSPNode::getThickness() const
{
    return m_thickness;
}
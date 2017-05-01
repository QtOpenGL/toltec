/*-----------------------------------------------------------------------------
*	CREATED:
*		13 II 2017
*	CONTRIBUTORS:
*		Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "lineCSPNode.hpp"

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*-----------------------------------------------------------------------------*/
LineCSPNode::LineCSPNode()
    :
    m_thickness(1)
{
    //INITIALIZE
    this->setShortName("lineComponentShader");
    this->setType(Node::LINE_CSP_NODE);
}

/*-----------------------------------------------------------------------------
*	SET THICKNESS
*-----------------------------------------------------------------------------*/
void LineCSPNode::setThickness(unsigned int thickness)
{
    m_thickness = thickness;
}

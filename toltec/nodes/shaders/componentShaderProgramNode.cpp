/*-----------------------------------------------------------------------------
*	CREATED:
*		13 II 2017
*	CONTRIBUTORS:
*		Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "componentShaderProgramNode.hpp"

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*-----------------------------------------------------------------------------*/
ComponentShaderProgramNode::ComponentShaderProgramNode()
    :
    m_color(1.0f, 1.0f, 1.0f)
{
    //INITIALIZE
    this->setShortName("componentShaderProgramNode");
    this->setType(Node::COMPONENT_SHADER_PROGRAM_NODE);
}

/*-----------------------------------------------------------------------------
*	SET COLOR
*-----------------------------------------------------------------------------*/
void ComponentShaderProgramNode::setColor(const glm::vec3& color)
{
    m_color = color;
}

void ComponentShaderProgramNode::setColor(float r, float g, float b)
{
    m_color = glm::vec3(r, g, b);
}

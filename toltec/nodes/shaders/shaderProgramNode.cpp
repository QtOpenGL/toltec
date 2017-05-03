/*-----------------------------------------------------------------------------
*   CREATED:
*       09 I 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "shaderProgramNode.hpp"

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*-----------------------------------------------------------------------------*/
ShaderProgramNode::ShaderProgramNode()
{
    //INITIALIZE
    this->setShortName("shaderProgramNode");
    this->setType(Node::SHADER_PROGRAM_NODE);
}

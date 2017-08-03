/*-----------------------------------------------------------------------------
*   CREATED:
*       13 I 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "surfaceNode.hpp"

#include "nodes/shaders/lambertSSPNode.hpp"
#include "resourceManager.hpp"

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
*   CONSTRUCTOR
*-----------------------------------------------------------------------------*/
SurfaceNode::SurfaceNode()
    :
    mp_surfaceShaderProgramNode(nullptr)
{
    //INITIALIZE
    this->setShortName("surfaceNode");
    this->setType(nodes::Type::SURFACE_NODE);
    this->setSurfaceShaderProgramNode(&ResourceManager::getInstance().getDefaultSSPNode());
}

/*-----------------------------------------------------------------------------
*   SET SURFACE SHADER PROGRAM
*-----------------------------------------------------------------------------*/
void SurfaceNode::setSurfaceShaderProgramNode(SurfaceShaderProgramNode* p_surfaceShaderProgramNode)
{
    //CHECK
    if (p_surfaceShaderProgramNode == mp_surfaceShaderProgramNode)
        return;

    //REMOVE / SET / ADD
    if (p_surfaceShaderProgramNode == nullptr)
    {
        mp_surfaceShaderProgramNode = &ResourceManager::getInstance().getDefaultSSPNode();
        mp_surfaceShaderProgramNode->addSurface(this, true);
    }
    else
    {
        if (mp_surfaceShaderProgramNode != nullptr)
            mp_surfaceShaderProgramNode->removeSurface(this, true);

        mp_surfaceShaderProgramNode = p_surfaceShaderProgramNode;
        mp_surfaceShaderProgramNode->addSurface(this, true);
    }
}
} //NAMESPACE: NODES
} //NAMESPACE: CORE
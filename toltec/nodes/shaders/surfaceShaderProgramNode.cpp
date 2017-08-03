/*-----------------------------------------------------------------------------
*   CREATED:
*       11 I 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "surfaceShaderProgramNode.hpp"

#include "nodes/surfaceNode.hpp"
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
SurfaceShaderProgramNode::SurfaceShaderProgramNode()
{
    //INITIALIZE
    this->setShortName("surfaceShaderProgramNode");
    this->setType(nodes::Type::SURFACE_SHADER_PROGRAM_NODE);
}

/*-----------------------------------------------------------------------------
*   ADD SURFACE
*-----------------------------------------------------------------------------*/
void SurfaceShaderProgramNode::addSurface(SurfaceNode* p_surfaceNode, const bool hardAdd)
{
    //CHECK
    for (SurfaceNode* p_surfaceListElement : m_surfaceNodeList)
        if (p_surfaceListElement == p_surfaceNode)
            return;
    if (p_surfaceNode == nullptr)
        return;

    //ADD
    if (hardAdd == false)
    {
        //clean old
        SurfaceShaderProgramNode* p_shaderProgram = p_surfaceNode->getSurfaceShaderProgramNode();
        p_shaderProgram->removeSurface(p_surfaceNode, true);

        //add / set
        m_surfaceNodeList.push_back(p_surfaceNode);
        p_surfaceNode->setSurfaceShaderProgramNode(this);
    }
    else
    {
        //add
        m_surfaceNodeList.push_back(p_surfaceNode);
    }
}

/*-----------------------------------------------------------------------------
*   REMOVE SURFACE
*-----------------------------------------------------------------------------*/
void SurfaceShaderProgramNode::removeSurface(SurfaceNode* p_surfaceNode, const bool hardRemove)
{
    //CHECK
    if (p_surfaceNode == nullptr)
        return;

    //REMOVE
    std::size_t numSurfaceNodes = m_surfaceNodeList.size();
    for (std::size_t i = 0; i < numSurfaceNodes; i++)
    {
        if (m_surfaceNodeList[i] == p_surfaceNode)
        {
            //remove old
            m_surfaceNodeList.erase(m_surfaceNodeList.begin() + i);

            //set default
            if (hardRemove == false)
                p_surfaceNode->setSurfaceShaderProgramNode(&ResourceManager::getInstance().getDefaultSSPNode());

            break;
        }
    }
}
} //NAMESPACE: NODES
} //NAMESPACE: CORE


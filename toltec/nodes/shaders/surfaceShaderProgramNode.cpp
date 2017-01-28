/*-----------------------------------------------------------------------------
*	CREATED:
*		11 I 2017
*	CONTRIBUTORS:
*		PIOTR MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "surfaceShaderProgramNode.hpp"

#include "nodes/surfaceNode.hpp"
#include "resourceManager.hpp"

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*-----------------------------------------------------------------------------*/
SurfaceShaderProgramNode::SurfaceShaderProgramNode()
{
	//INITIALIZE
	this->setShortName("surfaceShaderProgramNode");
}

/*-----------------------------------------------------------------------------
*	ADD SURFACE
*-----------------------------------------------------------------------------*/
void SurfaceShaderProgramNode::addSurface(SurfaceNode* p_surfaceNode, const bool hardAdd)
{
	//CHECK
	for (SurfaceNode* p_surfaceListElement : m_surfaceList)
		if (p_surfaceListElement == p_surfaceNode)
			return;
	if (p_surfaceNode == nullptr)
		return;

	//ADD
	if (hardAdd == false)
	{
		//clean old
		SurfaceShaderProgramNode* p_shaderProgram = p_surfaceNode->getSurfaceShaderProgram();
		p_shaderProgram->removeSurface(p_surfaceNode, true);

		//add / set
		m_surfaceList.push_back(p_surfaceNode);
		p_surfaceNode->setSurfaceShaderProgram(this);
	}
	else
	{
		//add
		m_surfaceList.push_back(p_surfaceNode);
	}
}

/*-----------------------------------------------------------------------------
*	REMOVE SURFACE
*-----------------------------------------------------------------------------*/
void SurfaceShaderProgramNode::removeSurface(SurfaceNode* p_surfaceNode, const bool hardRemove)
{
	//CHECK
	if (p_surfaceNode == nullptr)
		return;

	//REMOVE
	std::size_t numSurfaceNodes = m_surfaceList.size();
	for (std::size_t i = 0; i < numSurfaceNodes; i++)
	{
		if (m_surfaceList[i] == p_surfaceNode)
		{
			//remove old
			m_surfaceList.erase(m_surfaceList.begin() + i);

			//set default
			if (hardRemove == false)
				p_surfaceNode->setSurfaceShaderProgram(ResourceManager::getInstance().getDefaultSSPNode());

			break;
		}
	}
}



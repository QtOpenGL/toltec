/*-----------------------------------------------------------------------------
*	CREATED:
*		11 I 2017
*	CONTRIBUTORS:
*		PETER MAKAL
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
void SurfaceShaderProgramNode::addSurface(SurfaceNode* p_surfaceNode)
{
	//CHECK
	for (SurfaceNode* p_surfaceListElement : m_surfaceList)
		if (p_surfaceListElement == p_surfaceNode)
			return;
	if (p_surfaceNode == nullptr)
		return;

	//CLEAN OLD
	SurfaceShaderProgramNode* p_shaderProgram = p_surfaceNode->getSurfaceShaderProgram();
	p_shaderProgram->hardRemoveSurface(p_surfaceNode);

	//ADD / SET
	m_surfaceList.push_back(p_surfaceNode);
	p_surfaceNode->setSurfaceShaderProgram(this);
}

/*-----------------------------------------------------------------------------
*	HARD ADD SURFACE
*-----------------------------------------------------------------------------*/
void SurfaceShaderProgramNode::hardAddSurface(SurfaceNode* p_surfaceNode)
{
	//CHECK
	for (SurfaceNode* p_surfaceListElement : m_surfaceList)
		if (p_surfaceListElement == p_surfaceNode)
			return;
	if (p_surfaceNode == nullptr)
		return;

	//ADD
	m_surfaceList.push_back(p_surfaceNode);
}

/*-----------------------------------------------------------------------------
*	REMOVE SURFACE
*-----------------------------------------------------------------------------*/
void SurfaceShaderProgramNode::removeSurface(SurfaceNode* p_surfaceNode)
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
			m_surfaceList.erase(m_surfaceList.begin() + i);
			p_surfaceNode->setSurfaceShaderProgram(ResourceManager::getInstance().getDefaultSSPNode);
			break;
		}
	}
}

/*-----------------------------------------------------------------------------
*	HARD REMOVE SURFACE
*-----------------------------------------------------------------------------*/
void SurfaceShaderProgramNode::hardRemoveSurface(SurfaceNode* p_surfaceNode)
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
			m_surfaceList.erase(m_surfaceList.begin() + i);
			break;
		}
	}
}



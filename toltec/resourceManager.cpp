/*-----------------------------------------------------------------------------
*	CREATED:
*		14 IX 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "resourceManager.hpp"

#include <cstddef>

#include "nodes/cameraNode.hpp"
#include "nodes/polygonMeshNode.hpp"
#include "nodes/shaderProgramNode.hpp"
#include "nodes/transformNode.hpp"

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*-----------------------------------------------------------------------------*/
ResourceManager::ResourceManager()
	:
	mp_defaultShaderProgramNode(nullptr),
	mp_rootTransformNode(nullptr),
	mp_defaultCameraNode(nullptr)
{
	//INITIALIZE
	m_globalNodeIDList.push_back(0);
}

/*-----------------------------------------------------------------------------
*	SET DEFAULT SHADER PROGRAM NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::setDefaultShaderProgramNode(ShaderProgramNode* p_shaderProgramNode)
{
	if (mp_defaultShaderProgramNode != nullptr)	//return if already assigned
		return;

	mp_defaultShaderProgramNode = p_shaderProgramNode;

	m_shaderProgramNodeList.push_back(mp_defaultShaderProgramNode);
	m_undeletableNodeList.push_back(mp_defaultShaderProgramNode);
}

/*-----------------------------------------------------------------------------
*	SET ROOT TRANSFORM NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::setRootTransformNode(TransformNode* p_rootTransformNode)
{
	if (mp_rootTransformNode != nullptr)	//return if already assigned
		return;

	mp_rootTransformNode = p_rootTransformNode;

	m_transformNodeList.push_back(mp_rootTransformNode);
	m_undeletableNodeList.push_back(mp_rootTransformNode);
}

/*-----------------------------------------------------------------------------
*	SET DEFAULT CAMERA NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::setDefaultCameraNode(CameraNode* p_defaultCameraNode)
{
	if (mp_defaultCameraNode != nullptr)	//return if already assigned
		return;

	mp_defaultCameraNode = p_defaultCameraNode;

	m_cameraNodeList.push_back(mp_defaultCameraNode);
	m_undeletableNodeList.push_back(mp_defaultCameraNode);
}

/*-----------------------------------------------------------------------------
*	ADD TRANSFORM NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::addTransformNode(TransformNode* p_transformNode)
{
	//CHECK IF ALREADY ON THE LIST
	for (TransformNode* p_transformNodeListItem : m_transformNodeList)
		if (p_transformNodeListItem == p_transformNode)
			return;

	//ADD
	m_transformNodeList.push_back(p_transformNode);
}

/*-----------------------------------------------------------------------------
*	ADD POLYGON MESH NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::addPolygonMeshNode(PolygonMeshNode* p_polygonMeshNode)
{
	//CHECK IF ALREADY ON THE LIST
	for (PolygonMeshNode* p_polygonMeshNodeListItem : m_polygonMeshNodeList)
		if (p_polygonMeshNodeListItem == p_polygonMeshNode)
			return;

	//ADD
	m_polygonMeshNodeList.push_back(p_polygonMeshNode);
}

/*-----------------------------------------------------------------------------
*	ASSIGN NODE ID
*-----------------------------------------------------------------------------*/
std::uint32_t ResourceManager::assignNodeID()
{
	std::size_t globalNodeIDListSize = m_globalNodeIDList.size();
	if (globalNodeIDListSize == 1)
	{
		m_globalNodeIDList.push_back(1);
		return 1;
	}
	else
	{
		for (std::size_t i = 0; i < globalNodeIDListSize; i++)
		{
			if (m_globalNodeIDList[i] == 0)
			{
				m_globalNodeIDList[i] = i;
				return i;
			}
		}

		m_globalNodeIDList.push_back(globalNodeIDListSize);
		return globalNodeIDListSize;
	}
}

/*-----------------------------------------------------------------------------
*	REMOVE NODE ID
*-----------------------------------------------------------------------------*/
void ResourceManager::removeNodeID(const std::uint32_t nodeID)
{
	if (nodeID < m_globalNodeIDList.size())
		m_globalNodeIDList[nodeID] = 0;
}

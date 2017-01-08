#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		14 IX 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		ResourceManager is a singleton class responsible for managing resources
*		across the program. It also sends the data to the rendering system.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <cstdint>
#include <vector>

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class CameraNode;
class Node;
class PolygonMeshNode;
class TransformNode;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	RESOURCE MANAGER
*-----------------------------------------------------------------------------*/
class ResourceManager
{
public:
	//SINGLETON
	static ResourceManager& getInstance()
	{
		static ResourceManager instance;
		return instance;
	}
	ResourceManager(const ResourceManager&) = delete;
	void operator=(const ResourceManager&) = delete;

	//ADD
	void				addTransformNode(TransformNode* p_transformNode);
	void				addPolygonMeshNode(PolygonMeshNode* p_polygonMeshNode);

	//SET
	void				setRootTransformNode(TransformNode* p_rootTransformNode);
	void				setDefaultCameraNode(CameraNode* p_defaultCameraNode);

	//GET
	TransformNode*		getRootTransformNode();

	//OTHER
	std::uint32_t		assignNodeID();
	void				removeNodeID(const std::uint32_t nodeID);

private:
	//SINGLETON
	ResourceManager();

private:
	std::vector<std::uint32_t>		m_globalNodeIDList;

	std::vector<Node*>				m_undeletableNodeList;

	TransformNode*					mp_rootTransformNode;
	CameraNode*						mp_defaultCameraNode;

	std::vector<TransformNode*>		m_transformNodeList;
	std::vector<CameraNode*>		m_cameraNodeList;
	std::vector<PolygonMeshNode*>	m_polygonMeshNodeList;
};

/*----------------------------------------------------------------------------*/

inline TransformNode* ResourceManager::getRootTransformNode()
{
	return mp_rootTransformNode;
}

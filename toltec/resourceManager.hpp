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
#include <vector>

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
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

	//GET
	TransformNode*		getRootTransformNode();

private:
	//SINGLETON
	ResourceManager() {}

private:
	TransformNode*					mp_rootTransformNode;
	std::vector<TransformNode*>		m_transformNodeList;
	std::vector<PolygonMeshNode*>	m_polygonMeshNodeList;
};

/*----------------------------------------------------------------------------*/

inline TransformNode* ResourceManager::getRootTransformNode()
{
	return mp_rootTransformNode;
}
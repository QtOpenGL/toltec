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

#include "nodes/polygonMeshNode.hpp"
#include "nodes/transformNode.hpp"

/*-----------------------------------------------------------------------------
*	SET ROOT TRANSFORM NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::setRootTransformNode(TransformNode* p_rootTransformNode)
{
	mp_rootTransformNode = p_rootTransformNode;
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

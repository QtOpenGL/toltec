/*-----------------------------------------------------------------------------
*	CREATED:
*		13 IX 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "createCube.hpp"

#include <vector>

#include "nodes/polygonMeshNode.hpp"
#include "nodes/transformNode.hpp"
#include "toltecPolygonMeshLibrary/mesh.hpp"
#include "resourceManager.hpp"

/*-----------------------------------------------------------------------------
*	FUNCTION DEFINITIONS
*	CREATE CUBE
*-----------------------------------------------------------------------------*/
void createCube()
{
	//CREATE TRANSFORM NODE
	TransformNode* p_transformNode = new TransformNode();

	//DEFINE CUBE POINTS
	std::vector<tpm::Point3D> point3DList = {
		tpm::Point3D{ -1, -1,  1 },		//0
		tpm::Point3D{  1, -1,  1 },		//1
		tpm::Point3D{  1,  1,  1 },		//2
		tpm::Point3D{ -1,  1,  1 },		//3
		tpm::Point3D{ -1, -1, -1 },		//4
		tpm::Point3D{  1, -1, -1 },		//5
		tpm::Point3D{  1,  1, -1 },		//6
		tpm::Point3D{ -1,  1, -1 }		//7
	};

	//DEFINE VERTEX SEQUENCE
	std::vector<unsigned int> vertexSequence = {
		0, 1, 2, 3,
		7, 6, 5, 4,
		1, 0, 4, 5,
		2, 1, 5, 6,
		3, 2, 6, 7,
		0, 3, 7, 4
	};

	//DEFINE POLYGON OFFSET LIST
	std::vector<unsigned int> polygonOffsetList = { 4, 4, 4, 4, 4, 4 };

	//CREATE POLYGON MESH NODE
	PolygonMeshNode* p_polygonMeshNode = new PolygonMeshNode();
	p_polygonMeshNode->createMesh(point3DList, vertexSequence, polygonOffsetList);

	//SET SCENE TREE
	p_transformNode->addChild(p_polygonMeshNode);
	ResourceManager::getInstance().getRootTransformNode()->addChild(p_transformNode);

	//ADD TO THE RESOURCE MANAGER
	ResourceManager::getInstance().addTransformNode(p_transformNode);
	ResourceManager::getInstance().addPolygonMeshNode(p_polygonMeshNode);
}
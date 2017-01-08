/*-----------------------------------------------------------------------------
*	CREATED:
*		30 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "polygonMeshNode.hpp"

#include <iomanip>
#include <iostream>
#include <vector>

#include "transformNode.hpp"

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*-----------------------------------------------------------------------------*/
PolygonMeshNode::PolygonMeshNode()
{
	//INITIALIZE
	this->setShortName("polygonMeshNode");
}

/*-----------------------------------------------------------------------------
*	CREATE
*-----------------------------------------------------------------------------*/
bool PolygonMeshNode::createMesh(
	std::vector<tpm::Point3D>&	point3DList,
	std::vector<unsigned int>&	vertexSequence,
	std::vector<unsigned int>&	polygonOffsetList)
{
	//CHECK
	unsigned int faceVertexCountCheck = 0;
	for (const unsigned int& numPolygonSides : polygonOffsetList)
		faceVertexCountCheck += numPolygonSides;

	if (vertexSequence.size() != faceVertexCountCheck)
		return false;

	//CREATE VERTICES
	std::vector<tpm::Vertex*> vertexList;

	for (tpm::Point3D& point3D : point3DList)
		vertexList.push_back(m_mesh.addVertex(point3D));

	//CREATE FACES
	std::vector<tpm::Vertex*> faceBuildList;

	unsigned int faceVertexIndex = 0;
	for (const unsigned int& numPolygonSides : polygonOffsetList)
	{
		faceBuildList.clear();
		for (unsigned int i = 0; i < numPolygonSides; i++)
		{
			faceBuildList.push_back(vertexList[vertexSequence[faceVertexIndex]]);
			faceVertexIndex++;
		}
		m_mesh.addFace(faceBuildList);
	}

	return true;
}

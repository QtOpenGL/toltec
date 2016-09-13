/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "polygonMeshNode.hpp"

#include <iomanip>
#include <iostream>
#include <vector>

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*-----------------------------------------------------------------------------*/
PolygonMeshNode::PolygonMeshNode()
{
	//...
}

/*-----------------------------------------------------------------------------
*	CREATE
*-----------------------------------------------------------------------------*/
bool PolygonMeshNode::create(
	std::vector<tpm::Point3D>&	point3DList,
	std::vector<unsigned int>&	vertexSequence,
	std::vector<unsigned int>&	polygonOffsets,
	TransformNode*				p_parent)
{
	//CHECK
	unsigned int faceVertexCountCheck = 0;
	for (const unsigned int& numPolygonSides : polygonOffsets)
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
	for (const unsigned int& numPolygonSides : polygonOffsets)
	{
		faceBuildList.clear();
		for (unsigned int i = 0; i < numPolygonSides; i++)
		{
			faceBuildList.push_back(vertexList[faceVertexIndex]);
			faceVertexIndex++;
		}
		m_mesh.addFace(faceBuildList);
	}

	return true;
}

/*-----------------------------------------------------------------------------
*   CREATED:
*       30 VIII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "polygonMeshNode.hpp"

#include <iomanip>
#include <iostream>
#include <vector>

#include "transformNode.hpp"

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*-----------------------------------------------------------------------------*/
PolygonMeshNode::PolygonMeshNode()
{
    //INITIALIZE
    this->setShortName("polygonMeshNode");
    this->setType(Node::POLYGON_MESH_NODE);
}

/*-----------------------------------------------------------------------------
*   CREATE
*-----------------------------------------------------------------------------*/
bool PolygonMeshNode::createMesh(
    std::vector<glm::vec3>& point3DList,
    std::vector<unsigned int>&  vertexSequence,
    std::vector<unsigned int>&  polygonOffsetList)
{
    //CHECK
    unsigned int faceVertexCountCheck = 0;
    for (const unsigned int& numPolygonSides : polygonOffsetList)
        faceVertexCountCheck += numPolygonSides;

    if (vertexSequence.size() != faceVertexCountCheck)
        return false;

    //CREATE VERTICES
    std::vector<tpm::Vertex*> vertexList;
    for (glm::vec3& point3D : point3DList)
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

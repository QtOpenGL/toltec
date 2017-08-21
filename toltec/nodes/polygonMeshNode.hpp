#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       30 VIII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       PolygonMeshNode class holds information about mesh data structure 
*       (vertices, edges, triangles, faces, etc.).
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <glm/glm.hpp>

#include "surfaceNode.hpp"
#include "toltecPolygonMeshLibrary/mesh.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: CORE
*-----------------------------------------------------------------------------*/
namespace core
{
/*-----------------------------------------------------------------------------
*   NAMESPACE: NODES
*-----------------------------------------------------------------------------*/
namespace nodes
{
/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   SCENE 3D NODE
*-----------------------------------------------------------------------------*/
class PolygonMeshNode : public SurfaceNode
{
public:
    //CTOR DTOR
                PolygonMeshNode();
    virtual     ~PolygonMeshNode() {}

    //GET
    tpm::Mesh*  getMesh();

    //OTHER
    bool        createMesh(
                    std::vector<glm::vec3>&     point3DList,
                    std::vector<unsigned int>&  faceVertexSequence,
                    std::vector<unsigned int>&  polygonOffsets);

private:
    tpm::Mesh   m_mesh;
};

/*----------------------------------------------------------------------------*/

inline tpm::Mesh* PolygonMeshNode::getMesh()
{
    return &m_mesh;
}
} //NAMESPACE: NODES
} //NAMESPACE: CORE

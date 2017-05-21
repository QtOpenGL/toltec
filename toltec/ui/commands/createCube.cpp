/*-----------------------------------------------------------------------------
*   CREATED:
*       13 IX 2016
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "createCube.hpp"

#include <vector>

#include <glm/glm.hpp>

#include "nodes/polygonMeshNode.hpp"
#include "nodes/transformNode.hpp"
#include "toltecPolygonMeshLibrary/mesh.hpp"
#include "resourceManager.hpp"

/*-----------------------------------------------------------------------------
*   FUNCTION DEFINITIONS
*   CREATE CUBE
*-----------------------------------------------------------------------------*/
void createCube()
{
    //CREATE TRANSFORM NODE
    TransformNode* p_transformNode = new TransformNode();
    p_transformNode->setShortName("polyCube");

    //DEFINE CUBE POINTS
    std::vector<glm::vec3> point3DList = {
        glm::vec3{ -1, -1,  1 },    //0
        glm::vec3{  1, -1,  1 },    //1
        glm::vec3{  1,  1,  1 },    //2
        glm::vec3{ -1,  1,  1 },    //3
        glm::vec3{ -1, -1, -1 },    //4
        glm::vec3{  1, -1, -1 },    //5
        glm::vec3{  1,  1, -1 },    //6
        glm::vec3{ -1,  1, -1 }     //7
    };

    //DEFINE VERTEX SEQUENCE
    std::vector<unsigned int> faceVertexSequence = {
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
    p_polygonMeshNode->setShortName("polyCube");
    p_polygonMeshNode->createMesh(point3DList, faceVertexSequence, polygonOffsetList);

    //SET SCENE TREE
    p_transformNode->addChild(p_polygonMeshNode);
    ResourceManager::getInstance().getRootTransformNode()->addChild(p_transformNode);

    //ADD TO THE RESOURCE MANAGER
    ResourceManager::getInstance().addTransformNode(p_transformNode);
    ResourceManager::getInstance().addPolygonMeshNode(p_polygonMeshNode);
}
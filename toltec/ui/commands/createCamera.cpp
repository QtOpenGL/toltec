/*-----------------------------------------------------------------------------
*   CREATED:
*       08 VIII 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "creationCommands.hpp"

#include <memory>

#include "nodes/cameraNode.hpp"
#include "nodes/transformNode.hpp"
#include "resourceManager.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: UI (USER ITERFACE)
*-----------------------------------------------------------------------------*/
namespace ui
{
/*-----------------------------------------------------------------------------
*   NAMESPACE: CMDS (COMMANDS)
*-----------------------------------------------------------------------------*/
namespace cmds
{
/*-----------------------------------------------------------------------------
*   FUNCTION DEFINITIONS
*   CREATE CAMERA
*-----------------------------------------------------------------------------*/
std::pair<node_id_t, node_id_t> createCamera()
{
    //CREATE NODES
    auto p_transformNode = std::make_unique<core::nodes::TransformNode>();
    p_transformNode->setName("camera");

    auto p_cameraNode = std::make_unique<core::nodes::CameraNode>();
    p_cameraNode->setName("camera");

    //FETCH NODES IDs
    auto nodesIDs = std::pair<node_id_t, node_id_t>(
        p_transformNode->getNodeID(),
        p_cameraNode->getNodeID()
    );

    //SET SCENE TREE
    p_cameraNode->setParent(p_transformNode.get());
    p_transformNode->setParent(&(ResourceManager::getInstance().getRootTransformNode()));

    //ADD TO THE RESOURCE MANAGER
    ResourceManager::getInstance().addTransformNode(std::move(p_transformNode));
    ResourceManager::getInstance().addCameraNode(std::move(p_cameraNode));

    return nodesIDs;
}
} //NAMESPACE: CMDS
} //NAMESPACE: UI
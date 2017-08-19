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
core::nodes::CameraNode* createCamera()
{
    //CREATE NODES
    auto p_transformNode = std::make_unique<core::nodes::TransformNode>();
    p_transformNode->setName("camera");

    auto p_cameraNode = std::make_unique<core::nodes::CameraNode>();
    p_cameraNode->setName("camera");
    p_cameraNode->updateViewMatrix(
        p_transformNode->getTranslation(),
        p_transformNode->getTargetPosition(),
        p_transformNode->getLocalY()
    );

    //SET SCENE TREE
    p_cameraNode->setParent(p_transformNode.get());
    p_transformNode->setParent(&(ResourceManager::getInstance().getRootTransformNode()));

    //ADD TO THE RESOURCE MANAGER
    core::nodes::CameraNode* p_returnPointer = p_cameraNode.get();
    ResourceManager::getInstance().addTransformNode(std::move(p_transformNode));
    ResourceManager::getInstance().addCameraNode(std::move(p_cameraNode));

    return p_returnPointer;
}
} //NAMESPACE: CMDS
} //NAMESPACE: UI
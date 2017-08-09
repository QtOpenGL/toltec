/*-----------------------------------------------------------------------------
*   CREATED:
*       14 IX 2016
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "resourceManager.hpp"

#include <cstddef>

#include "nodes/cameraNode.hpp"
#include "nodes/polygonMeshNode.hpp"
#include "nodes/shaders/componentShaderProgramNode.hpp"
#include "nodes/shaders/shaderProgramNode.hpp"
#include "nodes/shaders/surfaceShaderProgramNode.hpp"
#include "nodes/transformNode.hpp"

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*-----------------------------------------------------------------------------*/
ResourceManager::ResourceManager()
    :
    mp_defaultSSPNode(nullptr),
    mp_rootTransformNode(nullptr),
    mp_defaultCameraNode(nullptr)
{
    //INITIALIZE
    m_globalNodeIDList.push_back(0);
}

/*-----------------------------------------------------------------------------
*   ADD CAMERA NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::addCameraNode(std::unique_ptr<core::nodes::CameraNode> p_cameraNode)
{
    //CHECK IF IT IS ALREADY ON THE LIST
    for (const auto& p_cameraNodeListElement : m_cameraNodeList)
        if (p_cameraNodeListElement == p_cameraNode.get())
            return;

    //ADD
    m_cameraNodeList.push_back(p_cameraNode.get());
    m_allNodeList.push_back(std::move(p_cameraNode));
}

/*-----------------------------------------------------------------------------
*   ADD COMPONENT SHADER PROGRAM NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::addComponentShaderProgramNode(
    std::unique_ptr<core::nodes::ComponentShaderProgramNode> p_componentShaderProgramNode)
{
    //CHECK IF IT IS ALREADY ON THE LIST
    for (const auto& p_componentShaderProgramNodeListElement : m_componentShaderProgramNodeList)
        if (p_componentShaderProgramNodeListElement == p_componentShaderProgramNode.get())
            return;

    //ADD
    m_componentShaderProgramNodeList.push_back(p_componentShaderProgramNode.get());
    m_undeletableNodeList.push_back(p_componentShaderProgramNode.get());
    m_allNodeList.push_back(std::move(p_componentShaderProgramNode));
}

/*-----------------------------------------------------------------------------
*   ADD POLYGON MESH NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::addPolygonMeshNode(std::unique_ptr<core::nodes::PolygonMeshNode> p_polygonMeshNode)
{
    //CHECK IF IT IS ALREADY ON THE LIST
    for (const auto& p_polygonMeshNodeListElement : m_polygonMeshNodeList)
        if (p_polygonMeshNodeListElement == p_polygonMeshNode.get())
            return;

    //ADD
    m_polygonMeshNodeList.push_back(p_polygonMeshNode.get());
    m_allNodeList.push_back(std::move(p_polygonMeshNode));
}

/*-----------------------------------------------------------------------------
*   ADD SURFACE SHADER PROGRAM NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::addSurfaceShaderProgramNode(
    std::unique_ptr<core::nodes::SurfaceShaderProgramNode> p_surfaceShaderProgramNode)
{
    //CHECK IF IT IS ALREADY ON THE LIST
    for (const auto& p_surfaceShaderProgramNodeListElement : m_surfaceShaderProgramNodeList)
        if (p_surfaceShaderProgramNodeListElement == p_surfaceShaderProgramNode.get())
            return;

    //ADD
    m_surfaceShaderProgramNodeList.push_back(p_surfaceShaderProgramNode.get());
    m_allNodeList.push_back(std::move(p_surfaceShaderProgramNode));
}

/*-----------------------------------------------------------------------------
*   ADD TRANSFORM NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::addTransformNode(std::unique_ptr<core::nodes::TransformNode> p_transformNode)
{
    //CHECK IF IT IS ALREADY ON THE LIST
    for (const auto& p_transformNodeListElement : m_transformNodeList)
        if (p_transformNodeListElement == p_transformNode.get())
            return;

    //ADD
    m_transformNodeList.push_back(p_transformNode.get());
    m_allNodeList.push_back(std::move(p_transformNode));
}

/*-----------------------------------------------------------------------------
*   SET DEFAULT CAMERA NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::setDefaultCameraNode(core::nodes::CameraNode* p_defaultCameraNode)
{
    if (mp_defaultCameraNode != nullptr)    //return if already assigned
        return;

    mp_defaultCameraNode = p_defaultCameraNode;
    m_undeletableNodeList.push_back(mp_defaultCameraNode);
}

/*-----------------------------------------------------------------------------
*   SET DEFAULT SHADER PROGRAM NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::setDefaultSSPNode(core::nodes::SurfaceShaderProgramNode* p_shaderProgramNode)
{
    if (mp_defaultSSPNode != nullptr)   //return if already assigned
        return;

    mp_defaultSSPNode = p_shaderProgramNode;
    m_undeletableNodeList.push_back(mp_defaultSSPNode);
}

/*-----------------------------------------------------------------------------
*   SET ROOT TRANSFORM NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::setRootTransformNode(core::nodes::TransformNode* p_rootTransformNode)
{
    if (mp_rootTransformNode != nullptr)    //return if already assigned
        return;

    mp_rootTransformNode = p_rootTransformNode;
    m_undeletableNodeList.push_back(mp_rootTransformNode);
}

/*-----------------------------------------------------------------------------
*   GET CAMERA NODE
*-----------------------------------------------------------------------------*/
core::nodes::CameraNode* ResourceManager::getCameraNode(const node_id& nodeID)
{
    for (auto p_cameraNode : m_cameraNodeList)
    {
        if (p_cameraNode->getNodeID() == nodeID)
            return p_cameraNode;
    }

    return nullptr;
}

/*-----------------------------------------------------------------------------
*   GET NODE
*-----------------------------------------------------------------------------*/
core::nodes::Node* ResourceManager::getNode(const node_id& nodeID)
{
    for (auto& p_node : m_allNodeList)
    {
        if (p_node->getNodeID() == nodeID)
            return p_node.get();
    }

    return nullptr;
}

/*-----------------------------------------------------------------------------
*   GET NODES
*-----------------------------------------------------------------------------*/
std::vector<core::nodes::Node*> ResourceManager::getNodes(const std::string& nodeName)
{
    std::vector<core::nodes::Node*> selectedNodes;
    for (auto& p_node : m_allNodeList)
    {
        if (p_node->getName() == nodeName)
            selectedNodes.push_back(p_node.get());
    }

    return selectedNodes;
}

/*-----------------------------------------------------------------------------
*   ASSIGN NODE ID
*-----------------------------------------------------------------------------*/
node_id ResourceManager::assignNodeID()
{
    std::size_t globalNodeIDListSize = m_globalNodeIDList.size();
    if (globalNodeIDListSize == 1)
    {
        m_globalNodeIDList.push_back(1);
        return 1;
    }
    else
    {
        for (std::size_t i = 0; i < globalNodeIDListSize; i++)
        {
            if (m_globalNodeIDList[i] == 0)
            {
                m_globalNodeIDList[i] = i;
                return i;
            }
        }

        m_globalNodeIDList.push_back(globalNodeIDListSize);
        return (node_id)globalNodeIDListSize;
    }
}

/*-----------------------------------------------------------------------------
*   REMOVE NODE ID
*-----------------------------------------------------------------------------*/
void ResourceManager::removeNodeID(const node_id& nodeID)
{
    if (nodeID < m_globalNodeIDList.size())
        m_globalNodeIDList[nodeID] = 0;
}
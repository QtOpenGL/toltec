#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       14 IX 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ResourceManager is a singleton class responsible for managing resources
*       across the program. It also sends the data to the rendering system.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <cstdint>
#include <map>
#include <memory>
#include <vector>

#include "utils.hpp"

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
namespace core 
{
    namespace nodes 
    {
        class CameraNode;
        class ComponentShaderProgramNode;
        class Node;
        class PolygonMeshNode;
        class ShaderProgramNode;
        class SurfaceShaderProgramNode;
        class TransformNode;
    }
}

/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   RESOURCE MANAGER
*-----------------------------------------------------------------------------*/
class ResourceManager
{
public:
    //SINGLETON
    static ResourceManager& getInstance()
    {
        static ResourceManager instance;
        return instance;
    }
    ResourceManager(const ResourceManager&) = delete;
    void operator=(const ResourceManager&) = delete;

    //TYPES
    enum DedicatedShaderProgram {
        DEFAULT_SURFACE,
        CAMERA_ACTIVE,
        CAMERA_INACTIVE,
        CAMERA_HOVER,
        VERTEX_ACTIVE,
        VERTEX_INACTIVE,
        VERTEX_HOVER,
    };

    //ADD
    void            addCameraNode(std::unique_ptr<core::nodes::CameraNode> p_cameraNode);
    void            addDedicatedShaderProgramNode(ResourceManager::DedicatedShaderProgram dedicatedShaderProgram, 
                        std::unique_ptr<core::nodes::ShaderProgramNode> p_shaderProgramNode);
    void            addPolygonMeshNode(std::unique_ptr<core::nodes::PolygonMeshNode> p_polygonMeshNode);
    void            addTransformNode(std::unique_ptr<core::nodes::TransformNode> p_transformNode);
    void            addUserShaderProgramNode(std::unique_ptr<core::nodes::ShaderProgramNode> p_shaderProgramNode);
                    
    //SET           
    void            setDefaultCameraNode(core::nodes::CameraNode* p_defaultCameraNode);
    void            setRootTransformNode(core::nodes::TransformNode* p_rootTransformNode);

    //GET
    std::vector<std::unique_ptr<core::nodes::Node>>&        getAllNodeList();
    core::nodes::CameraNode*                                getCameraNode(const node_id& nodeID);
    core::nodes::ShaderProgramNode*                         getDedicatedShaderProgramNode(const ResourceManager::DedicatedShaderProgram& dedicatedShaderProgram) const;
    core::nodes::Node*                                      getNode(const node_id& nodeID);
    std::vector<core::nodes::Node*>                         getNodes(const std::string& nodeName);
    core::nodes::TransformNode*                             getRootTransformNode();
    const std::vector<core::nodes::ShaderProgramNode*>&     getUserShaderProgramNodeList() const;

    //OTHER
    node_id         assignNodeID();
    void            removeNodeID(const node_id& nodeID);

private:
    //SINGLETON
    ResourceManager();

private:
    std::vector<node_id>                                    m_globalNodeIDList;

    std::vector<std::unique_ptr<core::nodes::Node>>         m_allNodeList;      //owership of all nodes
    std::vector<core::nodes::Node*>                         m_undeletableNodeList;

    core::nodes::CameraNode*                                mp_defaultCameraNode;
    core::nodes::SurfaceShaderProgramNode*                  mp_defaultSSPNode;
    core::nodes::TransformNode*                             mp_rootTransformNode;

    std::vector<core::nodes::CameraNode*>                   m_cameraNodeList;
    std::map<ResourceManager::DedicatedShaderProgram, core::nodes::ShaderProgramNode*> m_dedicatedShaderProgramMap;
    std::vector<core::nodes::PolygonMeshNode*>              m_polygonMeshNodeList;
    std::vector<core::nodes::TransformNode*>                m_transformNodeList;
    std::vector<core::nodes::ShaderProgramNode*>            m_userShaderProgramNodeList;
};

/*----------------------------------------------------------------------------*/

inline std::vector<std::unique_ptr<core::nodes::Node>>& ResourceManager::getAllNodeList()
{
    return m_allNodeList;
}

inline core::nodes::TransformNode* ResourceManager::getRootTransformNode()
{
    return mp_rootTransformNode;
}

inline const std::vector<core::nodes::ShaderProgramNode*>& 
ResourceManager::getUserShaderProgramNodeList() const
{
    return m_userShaderProgramNodeList;
}

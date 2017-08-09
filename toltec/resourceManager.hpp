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

    //ADD
    void            addCameraNode(std::unique_ptr<core::nodes::CameraNode> p_cameraNode);
    void            addComponentShaderProgramNode(std::unique_ptr<core::nodes::ComponentShaderProgramNode> p_componentShaderProgramNode);
    void            addPolygonMeshNode(std::unique_ptr<core::nodes::PolygonMeshNode> p_polygonMeshNode);
    void            addSurfaceShaderProgramNode(std::unique_ptr<core::nodes::SurfaceShaderProgramNode> p_surfaceShaderProgramNode);
    void            addTransformNode(std::unique_ptr<core::nodes::TransformNode> p_transformNode);
                    
    //SET           
    void            setDefaultCameraNode(core::nodes::CameraNode* p_defaultCameraNode);
    void            setDefaultSSPNode(core::nodes::SurfaceShaderProgramNode* p_surfaceShaderProgramNode);
    void            setRootTransformNode(core::nodes::TransformNode* p_rootTransformNode);

    //GET
    std::vector<std::unique_ptr<core::nodes::Node>>&                getAllNodeList();
    core::nodes::CameraNode*                                        getCameraNode(const node_id& nodeID);
    const std::vector<core::nodes::ComponentShaderProgramNode*>&    getComponentShaderProgramNodeList() const;
    core::nodes::SurfaceShaderProgramNode&                          getDefaultSSPNode();
    core::nodes::Node*                                              getNode(const node_id& nodeID);
    std::vector<core::nodes::Node*>                                 getNodes(const std::string& nodeName);
    core::nodes::TransformNode&                                     getRootTransformNode();
    const std::vector<core::nodes::SurfaceShaderProgramNode*>&      getSurfaceShaderProgramNodeList() const;

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
    std::vector<core::nodes::ComponentShaderProgramNode*>   m_componentShaderProgramNodeList;
    std::vector<core::nodes::PolygonMeshNode*>              m_polygonMeshNodeList;
    std::vector<core::nodes::SurfaceShaderProgramNode*>     m_surfaceShaderProgramNodeList;
    std::vector<core::nodes::TransformNode*>                m_transformNodeList;
};

/*----------------------------------------------------------------------------*/

inline std::vector<std::unique_ptr<core::nodes::Node>>& ResourceManager::getAllNodeList()
{
    return m_allNodeList;
}

inline core::nodes::SurfaceShaderProgramNode& ResourceManager::getDefaultSSPNode()
{
    return *mp_defaultSSPNode;
}

inline core::nodes::TransformNode& ResourceManager::getRootTransformNode()
{
    return *mp_rootTransformNode;
}

inline const std::vector<core::nodes::SurfaceShaderProgramNode*>& 
ResourceManager::getSurfaceShaderProgramNodeList() const
{
    return m_surfaceShaderProgramNodeList;
}

inline const std::vector<core::nodes::ComponentShaderProgramNode*>& 
ResourceManager::getComponentShaderProgramNodeList() const
{
    return m_componentShaderProgramNodeList;
}

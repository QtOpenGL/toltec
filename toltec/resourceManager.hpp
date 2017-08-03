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
    void            addSurfaceShaderProgramNode(std::unique_ptr<core::nodes::SurfaceShaderProgramNode> p_surfaceShaderProgramNode);
    void            addComponentShaderProgramNode(std::unique_ptr<core::nodes::ComponentShaderProgramNode> p_componentShaderProgramNode);
    void            addTransformNode(std::unique_ptr<core::nodes::TransformNode> p_transformNode);
    void            addCameraNode(std::unique_ptr<core::nodes::CameraNode> p_cameraNode);
    void            addPolygonMeshNode(std::unique_ptr<core::nodes::PolygonMeshNode> p_polygonMeshNode);

    //SET
    void            setDefaultSSPNode(core::nodes::SurfaceShaderProgramNode* p_surfaceShaderProgramNode);
    void            setRootTransformNode(core::nodes::TransformNode* p_rootTransformNode);
    void            setDefaultCameraNode(core::nodes::CameraNode* p_defaultCameraNode);

    //GET
    std::vector<std::unique_ptr<core::nodes::Node>>&                getAllNodeList();
    core::nodes::SurfaceShaderProgramNode&                          getDefaultSSPNode();
    core::nodes::TransformNode&                                     getRootTransformNode();
    const std::vector<core::nodes::SurfaceShaderProgramNode*>&      getSurfaceShaderProgramNodeList() const;
    const std::vector<core::nodes::ComponentShaderProgramNode*>&    getComponentShaderProgramNodeList() const;

    //OTHER
    std::uint32_t   assignNodeID();
    void            removeNodeID(const std::uint32_t nodeID);

private:
    //SINGLETON
    ResourceManager();

private:
    std::vector<std::uint32_t>                              m_globalNodeIDList;

    std::vector<std::unique_ptr<core::nodes::Node>>         m_allNodeList;
    std::vector<core::nodes::Node*>                         m_undeletableNodeList;

    core::nodes::SurfaceShaderProgramNode*                  mp_defaultSSPNode;
    core::nodes::TransformNode*                             mp_rootTransformNode;
    core::nodes::CameraNode*                                mp_defaultCameraNode;

    std::vector<core::nodes::SurfaceShaderProgramNode*>     m_surfaceShaderProgramNodeList;
    std::vector<core::nodes::ComponentShaderProgramNode*>   m_componentShaderProgramNodeList;
    std::vector<core::nodes::TransformNode*>                m_transformNodeList;
    std::vector<core::nodes::CameraNode*>                   m_cameraNodeList;
    std::vector<core::nodes::PolygonMeshNode*>              m_polygonMeshNodeList;
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

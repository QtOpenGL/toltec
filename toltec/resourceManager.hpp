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
class CameraNode;
class ComponentShaderProgramNode;
class Node;
class PolygonMeshNode;
class ShaderProgramNode;
class SurfaceShaderProgramNode;
class TransformNode;

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
    void            addSurfaceShaderProgramNode(std::unique_ptr<SurfaceShaderProgramNode> p_surfaceShaderProgramNode);
    void            addComponentShaderProgramNode(std::unique_ptr<ComponentShaderProgramNode> p_componentShaderProgramNode);
    void            addTransformNode(std::unique_ptr<TransformNode> p_transformNode);
    void            addCameraNode(std::unique_ptr<CameraNode> p_cameraNode);
    void            addPolygonMeshNode(std::unique_ptr<PolygonMeshNode> p_polygonMeshNode);

    //SET
    void            setDefaultSSPNode(SurfaceShaderProgramNode* p_surfaceShaderProgramNode);
    void            setRootTransformNode(TransformNode* p_rootTransformNode);
    void            setDefaultCameraNode(CameraNode* p_defaultCameraNode);

    //GET
    std::vector<std::unique_ptr<Node>>&             getAllNodeList();
    SurfaceShaderProgramNode&                       getDefaultSSPNode();
    TransformNode&                                  getRootTransformNode();
    const std::vector<SurfaceShaderProgramNode*>&   getSurfaceShaderProgramNodeList() const;
    const std::vector<ComponentShaderProgramNode*>& getComponentShaderProgramNodeList() const;

    //OTHER
    std::uint32_t   assignNodeID();
    void            removeNodeID(const std::uint32_t nodeID);

private:
    //SINGLETON
    ResourceManager();

private:
    std::vector<std::uint32_t>                  m_globalNodeIDList;

    std::vector<std::unique_ptr<Node>>          m_allNodeList;
    std::vector<Node*>                          m_undeletableNodeList;

    SurfaceShaderProgramNode*                   mp_defaultSSPNode;
    TransformNode*                              mp_rootTransformNode;
    CameraNode*                                 mp_defaultCameraNode;

    std::vector<SurfaceShaderProgramNode*>      m_surfaceShaderProgramNodeList;
    std::vector<ComponentShaderProgramNode*>    m_componentShaderProgramNodeList;
    std::vector<TransformNode*>                 m_transformNodeList;
    std::vector<CameraNode*>                    m_cameraNodeList;
    std::vector<PolygonMeshNode*>               m_polygonMeshNodeList;
};

/*----------------------------------------------------------------------------*/

inline std::vector<std::unique_ptr<Node>>& ResourceManager::getAllNodeList()
{
    return m_allNodeList;
}

inline SurfaceShaderProgramNode& ResourceManager::getDefaultSSPNode()
{
    return *mp_defaultSSPNode;
}

inline TransformNode& ResourceManager::getRootTransformNode()
{
    return *mp_rootTransformNode;
}

inline const std::vector<SurfaceShaderProgramNode*>& ResourceManager::getSurfaceShaderProgramNodeList() const
{
    return m_surfaceShaderProgramNodeList;
}

inline const std::vector<ComponentShaderProgramNode*>& ResourceManager::getComponentShaderProgramNodeList() const
{
    return m_componentShaderProgramNodeList;
}

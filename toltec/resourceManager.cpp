/*-----------------------------------------------------------------------------
*	CREATED:
*		14 IX 2016
*	CONTRIBUTORS:
*		PIOTR MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
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
*	CONSTRUCTOR
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
*	ADD SURFACE SHADER PROGRAM NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::addSurfaceShaderProgramNode(SurfaceShaderProgramNode* p_surfaceShaderProgramNode)
{
    //CHECK IF ALREADY ON THE LIST
    for (SurfaceShaderProgramNode* p_surfaceShaderProgramNodeListItem : m_surfaceShaderProgramNodeList)
        if (p_surfaceShaderProgramNodeListItem == p_surfaceShaderProgramNode)
            return;

    //ADD
    m_surfaceShaderProgramNodeList.push_back(p_surfaceShaderProgramNode);
    m_allNodeList.push_back(p_surfaceShaderProgramNode);
}

/*-----------------------------------------------------------------------------
*	ADD COMPONENT SHADER PROGRAM NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::addComponentShaderProgramNode(ComponentShaderProgramNode* p_componentShaderProgramNode)
{
    //CHECK IF ALREADY ON THE LIST
    for (ComponentShaderProgramNode* p_componentShaderProgramNodeListItem : m_componentShaderProgramNodeList)
        if (p_componentShaderProgramNodeListItem == p_componentShaderProgramNode)
            return;

    //ADD
    m_componentShaderProgramNodeList.push_back(p_componentShaderProgramNode);
    m_allNodeList.push_back(p_componentShaderProgramNode);
    m_undeletableNodeList.push_back(p_componentShaderProgramNode);
}

/*-----------------------------------------------------------------------------
*	ADD TRANSFORM NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::addTransformNode(TransformNode* p_transformNode)
{
    //CHECK IF ALREADY ON THE LIST
    for (TransformNode* p_transformNodeListItem : m_transformNodeList)
        if (p_transformNodeListItem == p_transformNode)
            return;

    //ADD
    m_transformNodeList.push_back(p_transformNode);
    m_allNodeList.push_back(p_transformNode);
}

/*-----------------------------------------------------------------------------
*	ADD POLYGON MESH NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::addPolygonMeshNode(PolygonMeshNode* p_polygonMeshNode)
{
    //CHECK IF ALREADY ON THE LIST
    for (PolygonMeshNode* p_polygonMeshNodeListItem : m_polygonMeshNodeList)
        if (p_polygonMeshNodeListItem == p_polygonMeshNode)
            return;

    //ADD
    m_polygonMeshNodeList.push_back(p_polygonMeshNode);
    m_allNodeList.push_back(p_polygonMeshNode);
}

/*-----------------------------------------------------------------------------
*	SET DEFAULT SHADER PROGRAM NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::setDefaultSSPNode(SurfaceShaderProgramNode* p_shaderProgramNode)
{
    if (mp_defaultSSPNode != nullptr)	//return if already assigned
        return;

    mp_defaultSSPNode = p_shaderProgramNode;

    m_surfaceShaderProgramNodeList.push_back(mp_defaultSSPNode);
    m_allNodeList.push_back(mp_defaultSSPNode);
    m_undeletableNodeList.push_back(mp_defaultSSPNode);
}

/*-----------------------------------------------------------------------------
*	SET ROOT TRANSFORM NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::setRootTransformNode(TransformNode* p_rootTransformNode)
{
    if (mp_rootTransformNode != nullptr)	//return if already assigned
        return;

    mp_rootTransformNode = p_rootTransformNode;

    m_transformNodeList.push_back(mp_rootTransformNode);
    m_allNodeList.push_back(mp_rootTransformNode);
    m_undeletableNodeList.push_back(mp_rootTransformNode);
}

/*-----------------------------------------------------------------------------
*	SET DEFAULT CAMERA NODE
*-----------------------------------------------------------------------------*/
void ResourceManager::setDefaultCameraNode(CameraNode* p_defaultCameraNode)
{
    if (mp_defaultCameraNode != nullptr)	//return if already assigned
        return;

    mp_defaultCameraNode = p_defaultCameraNode;

    m_cameraNodeList.push_back(mp_defaultCameraNode);
    m_allNodeList.push_back(mp_defaultCameraNode);
    m_undeletableNodeList.push_back(mp_defaultCameraNode);
}

/*-----------------------------------------------------------------------------
*	ASSIGN NODE ID
*-----------------------------------------------------------------------------*/
std::uint32_t ResourceManager::assignNodeID()
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
        return globalNodeIDListSize;
    }
}

/*-----------------------------------------------------------------------------
*	REMOVE NODE ID
*-----------------------------------------------------------------------------*/
void ResourceManager::removeNodeID(const std::uint32_t nodeID)
{
    if (nodeID < m_globalNodeIDList.size())
        m_globalNodeIDList[nodeID] = 0;
}

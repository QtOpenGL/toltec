/*-----------------------------------------------------------------------------
*   CREATED:
*       02 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "toltecOpenGLRendererResource.hpp"

#include <memory>
#include <iostream>

#include "nodes/cameraNode.hpp"
#include "nodes/polygonMeshNode.hpp"
#include "nodes/renderableObjectNode.hpp"
#include "nodes/sceneNode.hpp"
#include "nodes/shaders/surfaceShaderProgramNode.hpp"
#include "nodes/transformNode.hpp"
#include "resourceManager.hpp"
#include "renderingSystem/openGL/indexBuffer.hpp"
#include "renderingSystem/openGL/openGLViewport.hpp"
#include "renderingSystem/openGL/vertexBuffer.hpp"
#include "renderingSystem/toltec/openGL/cameraData.hpp"
#include "renderingSystem/toltec/openGL/renderableObject.hpp"
#include "renderingSystem/toltec/openGL/renderItem.hpp"
#include "renderingSystem/toltec/openGL/shaders/lambertShaderProgram.hpp"
#include "renderingSystem/toltec/openGL/shaders/shaderInstance.hpp"
#include "utils.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*-----------------------------------------------------------------------------*/
ToltecOpenGLRendererResource::ToltecOpenGLRendererResource()
    :
    m_activeViewportIndex(0)
{
}

/*-----------------------------------------------------------------------------
*   DESTRUCTOR
*-----------------------------------------------------------------------------*/
ToltecOpenGLRendererResource::~ToltecOpenGLRendererResource()
{
    this->deleteResources();
}

/*-----------------------------------------------------------------------------
*   ADD TO FINAL RENDER ITEM LIST
*-----------------------------------------------------------------------------*/
void ToltecOpenGLRendererResource::addToFinalRenderItemList(RenderItem* p_renderItem, 
    unsigned int viewportIndex)
{
    try
    {
        auto& finalRenderItemList = m_resourcePerViewportList.at(viewportIndex)->finalRenderItemList;
        finalRenderItemList.push_back(p_renderItem);
    }
    catch (std::out_of_range& e1)
    {
        DEBUG_ERR("Invalid viewport index!");
    }
}

/*-----------------------------------------------------------------------------
*   GET RENDERABLE OBJECT MAP
*-----------------------------------------------------------------------------*/
const std::map<node_id, std::unique_ptr<RenderableObject>>& 
ToltecOpenGLRendererResource::getRenderableObjectMap(unsigned int viewportIndex) const
{
    try
    {
        const auto& renderableObjectMap = m_resourcePerViewportList.at(viewportIndex)->renderableObjectMap;
        return renderableObjectMap;
    }
    catch (std::out_of_range& e1)
    {
        DEBUG_ERR("Invalid viewport index! Returning object at index 0.");
        const auto& renderableObjectMap = m_resourcePerViewportList.at(0)->renderableObjectMap;
        return renderableObjectMap;
    }
}

/*-----------------------------------------------------------------------------
*   GET FINAL RENDER ITEM LIST
*-----------------------------------------------------------------------------*/
const std::vector<RenderItem*>& ToltecOpenGLRendererResource::getFinalRenderItemList(unsigned int viewportIndex) const
{
    try
    {
        const auto& finalRenderItemList = m_resourcePerViewportList.at(viewportIndex)->finalRenderItemList;
        return finalRenderItemList;
    }
    catch (std::out_of_range& e1)
    {
        DEBUG_ERR("Invalid viewport index! Returning object at index 0.");
        const auto& finalRenderItemList = m_resourcePerViewportList.at(0)->finalRenderItemList;
        return finalRenderItemList;
    }
}

/*-----------------------------------------------------------------------------
*   INITIALIZE RESOURCES
*-----------------------------------------------------------------------------*/
void ToltecOpenGLRendererResource::initializeResources()
{
    if (m_areResourcesInitialized == false)
    {
        //MAKE SURE WE START WITH CLEAN SHEET
        this->deleteResources();

        //CREATE RESOURCES PER CONTEXT (VIEWPORT)
        std::size_t viewportListSize = m_viewportList.size();
        for (std::size_t i = 0; i < viewportListSize; i++)
        {
            //MAKE CONTEXT CURRENT
            gl::OpenGLViewport* p_viewport = dynamic_cast<gl::OpenGLViewport*>(m_viewportList[i]);
            if (p_viewport == nullptr)
            {
                DEBUG_ERR("AbstractViewport could not be casted to OpenGLViewport!");
                return;
            }
            p_viewport->makeCurrent();

            //CREATE RESOURCE
            m_resourcePerViewportList.push_back(
                std::move(std::make_unique<ToltecOpenGLRendererResource::ResourcePerViewport>()));
            m_activeViewportIndex = i;

            //CREATE SHADER PROGRAMS
            this->initializeShaderProgramMap();

            //SCAN SHADER PROGRAM LIST
            this->scanUserShaderProgramNodeList(true);

            //SCAN SCENE TREE
            std::vector<glm::mat4> modelMatrixList;
            int treeDepthLevel = 0;
            bool calculateFinalModelMatrixFlag = false;

            this->scanSceneTree(
                *ResourceManager::getInstance().getRootTransformNode(),
                treeDepthLevel,
                &modelMatrixList,
                calculateFinalModelMatrixFlag,
                true
            );

            //FINISH OPERATION ON CONTEXT
            p_viewport->doneCurrent();
        }
        //-->

        m_areResourcesInitialized = true;
    }
}

/*-----------------------------------------------------------------------------
*   DELETE RESOURCES
*-----------------------------------------------------------------------------*/
void ToltecOpenGLRendererResource::deleteResources()
{
    for (auto& resourcePerViewport : m_resourcePerViewportList)
        resourcePerViewport->finalRenderItemList.clear();
}

/*-----------------------------------------------------------------------------
*   CLEAR FINAL RENDER ITEM LIST
*-----------------------------------------------------------------------------*/
void ToltecOpenGLRendererResource::clearFinalRenderItemList(const int& viewportIndex)
{
    try
    {
        auto& finalRenderItemList = m_resourcePerViewportList.at(viewportIndex)->finalRenderItemList;
        finalRenderItemList.clear();
    }
    catch (std::out_of_range& e1)
    {
        DEBUG_ERR("Invalid viewport index!");
    }
}

/*-----------------------------------------------------------------------------
*   CLEAR ALL FINAL RENDER ITEM LISTS
*-----------------------------------------------------------------------------*/
void ToltecOpenGLRendererResource::clearAllFinalRenderItemLists()
{
    for (auto& resourcePerViewport : m_resourcePerViewportList)
        resourcePerViewport->finalRenderItemList.clear();
}

/*-----------------------------------------------------------------------------
*   INITIALIZE SHADER PROGRAM MAP
*-----------------------------------------------------------------------------*/
void ToltecOpenGLRendererResource::initializeShaderProgramMap()
{
    //LAMBERT SHADER PROGRAM
    std::unique_ptr<LambertShaderProgram> p_lambertShaderProgram(new LambertShaderProgram());
    m_resourcePerViewportList[m_activeViewportIndex]
        ->shaderProgramMap
        .insert(std::make_pair(
            core::nodes::Type::LAMBERT_SSP_NODE,
            std::move(p_lambertShaderProgram)
        ));
}

/*-----------------------------------------------------------------------------
*   SCAN USER SHADER PROGRAM NODE LIST
*-----------------------------------------------------------------------------*/
void ToltecOpenGLRendererResource::scanUserShaderProgramNodeList(const bool& initializeRendererResourceFlag)
{
    auto& userShaderProgramNodeList = ResourceManager::getInstance().getUserShaderProgramNodeList();
    auto& shaderProgramMap = m_resourcePerViewportList[m_activeViewportIndex]->shaderProgramMap;

    for (auto p_userShaderProgramNode : userShaderProgramNodeList)
    {
        //INITIALIZE
        if (initializeRendererResourceFlag == true ||
            p_userShaderProgramNode->getInitializeFlag() == true)
        {
            //If you find corresponding ShaderProgram in a shaderProgramMap (created
            //previously in a ToltecOpenGLRendererResource::initializeShaderProgramMap
            //function) then create ShaderInstance of this ShaderProgram and insert it
            //into shaderInstanceMap.

            auto iter = shaderProgramMap.find(p_userShaderProgramNode->getType());
            if (iter != shaderProgramMap.end())
            {
                m_resourcePerViewportList[m_activeViewportIndex]
                    ->shaderInstanceMap
                    .insert(std::make_pair(
                        p_userShaderProgramNode->getNodeID(),
                        iter->second->createShaderInstance()
                    ));
            }
        }

        //UPDATE
        else if (p_userShaderProgramNode->getUpdateFlag() == true)
        {
            //...
        }
    }
}

/*-----------------------------------------------------------------------------
*   SCAN SCENE TREE
*-----------------------------------------------------------------------------*/
void ToltecOpenGLRendererResource::scanSceneTree(
    core::nodes::TransformNode&     transformNode, 
    int&                            treeDepthLevel, 
    std::vector<glm::mat4>*         p_modelMatrixList, 
    bool&                           calculateFinalModelMatrixFlag, 
    const bool&                     initializeRendererResourceFlag)
{
    //COLLECTING MODEL MATRICES
    //clear model matrices from higher or same depth level branches
    if (p_modelMatrixList->size() > treeDepthLevel)
    {
        p_modelMatrixList->erase(
            p_modelMatrixList->begin() + treeDepthLevel, 
            p_modelMatrixList->end());
    }

    //add model matrix from current depth level
    p_modelMatrixList->push_back(transformNode.getModelMatrix());

    //decide if calculating final model matrix will be needed
    if (transformNode.getInitializeFlag() == true || transformNode.getUpdateFlag() == true)
        calculateFinalModelMatrixFlag = true;

    //CHECK CHILD LIST
    std::vector<core::nodes::SceneNode*> childList = transformNode.getChildList();
    for (core::nodes::SceneNode* p_sceneNode : childList)
    {
        //RECUR IF TransformNode DETECTED
        if (p_sceneNode->getType() == core::nodes::Type::TRANSFORM_NODE)
        {
            core::nodes::TransformNode* p_transformNode = 
                static_cast<core::nodes::TransformNode*>(p_sceneNode);
            treeDepthLevel++;

            this->scanSceneTree(*p_transformNode, treeDepthLevel, p_modelMatrixList, 
                calculateFinalModelMatrixFlag, initializeRendererResourceFlag);
            continue;
        }
        //-->

        //PROCESS RenderableObjectNode
        RenderableObject* p_renderableObject = nullptr;

        if (initializeRendererResourceFlag == true ||
            p_sceneNode->getInitializeFlag() == true ||
            p_sceneNode->getUpdateFlag() == true)
        {
            //PROCESS: CameraNode
            if (p_sceneNode->getType() == core::nodes::Type::CAMERA_NODE)
            {
                core::nodes::CameraNode* p_cameraNode =
                    static_cast<core::nodes::CameraNode*>(p_sceneNode);
                this->processCameraNode(p_cameraNode, p_renderableObject,
                    initializeRendererResourceFlag);
            }

            //PROCESS: PolygonMeshNode
            else if (p_sceneNode->getType() == core::nodes::Type::POLYGON_MESH_NODE)
            {
                core::nodes::PolygonMeshNode* p_polygonMeshNode = 
                    static_cast<core::nodes::PolygonMeshNode*>(p_sceneNode);
                this->processPolygonMeshNode(p_polygonMeshNode, p_renderableObject, 
                    initializeRendererResourceFlag);
            }

            //PROCESS: ...
            //else if ()
            //{

            //}
        }

        //CALCULATE AND APPLY FINAL MODEL MATRIX (IF NEEDED)
        if (initializeRendererResourceFlag == true || calculateFinalModelMatrixFlag == true)
        {
            if (p_renderableObject != nullptr)
            {
                glm::mat4 finalModelMatrix;
                for (const glm::mat4& modelMatrix : *p_modelMatrixList)
                    finalModelMatrix *= modelMatrix;

                p_renderableObject->setModelMatrixValue(finalModelMatrix);
            }
        }
    }
}

/*-----------------------------------------------------------------------------
*   PROCESS CAMERA NODE
*-----------------------------------------------------------------------------*/
void ToltecOpenGLRendererResource::processCameraNode(
    core::nodes::CameraNode*    p_CameraNode, 
    RenderableObject*           p_renderableObject, 
    const bool&                 initializeRendererResourceFlag)
{
    /*-----------------------------------------------------------------------------
    *   INITIALIZE
    *-----------------------------------------------------------------------------*/
    if (initializeRendererResourceFlag == true || p_CameraNode->getInitializeFlag() == true)
    {
        //CAMERA DATA
        auto& cameraDataMap = m_resourcePerViewportList[m_activeViewportIndex]->cameraDataMap;

        auto cameraDataMapIter = cameraDataMap.find(p_CameraNode->getNodeID());
        if (cameraDataMapIter == cameraDataMap.end())
        {
            //ADD TO CAMERA DATA MAP
            CameraData* p_cameraData = new CameraData();
            cameraDataMap.insert(std::make_pair(p_CameraNode->getNodeID(), p_cameraData));

            //GET CAMERA TRANSFORM NODE PROPERTIES
            glm::vec3 cameraPosition;
            glm::vec3 cameraLocalZ;

            core::nodes::TransformNode* p_cameraTranformNode =
                dynamic_cast<core::nodes::TransformNode*>(p_CameraNode->getParent());
            if (p_cameraTranformNode == nullptr)
            {
                DEBUG_ERR("Camera transform node not found! Default values assign instead."
                    "This will cause unwanted behaviour.");

                cameraPosition =    glm::vec3(0.0f, 0.0f, 0.0f);
                cameraLocalZ =      glm::vec3(0.0f, 0.0f, 1.0f);
            }
            else
            {
                cameraPosition =    p_cameraTranformNode->getTranslation();
                cameraLocalZ =      p_cameraTranformNode->getLocalZ();
            }

            //SETUP CAMERA DATA
            p_cameraData->setupPositionUniform(cameraPosition);
            p_cameraData->setupLocalZUniform(cameraLocalZ);
            p_cameraData->setupViewMatrixUniform(p_CameraNode->getViewMatrix());
            p_cameraData->setupProjectionMatrixUniform(p_CameraNode->getProjectionMatrix());
        }

        //RENDERABLE OBJECT
        auto& renderableObjectMap = m_resourcePerViewportList[m_activeViewportIndex]->renderableObjectMap;

        auto renderableObjectMapIter = renderableObjectMap.find(p_CameraNode->getNodeID());
        if (renderableObjectMapIter == renderableObjectMap.end())
        {
            //ADD TO THE RENDERABLE OBJECT MAP
            p_renderableObject = new RenderableObject();
            renderableObjectMap.insert(std::make_pair(p_CameraNode->getNodeID(), p_renderableObject));

            //CREATE VERTEX AND INDEX BUFFERS
            //vertex buffer
            std::vector<float> vertexPositionList;
            std::unique_ptr<gl::VertexBuffer> p_vertexPositionBuffer(new gl::VertexBuffer(
                gl::VertexBuffer::DataType::FLOAT,
                gl::VertexBuffer::Semantic::POSITION
            ));

            vertexPositionList = {
                -0.5f, -0.5f,  0.0f,        //0
                 0.5f, -0.5f,  0.0f,        //1
                 0.5f,  0.5f,  0.0f,        //2
                -0.5f,  0.5f,  0.0f,        //3
                 0.5f, -0.5f, -1.0f,        //4
                -0.5f, -0.5f, -1.0f,        //5
                -0.5f,  0.5f, -1.0f,        //6
                 0.5f,  0.5f, -1.0f,        //7

                -0.5f,  -0.5f,  0.5f,       //8
                 0.5f,  -0.5f,  0.5f,       //9
                 0.5f,   0.5f,  0.5f,       //10
                -0.5f,   0.5f,  0.5f,       //11
                 0.25f, -0.25f, 0.0f,       //12
                -0.25f, -0.25f, 0.0f,       //13
                -0.25f,  0.25f, 0.0f,       //14
                 0.25f,  0.25f, 0.0f        //15
            };

            //index buffer
            std::vector<std::uint32_t> edgeIndexList;
            std::unique_ptr<gl::IndexBuffer> p_edgeIndexBuffer(new gl::IndexBuffer(
                gl::IndexBuffer::DataType::UINT_32));

            edgeIndexList = {
                0, 1, 1, 2, 2, 3, 3, 0,             //rectangle 0
                4, 5, 5, 6, 6, 7, 7, 4,             //rectangle 1
                0, 5, 1, 4, 2, 7, 3, 6,             //lines connecting rectangles

                8, 9, 9, 10, 10, 11, 11, 8,         //rectangle 2
                12, 13, 13, 14, 14, 15, 15, 12,     //rectangle 3
                8, 13, 9, 12, 10, 15, 11, 14        //lines connecting rectangles
            };

            //UPDATE VERTEX AND INDEX BUFFERS
            p_vertexPositionBuffer->updateData(vertexPositionList);
            p_edgeIndexBuffer->updateData(edgeIndexList);

            //ADD VERTEX AND INDEX BUFFERS TO THE GEOMETRY
            tgl::Geometry& geometry = p_renderableObject->getGeometry();

            gl::IndexBuffer* p_edgeIndexBufferReference = p_edgeIndexBuffer.get();

            geometry.addVertexBuffer(std::move(p_vertexPositionBuffer));
            geometry.addIndexBuffer(std::move(p_edgeIndexBuffer));

            //CREATE RENDER ITEM
            ////find shader instance
            //auto& shaderInstanceMap = m_resourcePerViewportList[m_activeViewportIndex]->shaderInstanceMap;
            //ShaderInstance* p_shaderInstance = nullptr;

            //auto shaderInstanceMapIter = shaderInstanceMap.find(
            //  p_polygonMeshNode->getSurfaceShaderProgramNode()->getNodeID());

            //if (shaderInstanceMapIter != shaderInstanceMap.end())
            //  p_shaderInstance = shaderInstanceMapIter->second.get();
            //else
            //  p_shaderInstance = shaderInstanceMap.begin()->second.get();

            ////line
            //auto p_lineRenderItem = std::make_unique<RenderItem>(
            //  geometry.getVAOID(),
            //  p_edgeIndexBuffer->getID(),
            //  p_shaderInstace,
            //  RenderItem::DrawMode::LINES
            //);

            ////add
            //p_renderableObject->addRenderItem(std::move(p_lineRenderItem));
        }
    }

    /*-----------------------------------------------------------------------------
    *   UPDATE
    *-----------------------------------------------------------------------------*/
    else if (p_CameraNode->getUpdateFlag() == true)
    {
        //...
    }
}

/*-----------------------------------------------------------------------------
*   PROCESS POLYGON MESH NODE
*-----------------------------------------------------------------------------*/
void ToltecOpenGLRendererResource::processPolygonMeshNode(
    core::nodes::PolygonMeshNode*   p_polygonMeshNode, 
    RenderableObject*               p_renderableObject, 
    const bool&                     initializeRendererResourceFlag)
{
    /*-----------------------------------------------------------------------------
    *   INITIALIZE
    *-----------------------------------------------------------------------------*/
    if (initializeRendererResourceFlag == true || p_polygonMeshNode->getInitializeFlag() == true)
    {
        //RENDERABLE OBJECT
        auto& renderableObjectMap = m_resourcePerViewportList[m_activeViewportIndex]->renderableObjectMap;

        auto renderableObjectMapIter = renderableObjectMap.find(p_polygonMeshNode->getNodeID());
        if (renderableObjectMapIter == renderableObjectMap.end())
        {
            //ADD TO THE RENDERABLE OBJECT MAP
            p_renderableObject = new RenderableObject();
            renderableObjectMap.insert(std::make_pair(p_polygonMeshNode->getNodeID(), p_renderableObject));

            //CREATE VERTEX AND INDEX BUFFERS
            //vertex buffers
            std::vector<float> faceVertexPositionList;
            std::vector<float> faceVertexUVList;
            std::vector<float> faceVertexNormalList;

            std::unique_ptr<gl::VertexBuffer> p_vertexPositionBuffer(new gl::VertexBuffer(
                gl::VertexBuffer::DataType::FLOAT, 
                gl::VertexBuffer::Semantic::POSITION
            ));
            std::unique_ptr<gl::VertexBuffer> p_vertexUVBuffer(new gl::VertexBuffer(
                gl::VertexBuffer::DataType::FLOAT, 
                gl::VertexBuffer::Semantic::UV
            ));
            std::unique_ptr<gl::VertexBuffer> p_vertexNormalBuffer(new gl::VertexBuffer(
                gl::VertexBuffer::DataType::FLOAT, 
                gl::VertexBuffer::Semantic::NORMAL
            ));

            //index buffers
            std::uint32_t faceVertexIndexCount = 0;

            std::vector<std::uint32_t> faceIndexList;
            std::vector<std::uint32_t> edgeIndexList;
            std::vector<std::uint32_t> vertexIndexList;

            std::unique_ptr<gl::IndexBuffer> p_faceIndexBuffer(new gl::IndexBuffer(
                gl::IndexBuffer::DataType::UINT_32));
            std::unique_ptr<gl::IndexBuffer> p_edgeIndexBuffer(new gl::IndexBuffer(
                gl::IndexBuffer::DataType::UINT_32));
            std::unique_ptr<gl::IndexBuffer> p_vertexIndexBuffer(new gl::IndexBuffer(
                gl::IndexBuffer::DataType::UINT_32));

            //fetch and generate
            tpm::Mesh* p_mesh =                 p_polygonMeshNode->getMesh();
            tpm::FaceVertex* p_faceVertex =     nullptr;
            tpm::Vertex* p_vertex =             nullptr;

            for (const std::unique_ptr<tpm::Face>& p_face : p_mesh->getFaceList())
            {
                //fetch vertex attributes
                for (const std::uint32_t& faceVertexID : p_face->faceVertexIDList)
                {
                    p_faceVertex = p_mesh->getFaceVertexList()[faceVertexID].get();
                    p_vertex = p_mesh->getVertexList()[p_faceVertex->vertexID].get();

                    faceVertexPositionList.push_back(p_vertex->position.x);
                    faceVertexPositionList.push_back(p_vertex->position.y);
                    faceVertexPositionList.push_back(p_vertex->position.z);

                    faceVertexUVList.push_back(p_faceVertex->uv.x);
                    faceVertexUVList.push_back(p_faceVertex->uv.y);

                    faceVertexNormalList.push_back(p_faceVertex->normal.x);
                    faceVertexNormalList.push_back(p_faceVertex->normal.y);
                    faceVertexNormalList.push_back(p_faceVertex->normal.z);
                }

                //generate indices
                std::uint32_t firstFaceVertexIndexOfAFace =     faceVertexIndexCount;
                std::size_t numFaceVertices =                   p_face->faceVertexIDList.size();
                for (std::size_t i = 0; i < numFaceVertices; i++)
                {
                    //face index list
                    //This is the simplest triangulation algorithm that only works on a convex 
                    //polygons (it creates triangle fan). Maybe in the future I will implement
                    //something more robust.
                    if (i >= 2)
                    {
                        faceIndexList.push_back(firstFaceVertexIndexOfAFace);
                        faceIndexList.push_back(faceVertexIndexCount - 1);
                        faceIndexList.push_back(faceVertexIndexCount);
                    }

                    //edge index list
                    if (i < numFaceVertices - 1)
                    {
                        edgeIndexList.push_back(faceVertexIndexCount);
                        edgeIndexList.push_back(faceVertexIndexCount + 1);
                    }
                    else
                    {
                        edgeIndexList.push_back(faceVertexIndexCount);
                        edgeIndexList.push_back(firstFaceVertexIndexOfAFace);
                    }

                    //vertex index list
                    vertexIndexList.push_back(faceVertexIndexCount);
                    //->

                    faceVertexIndexCount++;
                }
            }

            //UPDATE VERTEX AND INDEX BUFFERS
            p_vertexPositionBuffer->updateData(faceVertexPositionList);
            //p_vertexUVBuffer->updateData(faceVertexUVList);
            //p_vertexNormalBuffer->updateData(faceVertexNormalList);           

            p_faceIndexBuffer->updateData(faceIndexList);
            //p_edgeIndexBuffer->updateData(edgeIndexList);
            //p_vertexIndexBuffer->updateData(vertexIndexList);

            //ADD VERTEX AND INDEX BUFFERS TO THE GEOMETRY
            tgl::Geometry& geometry = p_renderableObject->getGeometry();

            geometry.addVertexBuffer(std::move(p_vertexPositionBuffer));
            //geometry.addVertexBuffer(std::move(p_vertexUVBuffer));
            //geometry.addVertexBuffer(std::move(p_vertexNormalBuffer));
        
            gl::IndexBuffer* p_faceIndexBufferReference = p_faceIndexBuffer.get();
            gl::IndexBuffer* p_edgeIndexBufferReference = p_edgeIndexBuffer.get();
            gl::IndexBuffer* p_vertexIndexBufferReference = p_vertexIndexBuffer.get();

            geometry.addIndexBuffer(std::move(p_faceIndexBuffer));
            //geometry.addIndexBuffer(std::move(p_edgeIndexBuffer));
            //geometry.addIndexBuffer(std::move(p_vertexIndexBuffer));

            //CREATE RENDER ITEMS
            //find shader instance
            auto& shaderInstanceMap = m_resourcePerViewportList[m_activeViewportIndex]->shaderInstanceMap;
            ShaderInstance* p_shaderInstance = nullptr;

            auto shaderInstanceMapIter = shaderInstanceMap.find(
                p_polygonMeshNode->getSurfaceShaderProgramNode()->getNodeID());
            
            if (shaderInstanceMapIter != shaderInstanceMap.end())
                p_shaderInstance = shaderInstanceMapIter->second.get();
            else
                p_shaderInstance = shaderInstanceMap.begin()->second.get();

            ////point
            //RenderItem* p_pointRenderItem = new RenderItem(
            //  p_geometry->getVAOID(),
            //  vertexIndexBuffer.getID(),
            //  p_shaderInstace, 
            //  RenderItem::POINTS_DRAW_MODE
            //);
            ////line
            //RenderItem* p_pointRenderItem = new RenderItem(
            //  p_geometry->getVAOID(),
            //  edgeIndexBuffer.getID(),
            //  p_shaderInstace,
            //  RenderItem::LINES_DRAW_MODE
            //);
            //triangle
            std::unique_ptr<RenderItem> p_pointRenderItem(new RenderItem(
                geometry.getVAOID(),
                p_faceIndexBufferReference,
                p_shaderInstance
            ));

            //ADD RENDER ITEMS
            p_renderableObject->addRenderItem(std::move(p_pointRenderItem));
        }

    }

    /*-----------------------------------------------------------------------------
    *   UPDATE
    *-----------------------------------------------------------------------------*/
    else if (p_polygonMeshNode->getUpdateFlag() == true)
    {

    }
}
} //NAMESPACE: TGL

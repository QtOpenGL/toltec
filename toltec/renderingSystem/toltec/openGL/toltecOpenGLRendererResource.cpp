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

#include "nodes/polygonMeshNode.hpp"
#include "nodes/renderableObjectNode.hpp"
#include "nodes/sceneNode.hpp"
#include "nodes/shaders/surfaceShaderProgramNode.hpp"
#include "nodes/transformNode.hpp"
#include "resourceManager.hpp"
#include "renderingSystem/openGL/indexBuffer.hpp"
#include "renderingSystem/openGL/openGLViewport.hpp"
#include "renderingSystem/openGL/vertexBuffer.hpp"
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
                m_resourcePerViewportList.push_back(ResourcePerViewport());
                m_activeViewportIndex = i;

                //CREATE SHADER PROGRAMS
                this->initializeShaderProgramMap();

                //SCAN SCENE TREE
                std::vector<glm::mat4> modelMatrixList;
                int treeDepthLevel = 0;
                bool calculateFinalModelMatrixFlag = false;

                this->scanSceneTree(
                    ResourceManager::getInstance().getRootTransformNode(),
                    treeDepthLevel,
                    &modelMatrixList,
                    calculateFinalModelMatrixFlag,
                    true);

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
        {
            for (auto& kv : resourcePerViewport.renderableObjectMap)
                delete kv.second;

            for (auto& kv : resourcePerViewport.shaderInstanceMap)
                delete kv.second;

            resourcePerViewport.finalRenderItemList.clear();
        }
    }

    /*-----------------------------------------------------------------------------
    *   INITIALIZE SHADER PROGRAM MAP
    *-----------------------------------------------------------------------------*/
    void ToltecOpenGLRendererResource::initializeShaderProgramMap()
    {
        //CREATE
        LambertShaderProgram lambertShaderProgram;
    }

    /*-----------------------------------------------------------------------------
    *   SCAN SCENE TREE
    *-----------------------------------------------------------------------------*/
    void ToltecOpenGLRendererResource::scanSceneTree(TransformNode* p_transformNode, int& treeDepthLevel, 
        std::vector<glm::mat4>* p_modelMatrixList, bool& calculateFinalModelMatrixFlag, 
        const bool& initializeRendererResourceFlag)
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
        p_modelMatrixList->push_back(p_transformNode->getModelMatrix());

        //decide if calculating final model matrix will be needed
        if (p_transformNode->getInitializeFlag() == true || p_transformNode->getUpdateFlag() == true)
            calculateFinalModelMatrixFlag = true;

        //CHECK CHILD LIST
        std::vector<SceneNode*> childList = p_transformNode->getChildList();
        for (SceneNode* p_sceneNode : childList)
        {
            //RECUR IF TransformNode DETECTED
            if (p_sceneNode->getType() == Node::TRANSFORM_NODE)
            {
                p_transformNode = static_cast<TransformNode*>(p_sceneNode);
                treeDepthLevel++;

                this->scanSceneTree(p_transformNode, treeDepthLevel, p_modelMatrixList, 
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
                //PROCESS: PolygonMeshNode
                if (p_sceneNode->getType() == Node::POLYGON_MESH_NODE)
                {
                    PolygonMeshNode* p_polygonMeshNode = static_cast<PolygonMeshNode*>(p_sceneNode);
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
                glm::mat4 finalModelMatrix;
                for (glm::mat4& modelMatrix : *p_modelMatrixList)
                    finalModelMatrix *= modelMatrix;

                if (p_renderableObject != nullptr)
                    p_renderableObject->setModelMatrix(finalModelMatrix);
            }
        }
    }

    /*-----------------------------------------------------------------------------
    *   PROCESS POLYGON MESH NODE
    *-----------------------------------------------------------------------------*/
    void ToltecOpenGLRendererResource::processPolygonMeshNode(PolygonMeshNode* p_polygonMeshNode, 
        RenderableObject* p_renderableObject, const bool& initializeRendererResourceFlag)
    {
        /*-----------------------------------------------------------------------------
        *   INITIALIZE
        *-----------------------------------------------------------------------------*/
        if (initializeRendererResourceFlag == true || p_polygonMeshNode->getInitializeFlag() == true)
        {
            //ADD TO THE RENDERABLE OBJECT MAP
            auto& renderableObjectMap = m_resourcePerViewportList[m_activeViewportIndex].renderableObjectMap;

            auto renderableObjectMapIter = renderableObjectMap.find(p_polygonMeshNode->getNodeID());
            if (renderableObjectMapIter != renderableObjectMap.end())
                return;

            p_renderableObject = new RenderableObject();
            renderableObjectMap.insert(
                std::pair<std::uint32_t, RenderableObject*>(
                    p_polygonMeshNode->getNodeID(), p_renderableObject));

            //CREATE VERTEX AND INDEX BUFFERS
            tpm::Mesh* p_mesh = p_polygonMeshNode->getMesh();

            DEBUG_MSG(
                p_polygonMeshNode->getFullName() << std::endl <<
                "Face vertex list size: " << p_mesh->getFaceVertexList().size() << std::endl <<
                "Vertex list size: " << p_mesh->getVertexList().size() << std::endl <<
                "Face list size: " << p_mesh->getFaceList().size());

            tpm::FaceVertex* p_faceVertex = nullptr;
            tpm::Vertex* p_vertex = nullptr;

            //vertex buffers
            std::vector<float> faceVertexPositionList;
            std::vector<float> faceVertexUVList;
            std::vector<float> faceVertexNormalList;

            gl::VertexBuffer positionVertexBuffer(
                gl::VertexBuffer::DataType::FLOAT, 
                gl::VertexBuffer::Semantic::POSITION
            );
            gl::VertexBuffer uvVertexBuffer(
                gl::VertexBuffer::DataType::FLOAT, 
                gl::VertexBuffer::Semantic::UV
            );
            gl::VertexBuffer normalVertexBuffer(
                gl::VertexBuffer::DataType::FLOAT, 
                gl::VertexBuffer::Semantic::NORMAL
            );

            //index buffers
            std::uint32_t faceVertexIndexCount = 0;

            std::vector<std::uint32_t> faceIndexList;
            std::vector<std::uint32_t> edgeIndexList;
            std::vector<std::uint32_t> vertexIndexList;

            gl::IndexBuffer faceIndexBuffer(gl::IndexBuffer::DataType::UINT_32);
            gl::IndexBuffer edgeIndexBuffer(gl::IndexBuffer::DataType::UINT_32);
            gl::IndexBuffer vertexIndexBuffer(gl::IndexBuffer::DataType::UINT_32);

            //fetch and generate
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
            positionVertexBuffer.updateData(faceVertexPositionList);
            uvVertexBuffer.updateData(faceVertexUVList);
            normalVertexBuffer.updateData(faceVertexNormalList);

            faceIndexBuffer.updateData(faceIndexList);
            edgeIndexBuffer.updateData(edgeIndexList);
            vertexIndexBuffer.updateData(vertexIndexList);

            //ADD VERTEX AND INDEX BUFFERS TO THE GEOMETRY
            tgl::Geometry& geometry = p_renderableObject->getGeometry();

            geometry.addVertexBuffer(positionVertexBuffer);
            geometry.addVertexBuffer(uvVertexBuffer);
            geometry.addVertexBuffer(normalVertexBuffer);
                    
            geometry.addIndexBuffer(faceIndexBuffer);
            geometry.addIndexBuffer(edgeIndexBuffer);
            geometry.addIndexBuffer(vertexIndexBuffer);

            //CREATE RENDER ITEMS
            //find shader instance
            auto& shaderInstanceMap = m_resourcePerViewportList[m_activeViewportIndex].shaderInstanceMap;
            ShaderInstance* p_shaderInstance = nullptr;

            auto shaderInstanceMapIter = shaderInstanceMap.find(
                p_polygonMeshNode->getSurfaceShaderProgramNode()->getNodeID());
            
            if (shaderInstanceMapIter != shaderInstanceMap.end())
                p_shaderInstance = shaderInstanceMapIter->second;
            else
                p_shaderInstance = shaderInstanceMap.begin()->second;

            //triangle
            std::unique_ptr<RenderItem> p_pointRenderItem(new RenderItem(
                geometry.getVAOID(),
                faceIndexBuffer.getID(),
                p_shaderInstance,
                RenderItem::DrawMode::TRIANGLES
            ));
            ////line
            //RenderItem* p_pointRenderItem = new RenderItem(
            //  p_geometry->getVAOID(),
            //  edgeIndexBuffer.getID(),
            //  p_shaderInstace,
            //  RenderItem::LINES_DRAW_MODE
            //);
            ////point
            //RenderItem* p_pointRenderItem = new RenderItem(
            //  p_geometry->getVAOID(),
            //  vertexIndexBuffer.getID(),
            //  p_shaderInstace, 
            //  RenderItem::POINTS_DRAW_MODE
            //);

            //ADD RENDER ITEMS
            p_renderableObject->addRenderItem(std::move(p_pointRenderItem));
        }

        /*-----------------------------------------------------------------------------
        *   UPDATE
        *-----------------------------------------------------------------------------*/
        else if (p_polygonMeshNode->getUpdateFlag() == true)
        {

        }
    }
} //NAMESPACE: TGL

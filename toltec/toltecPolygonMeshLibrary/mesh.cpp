#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       10 IX 2016
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "mesh.hpp"

#include <algorithm>
#include <cstdlib>
#include <iterator>

#include "utils.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: TPM (TOLTEC POLYGON MESH)
*-----------------------------------------------------------------------------*/
namespace tpm
{
/*-----------------------------------------------------------------------------
*   ADD VERTEX
*   (const glm::vec3&)
*-----------------------------------------------------------------------------*/
const std::unique_ptr<Vertex>& Mesh::addVertex(const glm::vec3& point3D)
{
    std::unique_ptr<Vertex> p_vertex(new Vertex{ point3D });
    m_vertexList.push_back(std::move(p_vertex));

    return m_vertexList.back();
}

/*-----------------------------------------------------------------------------
*   ADD VERTEX
*   (float, float, float)
*-----------------------------------------------------------------------------*/
const std::unique_ptr<Vertex>& Mesh::addVertex(float x, float y, float z)
{
    glm::vec3 point3D(x, y, z);
    std::unique_ptr<Vertex> p_vertex(new Vertex{ point3D });
    m_vertexList.push_back(std::move(p_vertex));

    return m_vertexList.back();
}

/*-----------------------------------------------------------------------------
*   ADD FACE
*-----------------------------------------------------------------------------*/
const std::unique_ptr<Face>& Mesh::addFace(const std::vector<Vertex*>& vertexList)
{
    //ADD FACE
    std::unique_ptr<Face> p_face(new Face{});
    m_faceList.push_back(std::move(p_face));

    //ADD FACE VERTICES
    for (const auto& p_vertex : vertexList)
    {
        //CREATE FACE VERTEX
        std::unique_ptr<FaceVertex> p_faceVertex(new FaceVertex{});
        m_faceVertexList.push_back(std::move(p_faceVertex));
        std::size_t faceVertexIndex = m_faceVertexList.size() - 1;

        //FIND VERTEX
        std::size_t vertexIndex = 0;
        bool vertexFoundFlag = false;
        for (const auto& vertexListElement : m_vertexList)
        {
            if (vertexListElement.get() == p_vertex)
            {
                vertexFoundFlag = true;
                break;
            }

            vertexIndex++;
        }

        //vertex doesn't exist
        if (vertexFoundFlag == false)
        {
            //create a copy of passed vertex (without passing face vertex id list)
            std::unique_ptr<Vertex> p_newVertex(new Vertex{ p_vertex->position });
            m_vertexList.push_back(std::move(p_newVertex));

            //fetch index
            vertexIndex = m_vertexList.size() - 1;

            //add face vertex index to vertex
            m_vertexList.back()->faceVertexIDList.push_back(faceVertexIndex);
        }
        //vertex already exists
        else
        {
            //add face vertex index to vertex
            p_vertex->faceVertexIDList.push_back(faceVertexIndex);
        }

        //APPLY INDICES
        m_faceVertexList.back()->vertexID = std::uint32_t(vertexIndex);
        m_faceList.back()->faceVertexIDList.push_back(faceVertexIndex);
    }

    return m_faceList.back();
}
} //NAMESPACE: TPM
#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       10 IX 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <cstdint>
#include <vector>

#include <glm/glm.hpp>

/*-----------------------------------------------------------------------------
*   NAMESPACE: TPM (TOLTEC POLYGON MESH)
*-----------------------------------------------------------------------------*/
namespace tpm
{
    /*-----------------------------------------------------------------------------
    *   STRUCTS
    *-----------------------------------------------------------------------------*/
    struct FaceVertex {
        std::uint32_t               vertexID;
        glm::vec3                   normal;
        glm::vec2                   uv;
    };

    struct Vertex {
        glm::vec3                   position;
        std::vector<std::uint32_t>  faceVertexIDList;
    };

    struct Face {
        std::vector<std::uint32_t>  faceVertexIDList;
    };

    /*-----------------------------------------------------------------------------
    *   CLASS DECLARATIONS
    *   MESH
    *-----------------------------------------------------------------------------*/
    class Mesh
    {
    public:
        //CONSTRUCTORS
        virtual     ~Mesh();

        //ADD
        Vertex*     addVertex(const glm::vec3& point3D);
        Vertex*     addVertex(float x, float y, float z);
        Face*       addFace(const std::vector<Vertex*>& vertexList);

        //GET
        const std::vector<FaceVertex*>& getFaceVertexList() const;
        const std::vector<Vertex*>&     getVertexList() const;
        const std::vector<Face*>&       getFaceList() const;

        //OTHER
        void        zeroOutUVs();
        void        calcNormals();
        void        triangulate();
        void        collectGarbage();

    private:
        std::vector<FaceVertex*>    m_faceVertexList;
        std::vector<Vertex*>        m_vertexList;
        std::vector<Face*>          m_faceList;
    };

    /*----------------------------------------------------------------------------*/

    inline const std::vector<FaceVertex*>& Mesh::getFaceVertexList() const
    {
        return m_faceVertexList;
    }

    inline const std::vector<Vertex*>& Mesh::getVertexList() const
    {
        return m_vertexList;
    }

    inline const std::vector<Face*>& Mesh::getFaceList() const
    {
        return m_faceList;
    }
} //NAMESPACE: TPM
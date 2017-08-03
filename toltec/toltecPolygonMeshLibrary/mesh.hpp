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
#include <memory>
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
    virtual     ~Mesh() {}

    //ADD
    const std::unique_ptr<Vertex>&  addVertex(const glm::vec3& point3D);
    const std::unique_ptr<Vertex>&  addVertex(float x, float y, float z);
    const std::unique_ptr<Face>&    addFace(const std::vector<Vertex*>& vertexList);

    //GET
    const std::vector<std::unique_ptr<FaceVertex>>& getFaceVertexList() const;
    const std::vector<std::unique_ptr<Vertex>>&     getVertexList() const;
    const std::vector<std::unique_ptr<Face>>&       getFaceList() const;

    //OTHER
    void        zeroOutUVs();
    void        calcNormals();
    void        triangulate();
    void        collectGarbage();

private:
    std::vector<std::unique_ptr<FaceVertex>>    m_faceVertexList;
    std::vector<std::unique_ptr<Vertex>>        m_vertexList;
    std::vector<std::unique_ptr<Face>>          m_faceList;
};

/*----------------------------------------------------------------------------*/

inline const std::vector<std::unique_ptr<FaceVertex>>& Mesh::getFaceVertexList() const
{
    return m_faceVertexList;
}

inline const std::vector<std::unique_ptr<Vertex>>& Mesh::getVertexList() const
{
    return m_vertexList;
}

inline const std::vector<std::unique_ptr<Face>>& Mesh::getFaceList() const
{
    return m_faceList;
}
} //NAMESPACE: TPM
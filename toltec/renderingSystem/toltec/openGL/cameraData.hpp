#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       12 VIII 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       CameraData class holds all uniforms needed to render from specific 
*       view/angle: view matrix, projection matrix, position, orientation, etc. 
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <glm/glm.hpp>
#include "renderingSystem/openGL/uniformUnit.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   CAMERA DATA
*-----------------------------------------------------------------------------*/
class CameraData
{
public:
    //CTOR DTOR
                        CameraData();
    virtual             ~CameraData() {}

    //GET
    gl::UniformVec3     getPositionUniform() const;
    gl::UniformVec3     getLocalZUniform() const;
    gl::UniformMat4     getViewMatrixUniform() const;
    gl::UniformMat4     getProjectionMatrixUniform() const;

    //OTHER
    void                setupPositionUniform(const glm::vec3& position);
    void                setupLocalZUniform(const glm::vec3& localZ);
    void                setupViewMatrixUniform(const glm::mat4& viewMatrix);
    void                setupProjectionMatrixUniform(const glm::mat4& projectionMatrix);

private:
    gl::UniformVec3     m_positionUniform;
    gl::UniformVec3     m_localZUniform;            //aka camera direction
    gl::UniformMat4     m_viewMatrixUniform;
    gl::UniformMat4     m_projectionMatrixUniform;
};

/*----------------------------------------------------------------------------*/

inline gl::UniformVec3 CameraData::getPositionUniform() const
{
    return m_positionUniform;
}

inline gl::UniformVec3 CameraData::getLocalZUniform() const
{
    return m_localZUniform;
}

inline gl::UniformMat4 CameraData::getViewMatrixUniform() const
{
    return m_viewMatrixUniform;
}

inline gl::UniformMat4 CameraData::getProjectionMatrixUniform() const
{
    return m_projectionMatrixUniform;
}
} //NAMESPACE: TGL
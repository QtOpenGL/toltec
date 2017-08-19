/*-----------------------------------------------------------------------------
*   CREATED:
*       12 VIII 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "cameraData.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*-----------------------------------------------------------------------------*/
CameraData::CameraData()
    :
    m_positionUniform("g_cameraPosition"),
    m_localZUniform("g_cameraDirection"),
    m_viewMatrixUniform("g_viewMatrix"),
    m_projectionMatrixUniform("g_projectionMatrix")
{
}

/*-----------------------------------------------------------------------------
*   SETUP POSITION UNIFORM
*-----------------------------------------------------------------------------*/
void CameraData::setupPositionUniform(const glm::vec3& position)
{
    m_positionUniform.setValue(position);
}

/*-----------------------------------------------------------------------------
*   SETUP LOCAL Z UNIFORM
*-----------------------------------------------------------------------------*/
void CameraData::setupLocalZUniform(const glm::vec3 & localZ)
{
    m_localZUniform.setValue(localZ);
}

/*-----------------------------------------------------------------------------
*   SETUP VIEW MATRIX UNIFORM
*-----------------------------------------------------------------------------*/
void CameraData::setupViewMatrixUniform(const glm::mat4 & viewMatrix)
{
    m_viewMatrixUniform.setValue(viewMatrix);
}

/*-----------------------------------------------------------------------------
*   SETUP PROJECTION MATRIX UNIFORM
*-----------------------------------------------------------------------------*/
void CameraData::setupProjectionMatrixUniform(const glm::mat4 & projectionMatrix)
{
    m_projectionMatrixUniform.setValue(projectionMatrix);
}
} //NAMESPACE: TGL
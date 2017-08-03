/*-----------------------------------------------------------------------------
*   CREATED:
*       03 I 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/
#include "cameraNode.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include "transformNode.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: CORE
*-----------------------------------------------------------------------------*/
namespace core
{
/*-----------------------------------------------------------------------------
*   NAMESPACE: NODES
*-----------------------------------------------------------------------------*/
namespace nodes
{
/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*-----------------------------------------------------------------------------*/
CameraNode::CameraNode()
    :
    m_type(CameraNode::PERSPECTIVE_CAMERA),
    m_fieldOfView(glm::radians(54.0f)),
    m_orthographicArea(1.0f),
    m_zNear(0.1f),
    m_zFar(10000.0f),
    m_aspectRatio(1.0f),

    m_updatePerspectiveMatrixFlag(false),
    m_updateOrthographicMatrixFlag(false)
{
    //INITIALIZE
    this->setShortName("cameraNode");
    this->setType(nodes::Type::CAMERA_NODE);
}

/*-----------------------------------------------------------------------------
*   SET TYPE
*-----------------------------------------------------------------------------*/
void CameraNode::setCameraType(CameraNode::CameraType cameraType)
{
    m_type = cameraType;
}

/*-----------------------------------------------------------------------------
*   SET FIELD OF VIEW
*-----------------------------------------------------------------------------*/
void CameraNode::setFieldOfView(const float fieldOfView)
{
    m_fieldOfView =                     fieldOfView;
    m_updatePerspectiveMatrixFlag =     true;
}

/*-----------------------------------------------------------------------------
*   SET ORTHOGRAPHIC AREA
*-----------------------------------------------------------------------------*/
void CameraNode::setOrthographicArea(const float orthographicArea)
{
    m_orthographicArea =                orthographicArea;
    m_updateOrthographicMatrixFlag =    true;
}

/*-----------------------------------------------------------------------------
*   SET Z NEAR
*-----------------------------------------------------------------------------*/
void CameraNode::setZNear(const float zNear)
{
    m_zNear =                           zNear;
    m_updatePerspectiveMatrixFlag =     true;
    m_updateOrthographicMatrixFlag =    true;
}

/*-----------------------------------------------------------------------------
*   SET Z FAR
*-----------------------------------------------------------------------------*/
void CameraNode::setZFar(const float zFar)
{
    m_zFar =                            zFar;
    m_updatePerspectiveMatrixFlag =     true;
    m_updateOrthographicMatrixFlag =    true;
}

/*-----------------------------------------------------------------------------
*   GET PROJECTION MATRIX
*-----------------------------------------------------------------------------*/
const glm::mat4& CameraNode::getProjectionMatrix()
{
    switch (m_type) 
    {
    case CameraNode::PERSPECTIVE_CAMERA:
        if (m_updatePerspectiveMatrixFlag == true)
        {
            m_perspectiveMatrix = glm::perspective(m_fieldOfView, m_aspectRatio, m_zNear, m_zFar);
            m_updatePerspectiveMatrixFlag = false;
        }
        
        return m_perspectiveMatrix;
        break;

    case CameraNode::ORTHOGRAPHIC_CAMERA:
        if (m_updateOrthographicMatrixFlag == true)
        {
            m_orthographicMatrix = glm::ortho(
                -m_aspectRatio * m_orthographicArea,
                m_aspectRatio * m_orthographicArea,
                -1.0f * m_orthographicArea,
                1.0f * m_orthographicArea,
                m_zNear,
                m_zFar);
            m_updateOrthographicMatrixFlag = false;
        }

        return m_orthographicMatrix;
        break;

    default:
        return m_perspectiveMatrix;
        break;
    }
}

/*-----------------------------------------------------------------------------
*   GET PERSPECTIVE MATRIX
*-----------------------------------------------------------------------------*/
const glm::mat4& CameraNode::getPerspectiveMatrix()
{
    if (m_updatePerspectiveMatrixFlag == true)
    {
        m_perspectiveMatrix = glm::perspective(m_fieldOfView, m_aspectRatio, m_zNear, m_zFar);
        m_updatePerspectiveMatrixFlag = false;
    }

    return m_perspectiveMatrix;
}

/*-----------------------------------------------------------------------------
*   GET ORTHOGRAPHIC MATRIX
*-----------------------------------------------------------------------------*/
const glm::mat4& CameraNode::getOrthographicMatrix()
{
    if (m_updateOrthographicMatrixFlag == true)
    {
        m_orthographicMatrix = glm::ortho(
            -m_aspectRatio * m_orthographicArea,
            m_aspectRatio * m_orthographicArea,
            -1.0f * m_orthographicArea,
            1.0f * m_orthographicArea,
            m_zNear,
            m_zFar);
        m_updatePerspectiveMatrixFlag = false;
    }

    return m_perspectiveMatrix;
}

/*-----------------------------------------------------------------------------
*   UPDATE VIEW MATRIX
*   ()
*-----------------------------------------------------------------------------*/
void CameraNode::updateViewMatrix()
{
    TransformNode* p_transformNode = dynamic_cast<TransformNode*>(this->getParent());
    m_viewMatrix = glm::lookAt(
        p_transformNode->getTranslation(), 
        p_transformNode->getTargetPosition(), 
        p_transformNode->getLocalY());
}

/*-----------------------------------------------------------------------------
*   UPDATE VIEW MATRIX
*   (const glm::vec3&, const glm::vec3&, const glm::vec3&)
*-----------------------------------------------------------------------------*/
void CameraNode::updateViewMatrix(const glm::vec3& cameraPosition, const glm::vec3& targetPosition, 
    const glm::vec3& localY)
{
    m_viewMatrix = glm::lookAt(cameraPosition, targetPosition, localY);
}

/*-----------------------------------------------------------------------------
*   UPDATE PERSPECTIVE MATRIX
*-----------------------------------------------------------------------------*/
void CameraNode::updatePerspectiveMatrix(const float aspectRatio)
{
    m_aspectRatio = aspectRatio;

    m_perspectiveMatrix = glm::perspective(m_fieldOfView, m_aspectRatio, m_zNear, m_zFar);
    m_updatePerspectiveMatrixFlag = false;
}

/*-----------------------------------------------------------------------------
*   UPDATE ORTHOGRAPHIC MATRIX
*-----------------------------------------------------------------------------*/
void CameraNode::updateOrthographicMatrix(const float aspectRatio)
{
    m_aspectRatio = aspectRatio;

    m_orthographicMatrix = glm::ortho(
        -m_aspectRatio * m_orthographicArea,
        m_aspectRatio * m_orthographicArea,
        -1.0f * m_orthographicArea,
        1.0f * m_orthographicArea,
        m_zNear, 
        m_zFar);
    m_updatePerspectiveMatrixFlag = false;
}
} //NAMESPACE: NODES
} //NAMESPACE: CORE
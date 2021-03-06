/*-----------------------------------------------------------------------------
*   CREATED:
*       14 IX 2016
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "transformNode.hpp"

#include <cstddef>
#include "utils.hpp"

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
TransformNode::TransformNode()
    :
    m_translation(glm::vec3(0.0f, 0.0f, 0.0f)),
    m_rotation(glm::vec3(0.0f, 0.0f, 0.0f)),
    m_scale(glm::vec3(1.0f, 1.0f, 1.0f)),

    m_updateModelMatrixFlag(false),

    m_localX(glm::vec3(1.0f, 0.0f, 0.0f)),
    m_localY(glm::vec3(0.0f, 1.0f, 0.0f)),
    m_localZ(glm::vec3(0.0f, 0.0f, 1.0f)),

    m_targetPosition(glm::vec3(0.0f, 0.0f, 1.0f))
{
    //INITIALIZE
    this->setName("transformNode");
    this->setType(nodes::Type::TRANSFORM_NODE);
    m_modelMatrix = utils::calcModelMatrix(m_translation, m_rotation, m_scale);
}

/*-----------------------------------------------------------------------------
*   SET TRANSLATION
*   (const glm::vec3&)
*-----------------------------------------------------------------------------*/
void TransformNode::setTranslation(const glm::vec3& translation)
{
    m_translation =             translation;
    m_updateModelMatrixFlag =   true;
}

/*-----------------------------------------------------------------------------
*   SET TRANSLATION
*   (float, float, float)
*-----------------------------------------------------------------------------*/
void TransformNode::setTranslation(float x, float y, float z)
{
    m_translation =             glm::vec3(x, y, z);
    m_updateModelMatrixFlag =   true;
}

/*-----------------------------------------------------------------------------
*   SET ROTATION
*   (const glm::vec3& rotation)
*-----------------------------------------------------------------------------*/
void TransformNode::setRotation(const glm::vec3& rotation)
{
    m_rotation =                rotation;
    m_updateModelMatrixFlag =   true;
}

/*-----------------------------------------------------------------------------
*   SET ROTATION
*   (float, float, float)
*-----------------------------------------------------------------------------*/
void TransformNode::setRotation(float x, float y, float z)
{
    m_rotation =                glm::vec3(x, y, z);
    m_updateModelMatrixFlag =   true;
}

/*-----------------------------------------------------------------------------
*   SET SCALE
*   (float)
*-----------------------------------------------------------------------------*/
void TransformNode::setScale(float uniformScale)
{
    m_scale =                   glm::vec3(uniformScale);
    m_updateModelMatrixFlag =   true;
}

/*-----------------------------------------------------------------------------
*   SET SCALE
*   (const glm::vec3& rotation)
*-----------------------------------------------------------------------------*/
void TransformNode::setScale(const glm::vec3& scale)
{
    m_scale =                   scale;
    m_updateModelMatrixFlag =   true;
}

/*-----------------------------------------------------------------------------
*   SET SCALE
*   (float, float, float)
*-----------------------------------------------------------------------------*/
void TransformNode::setScale(float x, float y, float z)
{
    m_scale =                   glm::vec3(x, y, z);
    m_updateModelMatrixFlag =   true;
}

/*-----------------------------------------------------------------------------
*   GET MODEL MATRIX
*-----------------------------------------------------------------------------*/
const glm::mat4& TransformNode::getModelMatrix()
{
    if (m_updateModelMatrixFlag == true)
    {
        m_modelMatrix =             utils::calcModelMatrix(m_translation, m_rotation, m_scale);
        m_updateModelMatrixFlag =   false;
    }

    return m_modelMatrix;
}
} //NAMESPACE: NODES
} //NAMESPACE: CORE
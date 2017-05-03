#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       30 VIII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       TransformNode class holds main model matrix that any vertex of a
*       partcular object can be multiply with in order to place it in world 
*       coordinates.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <vector>
#include <glm/glm.hpp>

#include "sceneNode.hpp"

/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   TRANSFORM NODE
*-----------------------------------------------------------------------------*/
class TransformNode : public SceneNode
{
public:
    //CONSTRUCTORS
                TransformNode();
    virtual     ~TransformNode() {}

    //ADD
    void        addChild(SceneNode* p_sceneNode);

    //REMOVE
    bool        removeChild(SceneNode* p_sceneNode);

    //SET
    void        setTranslation(const glm::vec3& translation);
    void        setTranslation(float x, float y, float z);
    void        setRotation(const glm::vec3& rotation);
    void        setRotation(float x, float y, float z);
    void        setScale(float uniformScale);
    void        setScale(const glm::vec3& scale);
    void        setScale(float x, float y, float z);

    //GET
    const std::vector<SceneNode*>&  getChildList() const;

    const glm::mat4&                getModelMatrix();

    const glm::vec3&                getTranslation() const;
    const glm::vec3&                getRotation() const;
    const glm::vec3&                getScale() const;

    const glm::vec3&                getLocalX() const;
    const glm::vec3&                getLocalY() const;
    const glm::vec3&                getLocalZ() const;

    const glm::vec3&                getTargetPosition() const;

private:
    std::vector<SceneNode*> m_childList;

    bool                    m_updateModelMatrixFlag;
    glm::mat4               m_modelMatrix;

    glm::vec3   
        m_translation,
        m_rotation,
        m_scale,

        m_localX,
        m_localY,
        m_localZ,

        m_targetPosition;
};

/*----------------------------------------------------------------------------*/

inline const std::vector<SceneNode*>& TransformNode::getChildList() const
{
    return m_childList;
}

inline const glm::vec3& TransformNode::getTranslation() const
{
    return m_translation;
}

inline const glm::vec3& TransformNode::getRotation() const
{
    return m_rotation;
}

inline const glm::vec3& TransformNode::getScale() const
{
    return m_scale;
}

inline const glm::vec3& TransformNode::getLocalX() const
{
    return m_localX;
}

inline const glm::vec3 & TransformNode::getLocalY() const
{
    return m_localY;
}

inline const glm::vec3 & TransformNode::getLocalZ() const
{
    return m_localZ;
}

inline const glm::vec3 & TransformNode::getTargetPosition() const
{
    return m_targetPosition;
}

#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       18 VIII 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <glm/glm.hpp>
#include "shaderProgramNode.hpp"

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
*   CLASS DECLARATIONS
*   CAMERA SHADER PROGRAM NODE
*-----------------------------------------------------------------------------*/
class CameraShaderProgramNode : public ShaderProgramNode
{
public:
    //CONSTRUCTORS
                CameraShaderProgramNode();
    virtual     ~CameraShaderProgramNode() {}

    //SET
    void        setColor(const glm::vec3& color);
    void        setColor(float r, float g, float b);

    //GET
    const glm::vec3&    getColor() const;

private:
    glm::vec3   m_color;
};

/*----------------------------------------------------------------------------*/

inline const glm::vec3& CameraShaderProgramNode::getColor() const
{
    return m_color;
}
} //NAMESPACE: NODES
} //NAMESPACE: CORE

#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       13 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ComponentShaderProgramNode is a base class for all shaders programs 
*       that apply to any geometric components (vertices, edges, faces, etc.)
*       as well as other stuff like object linear shapes representation 
*       (cameras, lights, joints, etc.), particles, pivots, manipulators
*       and many, many more.
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
*   COMPONENT SHADER PROGRAM NODE
*-----------------------------------------------------------------------------*/
class ComponentShaderProgramNode : public ShaderProgramNode
{
public:
    //CTOR DTOR
                ComponentShaderProgramNode();
    virtual     ~ComponentShaderProgramNode() {}

    //SET
    void        setColor(const glm::vec3& color);
    void        setColor(float r, float g, float b);

    //GET
    const glm::vec3&    getColor() const;

private:
    glm::vec3   m_color;
};

/*----------------------------------------------------------------------------*/

inline const glm::vec3& ComponentShaderProgramNode::getColor() const
{
    return m_color;
}
} //NAMESPACE: NODES
} //NAMESPACE: CORE

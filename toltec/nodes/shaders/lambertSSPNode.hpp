#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       09 I 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <glm/glm.hpp>

#include "surfaceShaderProgramNode.hpp"

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class TextureNode;

/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   LAMBERT SURFACE SHADER PROGRAM NODE
*-----------------------------------------------------------------------------*/
class LambertSSPNode : public SurfaceShaderProgramNode
{
public:
    //CONSTRUCTORS
                LambertSSPNode();
    virtual     ~LambertSSPNode() {}

private:
    glm::vec3       m_diffuseColor;
    TextureNode*    mp_diffuseMap;
    glm::vec3       m_transparencyColor;
    TextureNode*    mp_transparencyMap;
    glm::vec3       m_ambientColor;
    TextureNode*    mp_ambientMap;

    TextureNode*    mp_bumpMap;
};
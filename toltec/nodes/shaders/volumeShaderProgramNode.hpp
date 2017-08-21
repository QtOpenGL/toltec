#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       11 I 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       VolumeShaderProgramNode is a base class for all shaders programs that
*       mimics fluid look from the inside (water, fog, etc.).
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
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
*   VOLUME SHADER PROGRAM NODE
*-----------------------------------------------------------------------------*/
class VolumeShaderProgramNode : public ShaderProgramNode
{
public:
    //CTOR DTOR
                VolumeShaderProgramNode();
    virtual     ~VolumeShaderProgramNode() {}

private:
    //...
};
} //NAMESPACE: NODES
} //NAMESPACE: CORE

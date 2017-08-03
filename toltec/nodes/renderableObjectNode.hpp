#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       12 IX 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       RenderableObjectNode is a base class for all nodes that can be 
*       rendered inside the viewport.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "sceneNode.hpp"

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
*   RENDERABLE OBJECT NODE
*-----------------------------------------------------------------------------*/
class RenderableObjectNode : public SceneNode
{
public:
    //CONSTRUCTORS
                    RenderableObjectNode();
    virtual         ~RenderableObjectNode() {}

private:
    //...
};
} //NAMESPACE: NODES
} //NAMESPACE: CORE
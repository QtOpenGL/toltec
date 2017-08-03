/*-----------------------------------------------------------------------------
*   CREATED:
*       15 IX 2016
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "sceneNode.hpp"

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
SceneNode::SceneNode()
    :
    mp_parent(nullptr)
{
    //INITIALIZE
    this->setShortName("sceneNode");
    this->setType(nodes::Type::SCENE_NODE);
}

/*-----------------------------------------------------------------------------
*   SET PARENT NODE
*-----------------------------------------------------------------------------*/
void SceneNode::setParent(SceneNode* p_parent)
{
    //CHECK
    //Parent pointer will be only assigned if the parent is a TransformNode object.
    //Renderable object nodes can not be parents.
    TransformNode* p_transformNode = dynamic_cast<TransformNode*>(p_parent);
    if (p_transformNode == nullptr)
        return;

    if (mp_parent == p_parent)
        return;

    //SET PARENT
    mp_parent = p_parent;

    //ADD CHILD
    p_transformNode->addChild(this);
}
} //NAMESPACE: NODES
} //NAMESPACE: CORE
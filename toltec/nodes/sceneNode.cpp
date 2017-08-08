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

#include <algorithm>

#include "nodes/renderableObjectNode.hpp"
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
SceneNode::SceneNode()
    :
    mp_parent(nullptr)
{
    //INITIALIZE
    this->setName("sceneNode");
    this->setType(nodes::Type::SCENE_NODE);
}

/*-----------------------------------------------------------------------------
*   SET PARENT
*-----------------------------------------------------------------------------*/
void SceneNode::setParent(SceneNode* p_parent)
{
    //CHECK
    if (p_parent == nullptr)
        return;

    if (mp_parent == p_parent)
        return;

    if (dynamic_cast<RenderableObjectNode*>(p_parent) != nullptr) 
        return;     //RenderableObjectNode is not allowed to be a parent.

    //CLEAN PREVIOUS PARENT
    if (mp_parent != nullptr)
    {
        auto iter = std::find(mp_parent->getChildList().begin(), mp_parent->getChildList().end(), this);
        if (iter != mp_parent->getChildList().end())
            mp_parent->getChildList().erase(iter);
        else
            DEBUG_ERR("Parent does not have this child!");
    }

    //SET UP NEW PARENT
    mp_parent = p_parent;
    p_parent->getChildList().push_back(this);
}
} //NAMESPACE: NODES
} //NAMESPACE: CORE
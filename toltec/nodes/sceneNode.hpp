#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       30 VIII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       SceneNode class represnet base class for all nodes that will be 
*       placed and rendered in the viewport.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <vector>
#include "node.hpp"

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
*   SCENE NODE
*-----------------------------------------------------------------------------*/
class SceneNode : public Node
{
public:
    //CTOR DTOR
                    SceneNode();
    virtual         ~SceneNode() {}

    //SET
    void            setParent(SceneNode* p_parent);

    //GET
    SceneNode*                  getParent();
    std::vector<SceneNode*>&    getChildList();

private:
    SceneNode*                  mp_parent;
    std::vector<SceneNode*>     m_childList;
};

/*----------------------------------------------------------------------------*/

inline SceneNode* SceneNode::getParent()
{
    return mp_parent;
}

inline std::vector<SceneNode*>& SceneNode::getChildList()
{
    return m_childList;
}

} //NAMESPACE: NODES
} //NAMESPACE: CORE

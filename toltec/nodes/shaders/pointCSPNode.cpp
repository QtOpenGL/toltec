/*-----------------------------------------------------------------------------
*   CREATED:
*       13 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "pointCSPNode.hpp"

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
PointCSPNode::PointCSPNode()
    :
    m_size(1)
{
    //INITIALIZE
    this->setName("pointComponentShader");
    this->setType(nodes::Type::POINT_CSP_NODE);
}

/*-----------------------------------------------------------------------------
*   SET SIZE
*-----------------------------------------------------------------------------*/
void PointCSPNode::setSize(unsigned int size)
{
    m_size;
}
} //NAMESPACE: NODES
} //NAMESPACE: CORE
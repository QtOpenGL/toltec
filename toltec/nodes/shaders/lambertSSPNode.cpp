/*-----------------------------------------------------------------------------
*   CREATED:
*       09 I 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "lambertSSPNode.hpp"

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
LambertSSPNode::LambertSSPNode()
    :
    m_diffuseColor(glm::vec3(0.5f, 0.5f, 0.5f)),
    mp_diffuseMap(nullptr),
    m_transparencyColor(glm::vec3(0.0f, 0.0f, 0.0f)),
    mp_transparencyMap(nullptr),
    m_ambientColor(glm::vec3(0.0f, 0.0f, 0.0f)),
    mp_ambientMap(nullptr),

    mp_bumpMap(nullptr)
{
    //INITIALIZE
    this->setShortName("lambertShader");
    this->setType(nodes::Type::LAMBERT_SSP_NODE);
}
} //NAMESPACE: NODES
} //NAMESPACE: CORE
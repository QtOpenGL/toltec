/*-----------------------------------------------------------------------------
*   CREATED:
*       21 VIII 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "attributeConnector.hpp"

#include "nodes/abstractAttribute.hpp"

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
AttributeConnector::AttributeConnector(
    AbstractAttribute*                  p_inputAttribute, 
    AbstractAttribute*                  p_outputAttribute,
    AttributeConnector::ConnectionType  connectionType)
    :
    mp_inputAttribute(p_inputAttribute),
    mp_outputAttribute(p_outputAttribute),
    m_connectionType(connectionType)
{
    //SETUP
    mp_inputAttribute->setOutputConnection(this);
    mp_outputAttribute->setInputConnection(this);
}

/*-----------------------------------------------------------------------------
*   DESTRUCTOR
*-----------------------------------------------------------------------------*/
AttributeConnector::~AttributeConnector()
{
    mp_inputAttribute->setOutputConnection(nullptr);
    mp_outputAttribute->setInputConnection(nullptr);
}
} //NAMESPACE: NODES
} //NAMESPACE: CORE

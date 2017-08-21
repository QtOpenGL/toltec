#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       21 VIII 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       AttributeConnector is a link object between attributes of different 
*       nodes. It should NOT be created by the user, instead there is a method 
*       in ResourceManager called setAttributeConnection.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
//...

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
namespace core
{
    namespace nodes
    {
        class AbstractAttribute;
    }
}

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
*   ATTRIBUTE CONNECTOR
*-----------------------------------------------------------------------------*/
class AttributeConnector
{
public:
    //TYPES
    enum ConnectionType {
        UNIT,
        CONTAINER
    };

    //CTOR DTOR
                AttributeConnector(
                    AbstractAttribute*                  p_inputAttribute, 
                    AbstractAttribute*                  p_outputAttribute,
                    AttributeConnector::ConnectionType  connectionType);
    virtual     ~AttributeConnector();

private:
    AttributeConnector::ConnectionType  m_connectionType;

    AbstractAttribute*                  mp_inputAttribute;
    AbstractAttribute*                  mp_outputAttribute;
};
} //NAMESPACE: NODES
} //NAMESPACE: CORE

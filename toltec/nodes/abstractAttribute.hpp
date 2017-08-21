#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       21 VIII 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ...
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
        class AttributeConnector;
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
*   ABSTRACT ATTRIBUTE
*-----------------------------------------------------------------------------*/
class AbstractAttribute
{
public:
    //TYPES
    enum Classification {
        UNIT,
        CONTAINER
    };

    enum Type {
        BOOL,
        DOUBLE,
        FLOAT,
        INT
    };

    //CTOR DTOR
                AbstractAttribute();
    virtual     ~AbstractAttribute() = 0;

    //SET
    //...

    //GET
    const AbstractAttribute::Classification&    getClassification() const;
    const AbstractAttribute::Type&              getType() const;

private:
    AttributeConnector*                         mp_inputConnection;
    AttributeConnector*                         mp_outputConnection;

protected:
    AbstractAttribute::Classification           m_classification;
    AbstractAttribute::Type                     m_type;
};

/*----------------------------------------------------------------------------*/

inline const AbstractAttribute::Classification& AbstractAttribute::getClassification() const
{
    return m_classification;
}

inline const AbstractAttribute::Type& AbstractAttribute::getType() const
{
    return m_type;
}
} //NAMESPACE: NODES
} //NAMESPACE: CORE

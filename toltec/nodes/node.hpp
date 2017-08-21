#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       30 VIII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       Base class for the node system.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <cstdint>
#include <string>

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
*   TYPES
*-----------------------------------------------------------------------------*/
enum Type {
    NODE,

    SCENE_NODE,
    TRANSFORM_NODE,
    RENDERABLE_OBJECT_NODE,
    SURFACE_NODE,
    POLYGON_MESH_NODE,
    CAMERA_NODE,

    SHADER_PROGRAM_NODE,
    SURFACE_SHADER_PROGRAM_NODE,
    LAMBERT_SSP_NODE,
    VOLUME_SHADER_PROGRAM_NODE,
    COMPONENT_SHADER_PROGRAM_NODE,
    POINT_CSP_NODE,
    LINE_CSP_NODE,
    PLANE_CSP_NODE
};

/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   NODE
*-----------------------------------------------------------------------------*/
class Node
{
public:
    //CTOR DTOR
                            Node();
    virtual                 ~Node();

    //SET
    void                    setName(const std::string& name);
    void                    setInitializeFlag(bool value);
    void                    setUpdateFlag(bool value);

    //GET
    const std::string&      getName() const;
    const node_id&      getNodeID() const;
    std::string             getFullName() const;
    nodes::Type             getType() const;

    bool                    getInitializeFlag() const;
    bool                    getUpdateFlag() const;

protected:
    void                    setType(nodes::Type type);

private:
    std::string             m_name;
    const node_id           m_id;
    nodes::Type             m_type;

    bool                    m_initializeFlag;
    bool                    m_updateFlag;
};

/*----------------------------------------------------------------------------*/

inline const std::string& Node::getName() const
{
    return m_name;
}

inline const node_id& Node::getNodeID() const
{
    return m_id;
}

inline nodes::Type Node::getType() const
{
    return m_type;
}

inline bool Node::getInitializeFlag() const
{
    return m_initializeFlag;
}

inline bool Node::getUpdateFlag() const
{
    return m_updateFlag;
}
} //NAMESPACE: NODES
} //NAMESPACE: CORE

#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		30 VIII 2016
*	CONTRIBUTORS:
*		PIOTR MAKAL
*	INFO:
*		Base class for the node system.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <cstdint>
#include <string>

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	NODE
*-----------------------------------------------------------------------------*/
class Node
{
public:
    //TYPES
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

    //CONSTRUCTORS
                            Node();
    virtual					~Node();

    //SET
    void					setShortName(const std::string& shortName);
    void					setInitializeFlag(bool value);
    void					setUpdateFlag(bool value);

    //GET
    const std::string&		getShortName() const;
    const std::uint32_t&	getNodeID() const;
    std::string				getFullName() const;
    Node::Type				getType() const;

    bool					getInitializeFlag() const;
    bool					getUpdateFlag() const;

protected:
    void					setType(Node::Type type);

private:
    std::string				m_shortName;
    const std::uint32_t		m_id;
    Node::Type				m_type;

    bool					m_initializeFlag;
    bool					m_updateFlag;
};

/*----------------------------------------------------------------------------*/

inline const std::string& Node::getShortName() const
{
    return m_shortName;
}

inline const std::uint32_t& Node::getNodeID() const
{
    return m_id;
}

inline Node::Type Node::getType() const
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

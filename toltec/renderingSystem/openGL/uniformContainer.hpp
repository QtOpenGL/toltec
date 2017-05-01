#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		25 II 2017
*	CONTRIBUTORS:
*		Piotr Makal
*	INFO:
*		UniformContainer class is a base class for three types of 
*		uniform containers: uniform, uniform array and uniform struct.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <string>

/*-----------------------------------------------------------------------------
*	NAMESPACE: GL (OPENGL)
*-----------------------------------------------------------------------------*/
namespace gl
{
    /*-----------------------------------------------------------------------------
    *	CLASS DECLARATIONS
    *	UNIFORM CONTAINER
    *-----------------------------------------------------------------------------*/
    class UniformContainer
    {
    public:
        //TYPES
        enum ContainerType {
            NONE_TYPE,
            SINGLE_TYPE,
            ARRAY_TYPE,
            STRUCT_TYPE
        };

        //CONSTRUCTORS
        explicit		UniformContainer(const std::string& name);
        virtual			~UniformContainer() {}

        //GET
        UniformContainer::ContainerType		getContainerType() const;
        const std::string&					getName() const;

    protected:
        UniformContainer::ContainerType		m_containerType;
        std::string							m_name;
    };

    /*----------------------------------------------------------------------------*/

    inline UniformContainer::ContainerType UniformContainer::getContainerType() const
    {
        return m_containerType;
    }

    inline const std::string& UniformContainer::getName() const
    {
        return m_name;
    }
} //NAMESPACE: GL
#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       25 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       Aggregate classes for uniforms.
*       
*       IMPORTANT: UniformArray class doesn't allow to create two or more 
*       dimensional arrays!
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <memory>
#include <vector>

#include <glbinding/gl/functions.h>
#include <glbinding/gl/types.h>

#include "renderingSystem/openGL/uniform.hpp"
#include "renderingSystem/openGL/uniformUnit.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: GL (OPENGL)
*-----------------------------------------------------------------------------*/
namespace gl
{
    /*-----------------------------------------------------------------------------
    *   CLASS DECLARATIONS
    *   UNIFORM CONTAINER
    *-----------------------------------------------------------------------------*/
    class UniformContainer : public Uniform
    {
    public:
        //TYPES
        enum Type {
            NONE,
            ARRAY,
            STRUCT
        };

        //CONSTRUCTORS
        explicit        UniformContainer(const std::string& name);
        virtual         ~UniformContainer() {}

        //ADD
        virtual void    addUniform(std::unique_ptr<Uniform> p_uniform, gl::GLuint shaderProgramID) {}

        //GET
        UniformContainer::Type      getType() const;

        //OTHER
        virtual void    findLocations(const std::string& baseUniformName, gl::GLuint shaderProgramID) {}
        virtual void    update() const;

    protected:
        UniformContainer::Type                  m_type;
        std::vector<std::unique_ptr<Uniform>>   m_uniformList;
    };

    /*----------------------------------------------------------------------------*/

    inline UniformContainer::Type UniformContainer::getType() const
    {
        return m_type;
    }

    /*-----------------------------------------------------------------------------
    *   UNIFORM ARRAY
    *-----------------------------------------------------------------------------*/
    class UniformArray : public UniformContainer
    {
    public:
        //CONSTRUCTORS
        explicit        UniformArray(const std::string& name);
        virtual         ~UniformArray() {}

        //ADD
        virtual void    addUniform(std::unique_ptr<Uniform> p_uniform, gl::GLuint shaderProgramID);

        //OTHER
        virtual void    findLocations(const std::string& baseUniformName, gl::GLuint shaderProgramID);

    private:
        UniformContainer::Type      m_arrayTypeContainer;
        UniformUnit::Type           m_arrayTypeUnit;
    };

    /*-----------------------------------------------------------------------------
    *   UNIFORM STRUCT
    *-----------------------------------------------------------------------------*/
    class UniformStruct : public UniformContainer
    {
    public:
        //CONSTRUCTORS
        explicit        UniformStruct(const std::string& name);
        virtual         ~UniformStruct() {}

        //ADD
        virtual void    addUniform(std::unique_ptr<Uniform> p_uniform, gl::GLuint shaderProgramID);

        //OTHER
        virtual void    findLocations(const std::string& baseUniformName, gl::GLuint shaderProgramID);
    };
} //NAMESPACE: GL
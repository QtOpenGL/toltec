#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       25 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <vector>
#include "renderingSystem/openGL/uniform.hpp"

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
        ////TYPES
        //enum Type {
        //  TYPE_NONE,
        //  TYPE_ARRAY,
        //  TYPE_STRUCT
        //};

        //CONSTRUCTORS
        explicit        UniformContainer(const std::string& name);
        virtual         ~UniformContainer() {}

    protected:
        std::vector<Uniform> m_uniformList;
    };

    /*-----------------------------------------------------------------------------
    *   UNIFORM ARRAY
    *-----------------------------------------------------------------------------*/
    class UniformArray : public UniformContainer
    {
    public:
        //CONSTRUCTORS
        explicit        UniformArray(const std::string& name);
        virtual         ~UniformArray() {}
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
    };
} //NAMESPACE: GL
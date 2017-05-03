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
#include <string>

/*-----------------------------------------------------------------------------
*   NAMESPACE: GL (OPENGL)
*-----------------------------------------------------------------------------*/
namespace gl
{
    /*-----------------------------------------------------------------------------
    *   CLASS DECLARATIONS
    *   UNIFORM
    *-----------------------------------------------------------------------------*/
    class Uniform
    {
    public:
        //TYPES
        enum Classification {
            CLASSIFICATION_NONE,
            CLASSIFICATION_UNIT,
            CLASSIFICATION_CONTAINER
        };

        //CONSTRUCTORS
        explicit        Uniform(const std::string& name);
        virtual         ~Uniform() {}

        //GET
        Uniform::Classification     getClassification() const;
        const std::string&          getName() const;

    protected:
        Uniform::Classification     m_classification;
        std::string                 m_name;
    };

    /*----------------------------------------------------------------------------*/

    inline Uniform::Classification Uniform::getClassification() const
    {
        return m_classification;
    }

    inline const std::string& Uniform::getName() const
    {
        return m_name;
    }
} //NAMESPACE: GL
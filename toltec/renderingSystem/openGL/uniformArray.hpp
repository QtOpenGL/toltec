#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		25 II 2017
*	CONTRIBUTORS:
*		Piotr Makal
*	INFO:
*		...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <vector>
#include "renderingSystem/openGL/uniformContainer.hpp"

/*-----------------------------------------------------------------------------
*	NAMESPACE: GL (OPENGL)
*-----------------------------------------------------------------------------*/
namespace gl
{
    /*-----------------------------------------------------------------------------
    *	CLASS DECLARATIONS
    *	UNIFORM ARRAY
    *-----------------------------------------------------------------------------*/
    class UniformArray : public UniformContainer
    {
    public:
        //CONSTRUCTORS
        explicit		UniformArray(const std::string& name);
        virtual			~UniformArray() {}

    private:
        std::vector<UniformContainer*>		m_uniformContainerList;
    };
} //NAMESPACE: GL
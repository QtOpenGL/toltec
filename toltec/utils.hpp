#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       28 VII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       General utilities used across the program.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <iostream>
#include <string>

#include <glm/fwd.hpp>

/*-----------------------------------------------------------------------------
*   MACROS
*-----------------------------------------------------------------------------*/
#ifdef DEBUG_BUILD

#define DEBUG_MSG(x) do                 \
{                                       \
    std::cout << "<DEBUG> " << x << std::endl;      \
} while (false)                         

#define DEBUG_ERR(x) do                                                             \
{                                                                                   \
    std::cerr << __FILE__ << "(" << __LINE__ << ")<ERROR> " << x << std::endl;      \
} while (false)

#else
#define DEBUG_MSG(x) do {} while (false)
#define DEBUG_ERR(x) do {} while (false)
#endif

/*-----------------------------------------------------------------------------
*   NAMESPACE: UTILS
*-----------------------------------------------------------------------------*/
namespace utils
{
    /*-----------------------------------------------------------------------------
    *   FUNCTION DECLARATIONS
    *-----------------------------------------------------------------------------*/
    const std::string& loadTextFile(const std::string& filePath);

    glm::mat4 calcModelMatrix(const glm::vec3& translation, const glm::vec3& rotation,
        const glm::vec3& scale);
    glm::vec3 rotate(const glm::vec3& point, const glm::vec3& xyzAngles);
    glm::vec3 rotate(const glm::vec3& point, float xAngle, float yAngle, float zAngle);
    glm::vec3 rotate(const glm::vec3& point, float angle, const glm::vec3& rotationVector);
} //NAMESPACE: UTILS


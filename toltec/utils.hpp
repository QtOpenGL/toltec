#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		28 VII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		General utilities used across the program.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <iostream>
#include <glm/fwd.hpp>

/*-----------------------------------------------------------------------------
*	MACROS
*-----------------------------------------------------------------------------*/
#ifdef DEBUG_BUILD
#define DEBUG_MSG(x) do { std::cerr << __FILE__ << "(" << __LINE__ << ") : " << x << "\n"; } \
	while (false)
#else
#define DEBUG_MSG(x) do {} while (false)
#endif

/*-----------------------------------------------------------------------------
*	NAMESPACE: UTILS
*-----------------------------------------------------------------------------*/
namespace utils
{
	/*-----------------------------------------------------------------------------
	*	FUNCTION DECLARATIONS
	*-----------------------------------------------------------------------------*/
	glm::mat4 calcModelMatrix(const glm::vec3& translation, const glm::vec3& rotation,
		const glm::vec3& scale);
	glm::vec3 rotate(const glm::vec3& point, const glm::vec3& xyzAngles);
	glm::vec3 rotate(const glm::vec3& point, float xAngle, float yAngle, float zAngle);
	glm::vec3 rotate(const glm::vec3& point, float angle, const glm::vec3& rotationVector);
} //NAMESPACE: UTILS


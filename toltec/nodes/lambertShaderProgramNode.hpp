#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		09 I 2017
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <glm/glm.hpp>

#include "node.hpp"

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class TextureNode;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	LAMBERT SHADER PROGRAM NODE
*-----------------------------------------------------------------------------*/
class LambertShaderProgramNode : public Node
{
public:
	//CONSTRUCTORS
				LambertShaderProgramNode();
	virtual		~LambertShaderProgramNode() {}

private:
	glm::vec3		m_diffuseColor;
	TextureNode*	mp_diffuseMap;
	glm::vec3		m_transparencyColor;
	TextureNode*	mp_transparencyMap;
	glm::vec3		m_ambientColor;
	TextureNode*	mp_ambientMap;

	TextureNode*	mp_bumpMap;
};
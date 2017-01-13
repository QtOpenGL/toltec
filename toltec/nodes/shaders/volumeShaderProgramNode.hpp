#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		11 I 2017
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		VolumeShaderProgramNode is a base class for all shaders programs that
*		mimics fluid look from the inside (water, fog, etc.).
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "shaderProgramNode.hpp"

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	VOLUME SHADER PROGRAM NODE
*-----------------------------------------------------------------------------*/
class VolumeShaderProgramNode : public ShaderProgramNode
{
public:
	//CONSTRUCTORS
				VolumeShaderProgramNode();
	virtual		~VolumeShaderProgramNode() {}

private:
	//...
};
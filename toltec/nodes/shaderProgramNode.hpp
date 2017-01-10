#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		09 I 2017
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		Base class for all shader programs.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "node.hpp"

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	SHADER PROGRAM NODE
*-----------------------------------------------------------------------------*/
class ShaderProgramNode : public Node
{
public:
	//CONSTRUCTORS
				ShaderProgramNode();
	virtual		~ShaderProgramNode() {}

private:
	//...
};
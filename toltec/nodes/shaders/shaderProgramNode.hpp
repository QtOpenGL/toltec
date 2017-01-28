#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		09 I 2017
*	CONTRIBUTORS:
*		PIOTR MAKAL
*	INFO:
*		Base class for all shader programs.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "nodes/node.hpp"

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
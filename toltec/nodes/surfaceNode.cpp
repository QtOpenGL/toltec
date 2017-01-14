/*-----------------------------------------------------------------------------
*	CREATED:
*		13 I 2017
*	CONTRIBUTORS:
*		PETER MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "surfaceNode.hpp"

#include "nodes/shaders/lambertSSPNode.hpp"
#include "resourceManager.hpp"

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*-----------------------------------------------------------------------------*/
SurfaceNode::SurfaceNode()
	:
	mp_surfaceShaderProgram(nullptr)
{
	//INITIALIZE
	this->setShortName("surfaceNode");
	this->setSurfaceShaderProgram(ResourceManager::getInstance().getDefaultSSPNode());
}

/*-----------------------------------------------------------------------------
*	SET SURFACESHADER PROGRAM
*-----------------------------------------------------------------------------*/
void SurfaceNode::setSurfaceShaderProgram(SurfaceShaderProgramNode* p_surfaceShaderProgram)
{
	//CHECK
	if (p_surfaceShaderProgram == mp_surfaceShaderProgram)
		return;

	//REMOVE / SET / ADD
	if (p_surfaceShaderProgram == nullptr)
	{
		mp_surfaceShaderProgram = ResourceManager::getInstance().getDefaultSSPNode();
		mp_surfaceShaderProgram->addSurface(this, true);
	}
	else
	{
		if (mp_surfaceShaderProgram != nullptr)
			mp_surfaceShaderProgram->removeSurface(this, true);
		mp_surfaceShaderProgram = p_surfaceShaderProgram;
		mp_surfaceShaderProgram->addSurface(this, true);
	}
}

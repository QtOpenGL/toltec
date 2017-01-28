#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		04 VIII 2016
*	CONTRIBUTORS:
*		PIOTR MAKAL
*	INFO:
*		...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
//...

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	ABSTRACT RENDERER RESOURCE
*-----------------------------------------------------------------------------*/
class AbstractRendererResource
{
public:
	//CONSTRUCTORS
					AbstractRendererResource();
	virtual			~AbstractRendererResource() {}

	//OTHER
	virtual void	initializeResources() = 0;
	virtual void	updateResources() = 0;
	virtual void	deleteResources() = 0;

protected:
	bool			m_areResourcesInitialized;

private:
	//...
};
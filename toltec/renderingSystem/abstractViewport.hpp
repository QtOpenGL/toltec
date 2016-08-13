#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		02 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		AbstractViewport class is a base class for all viewports and holds
*		common interface for them.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <QtWidgets/qopenglwidget.h>
#include "renderingSystem/renderingAPI.hpp"

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class AbstractRenderer;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	ABSTRACT VIEWPORT
*-----------------------------------------------------------------------------*/
class AbstractViewport : public QOpenGLWidget //THIS INHARITANCE SHOULD BE CHANGE IN THE FUTURE!
{
public:
	//CONSTRUCTORS
				AbstractViewport();
	virtual		~AbstractViewport() {}

	//SET
	void				setRenderer(AbstractRenderer* p_renderer);

	//GET
	AbstractRenderer*	getRenderer() const;
	RenderingAPI::Type	getType() const;

protected:
	AbstractRenderer*	mp_renderer;
	RenderingAPI::Type	m_type;
};

/*----------------------------------------------------------------------------*/

inline AbstractRenderer* AbstractViewport::getRenderer() const
{
	return mp_renderer;
}

inline RenderingAPI::Type AbstractViewport::getType() const
{
	return m_type;
}

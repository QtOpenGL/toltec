/*-----------------------------------------------------------------------------
*	CREATED:
*		07 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderingSystem/abstractViewport.hpp"

#include <QtGui/qevent.h>
#include "events/globalEventFilter.hpp"
#include "utils.hpp"

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*-----------------------------------------------------------------------------*/
AbstractViewport::AbstractViewport()
	:
	m_type(RenderingAPI::UNSPECIFIED_API),
	mp_renderer(nullptr),
	mp_camera(nullptr),

	m_isLeftMouseButtonPressed(false),
	m_isMiddleMouseButtonPressed(false),
	m_isRightMouseButtonPressed(false),

	m_mouseLocalXPosition(0),
	m_mouseLocalYPosition(0),
	m_mouseRelativeXPosition(0),
	m_mouseRelativeYPosition(0),

	m_mouseSensitivity(1.0f)
{
}

/*-----------------------------------------------------------------------------
*	MOUSE PRESS EVENT
*-----------------------------------------------------------------------------*/
void AbstractViewport::mousePressEvent(QMouseEvent* p_mouseEvent)
{
	switch (p_mouseEvent->button())
	{
	case Qt::LeftButton:
		m_isLeftMouseButtonPressed = true;
		break;
	case Qt::MiddleButton:		
		m_isMiddleMouseButtonPressed = true;
		break;
	case Qt::RightButton:		
		m_isRightMouseButtonPressed = true;
		break;
	}
}

/*-----------------------------------------------------------------------------
*	MOUSE RELEASE EVENT
*-----------------------------------------------------------------------------*/
void AbstractViewport::mouseReleaseEvent(QMouseEvent* p_mouseEvent)
{
	switch (p_mouseEvent->button())
	{
	case Qt::LeftButton:		
		m_isLeftMouseButtonPressed = false;
		break;
	case Qt::MiddleButton:		
		m_isMiddleMouseButtonPressed = false;
		break;
	case Qt::RightButton:		
		m_isRightMouseButtonPressed = false;
		break;
	}
}

/*-----------------------------------------------------------------------------
*	MOUSE MOVE EVENT
*-----------------------------------------------------------------------------*/
void AbstractViewport::mouseMoveEvent(QMouseEvent* p_mouseEvent)
{
	m_mouseRelativeXPosition =	m_mouseLocalXPosition - p_mouseEvent->localPos().x();
	m_mouseRelativeYPosition =	m_mouseLocalYPosition - p_mouseEvent->localPos().y();
	m_mouseLocalXPosition =		p_mouseEvent->localPos().x();
	m_mouseLocalYPosition =		p_mouseEvent->localPos().y();

	//CAMERA MOVEMENT
	//tumble
	if (GlobalEventFilter::isAltPressed() && m_isLeftMouseButtonPressed)
		this->tumble(-m_mouseRelativeXPosition, -m_mouseRelativeYPosition);
	//track
	else if (GlobalEventFilter::isAltPressed() && m_isMiddleMouseButtonPressed)
		this->track(-m_mouseRelativeXPosition, -m_mouseRelativeYPosition);
	//dolly
	else if (GlobalEventFilter::isAltPressed() && m_isRightMouseButtonPressed)
		this->dolly(-m_mouseRelativeXPosition, -m_mouseRelativeYPosition);
}

/*-----------------------------------------------------------------------------
*	SET RENDERER
*-----------------------------------------------------------------------------*/
void AbstractViewport::setRenderer(AbstractRenderer* p_renderer)
{
	mp_renderer = p_renderer;
}

/*-----------------------------------------------------------------------------
*	SET CAMERA
*-----------------------------------------------------------------------------*/
void AbstractViewport::setCamera(TransformNode* p_camera)
{
	mp_camera = p_camera;
}

/*-----------------------------------------------------------------------------
*	TUMBLE
*-----------------------------------------------------------------------------*/
void AbstractViewport::tumble(int x, int y)
{
}

/*-----------------------------------------------------------------------------
*	TRACK
*-----------------------------------------------------------------------------*/
void AbstractViewport::track(int x, int y)
{
}

/*-----------------------------------------------------------------------------
*	DOLLY
*-----------------------------------------------------------------------------*/
void AbstractViewport::dolly(int x, int y)
{
}

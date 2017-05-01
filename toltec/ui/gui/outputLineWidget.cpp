/*-----------------------------------------------------------------------------
*	CREATED:
*		10 VIII 2016
*	CONTRIBUTORS:
*		PIOTR MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "ui/gui/outputLineWidget.hpp"

#include <QtGui/qbrush.h>
#include <QtGui/qpainter.h>
#include <QtGui/qpen.h>

/*-----------------------------------------------------------------------------
*	STATIC
*-----------------------------------------------------------------------------*/
//CONSTANTS
//private
const QColor OutputLineWidget::ms_MESSAGE_COLOR =	QColor(0, 0, 0);
const QColor OutputLineWidget::ms_WARNING_COLOR =	QColor(120, 80, 0);
const QColor OutputLineWidget::ms_ERROR_COLOR =		QColor(160, 0, 0);

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*-----------------------------------------------------------------------------*/
OutputLineWidget::OutputLineWidget()
    :
    m_text("..."),
    m_messageColor(ms_MESSAGE_COLOR)
{
}

/*-----------------------------------------------------------------------------
*	PAINT EVENT
*-----------------------------------------------------------------------------*/
void OutputLineWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    //LOAD PARAMETERS
    int x =			this->rect().x();
    int y =			this->rect().y();
    int width =		this->rect().width();
    int height =	this->rect().height();

    //DRAW
    //background
    painter.setPen(Qt::NoPen);
    painter.setBrush(m_messageColor);
    painter.drawRect(this->rect());

    //text
    painter.setPen(QPen(QColor(200, 200, 200)));
    painter.setBrush(Qt::NoBrush);
    painter.drawText(x+6, y, width, height, (Qt::AlignLeft | Qt::AlignVCenter), m_text.c_str());
}

/*-----------------------------------------------------------------------------
*	SET TEXT
*-----------------------------------------------------------------------------*/
void OutputLineWidget::setText(const std::string& text, OutputLineWidget::MessageType messageType)
{
    m_text = text;

    switch (messageType) 
    {
    case OutputLineWidget::NORMAL_MESSAGE:
        m_messageColor = ms_MESSAGE_COLOR;
        break;
    case OutputLineWidget::WARNING_MESSAGE:
        m_messageColor = ms_WARNING_COLOR;
        break;
    case OutputLineWidget::ERROR_MESSAGE:
        m_messageColor = ms_ERROR_COLOR;
        break;
    }
}

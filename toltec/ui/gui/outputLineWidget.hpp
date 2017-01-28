#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		09 VIII 2016
*	CONTRIBUTORS:
*		PIOTR MAKAL
*	INFO:
*		OutputLineWidget is a class for displaying information inside of a GUI 
*		of the program. It can spit normal messages as well as warnings and
*		erros giving a user proper color hint with those.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <string>

#include <QtGui/qcolor.h>
#include <QtGui/qevent.h>
#include <QtWidgets/qwidget.h>

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	OUTPUT LINE WIDGET
*-----------------------------------------------------------------------------*/
class OutputLineWidget : public QWidget
{
public:
	//TYPES
	enum MessageType {
		NORMAL_MESSAGE,
		WARNING_MESSAGE,
		ERROR_MESSAGE
	};

	//(CON/DE)STRUCTORS
					OutputLineWidget();
	virtual			~OutputLineWidget() {}

	//EVENTS
	virtual void	paintEvent(QPaintEvent* event);

	//SET
	void			setText(
		const std::string& text, 
		OutputLineWidget::MessageType messageType = OutputLineWidget::NORMAL_MESSAGE);

private:
	static const QColor
		ms_MESSAGE_COLOR,
		ms_WARNING_COLOR,
		ms_ERROR_COLOR;

	std::string		m_text;
	QColor			m_messageColor;
};
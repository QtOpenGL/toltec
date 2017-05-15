#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       09 VIII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       OutputLineWidget is a class for displaying information inside of a GUI 
*       of the program. It can spit normal messages as well as warnings and
*       erros giving a user proper color hint with those.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <string>

#include <QtGui/qcolor.h>
#include <QtGui/qevent.h>
#include <QtWidgets/qwidget.h>

/*-----------------------------------------------------------------------------
*   NAMESPACE: GUI
*-----------------------------------------------------------------------------*/
namespace gui
{
    /*-----------------------------------------------------------------------------
    *   CLASS DECLARATIONS
    *   OUTPUT LINE WIDGET
    *-----------------------------------------------------------------------------*/
    class OutputLineWidget : public QWidget
    {
    public:
        //TYPES
        enum MessageType {
            NORMAL,
            WARNING,
            ERROR
        };

        //(CON/DE)STRUCTORS
                        OutputLineWidget();
        virtual         ~OutputLineWidget() {}

        //EVENTS
        virtual void    paintEvent(QPaintEvent* event);

        //SET
        void            setText(
                            const std::string& text, 
                            OutputLineWidget::MessageType messageType = OutputLineWidget::MessageType::NORMAL);

    private:
        static const QColor
                        ms_MESSAGE_COLOR,
                        ms_WARNING_COLOR,
                        ms_ERROR_COLOR;

        std::string     m_text;
        QColor          m_messageColor;
    };
}
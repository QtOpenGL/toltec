/*-----------------------------------------------------------------------------
*   CREATED:
*       21 IX 2016
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "globalEventFilter.hpp"

#include <QtGui/qevent.h>
#include "utils.hpp"

/*-----------------------------------------------------------------------------
*   STATIC VARIABLES
*-----------------------------------------------------------------------------*/
//PRIVATE
bool GlobalEventFilter::ms_isAltPressed = false;

/*-----------------------------------------------------------------------------
*   EVENT FILTER
*-----------------------------------------------------------------------------*/
bool GlobalEventFilter::eventFilter(QObject* p_qObject, QEvent* p_qEvent)
{
    QKeyEvent* p_keyEvent;

    switch (p_qEvent->type())
    {
    /*-----------------------------------------------------------------------------
    *   KEY PRESS
    *-----------------------------------------------------------------------------*/
    case QEvent::KeyPress:
        p_keyEvent = static_cast<QKeyEvent*>(p_qEvent);

        switch (p_keyEvent->key())
        {
        case Qt::Key_Alt:           //ALT
            ms_isAltPressed = true;
            return true;
            break;
        }
        break;

    /*-----------------------------------------------------------------------------
    *   KEY RELEASE
    *-----------------------------------------------------------------------------*/
    case QEvent::KeyRelease:
        p_keyEvent = static_cast<QKeyEvent*>(p_qEvent);

        switch (p_keyEvent->key())
        {
        case Qt::Key_Alt:           //ALT
            ms_isAltPressed = false;
            return true;
            break;
        }
    }

    return false;
}
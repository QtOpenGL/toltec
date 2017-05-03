#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       21 IX 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <QtCore/qobject.h>

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class QEvent;

/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   GLOBAL EVENT FILTER
*-----------------------------------------------------------------------------*/
class GlobalEventFilter : public QObject
{
    Q_OBJECT

public:
    //CONSTRUCTOR
    virtual         ~GlobalEventFilter() {}

    //EVENTS
    virtual bool    eventFilter(QObject* p_qObject, QEvent* p_qEvent);

    //STATIC
    static bool     isAltPressed();

private:
    //STATIC
    static bool     ms_isAltPressed;
};

/*----------------------------------------------------------------------------*/

inline bool GlobalEventFilter::isAltPressed()
{
    return ms_isAltPressed;
}
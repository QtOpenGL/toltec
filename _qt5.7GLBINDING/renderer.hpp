#pragma once

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <iostream>

#include <QtCore/qcoreapplication.h>
#include <QtCore/qcoreevent.h>
#include <QtCore/qobject.h>

#include <glm/glm.hpp>

#include "window.hpp"

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	RENDERER
*-----------------------------------------------------------------------------*/
class Renderer : public QObject
{
    Q_OBJECT

public:
    //CONSTRUCTORS
    explicit		Renderer(Window* p_window);
    virtual			~Renderer() {}

    //EVENTS
    virtual bool	event(QEvent* event);

    //OTHERS
    void			requestRender();

private:
    void			render();

private:
    Window*			mp_window;
};
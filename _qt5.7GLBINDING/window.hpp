#pragma once

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <iostream>
#include <string>

#include <QtGui/qwindow.h>

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class QOpenGLContext;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	WINDOW
*-----------------------------------------------------------------------------*/
class Window : public QWindow
{
public:
    //CONSTRUCTORS
                    Window(const std::string& name, int width, int height);
    virtual			~Window() {}

    //GET
    void			getWindowSize(int* p_width, int* p_height);

    //OTHERS
    void			makeCurrent();
    void			doneCurrent();
    void			swapBuffers();

private:
    QOpenGLContext* mp_openGLContext;
};

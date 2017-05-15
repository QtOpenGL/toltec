#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       27 VII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       MainWindow class, as it's name suggests, is the class for the main window
*       inside program.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <string>

#include <QtWidgets/qmainwindow.h>

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class QWidget;
class QVBoxLayout;

/*-----------------------------------------------------------------------------
*   NAMESPACE: GUI
*-----------------------------------------------------------------------------*/
namespace gui
{
    /*-----------------------------------------------------------------------------
    *   CLASS DECLARATIONS
    *   MAIN WINDOW
    *-----------------------------------------------------------------------------*/
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        //CONSTRUCTORS
                    MainWindow(const std::string& title, int width, int height);
        virtual     ~MainWindow() {}

    private:
        void        setupUI();
        void        setupMenuBar();

    private:
        QWidget*        mp_mainPanel;
        QVBoxLayout*    mp_mainLayout;
    };
} //NAMESPACE: GUI

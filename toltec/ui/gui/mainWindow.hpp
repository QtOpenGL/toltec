#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		27 VII 2016
*	CONTRIBUTORS:
*		PIOTR MAKAL
*	INFO:
*		MainWindow class, as it's name suggests, is the class for the main window
*		inside program.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <string>

#include <QtWidgets/qmainwindow.h>

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class QWidget;
class QVBoxLayout;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	MAIN WINDOW
*-----------------------------------------------------------------------------*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //CONSTRUCTORS
                MainWindow(const std::string& title, int width, int height);
    virtual		~MainWindow() {}

    //SET
    void		setMainPanel(QWidget* p_widget);

private:
    void		setupUI();

private:
    QWidget*		mp_mainPanel;
    QVBoxLayout*	mp_mainLayout;
};
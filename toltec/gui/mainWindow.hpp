#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		27 VII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		MainWindow class, as it's name suggests, is the class for the main window
*		inside program.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <string>

#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qmenu.h>
#include <QtWidgets/qmenubar.h>
#include <QtWidgets/qwidget.h>

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
};

/*----------------------------------------------------------------------------*/

inline void MainWindow::setMainPanel(QWidget* p_widget)
{
	this->setCentralWidget(p_widget);
}
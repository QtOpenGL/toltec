#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		27 VII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		MainWindow class, as it name suggest, is the class for the main window
*		inside program.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <string>

#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qmenu.h>
#include <QtWidgets/qmenubar.h>

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*-----------------------------------------------------------------------------*/
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	//CONSTRUCTORS
				MainWindow(const std::string& title, int width, int height);
	virtual		~MainWindow() {}

private:
	void		setupUI();
};
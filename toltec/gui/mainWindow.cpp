/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "mainWindow.hpp"

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*	(const std::string&, int, int)
*-----------------------------------------------------------------------------*/
MainWindow::MainWindow(const std::string& title, int width, int height)
{
	this->setWindowTitle(title.c_str());
	this->resize(width, height);
}
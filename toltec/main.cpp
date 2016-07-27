/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <QtWidgets/qapplication.h>

#include "gui/mainWindow.hpp"

/*-----------------------------------------------------------------------------
*	FUNCTION DEFINITIONS
*	MAIN
*-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	//START QT
	QApplication application(argc, argv);

	//CREATE MAIN WINDOW
	MainWindow mainWindow("Toltec", 960, 600);
	mainWindow.show();

	return application.exec();
}

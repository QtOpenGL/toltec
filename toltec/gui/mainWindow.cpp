/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "mainWindow.hpp"

/*-----------------------------------------------------------------------------
*	PUBLIC METHODS
*	CONSTRUCTOR
*	(const std::string&, int, int)
*-----------------------------------------------------------------------------*/
MainWindow::MainWindow(const std::string& title, int width, int height)
{
	//INITIALIZE
	this->setWindowTitle(title.c_str());
	this->resize(width, height);

	//SETUP
	this->setupUI();
}

/*-----------------------------------------------------------------------------
*	PRIVATE METHODS
*	SETUP UI
*-----------------------------------------------------------------------------*/
void MainWindow::setupUI()
{
	/*-----------------------------------------------------------------------------
	*	MENU BAR NESTING:
	*
	*	1..	MENU (FILE)
	*	2..	MENU (DISPLAY)
	*	3..	MENU (CREATE)
	*	3.1....	MENU (POLYGON PRIMITIVE)
	*	3.2....	MENU (LIGHT)
	*-----------------------------------------------------------------------------*/

	//1. FILE (MENU)
	QMenu* p_fileMenu = this->menuBar()->addMenu("File");
	p_fileMenu->addAction("Import");

	//2. DISPLAY (MENU)
	QMenu* p_displayMenu = this->menuBar()->addMenu("Display");
	p_displayMenu->addAction("Grid");

	//3. CREATE (MENU)
	QMenu* p_createMenu = this->menuBar()->addMenu("Create");
	p_createMenu->addAction("Camera");
	p_createMenu->addSeparator();

	//3.1 POLYGON PRIMITIVE (MENU)
	QMenu* p_polygonPrimitivesMenu = p_createMenu->addMenu("Polygon Primitive");
	p_polygonPrimitivesMenu->addAction("Plane");
	p_polygonPrimitivesMenu->addAction("Cube");
	p_polygonPrimitivesMenu->addAction("Sphere");
	p_polygonPrimitivesMenu->addAction("Cone");

	//3.2. LIGHT (MENU)
	QMenu* p_lightsMenu = p_createMenu->addMenu("Light");
	p_lightsMenu->addAction("Ambient Light");
	p_lightsMenu->addAction("Point Light");
	p_lightsMenu->addAction("Directional Light");
	p_lightsMenu->addAction("Spot Light");
	p_lightsMenu->addAction("Area Light");
}

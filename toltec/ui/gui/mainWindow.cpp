/*-----------------------------------------------------------------------------
*   CREATED:
*       27 VII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "mainWindow.hpp"

#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qmenu.h>
#include <QtWidgets/qmenubar.h>
#include <QtWidgets/qsizepolicy.h>
#include <QtWidgets/qwidget.h>

#include "guiManager.hpp"
#include "ui/gui/outputLineWidget.hpp"
#include "ui/gui/abstractPanel.hpp"
#include "ui/gui/panelContainer.hpp"
#include "renderingSystem/abstractViewport.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: GUI
*-----------------------------------------------------------------------------*/
namespace gui
{
    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&, int, int)
    *-----------------------------------------------------------------------------*/
    MainWindow::MainWindow(const std::string& title, int width, int height)
        :
        mp_mainPanelContainer(nullptr),
        mp_mainLayout(nullptr)
    {
        //INITIALIZE
        this->setWindowTitle(title.c_str());
        this->resize(width, height);

        //SETUP
        this->setupUI();
    }

    /*-----------------------------------------------------------------------------
    *   SETUP UI
    *-----------------------------------------------------------------------------*/
    void MainWindow::setupUI()
    {
        this->setupMenuBar();

        /*-----------------------------------------------------------------------------
        *   UI NESTING
        *
        *   1.. WIDGET (CENTRAL WIDGET)
        *   1.1.... V BOX LAYOUT
        *   1.1.1...... PANEL CONTAINER
        *   1.1.1.1........ VIEWPORT PANEL
        *   1.1.2...... LABEL (MESSAGE BAR)
        *-----------------------------------------------------------------------------*/
    
        //1. CENTRAL (WIDGET)
        auto p_centralWidget = new QWidget();
        //set
        this->setCentralWidget(p_centralWidget);

        //1.1. MAIN LAYOUT (V BOX LYAOUT)
        mp_mainLayout = new QVBoxLayout();
        mp_mainLayout->setContentsMargins(0, 0, 0, 0);
        mp_mainLayout->setSpacing(0);
        //set
        p_centralWidget->setLayout(mp_mainLayout);

        //1.1.1. PANEL CONTAINER
        mp_mainPanelContainer = new PanelContainer();
        mp_mainPanelContainer->setContentsMargins(0, 0, 0, 0);
        //add
        mp_mainLayout->addWidget(mp_mainPanelContainer);

        //1.1.1.1. VIEWPORT PANEL
        AbstractPanel* p_viewportPanel = GUIManager::getInstance().createPanel(AbstractPanel::Type::VIEWPORT);
        p_viewportPanel->setContentsMargins(0, 0, 0, 0);
        //add
        mp_mainPanelContainer->addPanel(p_viewportPanel);

        //1.1.2. OUTPUT STREAM (LABEL)
        auto p_outputLineWidget = new OutputLineWidget();
        p_outputLineWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        p_outputLineWidget->setFixedHeight(20);
        //add
        mp_mainLayout->addWidget(p_outputLineWidget);
        //set
        GUIManager::getInstance().setOutputLineWidget(p_outputLineWidget);
    }

    /*-----------------------------------------------------------------------------
    *   SETUP MENU BAR
    *-----------------------------------------------------------------------------*/
    void MainWindow::setupMenuBar()
    {
        /*-----------------------------------------------------------------------------
        *   MENU BAR NESTING
        *
        *   1.. MENU (FILE)
        *   2.. MENU (DISPLAY)
        *   3.. MENU (CREATE)
        *   3.1.... MENU (POLYGON PRIMITIVE)
        *   3.2.... MENU (LIGHT)
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
} //NAMESPACE: GUI
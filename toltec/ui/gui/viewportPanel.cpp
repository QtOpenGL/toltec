/*-----------------------------------------------------------------------------
*	CREATED:
*		31 VII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "viewportPanel.hpp"

#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qcombobox.h>
#include <QtWidgets/qmenu.h>
#include <QtWidgets/qmenubar.h>

#include <glbinding/gl/gl.h>
#include <glbinding/Binding.h>
#include <glbinding/ContextInfo.h>

#include "renderManager.hpp"
#include "renderingSystem/openGLViewport.hpp"
#include "renderingSystem/renderingAPI.hpp"
#include "renderingSystem/renderingSystem.hpp"
#include "utils.hpp"

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*-----------------------------------------------------------------------------*/
ViewportPanel::ViewportPanel()
{
	this->setupViewport();
	this->setupUI();
}

/*-----------------------------------------------------------------------------
*	DESTRUCTOR
*-----------------------------------------------------------------------------*/
ViewportPanel::~ViewportPanel()
{
	delete mp_viewport;
}

/*-----------------------------------------------------------------------------
*	SETUP VIEWPORT
*-----------------------------------------------------------------------------*/
void ViewportPanel::setupViewport()
{
	//GET DEFAULT RENDERING SYSTEM
	auto p_defaultRenderingSystem = RenderManager::getInstance().getDefaultRenderingSystem();
	p_defaultRenderingSystem->addViewportPanel(this);

	//GET ACTIVE RENDERING API OF THE DEFAULT RENDERING SYSTEM
	auto p_activeRenderingAPI = p_defaultRenderingSystem->getActiveRenderingAPI();
	RenderingAPI::Type renderingAPIType = p_activeRenderingAPI->getType();

	//CREATE PROPER VIEWPORT
	switch (renderingAPIType)
	{
	case RenderingAPI::OPENGL_API:
		OpenGLViewport* p_viewport = new OpenGLViewport();
		p_viewport->setRenderer(p_activeRenderingAPI->getRenderer());

		//set opengl
		p_viewport->makeCurrent();
		glbinding::Binding::initialize();
		p_viewport->doneCurrent();

		//assign to member
		mp_viewport = p_viewport;
	}
}

/*-----------------------------------------------------------------------------
*	SETUP UI
*-----------------------------------------------------------------------------*/
void ViewportPanel::setupUI()
{
	this->setContentsMargins(0, 0, 0, 0);

	/*-----------------------------------------------------------------------------
	*	UI NESTING
	*
	*	1.. V BOX LAYOUT
	*	1.1....	H BOX LAYOUT
	*	1.1.1......	COMBO BOX (ACTIVE CAMERA)
	*	1.1.2......	MENU BAR
	*	1.1.2.1........	MENU (SHADING)
	*	1.1.2.2........	MENU (LIGHTING)
	*	1.1.2.3........	MENU (SHOW)
	*	1.1.2.4........	MENU (RENDERER)
	*	1.2....	WIDGET (VIEWPORT)
	*-----------------------------------------------------------------------------*/

	//1. MAIN LAYOUT (V BOX LAYOUT)
	QVBoxLayout* p_mainLayout = new QVBoxLayout;
	p_mainLayout->setContentsMargins(0, 0, 0, 0);
	p_mainLayout->setSpacing(0);
	this->setLayout(p_mainLayout);

	//1.1. TOP BAR LAYOUT (H BOX LAYOUT)
	QHBoxLayout* p_topBarLayout = new QHBoxLayout;
	//add
	p_mainLayout->addLayout(p_topBarLayout);

	//1.1.1. ACTIVE CAMERA (COMBO BOX)
	mp_activeCameraComboBox = new QComboBox;
	//add
	p_topBarLayout->addWidget(mp_activeCameraComboBox);

	//1.1.2. MENU BAR
	QMenuBar* p_menuBar = new QMenuBar;
	p_menuBar->setFixedHeight(21);
	//add
	p_topBarLayout->addWidget(p_menuBar);

	//1.1.2.1. SHADING (MENU)
	QMenu* p_shadingMenu = new QMenu("Shading");
	p_shadingMenu->addAction("Wireframe");
	p_shadingMenu->addAction("Shaded");
	p_shadingMenu->addAction("Wireframe on Shaded");
	//add
	p_menuBar->addMenu(p_shadingMenu);

	//1.1.2.2. LIGHTING (MENU)
	QMenu* p_lightingMenu = new QMenu("Lighting");
	p_lightingMenu->addAction("Use Default Light");
	p_lightingMenu->addAction("Use All Lights");
	//add
	p_menuBar->addMenu(p_lightingMenu);

	//1.1.2.3. SHOW (MENU)
	QMenu* p_showMenu = new QMenu("Show");
	p_showMenu->addAction("Grid");
	//add
	p_menuBar->addMenu(p_showMenu);

	//1.1.2.4. RENDERER (MENU)
	QMenu* p_rendererMenu = new QMenu("Renderer");
	p_rendererMenu->addAction("Atman Renderer");
	//add
	p_menuBar->addMenu(p_rendererMenu);

	//1.2. VIEWPORT
	QWidget* p_viewportWidget = QWidget::createWindowContainer(mp_viewport);
	p_viewportWidget->setAutoFillBackground(false);
	//add
	p_mainLayout->addWidget(p_viewportWidget);
}
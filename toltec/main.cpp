/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <iostream>
#include <memory>

#include <QtWidgets/qapplication.h>
#include <glm/glm.hpp>

#include "events/globalEventFilter.hpp"
#include "ui/commands/creationCommands.hpp"
#include "ui/gui/mainWindow.hpp"
#include "ui/gui/viewportPanel.hpp"
#include "nodes/cameraNode.hpp"
#include "nodes/polygonMeshNode.hpp"
#include "nodes/transformNode.hpp"
#include "nodes/shaders/lambertSSPNode.hpp"
#include "nodes/shaders/pointCSPNode.hpp"
#include "renderingSystem/toltec/openGL/toltecOpenGLRenderer.hpp"
#include "renderingSystem/toltec/openGL/toltecOpenGLRendererResource.hpp"
#include "renderingSystem/renderingAPI.hpp"
#include "renderingSystem/renderingSystem.hpp"
#include "renderManager.hpp"
#include "resourceManager.hpp"
#include "utils.hpp"

/*-----------------------------------------------------------------------------
*   FUNCTION DEFINITIONS
*   MAIN
*-----------------------------------------------------------------------------*/
int main(int argc, char* argv[])
{ 
    using namespace core;

    /*-----------------------------------------------------------------------------
    *   START QT
    *-----------------------------------------------------------------------------*/
    QApplication application(argc, argv);

    /*-----------------------------------------------------------------------------
    *   CORE ARCHITECTURE
    *-----------------------------------------------------------------------------*/
    //GLOBAL EVENT FILTER
    GlobalEventFilter globalEventFilter;
    application.installEventFilter(&globalEventFilter);
     
    //CREATE PRIMARY OBJECTS
    //root transform node
    auto p_rootTransformNode = std::make_unique<nodes::TransformNode>();
    p_rootTransformNode->setName("root");
    ResourceManager::getInstance().setRootTransformNode(p_rootTransformNode.get());
    ResourceManager::getInstance().addTransformNode(std::move(p_rootTransformNode));

    //default camera node
    nodes::CameraNode* p_defaultCameraNode = ui::cmds::createCamera();
    ResourceManager::getInstance().setDefaultCameraNode(p_defaultCameraNode);

    //default shader
    auto p_lambertShaderProgramNode = std::make_unique<nodes::LambertSSPNode>();
    p_lambertShaderProgramNode->setName("defaultShader");
    ResourceManager::getInstance().setDefaultSSPNode(p_lambertShaderProgramNode.get());
    ResourceManager::getInstance().addSurfaceShaderProgramNode(std::move(p_lambertShaderProgramNode));

    //poly vertex component shader - inactive
    auto p_polyVertexShaderInactive = std::make_unique<nodes::PointCSPNode>();
    p_polyVertexShaderInactive->setName("polyVertexShaderInactive");
    p_polyVertexShaderInactive->setColor(1.0f, 0.0f, 1.0f);
    p_polyVertexShaderInactive->setSize(2);
    ResourceManager::getInstance().addComponentShaderProgramNode(std::move(p_polyVertexShaderInactive));

    //vertex component shader - inactive hover
    //...
    //vertex component shader - active
    //...
    //vertex component shader - active hover
    //...

    //poly edge component shader - inactive
    //PointCSPNode polyEdgeShaderInactive;
    //polyEdgeShaderInactive.setName("polyEdgeShaderInactive");
    //polyEdgeShaderInactive.setColor(1.0f, 0.0f, 1.0f);
    //polyEdgeShaderInactive.setSize(1);
    //ResourceManager::getInstance().addComponentShaderProgramNode(&polyEdgeShaderInactive);

    //poly edge component shader - inactive hover
    //...
    //poly edge component shader - active
    //...
    //poly edge component shader - active hover
    //...

    /*-----------------------------------------------------------------------------
    *   RENDERING ARCHITECTURE
    *-----------------------------------------------------------------------------*/
    //TOLTEC RENDERING SYSTEM
    RenderingSystem toltecRenderingSystem("toltec");

    //opengl
    auto p_toltecRendererResource = std::make_unique<tgl::ToltecOpenGLRendererResource>();
    auto p_toltecOpenGLRenderer =   std::make_unique<tgl::ToltecOpenGLRenderer>(p_toltecRendererResource.get());
    RenderingAPI toltecOpenGLRenderingAPI(
        RenderingAPI::OPENGL_API, 
        std::move(p_toltecRendererResource),
        std::move(p_toltecOpenGLRenderer)
    );

    //add
    toltecRenderingSystem.addRenderingAPI(&toltecOpenGLRenderingAPI);

    //ADD RENDERING SYSTEMS TO THE RENDER MANAGER
    RenderManager::getInstance().addRenderingSystem(&toltecRenderingSystem);

    /*-----------------------------------------------------------------------------
    *   GUI
    *-----------------------------------------------------------------------------*/
    ui::gui::MainWindow mainWindow("Toltec", 960, 600);
    mainWindow.show();

    /*-----------------------------------------------------------------------------
    *   CREATE SECONDARY OBJECTS
    *-----------------------------------------------------------------------------*/
    ui::cmds::createCube();

    /*-----------------------------------------------------------------------------
    *   EXECUTE
    *-----------------------------------------------------------------------------*/
    return application.exec();
}

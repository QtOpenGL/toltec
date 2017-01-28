/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderer.hpp"

#include <glbinding/gl/gl.h>
#include <glbinding/Binding.h>
#include <glbinding/ContextInfo.h>

/*-----------------------------------------------------------------------------
*	CLASS DEFINITIONS
*	RENDERER
*-----------------------------------------------------------------------------*/
Renderer::Renderer(Window* p_window)
	:
	mp_window(p_window)
{
	mp_window->makeCurrent();
	glbinding::Binding::initialize();

	std::cout << "OpenGL ver.:\t" << gl::glGetString(gl::GLenum::GL_VERSION) << std::endl
		<< "GLSL ver.:\t" << gl::glGetString(gl::GLenum::GL_SHADING_LANGUAGE_VERSION) << std::endl
		<< "Lib. vendor:\t" << gl::glGetString(gl::GLenum::GL_VENDOR) << std::endl
		<< "Renderer:\t" << gl::glGetString(gl::GLenum::GL_RENDERER) << "\n\n";

	mp_window->doneCurrent();
}

/*-----------------------------------------------------------------------------
*	EVENT
*-----------------------------------------------------------------------------*/
bool Renderer::event(QEvent* event)
{
	if (event->type() == QEvent::UpdateRequest)
	{
		this->render();
		return true;
	}
	else
	{
		return QObject::event(event);
	}
}

/*-----------------------------------------------------------------------------
*	REQUEST RENDER
*-----------------------------------------------------------------------------*/
void Renderer::requestRender()
{
	QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest));
}

/*-----------------------------------------------------------------------------
*	RENDER
*-----------------------------------------------------------------------------*/
void Renderer::render()
{
	using namespace gl;

	if (mp_window->isExposed() == false)
	{
		this->requestRender();
		return;
	}

	mp_window->makeCurrent();

	/*-----------------------------------------------------------------------------
	*  SHADER STUFF
	*-----------------------------------------------------------------------------*/
	const char* vertexShader =
		"#version 330\n"
		"layout(location = 0) in vec3 g_position;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(g_position, 1.0f);\n"
		"}";
	const char* fragShader =
		"#version 330\n"
		"out vec4 g_outColor;\n"
		"void main()\n"
		"{\n"
		"g_outColor = vec4(0.9f, 0.0f, 0.1f, 1.0f);\n"
		"}";

	GLuint shaderProgramID = glCreateProgram();
	GLuint vsID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fsID = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vsID, 1, &vertexShader, NULL);
	glShaderSource(fsID, 1, &fragShader, NULL);
	glCompileShader(vsID);
	glCompileShader(fsID);
	glAttachShader(shaderProgramID, vsID);
	glAttachShader(shaderProgramID, fsID);
	glLinkProgram(shaderProgramID);

	/*-----------------------------------------------------------------------------
	*  MESH STUFF
	*-----------------------------------------------------------------------------*/
	glPointSize(10.0f);

	glm::vec3 vertex = glm::vec3(0.0f, 0.0f, 0.0f);

	GLuint vbo;
	GLuint vao;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(float), &vertex, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	/*-----------------------------------------------------------------------------
	*  PRINT LOG
	*-----------------------------------------------------------------------------*/
	std::cout
		<< "Shader Program ID:\t\t" << shaderProgramID << std::endl
		<< "Vertex Shader ID:\t\t" << vsID << std::endl
		<< "Fragment Shader ID:\t\t" << fsID << std::endl
		<< "Vertex Array Object ID:\t\t" << vao << std::endl
		<< "Vertex Buffer Object ID:\t" << vbo << std::endl;

	int width, height;
	mp_window->getWindowSize(&width, &height);
	glViewport(0, 0, width, height);

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(shaderProgramID);
	glBindVertexArray(vao);
	glDrawArrays(GL_POINTS, 0, 1);
	glBindVertexArray(0);
	glUseProgram(0);

	mp_window->swapBuffers();
	mp_window->doneCurrent();
}
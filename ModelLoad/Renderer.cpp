#include "Renderer.h"


Camera Renderer::camera;
GLboolean Renderer::keys[1024] = { 0 };

Renderer::Renderer(int _width, int _height) : width(_width), height(_height)
{
	initGLFW();
	initGL();
}

void Renderer::initGL()
{
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();

	if (err != GLEW_OK)
	{
		cerr << "Failed to init glew : " << glewGetErrorString(err) << endl;
		exit(-1);
	}

	glViewport(0, 0, width, height);
	/* Enable smooth shading */
	//glShadeModel(GL_SMOOTH);
	/* Set the background */
	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	/* Depth buffer setup */
	glClearDepth(1.0f);
	/* Enables Depth Testing */
	glEnable(GL_DEPTH_TEST);
	/* The Type Of Depth Test To Do */
	glDepthFunc(GL_LEQUAL);
	///* Really Nice Perspective Calculations */
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	modelMatrix = mat4(1.0f);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, -0.7f, 0.0f));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1f, 0.1f, 0.1f));
	viewMatrix = camera.getView();
}

void Renderer::initGLFW()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window = glfwCreateWindow(width, height, "opengl", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, keyCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
	glfwSetCursorPosCallback(window, cursorPositionCallback);
}

void Renderer::compileShaderFromFile(const char *verFileName, const char *fragFileName)
{
	bool ret = prog.compileShaderFromFile(verFileName, GLSLShader::VERTEX);
	if (!ret)
	{
		cerr << "Compile Vertex Shader Error: " << prog.log() << endl;
		exit(-1);
	}
	ret = prog.compileShaderFromFile(fragFileName, GLSLShader::FRAGMENT);
	if (!ret)
	{
		cerr << "Compile Fragment Shader Error: " << prog.log() << endl;
		exit(-1);
	}


	prog.bindAttribLocation(0, "position");
	prog.bindAttribLocation(1, "normal");
	prog.bindAttribLocation(2, "uv");

	ret = prog.link();
	if (!ret)
	{
		cerr << "Link Error: " << prog.log() << endl;
		exit(-1);
	}

	ret = prog.validate();
	if (!ret)
	{
		cerr << "Validate Error: " << prog.log() << endl;
		exit(-1);
	}

	prog.use();
}

void Renderer::bindBuffer(Scene &scene)
{
	unsigned nObjects = scene.objects.size();
	for (unsigned i = 0; i < nObjects; ++i)
	{
		scene.objects[i]->bindBuffer();
	}
}

void Renderer::renderScene(Scene &scene)
{
	unsigned nObjects = scene.objects.size();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		do_move();
		viewMatrix = camera.getView();
		prog.setUniform("V", viewMatrix);
		for (unsigned i = 0; i < nObjects; ++i)
		{
			Object *obj = scene.objects[i];
			obj->render();
		}

		glfwSwapBuffers(window);
	}
	glfwTerminate();
}

void Renderer::setUniform()
{
	glfwGetFramebufferSize(window, &width, &height);
	mat4 projection = glm::perspective(glm::radians(45.0f), float(width) / height, 0.1f, 100.0f);
	mat4 mv = viewMatrix * modelMatrix;

	prog.setUniform("M", modelMatrix);
	prog.setUniform("P", projection);
}

void Renderer::do_move()
{
	if (keys[GLFW_KEY_UP])
	{
		camera.progressKeyBoard(FRONT);
	}
	if (keys[GLFW_KEY_DOWN])
	{
		camera.progressKeyBoard(BACK);
	}
	if (keys[GLFW_KEY_RIGHT])
	{
		camera.progressKeyBoard(RIGHT);
	}
	if (keys[GLFW_KEY_LEFT])
	{
		camera.progressKeyBoard(LEFT);
	}
}

void Renderer::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch (key)
	{
	case GLFW_KEY_UP:
		if (action == GLFW_PRESS) keys[key] = GL_TRUE;
		else if (action == GLFW_RELEASE)keys[key] = GL_FALSE;
		break;
	case GLFW_KEY_DOWN:
		if (action == GLFW_PRESS) keys[key] = GL_TRUE;
		else if (action == GLFW_RELEASE)keys[key] = GL_FALSE;
		break;
	case GLFW_KEY_LEFT:
		if (action == GLFW_PRESS) keys[key] = GL_TRUE;
		else if (action == GLFW_RELEASE)keys[key] = GL_FALSE;
		break;
	case GLFW_KEY_RIGHT:
		if (action == GLFW_PRESS) keys[key] = GL_TRUE;
		else if (action == GLFW_RELEASE)keys[key] = GL_FALSE;
		break;
	default:
		break;
	}
}

void Renderer::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	
}

void Renderer::cursorPositionCallback(GLFWwindow* window, double x, double y)
{
	
}
Renderer::~Renderer()
{

}
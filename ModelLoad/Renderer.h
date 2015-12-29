/***************************************
*author: guohongzhi  zju
*date:2015.8.22
*func: manage render
****************************************/
#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "Global.h"
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include "Scene.h"
#include "ProgramManager.h"
#include "camera.h"


class Renderer
{
public:
	Renderer(int _width = 480, int _height = 480);
	void compileShaderFromFile(const char *verFileName, const char *fragFileName);
	void renderScene(Scene &scene);
	void bindBuffer(Scene &scene);
	void setUniform();
	~Renderer(void);

private:
	int width;
	int height;
	mat4 modelMatrix;
	mat4 viewMatrix;
	static Camera camera;

	ProgramManager prog;

	GLFWwindow* window;

	void initGLFW();
	void initGL();

	static GLboolean keys[1024];

	// GLFW callback
	void do_move();
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void cursorPositionCallback(GLFWwindow* window, double x, double y);
	static void scrollCallback(GLFWwindow* window, double x, double y);
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

};

#endif
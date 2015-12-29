#include <iostream>
#include "Scene.h"
#include "Renderer.h"

using namespace std;

int main()
{
	Scene scene;
	scene.addModelFromFile("./models/nanosuit/nanosuit.obj");

	Renderer renderer(768, 1024);
	renderer.compileShaderFromFile("./shaders/verShader.glsl", "./shaders/fragShader.glsl");
	renderer.bindBuffer(scene);
	renderer.setUniform();
	renderer.renderScene(scene);
	return 0;
}
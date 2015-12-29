#ifndef _SCENE_H_
#define _SCENE_H_
#include "global.h"
#include "Object.h"

class Scene
{
public:
	Scene(){}
	~Scene();
	bool addModelFromFile(const char* path);
	//void bindBuffer();

	std::vector<Object*> objects;

	GLuint VB;
	GLuint IB;
	int numIndices;
};

#endif
#include "Scene.h"

bool Scene::addModelFromFile(const char* path)
{
	Object* obj = new Object();
	obj->load(path);

	unsigned index = objects.size() + 1;
	cout << "Model " << index << ": vertices = " << obj->nVertices << ", triangles = " << obj->nTriangles << endl;
	objects.push_back(obj);
	return true;
}

Scene::~Scene()
{
	unsigned nObjs = this->objects.size();

	for (unsigned i = 0; i < nObjs; ++i)
	{
		Object *p = this->objects[i];
		delete p;
	}
	this->objects.clear();
}
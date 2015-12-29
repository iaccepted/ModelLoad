/***************************************
*author: guohongzhi  zju
*date:2015.8.22
*func: load single object
****************************************/

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Global.h"
#include "Vertex.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Mesh.h"


class Object
{
public:
	Object(){}
	void load(const char *path);

	void bindBuffer();
	void render();

	unsigned int nVertices;
	unsigned int nTriangles;

private:
	GLuint vao, vbo, ebo;
	std::vector<Mesh> meshs;
};

#endif 
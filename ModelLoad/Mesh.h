#ifndef __MESH_H__
#define __MESH_H__

#include "Global.h"
#include "Vertex.h"

using namespace std;

class Mesh
{
private:

	GLuint vao, vbo, ebo;

public:
	vector<Vertex> vertices;
	vector<GLuint> indices;
	Mesh();
	void bindBuffer();
	void render();
};

#endif
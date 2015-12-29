#ifndef _VERTEX_H_
#define _VERTEX_H_

#include "Global.h"

typedef struct Vertex
{
	vec3 position;
	vec3 normal;
	vec2 uv;

	Vertex(float px, float py, float pz, float nx, float ny, float nz, float u, float v)
	{
		position = vec3(px, py, pz);
		normal = vec3(nx, ny, nz);
		uv = vec2(u, v);
	}

	Vertex(vec3 &p, vec3 &n, vec2 &_uv)
	{
		position = vec3(p);
		normal = vec3(n);
		uv = vec2(_uv);
	}
}Vertex;

#endif
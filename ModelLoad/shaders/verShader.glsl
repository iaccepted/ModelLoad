#version 430 core

in vec3 position;
in vec3 normal;
in vec2 uv;

uniform mat4 M;
uniform mat4 V;
uniform mat4 P;

out vec3 onormal;

void main()
{
	gl_Position = P * V * M * vec4(position, 1.0);
	onormal = normal;
}
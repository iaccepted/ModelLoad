#version 430 core

in vec3 onormal;
out vec4 ocolor;

vec3 lightDir = vec3(1.0, 1.0, 1.0);
vec3 lightColor = vec3(1.0, 1.0, 1.0);

void main()
{
	float ndotl = max(0.0, dot(normalize(lightDir), onormal));
	vec3 diffuse = vec3(ndotl);
	ocolor = vec4(diffuse, 1.0);
	//ocolor = vec4(0.3, 0.3, 0.3, 1.0);
}
#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

typedef enum toward
{
	FRONT,
	BACK,
	RIGHT,
	LEFT
}toward;

class Camera
{
private:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	GLfloat speed;
	glm::mat4 view;

public:
	Camera() : position(glm::vec3(0.0f, 0.0f, 3.0f)), front(glm::vec3(0.0f, 0.0f, -1.0f)),
		up(glm::vec3(0.0f, 1.0f, 0.0f)), right(glm::normalize(glm::cross(up, -1.0f * front))), speed(0.02f){}

	glm::mat4 getView();
	

	void progressKeyBoard(toward dir);

	
};

#endif
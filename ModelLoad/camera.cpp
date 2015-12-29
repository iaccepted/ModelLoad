#include "camera.h"

void Camera::progressKeyBoard(toward dir)
{
	switch (dir)
	{
	case FRONT:
		position += front * speed;
		break;
	case BACK:
		position -= front * speed;
		break;
	case LEFT:
		position -= right * speed;
		break;
	case RIGHT:
		position += right * speed;
		break;
	default:
		break;
	}
}

glm::mat4 Camera::getView()
{
	return glm::lookAt(position, position + front, up);
}
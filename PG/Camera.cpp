#include "Camera.hpp"

namespace gps {

	//Camera constructor
	Camera::Camera(glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 cameraUp) {
		this->cameraPosition = cameraPosition;
		this->cameraTarget = cameraTarget;
		this->cameraUpDirection = cameraUp;

		this->cameraFrontDirection = glm::normalize(cameraTarget - cameraPosition);
		this->cameraRightDirection = glm::normalize(glm::cross(cameraFrontDirection, cameraUp));
		this->cameraUpDirection = glm::normalize(glm::cross(cameraRightDirection, cameraFrontDirection));

	}

	//return the view matrix, using the glm::lookAt() function
	glm::mat4 Camera::getViewMatrix() {
		return glm::lookAt(cameraPosition, cameraPosition + cameraFrontDirection, cameraUpDirection);
	}

	//update the camera internal parameters following a camera move event
	void Camera::move(MOVE_DIRECTION direction, float speed) {

		switch (direction) {
		case MOVE_FORWARD:
			cameraPosition = cameraPosition + cameraFrontDirection * speed;
			break;
		case MOVE_BACKWARD:
			cameraPosition =cameraPosition - cameraFrontDirection * speed;
			break;
		case MOVE_RIGHT:
			cameraPosition = cameraPosition + glm::normalize(glm::cross(cameraFrontDirection, cameraUpDirection)) * speed;
			break;
		case MOVE_LEFT:
			cameraPosition =cameraPosition - glm::normalize(glm::cross(cameraFrontDirection, cameraUpDirection)) * speed;
			break;
		}
	}

	//update the camera internal parameters following a camera rotate event
	//yaw - camera rotation around the y axis
	//pitch - camera rotation around the x axis
	void Camera::rotate(float pitch, float yaw) {
		glm::vec3 direction;
		direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		direction.y = sin(glm::radians(pitch));
		direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		cameraFrontDirection = glm::normalize(direction);

		
	}
}
#include "CameraController.h"

#include <iostream>

void CameraController::onTick()
{
	if (getCore()->getKeyboard()->getKey('d'))
	{
		//std::cout << "Moving right" << std::endl;
		//getTransform()->translate(0.1f, 0, 0);
		temp = Move(getCore()->getDeltaT(), rotation, getTransform()->getPosition(), glm::vec3(1, 0, 0));
		getTransform()->translate(temp.x, temp.y, temp.z);
	}
	if (getCore()->getKeyboard()->getKey('a'))
	{
		//std::cout << "Moving left" << std::endl;
		//getTransform()->translate(-0.1f, 0, 0);
		temp = Move(getCore()->getDeltaT(), rotation, getTransform()->getPosition(), glm::vec3(-1, 0, 0));
		getTransform()->translate(temp.x, temp.y, temp.z);
	}
	if (getCore()->getKeyboard()->getKey('w'))
	{
		//std::cout << "Moving front" << std::endl;
		//getTransform()->translate(0, 0, -0.1f);
		temp = Move(getCore()->getDeltaT(), rotation, getTransform()->getPosition(), glm::vec3(0, 0, -1));
		getTransform()->translate(temp.x, temp.y, temp.z);
	}
	if (getCore()->getKeyboard()->getKey('s'))
	{
		//std::cout << "Moving back" << std::endl;
		//getTransform()->translate(0, 0, 0.1f);
		temp = Move(getCore()->getDeltaT(), rotation, getTransform()->getPosition(), glm::vec3(0, 0, 1));
		getTransform()->translate(temp.x, temp.y, temp.z);
	}

	rotation -= getCore()->getMouse()->mouseHorizontal(1280) * sensitivity;
	angle -= getCore()->getMouse()->mouseVertical(720) * sensitivity;
	if (angle >= 120.0f)
	{
		angle = 120;
	}
	if (angle <= -120.0f)
	{
		angle = -120;
	}

	getCore()->getCamera()->setAngle(angle);
	getCore()->getCamera()->setRotation(rotation);
}

glm::vec3 CameraController::Move(float _deltaTime, float _rotation, glm::vec3 _position, glm::vec3 _direction)
{
	glm::mat4 model(1.0f);
	model = glm::rotate(model, glm::radians(_rotation), glm::vec3(0, 1, 0));
	glm::vec4 tmp = model * glm::vec4(_direction, 1);
	_position += glm::vec3(tmp * speed * _deltaTime);

	std::cout << "Temp : " << temp.x << " " << temp.y << " " << temp.z << std::endl;
	std::cout << "Delta Time : " << _deltaTime << std::endl;
	std::cout << "Posision : " << _position.x << " " << _position.y << " " << _position.z << "\n" << std::endl;

	return _position;
}
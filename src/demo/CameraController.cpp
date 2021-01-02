#include "CameraController.h"

#include <iostream>

void CameraController::onTick()
{
	if (getCore()->getKeyboard()->getKey('d'))
	{
		std::cout << "Moving right" << std::endl;
		getTransform()->translate(0.1f, 0, 0);
	}
	if (getCore()->getKeyboard()->getKey('a'))
	{
		std::cout << "Moving left" << std::endl;
		getTransform()->translate(-0.1f, 0, 0);
	}
	if (getCore()->getKeyboard()->getKey('w'))
	{
		std::cout << "Moving front" << std::endl;
		getTransform()->translate(0, 0, -0.1f);
	}
	if (getCore()->getKeyboard()->getKey('s'))
	{
		std::cout << "Moving back" << std::endl;
		getTransform()->translate(0, 0, 0.1f);
	}
}


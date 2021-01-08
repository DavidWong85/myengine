#include "Mouse.h"

#include <iostream>

namespace myengine
{
	void Mouse::setMousePosition(float _x, float _y)
	{
		MousePosition.x = _x;
		MousePosition.y = _y;
	}

	int Mouse::mouseHorizontal(float _width)
	{
		return MousePosition.x - (_width / 2);
	}

	int Mouse::mouseVertical(float _height)
	{
		return MousePosition.y - (_height / 2);
	}
}
#include <glm/glm.hpp>

namespace myengine
{
	struct Mouse
	{
		 void setMousePosition(float _x, float _y);
		 int mouseHorizontal(float _width);
		 int mouseVertical(float _height);
	private:
		glm::vec2 MousePosition;
	};
}
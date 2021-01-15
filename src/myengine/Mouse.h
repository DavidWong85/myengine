#include <glm/glm.hpp>

namespace myengine
{
	struct Mouse
	{
		/**
		* set mouse position
		*/
		void setMousePosition(float _x, float _y);
		/**
		* return horizontal offset 
		*/
		int mouseHorizontal(float _width);
		/**
		* return vertical offset
		*/
		int mouseVertical(float _height);

	private:
		glm::vec2 MousePosition;
	};
}
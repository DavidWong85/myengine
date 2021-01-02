#include "Component.h"

#include <glm/glm.hpp>

namespace myengine
{
	struct Camera : public Component
	{
		void onInitialize();
		//void onDestroy();

		glm::mat4 getView();
		glm::mat4 getProjection();

	private:
		float fov = 45.0f;
		int camWidth = 1280;
		int camHeight = 720;
	};
}
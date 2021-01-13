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

		void setAngle(float _angle);
		void setRotation(float _rotation);

		float getAngle();
		float getRotation();

	private:
		float fov = 60.0f;
		int camWidth = 1280;
		int camHeight = 720;
		float angle = 0;
		float rotation = 0;
	};
}
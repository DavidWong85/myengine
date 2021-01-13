#include "Component.h"

#include <AL/al.h>

#include <glm/glm.hpp>
#include <memory>

namespace myengine
{
	struct Sound;
	struct Listener : public Component
	{
		void onInitialize();

		void onTick();

		void setAngle(float _angle);
		void setRotation(float _rotation);

	private:
		ALuint sid;
		glm::vec3 position;
		glm::vec3 foward;
		glm::vec3 up;
		float angle;
		float rotation;
	};
}
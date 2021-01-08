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

		void setPosition(glm::vec3 _position);

	private:
		ALuint sid;
		glm::vec3 position;
	};
}
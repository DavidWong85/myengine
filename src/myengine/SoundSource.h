#include "Component.h"

#include <glm/glm.hpp>
#include <AL/al.h>
#include <memory>

namespace myengine
{
	struct Sound;
	struct SoundSource : public Component
	{
		void onInitialize(std::shared_ptr<Sound> sound);
		void onTick();
		void onDestroy();

		void setPosition(glm::vec3 _position);

	private:
		ALuint sid;
		glm::vec3 position;
	};
}
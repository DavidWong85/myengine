#include "Component.h"

#include <glm/glm.hpp>
#include <AL/al.h>
#include <memory>

namespace myengine
{
	struct Sound;
	struct SoundSource : public Component
	{
		/**
		* Initial openAL
		*/
		void onInitialize(std::shared_ptr<Sound> sound);
		/**
		* update position
		*/
		void onTick();
		/**
		* delete source
		*/
		void onDestroy();

	private:
		ALuint sid;
		glm::vec3 position;
	};
}
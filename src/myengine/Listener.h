#include "Component.h"

#include <AL/al.h>

#include <glm/glm.hpp>
#include <memory>

namespace myengine
{
	struct Sound;
	struct Listener : public Component
	{
		/**
		* set listener position
		*/
		void onInitialize();
		/**
		* update listener position and orientation 
		*/
		void onTick();

	private:
		glm::vec3 position;
		glm::vec3 foward;
		glm::vec3 up;
		float angle;
		float rotation;
	};
}
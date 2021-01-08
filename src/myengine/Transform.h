#include "Component.h"

#include <glm/glm.hpp>

namespace myengine
{
	struct Transform : public Component
	{
		void onInitialize();
		glm::mat4 getModel();
		void setPosition(glm::vec3 _position);
		void translate(float x, float y, float z);
		glm::vec3 getPosition();
		

	private:
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
	};
}
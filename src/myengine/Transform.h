#include "Component.h"

#include <glm/glm.hpp>

namespace myengine
{
	struct Transform : public Component
	{
		void onInitialize();
		/**
		* get model matrix 
		*/
		glm::mat4 getModel();
		/**
		* set initial position
		*/
		void setPosition(glm::vec3 _position);
		/**
		* set translate position
		*/
		void translate(float x, float y, float z);
		/**
		* get position
		*/
		glm::vec3 getPosition();
		
	private:
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
	};
}
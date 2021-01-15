#include "Component.h"

#include <glm/glm.hpp>

namespace myengine
{
	struct Camera : public Component
	{
		/**
		* set Camera in core
		*/
		void onInitialize();
		/**
		* return view matrix
		*/
		glm::mat4 getView();
		/**
		* return projection matrix
		*/
		glm::mat4 getProjection();
		/**
		* set angle
		*/
		void setAngle(float _angle);
		/**
		* set rotation
		*/
		void setRotation(float _rotation);
		/**
		* get angle
		*/
		float getAngle();
		/**
		* get rotation
		*/
		float getRotation();

	private:
		float fov = 60.0f;
		int camWidth = 1280;
		int camHeight = 720;
		float angle = 0;
		float rotation = 0;
	};
}
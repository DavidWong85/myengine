#pragma once
#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <memory>

namespace myengine
{
	struct Entity;
	struct Core;
	struct Transform;

	struct Component
	{
		friend struct ::myengine::Entity;
		/**
		* call onTick()
		*/
		void tick();
		/**
		* call onRender()
		*/
		void render();
		/**
		* call onDestroy()
		*/
		void destroy();

		virtual void onInitialize();
		virtual void onTick();
		virtual void onRender();
		virtual void onDestroy();
		/**
		* return entity 
		*/
		std::shared_ptr<Entity> getEntity();
		/**
		* return core 
		*/
		std::shared_ptr<Core> getCore();
		/**
		* return transform
		*/
		std::shared_ptr<Transform> getTransform();

	private:
		std::weak_ptr<Entity> entity;
	};
}

#endif
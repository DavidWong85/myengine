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
		friend struct myengine::Entity;
		
		void tick();
		void render();
		void destroy();

		virtual void onInitialize();
		virtual void onTick();
		virtual void onRender();
		virtual void onDestroy();

		std::shared_ptr<Entity> getEntity();
		std::shared_ptr<Core> getCore();
		std::shared_ptr<Transform> getTransform();

	private:
		std::weak_ptr<Entity> entity;
	};
}

#endif
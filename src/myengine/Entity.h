#include "Exception.h"

#include <memory>
#include <vector>

namespace myengine
{
	struct Component;
	struct Core;
	struct Transform;

	struct Entity
	{
		friend struct ::myengine::Core;
		/**
		* add component with no argument
		*/
		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->entity = self;

			components.push_back(rtn);

			rtn->onInitialize();

			return rtn;
		}
		/**
		* add component with arguments
		*/
		template <typename T, typename ... Args>
		std::shared_ptr<T> addComponent(Args&&... args)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->entity = self;

			components.push_back(rtn);

			rtn->onInitialize(std::forward<Args>(args)...);

			return rtn;
		}
		/**
		* get component
		*/
		template <typename T>
		std::shared_ptr<T> getComponent()
		{
			for (size_t i = 0; i < components.size(); i++)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(components.at(i));

				if (!rtn) continue;

				return rtn;
			}
			throw Exception("Entity does not contain requested type");
		}
		/*
		* call all component's tick() 
		*/
		void tick();
		/*
		* call all component's render()
		*/
		void render();
		/* 
		* set flag to false and call all component's destroy()
		*/
		void destroy();
		/*
		* get share pointer to core
		*/
		std::shared_ptr<Core> getCore();
		/*
		* get share pointer to transform component
		*/
		std::shared_ptr<Transform> getTransform();

	private:
		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Core> core;
		std::weak_ptr<Entity> self;
		std::weak_ptr<Transform> transform;
		bool alive;
	};
}
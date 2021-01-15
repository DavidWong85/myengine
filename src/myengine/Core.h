#include <memory>
#include <vector>

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <AL/alc.h>

namespace myengine {

	struct Entity;
	struct Keyboard;
	struct Mouse;
	struct Camera;
	struct Resources;
	struct Sound;

	struct Core
	{
		friend struct Renderer;
		friend struct Camera;
		/**
		* create window 
		* set keboard, mouse and resources
		*/
		static std::shared_ptr<Core> initialize();
		/**
		* add entity to vector
		*/
		std::shared_ptr<Entity> addEntity();
		/**
		* return keyboard
		*/
		std::shared_ptr<Keyboard> getKeyboard();
		/**
		* return mouse
		*/
		std::shared_ptr<Mouse> getMouse();
		/**
		* return camera
		*/
		std::shared_ptr<Camera> getCamera();
		/**
		* return resources
		*/
		std::shared_ptr<Resources> getResources();
		/**
		* start the loop
		*/
		void start();
		/**
		* the main loop for the engine 
		*/
		static void loop();
		/**
		* return delta time
		*/
		float getDeltaT();
	private:
		SDL_Window* window;
		SDL_GLContext glContext;

		ALCdevice* device;
		ALCcontext* context;

		std::vector<std::shared_ptr<Entity>> entities;
		std::weak_ptr<Core> self;
		std::shared_ptr<Keyboard> keyboard;
		std::shared_ptr<Mouse> mouse;
		std::weak_ptr<Camera> camera;
		std::shared_ptr<Resources> resources;

		bool running = true;

		float deltaTime;
		float lastTime;
	};
}


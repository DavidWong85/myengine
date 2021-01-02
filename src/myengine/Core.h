#include <memory>
#include <vector>

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <rend/rend.h>
#include <AL/alc.h>

namespace myengine {

	struct Entity;
	struct Keyboard;
	struct Camera;
	struct Resources;
	struct Sound;

	struct Core
	{
		friend struct Renderer;
		friend struct Camera;

		static std::shared_ptr<Core> initialize();
		std::shared_ptr<Entity> addEntity();
		std::shared_ptr<Keyboard> getKeyboard();
		std::shared_ptr<Camera> getCamera();
		std::shared_ptr<Resources> getResources();

		void start();
		
		static void loop();

		//Destructor:
		//alcMakeContextCUrrent(NULL);
		//alcDestroyContext(context);
		//alcCloseDevice(device);

	private:
		SDL_Window* window;
		SDL_GLContext glContext;

		ALCdevice* device;
		ALCcontext* context;

		std::vector<std::shared_ptr<Entity>> entities;
		std::weak_ptr<Core> self;
		std::shared_ptr<Keyboard> keyboard;
		std::weak_ptr<Camera> camera;
		std::shared_ptr<Resources> resources;

		float lastTime;
	};
}


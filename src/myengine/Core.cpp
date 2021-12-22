#include "Core.h"
#include "Entity.h"
#include "Exception.h"
#include "Transform.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Resources.h"

#include <iostream>
#include <AL/al.h>

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

namespace myengine
{
	std::weak_ptr<Core> _core;
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->self = rtn;

		rtn->window = SDL_CreateWindow("myengine", 
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

		if (!rtn->window)
		{
			throw Exception("Failed to create window");
		}

		SDL_ShowCursor(0);

		rtn->glContext = SDL_GL_CreateContext(rtn->window);

		if (!rtn->glContext)
		{
			throw Exception("Failed to create OpenGL context");
		}

		//todo call glew 
		if (glewInit() != GLEW_OK)
		{
			throw std::exception();
		}

		rtn->device = alcOpenDevice(NULL);
		if (!rtn->device) 
		{ 
			throw Exception("Failed to open default device");
		}

		rtn->context = alcCreateContext(rtn->device, NULL); 
		if (!rtn->context) 
		{
			alcCloseDevice(rtn->device);  
			throw Exception("Failed to create context"); 
		}

		if (!alcMakeContextCurrent(rtn->context)) 
		{
			alcDestroyContext(rtn->context);  
			alcCloseDevice(rtn->device);  
			throw Exception("Failed to make context current"); 
		}

		rtn->keyboard = std::make_shared<Keyboard>();
		rtn->mouse = std::make_shared<Mouse>();
		rtn->resources = std::make_shared<Resources>();

		_core = rtn;
		return rtn;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		rtn->transform = rtn->addComponent<Transform>();
		
		rtn->core = self;
		rtn->self = rtn;
		rtn->alive = true;

		rtn->addComponent<Transform>();

		entities.push_back(rtn);
		
		return rtn;
	}

	std::shared_ptr<Keyboard> Core::getKeyboard()
	{
		return keyboard;
	}

	std::shared_ptr<Mouse> Core::getMouse()
	{
		return mouse;
	}

	std::shared_ptr<Camera> Core::getCamera()
	{
		return camera.lock();
	}

	std::shared_ptr<Resources> Core::getResources()
	{
		return resources;
	}

	#ifdef EMSCRIPTEN
	void Core::start()
	{
	emscripten_set_main_loop(Core::loop, 0, 1);
	}
	#else
	void Core::start()
	{
		while(true)
		{
			loop();
		}
	}
	#endif
	
	void Core::loop()
	{
		bool running = true;
		SDL_Event e = { 0 };
		std::shared_ptr<Core> c = _core.lock();

		float now = SDL_GetTicks();
		c->deltaTime = (now - c->lastTime) / 1000.0f;
		c->lastTime = now;

		while (SDL_PollEvent(&e) != 0) 
		{ 
			if (e.type == SDL_QUIT) 
			{
				running = false;
			} 
			else if (e.type == SDL_KEYDOWN)
			{
				c->keyboard->keys.push_back(e.key.keysym.sym);
				c->keyboard->downKeys.push_back(e.key.keysym.sym);
			}
			else if (e.type == SDL_KEYUP)
			{
				for (std::vector<int>::iterator it = c->keyboard->keys.begin();
					it != c->keyboard->keys.end();)
				{
					if (*it == e.key.keysym.sym)
					{
						it = c->keyboard->keys.erase(it);
					}
					else
					{
						it++;
					}
				}
				c->keyboard->upKeys.push_back(e.key.keysym.sym);
			}
			else if (e.type == SDL_MOUSEMOTION)
			{
				c->mouse->setMousePosition(e.motion.x, e.motion.y);
			}
		}

		SDL_WarpMouseInWindow(c->window, 1280 / 2, 720 / 2);

		for (size_t ei = 0; ei < c->entities.size(); ei++) 
		{
			c->entities.at(ei)->tick(); 
		}

		glClearColor(0.39f, 0.58f, 0.93f, 1.0f); 
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
		glEnable(GL_DEPTH_TEST);

		for (size_t ei = 0; ei < c->entities.size(); ei++) 
		{
			c->entities.at(ei)->render(); 
		}

		for (size_t ei = 0; ei < c->entities.size(); ei++)
		{
			if (c->entities.at(ei)->alive == false)
			{
				c->entities.erase(c->entities.begin() + ei);
				ei--;
			}
		}

		SDL_GL_SwapWindow(c->window); 

		c->keyboard->downKeys.clear();
		c->keyboard->upKeys.clear();
	}

	float Core::getDeltaT()
	{
		return deltaTime;
	}
}


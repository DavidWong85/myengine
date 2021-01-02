#include "Component.h"

#include <memory>

#include <graphics/graphics.h>
#include <GL/glew.h>

namespace myengine
{
	struct Model;
	struct Texture;

	struct Renderer : public Component
	{
		void onInitialize();
		void onRender();
		void setModel(std::shared_ptr<Model> model);
		void setTexture(std::shared_ptr<Texture> texture);

	private:
		std::shared_ptr<graphics::ShaderProgram> shader;
		std::shared_ptr<Model> model;
		std::shared_ptr<Texture> texture;
	};
}
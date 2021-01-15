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
		/*
		* Initialize with build-in shader
		*/
		void onInitialize();
		/*
		* Render model
		*/
		void onRender();
		/*
		* Set custom shader
		* read from external files
		*/
		void setShader(std::string vertexPath, std::string fragmentPath);
		/*
		* set model
		*/
		void setModel(std::shared_ptr<Model> model);
		/*
		* set texture
		*/
		void setTexture(std::shared_ptr<Texture> texture);

	private:
		std::shared_ptr<graphics::ShaderProgram> shader;
		std::shared_ptr<Model> model;
		std::shared_ptr<Texture> texture;
	};
}
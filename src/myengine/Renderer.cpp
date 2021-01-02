#include "Core.h"
#include "Renderer.h"
#include "Entity.h"
#include "Camera.h"
#include "Transform.h"
#include "Model.h"
#include "Texture.h"

#include <glm/glm.hpp>

namespace myengine
{
	void Renderer::onInitialize()
	{
		shader = std::make_shared<graphics::ShaderProgram>();
		//load default model;
	}

	void Renderer::onRender()
	{
		glUseProgram(shader->getID());
		glm::mat4 projection = getCore()->getCamera()->getProjection();

		//Prepare the model matrix
		glm::mat4 model = getEntity()->getComponent<Transform>()->getModel();

		//Prepare the view matrix
		glm::mat4 view = getCore()->getCamera()->getView();

		//Upload the model matrix
		glUniformMatrix4fv(shader->getmodelLoc(), 1, GL_FALSE, glm::value_ptr(model));
		//Upload the projection matrix
		glUniformMatrix4fv(shader->getprojectionLoc(), 1, GL_FALSE, glm::value_ptr(projection));
		//Upload the view matrix
		glUniformMatrix4fv(shader->getviewLoc(), 1, GL_FALSE, glm::value_ptr(view));

		texture->texture->Apply();
		this->model->mesh->Draw();
		glUseProgram(0);
	}

	void Renderer::setModel(std::shared_ptr<Model> model)
	{
		this->model = model;
	}

	void Renderer::setTexture(std::shared_ptr<Texture> texture)
	{
		this->texture = texture;
	}
}


#include <myengine/myengine.h>

struct CameraController : public Component
{
	void onTick();

	glm::vec3 Move(float _deltaTime, float _rotation, glm::vec3 _position, glm::vec3 _direction);

private:
	float angle = 0;
	float rotation = 0;
	float sensitivity = 0.06;
	float speed = 5.0f;

	glm::vec3 temp = glm::vec3(0, 0, 0);
};
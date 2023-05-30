#include "Component.h"
#include "SceneObject.h"

#include "Vector2.h"
#include "Matrix3.h"

#include "raylib.h"

class PlayerMovement : public Component
{
private:
	Math::Vector2 velocity = Math::Vector2();
	Math::Vector2 acceleration = Math::Vector2(25, 0);
	float maxSpeed = 50;

public:
	PlayerMovement(SceneObject* obj)
	{
		this->obj = obj;
	}

	void OnUpdate(float deltaTime)
	{
		if (IsKeyDown(KeyboardKey::KEY_W))
		{
			//velocity = velocity + obj->transform.GetGlobalRotationMatrix() * acceleration * deltaTime;
		}
	}

};
#include "PlayerMovement.h"
#include "SceneObject.h"

#include "Vector2.h"
#include "Matrix3.h"

#include "raylib.h"

#include <math.h>

void PlayerMovement::OnUpdate(float deltaTime)
{
	if (IsKeyDown(KeyboardKey::KEY_W))
	{
		Math::Vector2 direction = Math::Vector2(obj->transform.GetGlobalRotationMatrix().m01, obj->transform.GetGlobalRotationMatrix().m11);
		velocity = velocity + (direction * acceleration * deltaTime);
		
		//check if above max speed
		if (velocity.Magnitude() > abs(maxSpeed))
		{
			//do it like this so change of direction is slower
			velocity = velocity.Normalized() * maxSpeed;
		}
	}

	if (IsKeyDown(KeyboardKey::KEY_A))
	{
		obj->transform.Rotate(turnSpeed * deltaTime);
	}
	if (IsKeyDown(KeyboardKey::KEY_D))
	{
		obj->transform.Rotate(-turnSpeed * deltaTime);
	}

	obj->transform.Translate(Math::Vector2(velocity.x, velocity.y) * deltaTime);
}
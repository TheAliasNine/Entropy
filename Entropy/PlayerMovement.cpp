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
		Math::Vector2 addedVel = direction * acceleration * deltaTime;

		if (velocity.Magnitude() == 0) //to avoid nan on 0
		{
			velocity = velocity + addedVel;
		}
		else
		{
			//remove some velocity in current direction to increase the ability to turn without making it seem to turn too fast
			velocity = velocity - (velocity.Normalized() * addedVel.Magnitude());
			velocity = velocity + (addedVel * 2);
		}
		
		//set to max speed
		if (velocity.Magnitude() > abs(maxSpeed))
		{
			velocity = velocity.Normalized() * maxSpeed;
			
		}
	}
	else
	{
		//slow down proportionally for spacey feeling
		if (abs(velocity.Magnitude() < 0.001f))
		{
			velocity = Math::Vector2();
		}
		else
		{
			velocity = velocity / deceleration;
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
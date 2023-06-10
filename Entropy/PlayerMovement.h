#pragma once

#include "Component.h"
#include "CollisionInfo.h"

#include "Vector3.h"

class PlayerMovement : public Component
{
public:
	PlayerMovement(SceneObject* obj)
	{
		this->obj = obj;
	}

	void OnUpdate(float deltaTime) override;

	void OnDraw() override {};
	void OnCollision(CollisionInfo info) override;
private:
	bool invincible = false;
	float invincibleTimer = 0;
	float invincibleTime = 1.5f;

	Math::Vector2 velocity = Math::Vector2();
	float acceleration = 275;
	float maxSpeed = 425;
	float turnSpeed = 3;
	float deceleration = 0.8f;
};
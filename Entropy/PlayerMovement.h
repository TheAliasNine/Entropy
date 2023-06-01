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
	void OnCollision(CollisionInfo info) override {};
private:
	Math::Vector2 velocity = Math::Vector2();
	float acceleration = 275;
	float maxSpeed = 425;
	float turnSpeed = 3;
	float deceleration = 1.015f;
};
#pragma once
#include "SceneObject.h"
#include "Component.h"

class CollisionInfo;

class PlayerShooting : public Component
{
public:
	PlayerShooting(SceneObject* obj)
	{
		this->obj = obj;
	}

	void OnUpdate(float deltaTime) override;

	void OnCollision(CollisionInfo info)
	{

	}
};
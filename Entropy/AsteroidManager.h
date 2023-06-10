#pragma once
#include "Component.h"
#include "SceneObject.h"

/// <summary>
/// Put on player object
/// </summary>
class AsteroidManager : public Component
{
public:
	AsteroidManager(SceneObject* obj, SceneObject* player)
	{
		this->obj = obj;
		this->player = player;
	}

	void OnUpdate(float deltaTime) override;
	void OnCollision(CollisionInfo info) override {}
	SceneObject* obj;
private:
	int wave = 0;

	SceneObject* player;

	float minDist = 100;
	float maxDist = 300;
};
#pragma once

#include "Component.h"

class CollisionInfo;
class Bullet : public Component
{
public:
	Bullet(SceneObject* obj);

	void OnUpdate(float deltaTime) override;
	void OnCollision(CollisionInfo info) override;

private:
	float speed = 800;
	float liveTime = 0.75f;
	float timer = 0;
};
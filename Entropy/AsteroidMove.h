#pragma once
#include "Component.h"

#include "Vector2.h"

class AsteroidMove : public Component
{
public:
	enum Size
	{
		Large,
		Medium,
		Small,
	};
	AsteroidMove(SceneObject* obj, float rotation, Size size);

	void OnUpdate(float deltaTime) override;
	void OnCollision(CollisionInfo info) override;

private:
	float speed = 80;
	Math::Vector2 direction;
	Size size;


	void Break();
};
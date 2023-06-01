#pragma once
#include "Component.h" 
#include "Application.h"

class SceneObject;
class LineBased;
class Plane;
class AABB;

class Collider : public Component
{
public:

	enum Layer
	{
		Player,
		Asteroid,
		Enemy,
		Solid,
		PlayerBullet,
		InBounds,
	};


	Collider(SceneObject* obj, Layer layer);

	~Collider();

	Layer layer = Solid;


	virtual void CheckCollision(Collider* other) = 0;
	virtual void CheckCollision(LineBased* other) = 0;
	virtual void CheckCollision(Plane* other) = 0;
	virtual void CheckCollision(AABB* other) = 0;
};
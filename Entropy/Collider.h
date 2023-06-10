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


	virtual bool CheckCollision(Collider* other) = 0;
	virtual bool CheckCollision(LineBased* other) = 0;
	virtual bool CheckCollision(Plane* other) = 0;
	virtual bool CheckCollision(AABB* other) = 0;
};
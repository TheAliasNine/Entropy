#pragma once
#include "Component.h" 
#include "Application.h"

class SceneObject;
class LineBased;

class Collider : public Component
{
public:

	Collider(SceneObject* obj)
	{
		this->obj = obj;
	}

	enum Layer
	{
		Player,
		Asteroid,
		Enemy,
		Solid,
	};

	Layer layer = Solid;


	virtual void AddColliderToHandler() = 0;
	virtual void CheckCollision(Collider* other) = 0;
	virtual void CheckCollision(LineBased* other)  = 0;
};
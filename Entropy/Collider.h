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

	SceneObject* obj = nullptr;


	virtual void AddColliderToHandler() = 0;
	virtual void CheckCollision(const Collider* other) const = 0;
	virtual void CheckCollision(const LineBased* other) const = 0;
};
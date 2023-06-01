#pragma once
#include "SceneObject.h"
#include "Collider.h"
#include "AABB.h"

class ScreenBoundObject : public SceneObject
{
private:
	bool inBounds;
	Collider* boundedCollider;
	//AABB*

public:

	virtual void OnUpdate(float deltaTime);
};
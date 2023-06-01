#pragma once

#include "Collider.h"

class SceneObject;

class CollisionInfo
{
public:
	CollisionInfo(SceneObject* other, Collider::Layer collisionLayer);

	SceneObject* otherObj;
	Collider::Layer collisionLayer;
};
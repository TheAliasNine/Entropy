#pragma once

#include "Collider.h"

class CollisionInfo
{
public:
	CollisionInfo(SceneObject* other, Collider::Layer collisionLayer);

	SceneObject* otherObj;
	Collider::Layer collisionLayer;
};
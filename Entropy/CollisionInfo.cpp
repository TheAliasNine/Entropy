#include "CollisionInfo.h"
#include "Collider.h"

CollisionInfo::CollisionInfo(SceneObject* other, Collider::Layer layer)
{
	otherObj = other;
	collisionLayer = layer;
}
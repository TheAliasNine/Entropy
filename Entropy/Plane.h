#pragma once

#include "Collider.h"
#include "AABB.h"
#include "CollisionInfo.h"
#include "Vector2.h"

class Plane : public Collider
{
public:
	Plane(SceneObject* obj, Layer layer, float distance, Math::Vector2 normal);

	void OnCollision(CollisionInfo info) override {}


	void CheckCollision(Collider* collider) override;
	void CheckCollision(LineBased* lineBased) override;
	void CheckCollision(Plane* lineBased) override;
	void CheckCollision(AABB* aabb) override;

	float GetGlobalDist();
	Math::Vector2 GetGlobalNormal();


private:
	//origin is the origin of the object
	float d; //how far along the normal is the plane from the origin
	Math::Vector2 normal;
};
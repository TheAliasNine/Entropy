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


	bool CheckCollision(Collider* collider) override;
	bool CheckCollision(LineBased* lineBased) override;
	bool CheckCollision(Plane* lineBased) override;
	bool CheckCollision(AABB* aabb) override;

	float GetGlobalDist();
	Math::Vector2 GetGlobalNormal();


private:
	//origin is the origin of the object
	float d; //how far along the normal is the plane from the origin
	Math::Vector2 normal;
};
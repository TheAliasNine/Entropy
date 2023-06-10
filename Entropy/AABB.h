#pragma once

#include "Collider.h"
#include "CollisionInfo.h"

#include "Vector2.h"

class AABB : public Collider
{
public:
	AABB(SceneObject* obj, Layer layer, Math::Vector2 min, Math::Vector2 max);

	void OnCollision(CollisionInfo info) override {}


	bool CheckCollision(Collider* collider) override;
	bool CheckCollision(LineBased* lineBased) override;
	bool CheckCollision(Plane* lineBased) override;
	bool CheckCollision(AABB* aabb) override;

	Math::Vector2 GetGlobalMin();
	Math::Vector2 GetGlobalMax();

private:
	Math::Vector2 min;
	Math::Vector2 max;
};
#pragma once
#include "SceneObject.h"
#include "Collider.h"
#include "AABB.h"
#include "LineBased.h"
#include "CollisionInfo.h"

#include "Vector2.h"


class ScreenBoundObject : public SceneObject
{
public:
	ScreenBoundObject(Application* app, AABB* screen);
private:
	bool inBounds;
	Math::Vector2* previousFurthest;
	//The collider component this object has to check if it is in bounds or not
	LineBased* boundCollider = nullptr;
	//AABB*
	//specific bound Collider that doesn't go into the collision and just any bound objects manually check against it...


	//reference to the aabb collider that references the screen
	AABB* screenCollider;

public:

	virtual void Update(float deltaTime) override;
	void SetBound(LineBased* bound);
};
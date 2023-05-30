#pragma once


class SceneObject;
class CollisionInfo;

class Component
{
public:

	virtual void OnUpdate(float deltaTime) {};
	virtual void OnDraw() {};

	virtual void OnCollision(CollisionInfo info) = 0;

	SceneObject* obj = nullptr;
};
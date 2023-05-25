#pragma once


class SceneObject;
class Component
{
public:

	virtual void OnUpdate() = 0;
	virtual void OnDraw() = 0;

	SceneObject* obj;
};
#pragma once

#include "Component.h"

class SceneObject;
class Collider : public Component
{
public:
	enum Layer
	{
		Player,
		Asteroid,
		Enemy,
		Solid,
	};

	Layer layer = Solid;

	SceneObject * obj = nullptr;
};
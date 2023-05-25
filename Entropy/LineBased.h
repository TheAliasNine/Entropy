#pragma once

#include "Component.h"

class SceneObject;
class LineBased : public Component
{
public:
	LineBased();
	LineBased(SceneObject * so);

	void OnDraw();
	void OnUpdate();
};
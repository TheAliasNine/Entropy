#include "ScreenBoundObject.h"

void ScreenBoundObject::OnUpdate(float deltaTime)
{
	if (!inBounds)
	{
		//find furthest point from the border
		//then translate object so that it is touching the opposite border
	}
	inBounds = false;
}
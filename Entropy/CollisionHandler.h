#pragma once


#include "Collider.h"

#include <vector>

class CollisionHandler
{
public:
	void CheckCollisions();

private:
	std::vector<Collider> colliders;
};
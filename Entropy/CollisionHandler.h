#pragma once

#include <vector>

class Collider;


class CollisionHandler
{
public:
	//Maybe make a two stage collision system in future
	void CheckCollisions();



	void AddCollider(Collider* collider);
	void RemoveCollider(Collider* collider);

private:
	std::vector<Collider*> colliders;
};
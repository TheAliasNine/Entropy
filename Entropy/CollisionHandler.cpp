#include "CollisionHandler.h"

#include "Collider.h"


#include "LineBased.h"

void CollisionHandler::CheckCollisions()
{
	for (int base = 0; base < colliders.size() - 1; base++)
	{
		for (int other = base + 1; other < colliders.size(); other++)
		{
			//change when more than line collisions add
			colliders[base]
		}
	}
}



void CollisionHandler::AddCollider(Collider* collider)
{
	colliders.push_back(collider);
}

void CollisionHandler::RemoveCollider(Collider* collider)
{
	std::vector<Collider*>::iterator it = colliders.begin();
	for (int i = 0; i < colliders.size(); i++)
	{
		if (colliders[i] == collider)
		{
			colliders.erase(it);
			break;
		}

		it++;
	}
}
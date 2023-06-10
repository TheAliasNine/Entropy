#include "CollisionHandler.h"
#include "SceneObject.h"
#include "Collider.h"
#include "CollisionInfo.h"

#include "LineBased.h"


//ToDo:
//add continuous collision checking so things don't phase through between frames
void CollisionHandler::CheckCollisions()
{
	for (int base = 0; base + 1 < colliders.size(); base++)
	{
		for (int other = base + 1; other < colliders.size(); other++)
		{
			//add a collision layer matix to check

			if (colliders[base]->CheckCollision(colliders[other]))
			{
				Collider* otherPointer = colliders[other];
				CollisionInfo baseInfo = CollisionInfo(colliders[other]->obj, colliders[other]->layer);
				colliders[base]->obj->OnCollision(baseInfo);
				
				CollisionInfo otherInfo = CollisionInfo(colliders[base]->obj, colliders[base]->layer);
				otherPointer->obj->OnCollision(otherInfo);
			}
		}
	}
}



void CollisionHandler::AddCollider(Collider* collider)
{
	colliders.push_back(collider);
}

void CollisionHandler::RemoveCollider(Collider* collider)
{
	bool removed = false;
	std::vector<Collider*>::iterator it = colliders.begin();
	for (int i = 0; i < colliders.size(); i++)
	{
		if (colliders[i] == collider)
		{
			colliders.erase(it);
			removed = true;
			break;
		}

		it++;
	}
	if (!removed)
	{

	}
}
#include "AABB.h"
#include "Plane.h"
#include "LineBased.h"
#include "CollisionInfo.h"
#include "SceneObject.h"

#include "Vector2.h"

Plane::Plane(SceneObject* obj, Layer layer, float distance, Math::Vector2 normal) : Collider(obj, layer)
{
	d = distance;
	this->normal = normal;
}

bool Plane::CheckCollision(Collider* collider)
{
	return collider->CheckCollision(this);
}


float Plane::GetGlobalDist()
{
	return obj->transform.GetGlobalTranslation().Magnitude() + d;
}

Math::Vector2 Plane::GetGlobalNormal()
{
	Math::Vector3 rotatedNormal = obj->transform.GetGlobalRotationMatrix() * Math::Vector3(normal.x, normal.y, 0);
	return Math::Vector2(rotatedNormal.x, rotatedNormal.y);
}


bool Plane::CheckCollision(LineBased* lineBased)
{
	for (int i = 0; i < lineBased->globalLines.size(); i++)
	{
		//if start or end points collide with the plane
		float dotStart = Math::Vector2::Dot(GetGlobalNormal(), lineBased->globalLines[i].start);
		dotStart -= GetGlobalDist();
		float dotEnd = Math::Vector2::Dot(GetGlobalNormal(), lineBased->globalLines[i].end);
		dotEnd -= GetGlobalDist();

		if (dotStart > 0 || dotEnd > 0) return true;
	}
	return false;
}

/// <summary>
/// Blank function since this project doesn't require plane on plane collision
/// </summary>
bool Plane::CheckCollision(Plane* lineBased)
{
	return false;
}

bool Plane::CheckCollision(AABB* aabb)
{
	//just haven't done this, haha if it took a while to realise this was the cause of a bug
	return false;
}
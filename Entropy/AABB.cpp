#include "AABB.h"
#include "Plane.h"
#include "LineBased.h"
#include "CollisionInfo.h"
#include "SceneObject.h"

#include "Vector2.h"
#include "Vector3.h"
#include "Matrix3.h"

AABB::AABB(SceneObject* obj, Layer layer, Math::Vector2 min, Math::Vector2 max) : Collider(obj, layer)
{
	this->min = min;
	this->max = max;
}


Math::Vector2 AABB::GetGlobalMax()
{
	Math::Vector3 v3 = obj->transform.GetGlobalMatrix() * Math::Vector3(max.x, max.y, 1);
	return Math::Vector2(v3.x, v3.y);
}

Math::Vector2 AABB::GetGlobalMin()
{
	Math::Vector3 v3 = obj->transform.GetGlobalMatrix() * Math::Vector3(min.x, min.y, 1);
	return Math::Vector2(v3.x, v3.y);
}


void AABB::CheckCollision(Collider* collider)
{
	collider->CheckCollision(this);
}

void AABB::CheckCollision(LineBased* lineBased)
{
	for (int i = 0; i < lineBased->globalLines.size(); i++)
	{
		//if start or end points are within the min and the max
		Math::Vector2 globalMax = GetGlobalMax();
		Math::Vector2 globalMin = GetGlobalMin();
		if ((lineBased->globalLines[i].start.x > globalMin.x && lineBased->globalLines[i].start.x < globalMax.x
			&& lineBased->globalLines[i].start.y > globalMin.x && lineBased->globalLines[i].start.y < globalMax.x)
			|| (lineBased->globalLines[i].end.x > globalMin.x && lineBased->globalLines[i].end.x < globalMax.x
				&& lineBased->globalLines[i].end.y > globalMin.x && lineBased->globalLines[i].end.y < globalMax.x))
		{
			CollisionInfo thisInfo = CollisionInfo(lineBased->obj, lineBased->layer);
			obj->OnCollision(thisInfo);

			CollisionInfo otherInfo = CollisionInfo(obj, layer);
			lineBased->obj->OnCollision(otherInfo);
			return;
		}
	}
}

/// <summary>
/// Blank function since this project doesn't require plane on plane collision
/// </summary>
void AABB::CheckCollision(Plane* plane)
{

}

void AABB::CheckCollision(AABB* aabb)
{
	Math::Vector2 globalMax = GetGlobalMax();
	Math::Vector2 globalMin = GetGlobalMin();
	Math::Vector2 globalMax2 = aabb->GetGlobalMax();
	Math::Vector2 globalMin2 = aabb->GetGlobalMin();
	if (!(globalMax.x < globalMin2.x || globalMax2.x < globalMin.x || globalMax.y < globalMin2.y || globalMax2.y < globalMin.y))
	{
		CollisionInfo thisInfo = CollisionInfo(aabb->obj, aabb->layer);
		obj->OnCollision(thisInfo);

		CollisionInfo otherInfo = CollisionInfo(obj, layer);
		aabb->obj->OnCollision(otherInfo);
	}
}
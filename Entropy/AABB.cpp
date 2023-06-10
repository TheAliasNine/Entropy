#include "AABB.h"
#include "Plane.h"
#include "LineBased.h"
#include "CollisionInfo.h"
#include "SceneObject.h"

#include "Vector2.h"
#include "Vector3.h"
#include "Matrix3.h"

#include <math.h>

AABB::AABB(SceneObject* obj, Layer layer, Math::Vector2 min, Math::Vector2 max) : Collider(obj, layer)
{
	this->min = min;
	this->max = max;
}


Math::Vector2 AABB::GetGlobalMax()
{
	if (obj == nullptr)
	{
		return max;
	}
	Math::Vector3 v3 = obj->transform.GetGlobalMatrix() * Math::Vector3(max.x, max.y, 1);
	return Math::Vector2(v3.x, v3.y);
}

Math::Vector2 AABB::GetGlobalMin()
{
	if (obj == nullptr)
	{
		return min;
	}
	Math::Vector3 v3 = obj->transform.GetGlobalMatrix() * Math::Vector3(min.x, min.y, 1);
	return Math::Vector2(v3.x, v3.y);
}


bool AABB::CheckCollision(Collider* collider)
{
	return collider->CheckCollision(this);
}

bool AABB::CheckCollision(LineBased* lineBased)
{
	for (int i = 0; i < lineBased->globalLines.size(); i++)
	{
		Math::Vector2 AtoB = lineBased->globalLines[i].end - lineBased->globalLines[i].start;
		float lineMag = AtoB.Magnitude();
		Math::Vector2 lineDir = AtoB / lineMag;
		Math::Vector2 dirfrac = Math::Vector2(1.0f / lineDir.x, 1.0f / lineDir.y);

		Math::Vector2 globalMax = GetGlobalMax();
		Math::Vector2 globalMin = GetGlobalMin();

		float t1 = (globalMin.x - lineBased->globalLines[i].start.x) * dirfrac.x;
		float t2 = (globalMax.x - lineBased->globalLines[i].start.x) * dirfrac.x;
		float t3 = (globalMin.y - lineBased->globalLines[i].start.y) * dirfrac.y;
		float t4 = (globalMax.y - lineBased->globalLines[i].start.y) * dirfrac.y;


		float tmin = std::max(std::min(t1, t2), std::min(t3, t4));
		float tmax = std::min(std::max(t1, t2), std::max(t3, t4));

		if (!(tmax < 0) && !(tmin > tmax) && tmin < lineMag)
		{
			return true;
		}
	}
	return false;
}

/// <summary>
/// Blank function since this project doesn't require plane on plane collision
/// </summary>
bool AABB::CheckCollision(Plane* plane)
{
	return false;
}

bool AABB::CheckCollision(AABB* aabb)
{
	Math::Vector2 globalMax = GetGlobalMax();
	Math::Vector2 globalMin = GetGlobalMin();
	Math::Vector2 globalMax2 = aabb->GetGlobalMax();
	Math::Vector2 globalMin2 = aabb->GetGlobalMin();
	if (!(globalMax.x < globalMin2.x || globalMax2.x < globalMin.x || globalMax.y < globalMin2.y || globalMax2.y < globalMin.y)) return true;
	return false;
}
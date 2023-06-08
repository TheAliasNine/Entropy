#include "Collider.h"
#include "CollisionInfo.h"
#include "LineBased.h"
#include "Line.h"
#include "Plane.h"
#include "SceneObject.h"
#include "SoTransform.h"

#include "Vector2.h"

#include "raylib.h"


#include <math.h>

LineBased::LineBased(SceneObject* so, Layer layer, Color color) : Collider(so, layer)
{
	this->layer = layer;
	this->color = color;
}


void LineBased::OnDraw()
{
	UpdateGlobal();
	for (int i = 0; i < lines.size(); i++)
	{
		DrawLine((int)roundf(globalLines[i].start.x), 
			(int)roundf(globalLines[i].start.y), 
			(int)roundf(globalLines[i].end.x), 
			(int)roundf(globalLines[i].end.y), 
			color);
	}
}

void LineBased::AddLine(Line line)
{
	lines.push_back(line);
	Math::Vector3 startPos = obj->transform.GetGlobalMatrix() * Math::Vector3(line.start.x, line.start.y, 1);
	Math::Vector3 endPos = obj->transform.GetGlobalMatrix() * Math::Vector3(line.end.x, line.end.y, 1);
	globalLines.push_back(Line(Math::Vector2(startPos.x, startPos.y), Math::Vector2(endPos.x, endPos.y)));
	UpdateGlobal();
}

void LineBased::UpdateGlobal()
{
	for (int i = 0; i < lines.size(); i++)
	{
		Math::Vector3 startPos = obj->transform.GetGlobalMatrix() * Math::Vector3(lines[i].start.x, lines[i].start.y, 1);
		Math::Vector3 endPos = obj->transform.GetGlobalMatrix() * Math::Vector3(lines[i].end.x, lines[i].end.y, 1);

		globalLines[i] = Line(Math::Vector2(startPos.x, startPos.y), Math::Vector2(endPos.x, endPos.y));
	}
}
bool LineBased::CheckCollision(Collider* collider)
{
	return collider->CheckCollision(this);
}

bool LineBased::CheckCollision(LineBased* lineBased)
{
	UpdateGlobal();
	lineBased->UpdateGlobal();
	for (int mainIndex = 0; mainIndex < lines.size(); mainIndex++)
	{
		Line AB = globalLines[mainIndex];
		Math::Vector2 m = AB.end - AB.start;

		for (int otherIndex = 0; otherIndex < lineBased->lines.size(); otherIndex++)
		{
			Line CD = lineBased->globalLines[otherIndex];
			Math::Vector2 n = CD.end - CD.start;




			float t1 = Math::Vector2::Cross(CD.end, n);
			float t2 = Math::Vector2::Cross(AB.end, n);
			float t3 = Math::Vector2::Cross(m, n);
			float t = (t2 - t1) / t3;

			float s1 = Math::Vector2::Cross(AB.end, m);
			float s2 = Math::Vector2::Cross(CD.end, m);
			float s3 = Math::Vector2::Cross(n, m);
			float s = (s2 - s1) / s3;

			if ((t >= 0 && t <= 1) && (s >= 0 && s <= 1)) return true;
		}
	}
	return false;
}

bool LineBased::CheckCollision(Plane* plane)
{
	for (int i = 0; i < globalLines.size(); i++)
	{
		//if start or end points collide with the plane
		float dotStart = Math::Vector2::Dot(plane->GetGlobalNormal(), globalLines[i].start);
		dotStart -= plane->GetGlobalDist();
		float dotEnd = Math::Vector2::Dot(plane->GetGlobalNormal(), globalLines[i].end);
		dotEnd -= plane->GetGlobalDist();

		if (dotStart > 0 || dotEnd > 0)	return true;
	}
	return false;
}

bool LineBased::CheckCollision(AABB* aabb)
{
	for (int i = 0; i < globalLines.size(); i++)
	{
		Math::Vector2 AtoB = globalLines[i].end - globalLines[i].start;
		float lineMag = AtoB.Magnitude();
		Math::Vector2 lineDir = AtoB / lineMag;
		Math::Vector2 dirfrac = Math::Vector2(1.0f / lineDir.x, 1.0f / lineDir.y);

		Math::Vector2 globalMax = aabb->GetGlobalMax();
		Math::Vector2 globalMin = aabb->GetGlobalMin();

		float t1 = (globalMin.x - globalLines[i].start.x) * dirfrac.x;
		float t2 = (globalMax.x - globalLines[i].start.x) * dirfrac.x;
		float t3 = (globalMin.y - globalLines[i].start.y) * dirfrac.y;
		float t4 = (globalMax.y - globalLines[i].start.y) * dirfrac.y;


		float tmin = std::max(std::min(t1, t2), std::min(t3, t4));
		float tmax = std::min(std::max(t1, t2), std::max(t3, t4));

		if (!(tmax < 0) && !(tmin > tmax) && tmin < lineMag)
		{
			return true;
		}
	}
	return false;
}
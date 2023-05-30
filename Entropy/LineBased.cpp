#include "Collider.h"
#include "CollisionInfo.h"
#include "LineBased.h"
#include "Line.h"
#include "SceneObject.h"
#include "SoTransform.h"

#include "Vector2.h"

#include "raylib.h"


#include <math.h>


LineBased::LineBased(Layer layer, Color color, SceneObject* so) : Collider(so)
{
	this->layer = layer;
	this->color = color;
	AddColliderToHandler();
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
}

void LineBased::UpdateGlobal()
{
	for (int i = 0; i < globalLines.size(); i++)
	{
		Math::Vector3 startPos = obj->transform.GetGlobalMatrix() * Math::Vector3(lines[i].start.x, lines[i].start.y, 1);
		Math::Vector3 endPos = obj->transform.GetGlobalMatrix() * Math::Vector3(lines[i].end.x, lines[i].end.y, 1);

		globalLines[i] = Line(Line(Math::Vector2(startPos.x, startPos.y), Math::Vector2(endPos.x, endPos.y)));
	}
}


void LineBased::AddColliderToHandler()
{
	obj->app->GetCollisionHandler()->AddCollider(this);
}

void LineBased::CheckCollision(const Collider* collider) const
{
	collider->CheckCollision(this);
}

void LineBased::CheckCollision(const LineBased* lineBased) const
{
	for (int mainIndex = 0; mainIndex < lines.size(); mainIndex++)
	{
		Line ab = lines[mainIndex];
		Math::Vector2 abDir = (ab.start - ab.end).Normalized();
		Math::Vector2 abInverse = Math::Vector2(-abDir.y, abDir.x);

		for (int otherIndex = 0; otherIndex < lineBased->lines.size(); otherIndex++)
		{
			Line cd = lines[otherIndex];

			//get vector from startA to startB
			Math::Vector2 aToC = cd.start - ab.start;
			Math::Vector2 cToD = cd.end - cd.start;
			//get vector for b start to b end

			float dot = Math::Vector2::Dot(cToD, abInverse);
			if (dot < 0.000001f) continue;

			float t = (aToC.y * cToD.x - aToC.x * cToD.y) / dot;
			float s = Math::Vector2::Dot(aToC, abInverse) / dot;

			if ((t >= 0 && t <= 1) || (s >= 0 && s <= 1))
			{
				CollisionInfo thisInfo = CollisionInfo(lineBased->obj, lineBased->layer);
				obj->OnCollision(thisInfo);

				CollisionInfo otherInfo = CollisionInfo(obj, layer);
				lineBased->obj->OnCollision(otherInfo);

				return;
			}
		}
	}
}
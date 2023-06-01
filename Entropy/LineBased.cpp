#include "Collider.h"
#include "CollisionInfo.h"
#include "LineBased.h"
#include "Line.h"
#include "SceneObject.h"
#include "SoTransform.h"

#include "Vector2.h"

#include "raylib.h"


#include <math.h>


#include <iostream>

LineBased::LineBased(Layer layer, Color color, SceneObject* so) : Collider(so)
{
	this->layer = layer;
	this->color = color;
	AddColliderToHandler();
}

LineBased::~LineBased()
{
	obj->app->GetCollisionHandler()->RemoveCollider(this);
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

void LineBased::CheckCollision(Collider* collider)
{
	collider->CheckCollision(this);
}

void LineBased::CheckCollision(LineBased* lineBased)
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

			if ((t >= 0 && t <= 1) && (s >= 0 && s <= 1))
			{
				CollisionInfo thisInfo = CollisionInfo(lineBased->obj, lineBased->layer);
				obj->OnCollision(thisInfo);

				CollisionInfo otherInfo = CollisionInfo(obj, layer);
				lineBased->obj->OnCollision(otherInfo);

				std::cout << "Collision" << std::endl;
				return;
			}
		}
	}
}
#include "ScreenBoundObject.h"

#include "Vector2.h"

#include <math.h>


ScreenBoundObject::ScreenBoundObject(Application* app, AABB* screen) : SceneObject(app)
{
	screenCollider = screen;
	inBounds = false;
	previousFurthest = nullptr;
}


void ScreenBoundObject::Update(float deltaTime)
{
	inBounds = screenCollider->CheckCollision(boundCollider);
	if (!inBounds)
	{
		Math::Vector2 FP = boundCollider->globalLines[0].start; //(FP meaning Furthest Point)
		Math::Vector2 FPClosestBorderPoint = Math::Vector2::Clamp(boundCollider->globalLines[0].start, screenCollider->GetGlobalMin(), screenCollider->GetGlobalMax());
		if (previousFurthest == nullptr)
		{
			float FPDistSqr = (FPClosestBorderPoint - boundCollider->globalLines[0].start).MagnitudeSqr();;
			for (int i = 0; i < boundCollider->globalLines.size(); i++)
			{
				//find closest part of the border to it  (clamp the value)
				//then find the distance^2 (for efficiency) compare distanceSqr against the current highest

				Math::Vector2 closestBorder = Math::Vector2::Clamp(boundCollider->globalLines[i].start, screenCollider->GetGlobalMin(), screenCollider->GetGlobalMax());
				float distSqr = (closestBorder - boundCollider->globalLines[i].start).MagnitudeSqr();

				if (distSqr > FPDistSqr)
				{
					FP = boundCollider->globalLines[i].start;
					previousFurthest = &boundCollider->globalLines[i].start;
					FPClosestBorderPoint = closestBorder;
					FPDistSqr = distSqr;
				}

				closestBorder = Math::Vector2::Clamp(boundCollider->globalLines[i].end, screenCollider->GetGlobalMin(), screenCollider->GetGlobalMax());
				distSqr = (closestBorder - boundCollider->globalLines[i].end).MagnitudeSqr();

				if (distSqr > FPDistSqr)
				{
					FP = boundCollider->globalLines[i].end;
					previousFurthest = &boundCollider->globalLines[i].end;
					FPClosestBorderPoint = closestBorder;
					FPDistSqr = distSqr;
				}
			}
		}
		else
		{
			FP = *previousFurthest;
			FPClosestBorderPoint = Math::Vector2::Clamp(FP, screenCollider->GetGlobalMin(), screenCollider->GetGlobalMax());
		}
		Math::Vector2 displacementFromBorder = FP - FPClosestBorderPoint;

		//find out how much to translate the object so its touching the opposite border
		//if dimension is positive translate the object (min - furthestpoint)
		//if dimension is negative translate the object (max - furthestpoint)

		Math::Vector2 translation = Math::Vector2();
		if (displacementFromBorder.x < 0)
		{
			translation.x = screenCollider->GetGlobalMax().x - FP.x;
		}
		else if (displacementFromBorder.x > 0)
		{
			translation.x = screenCollider->GetGlobalMin().x - FP.x;
		}
		if (displacementFromBorder.y < 0)
		{
			translation.y = screenCollider->GetGlobalMax().y - FP.y;
		}
		else if (displacementFromBorder.y > 0)
		{
			translation.y = screenCollider->GetGlobalMin().y - FP.y;
		}
		transform.Translate(translation);
	}
	else
	{
		previousFurthest = nullptr;
	}
	SceneObject::Update(deltaTime);
}

void ScreenBoundObject::SetBound(LineBased* bound)
{
	boundCollider = bound;
}
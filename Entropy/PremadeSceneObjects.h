#pragma once
#include "SceneObject.h"
#include "AllComponents.h"

class Application;
namespace PremadeSceneObjects
{
	static SceneObject* Player(Application* app)
	{
		SceneObject* so = new SceneObject(app);
		LineBased* lines = new LineBased(Collider::Player, WHITE, so);

		lines->AddLine(Line(Math::Vector2(-10, -15), Math::Vector2(0, 15)));
		lines->AddLine(Line(Math::Vector2(10, -15), Math::Vector2(0, 15)));
		lines->AddLine(Line(Math::Vector2(8, -9), Math::Vector2(-8, -9)));
		PlayerMovement* playerMovement = new PlayerMovement(so);
		so->AddComponent(playerMovement);
		so->AddComponent(lines);
		so->transform.Translate(Math::Vector2(100, 100));
		return so;
	}
}
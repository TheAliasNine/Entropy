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

		PlayerShooting* shooting = new PlayerShooting(so);
		so->AddComponent(shooting);
		so->transform.Translate(Math::Vector2(100, 100));
		return so;
	}

	static SceneObject* PlayerBullet(Application* app)
	{
		SceneObject* so = new SceneObject(app);
		LineBased* lines = new LineBased(Collider::PlayerBullet, WHITE, so);
		lines->AddLine(Line(Math::Vector2(0, 10), Math::Vector2(0, 15)));

		so->AddComponent(lines);

		Bullet* bullet = new Bullet(so);
		so->AddComponent(bullet);

		return(so);
	}
}
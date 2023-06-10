#pragma once
#include "SceneObject.h"
#include "ScreenBoundObject.h"
#include "AllComponents.h"

class Application;
namespace PremadeSceneObjects
{
	static SceneObject* Player(Application* app)
	{
		SceneObject* so = new SceneObject(app);
		LineBased* lines = new LineBased(so, Collider::Player, WHITE);

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
		LineBased* lines = new LineBased(so, Collider::PlayerBullet, WHITE);
		lines->AddLine(Line(Math::Vector2(0, 10), Math::Vector2(0, 15)));

		so->AddComponent(lines);

		Bullet* bullet = new Bullet(so);
		so->AddComponent(bullet);

		return(so);
	}

	static AABB* InBounds(float screenWidth, float screenheight)
	{
		AABB* aabb = new AABB(nullptr, Collider::InBounds, Math::Vector2(), Math::Vector2(screenWidth, screenheight));
		return aabb;
	}


	//ScreenBoundObjects
	static SceneObject* ScreenBoundPlayer(Application* app, AABB* screen)
	{
		ScreenBoundObject* so = new ScreenBoundObject(app, screen);
		LineBased* lines = new LineBased(so, Collider::Player, WHITE);

		lines->AddLine(Line(Math::Vector2(-10, -15), Math::Vector2(0, 15)));
		lines->AddLine(Line(Math::Vector2(10, -15), Math::Vector2(0, 15)));
		lines->AddLine(Line(Math::Vector2(8, -9), Math::Vector2(-8, -9)));
		PlayerMovement* playerMovement = new PlayerMovement(so);
		so->AddComponent(playerMovement);
		so->AddComponent(lines);
		so->SetBound(lines);
		PlayerShooting* shooting = new PlayerShooting(so);
		so->AddComponent(shooting);
		so->transform.Translate(Math::Vector2(250, 250));
		return so;
	}

	static SceneObject* ScreenBoundPlayerBullet(Application* app, AABB* screen)
	{
		ScreenBoundObject* so = new ScreenBoundObject(app, screen);
		LineBased* lines = new LineBased(so, Collider::PlayerBullet, WHITE);
		lines->AddLine(Line(Math::Vector2(0, 0), Math::Vector2(0, 7)));

		so->AddComponent(lines);
		so->SetBound(lines);

		Bullet* bullet = new Bullet(so);
		so->AddComponent(bullet);

		return(so);
	}

	static SceneObject* ScreenBoundAsteroid(Application* app, AABB* screen, float rotation, AsteroidMove::Size size)
	{
		ScreenBoundObject* so = new ScreenBoundObject(app, screen);
		LineBased* lines = new LineBased(so, Collider::Asteroid, WHITE);
		lines->AddLine(Line(Math::Vector2(-15, 9), Math::Vector2(-15, -9)));
		lines->AddLine(Line(Math::Vector2(-15, -9), Math::Vector2(-6.5f, -16.5f)));
		lines->AddLine(Line(Math::Vector2(-7.5f, -16.5f), Math::Vector2(0, -9)));
		lines->AddLine(Line(Math::Vector2(0, -9), Math::Vector2(7.5f, -16.5f)));
		lines->AddLine(Line(Math::Vector2(7.5f, -16.5f), Math::Vector2(15, -9)));
		lines->AddLine(Line(Math::Vector2(15, -9), Math::Vector2(10.5f, 0)));
		lines->AddLine(Line(Math::Vector2(10.5f, 0), Math::Vector2(15, 9)));

		lines->AddLine(Line(Math::Vector2(-15, 9), Math::Vector2(-7.5f, 16.5f)));
		lines->AddLine(Line(Math::Vector2(-7.5f, 16.5f), Math::Vector2(4.5f, 16.5f)));
		lines->AddLine(Line(Math::Vector2(4.5f, 16.5f), Math::Vector2(15, 9)));


		so->AddComponent(lines);
		so->SetBound(lines);

		AsteroidMove* ast = new AsteroidMove(so, rotation, size);
		so->AddComponent(ast);
		so->transform.SetLocalTranslation(Math::Vector2(250, 250));
		return(so);
	}

	static SceneObject* WaveManager(Application* app, SceneObject* player)
	{
		SceneObject* so = new SceneObject(app);
		AsteroidManager* astMan = new AsteroidManager(so, player);
		so->AddComponent(astMan);
		return so;
	}
}
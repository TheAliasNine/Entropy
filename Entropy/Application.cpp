#include "Application.h"
#include "CollisionHandler.h"
#include "SceneObject.h"
#include "LineBased.h"
#include "Line.h"



#include "raylib.h"


Application::Application()
{
	collisionHandler = new CollisionHandler();
}

Application::~Application()
{
	Unload();
}


void Application::Run()
{
	InitWindow(1000, 1000, "Entropy");

	SetTargetFPS(60);

	Load();
	while (!WindowShouldClose())
	{
		Update();
		Draw();
	}

	Unload();
	CloseWindow();
}

void Application::Load()
{
	SceneObject* so = new SceneObject(this);
	LineBased* lines = new LineBased(Collider::Player, WHITE, so);

	lines->AddLine(Line(Math::Vector2(-10, 15), Math::Vector2(0, -15)));
	lines->AddLine(Line(Math::Vector2(10, 15), Math::Vector2(0, -15)));
	lines->AddLine(Line(Math::Vector2(8, 9), Math::Vector2(-8, 9)));

	so->AddComponent(lines);
	so->transform.Translate(Math::Vector2(100, 100));
	sceneHierarchy.push_back(so);

	SceneObject* so2 = new SceneObject(this);
	LineBased* lines2 = new LineBased(Collider::Player, WHITE, so2);

	lines2->AddLine(Line(Math::Vector2(-10, 15), Math::Vector2(0, -15)));
	lines2->AddLine(Line(Math::Vector2(10, 15), Math::Vector2(0, -15)));
	lines2->AddLine(Line(Math::Vector2(8, 9), Math::Vector2(-8, 9)));

	so2->AddComponent(lines2);
	so2->transform.Translate(Math::Vector2(100, 100));
	sceneHierarchy.push_back(so2);



}

void Application::Unload()
{

}

void Application::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);


	for (int i = 0; i < sceneHierarchy.size(); i++)
	{
		sceneHierarchy[i]->Draw();
	}


	EndDrawing();
}

void Application::Update()
{
	for (int i = 0; i < sceneHierarchy.size(); i++)
	{
		sceneHierarchy[i]->Update(GetFrameTime());
	}
	collisionHandler->CheckCollisions();
}

CollisionHandler* Application::GetCollisionHandler()
{
	return collisionHandler;
}

//lines

//player
/*
	lines->AddLine(Line(Math::Vector2(-10, 15), Math::Vector2(0, -15)));
	lines->AddLine(Line(Math::Vector2(10, 15), Math::Vector2(0, -15)));
	lines->AddLine(Line(Math::Vector2(8, 9), Math::Vector2(-8, 9)));
*/



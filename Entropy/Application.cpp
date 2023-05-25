#include "Application.h"
#include "SceneObject.h"
#include "LineBased.h"
#include "Line.h"



#include "raylib.h"


Application::Application()
{

}

Application::~Application()
{
	Unload();
}


void Application::Run()
{
	InitWindow(400, 400, "Entropy");

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
	SceneObject * so = new SceneObject();
	LineBased* lines = new LineBased(Collider::Player, WHITE, so);

	lines->AddLine(Line(Math::Vector2(-10, -15), Math::Vector2(0, 15)));
	lines->AddLine(Line(Math::Vector2(10, -15), Math::Vector2(0, 15)));

	so->AddComponent(lines);
	so->transform.Translate(Math::Vector2(100, 100));
	sceneHierarchy.push_back(so);
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
		sceneHierarchy[i]->Update();
	}
}
#include "Application.h"

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
	
}

void Application::Unload()
{

}

void Application::Draw()
{
	BeginDrawing();

	ClearBackground(BLACK);

	EndDrawing();
}

void Application::Update()
{

}

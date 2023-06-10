#include "Application.h"
#include "CollisionHandler.h"
#include "SceneObject.h"
#include "PremadeSceneObjects.h"
#include "Plane.h"

#include "Vector2.h"

#include "raylib.h"

#include "AsteroidMove.h"

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
	InitWindow(500, 500, "Entropy");

	//300 because need to be able to check enough physics updates to try and stop lines from travelling to far in a single frame and skipping collision check
	SetTargetFPS(300);

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
	score = 0;
	deleteOnNoLives = true;
	lives = 3;
	screen = PremadeSceneObjects::InBounds(500, 500);
	SceneObject* player = PremadeSceneObjects::ScreenBoundPlayer(this, screen);
	sceneHierarchy.push_back(player);
	sceneHierarchy.push_back(PremadeSceneObjects::WaveManager(this, player));

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

	DrawText(FormatText("Score: %i", score), 10, 10, 20, WHITE);

	int xoffset = 23;
	int yoffset = 50;
	for (int i = 0; i < lives; i++)
	{
		DrawLine(-10 + xoffset, -15 + yoffset, 0 + xoffset, 15 + yoffset, WHITE);
		DrawLine(10 + xoffset, -15 + yoffset, 0 + xoffset, 15 + yoffset, WHITE);
		DrawLine(8 + xoffset, -9 + yoffset, -8 + xoffset, -9 + yoffset, WHITE);
		xoffset += 30;
	}
	if (lives < 1)
	{
		DrawText("Game Over", 175, 200, 30, WHITE);
		DrawText("press 'r' to restart", 150, 250, 20, WHITE);
	}

	EndDrawing();
}

void Application::Update()
{
	if (!deleteOnNoLives && IsKeyDown(KEY_R))
	{
		Load();
		return;
	}

	for (int i = 0; i < sceneHierarchy.size(); i++)
	{
		sceneHierarchy[i]->Update(GetFrameTime());
	}
	collisionHandler->CheckCollisions();
	if (lives < 1 && deleteOnNoLives)
	{
		deleteOnNoLives = false;
		for (int i = sceneHierarchy.size() - 1; i > -1; i--)
		{
			delete sceneHierarchy[i];
		}
		sceneHierarchy.erase(sceneHierarchy.begin(), sceneHierarchy.end());
	}
}

CollisionHandler* Application::GetCollisionHandler()
{
	return collisionHandler;
}

void Application::AddSceneObject(SceneObject* obj)
{
	sceneHierarchy.push_back(obj);
}

void Application::RemoveSceneObject(SceneObject* obj)
{
	for (int i = 0; i < sceneHierarchy.size(); i++)
	{
		if (sceneHierarchy[i] == obj)
		{
			std::vector<SceneObject*>::iterator it = sceneHierarchy.begin();
			it += i;
			sceneHierarchy.erase(it);
		}
	}
}
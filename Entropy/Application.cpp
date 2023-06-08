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
	InitWindow(1000, 1000, "Entropy");

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
	screen = PremadeSceneObjects::InBounds(1000, 1000);
	sceneHierarchy.push_back(PremadeSceneObjects::ScreenBoundPlayer(this, screen));
	sceneHierarchy.push_back(PremadeSceneObjects::ScreenBoundAsteroid(this, screen, 45, AsteroidMove::Large));

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
#include "Application.h"
#include "CollisionHandler.h"
#include "SceneObject.h"
#include "PremadeSceneObjects.h"


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
	sceneHierarchy.push_back(PremadeSceneObjects::Player(this));
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
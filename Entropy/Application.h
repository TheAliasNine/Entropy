#pragma once
#include "CollisionHandler.h"

#include <vector>

class SceneObject;

class Application
{
public:
	Application();
	~Application();
	void Run();

	CollisionHandler* GetCollisionHandler();

private:
	void Load();
	void Unload(); //release all memory
	
	void Update();
	void Draw(); 

	std::vector<SceneObject*> sceneHierarchy;
	CollisionHandler* collisionHandler;
};
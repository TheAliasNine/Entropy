#pragma once
#include "CollisionHandler.h"

#include <vector>

class SceneObject;
class AABB;

class Application
{
public:
	Application();
	~Application();
	void Run();

	CollisionHandler* GetCollisionHandler();

	void AddSceneObject(SceneObject* obj);
	void RemoveSceneObject(SceneObject* obj);
	AABB* screen;

	int score = 0;
	int lives = 3;

private:
	bool deleteOnNoLives = true;
	void Load();
	void Unload(); //release all memory
	
	void Update();
	void Draw(); 

	std::vector<SceneObject*> sceneHierarchy;
	CollisionHandler* collisionHandler;
};
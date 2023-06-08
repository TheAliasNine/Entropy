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


private:
	void Load();
	void Unload(); //release all memory
	
	void Update();
	void Draw(); 

	std::vector<SceneObject*> sceneHierarchy;
	CollisionHandler* collisionHandler;
};
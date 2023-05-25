#pragma once

#include "SceneObject.h"

#include <vector>

class Application
{
public:
	Application();
	~Application();
	void Run();

private:
	void Load();
	void Unload(); //release all memory
	
	void Update();
	void Draw(); 

	std::vector<SceneObject*> sceneHierarchy;
	
};
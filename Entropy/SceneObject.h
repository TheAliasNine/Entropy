#pragma once
#include <vector>

class SceneObject
{
public:
	SceneObject();
	~SceneObject();

	//Copy Constructor
	SceneObject(const SceneObject& other);
	//Copy Assignment
	SceneObject& operator= (const SceneObject& other);

	//Move
	SceneObject(SceneObject&& other);
	//Move Assignment
	SceneObject& operator= (SceneObject&& other);


protected:
	SceneObject* parent;
	std::vector<SceneObject> children;

	//need a transform struct to attatch

	//methods for adding children
	//override methods for Update and Draw
	//probably some sort of components
	

	//how to handle drawing
	//a sprite object?
	//a component that defines how to draw itself

};
#pragma once

#include "Component.h"
#include "Transform.h"

#include <vector>


class SceneObject
{
public:
	SceneObject();
	~SceneObject();

	//Copy Constructor
	SceneObject(const SceneObject& other) = default;
	//Copy Assignment
	SceneObject& operator= (const SceneObject& other) = default;

	//Move
	SceneObject(SceneObject&& other) = default;
	//Move Assignment
	SceneObject& operator= (SceneObject&& other) = default;

	Transform transform;
	void UpdateTransform();

	SceneObject * GetParent();

	void SetParent(SceneObject* so);


	virtual void Update();

	virtual void Draw();

protected:
	SceneObject * parent = nullptr;
	std::vector<SceneObject *> children;

	void Unparent();

	/// <summary>
	/// Unparents the object if updateObj is false the object is not updated. Use for when the object would be deleted.
	/// </summary>
	void Unparent(bool updateObj);
	//methods for adding children


	std::vector<SceneObject*> components;
};
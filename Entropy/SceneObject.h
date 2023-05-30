#pragma once
#include "Application.h"
#include "Component.h"
#include "SoTransform.h"
#include "CollisionInfo.h"

#include <vector>


class SceneObject
{
public:
	SceneObject(Application* app);
	~SceneObject();

	//Copy Constructor
	SceneObject(const SceneObject& other) = default;
	//Copy Assignment
	SceneObject& operator= (const SceneObject& other) = default;

	//Move
	SceneObject(SceneObject&& other) = default;
	//Move Assignment
	SceneObject& operator= (SceneObject&& other) = default;

	SoTransform transform;
	void UpdateTransform();

	SceneObject* GetParent();

	void SetParent(SceneObject* so);


	virtual void Update(float deltaTime);

	virtual void Draw();

	void AddComponent(Component* component);

	Application* app;

	void OnCollision(CollisionInfo info);

protected:
	SceneObject * parent = nullptr;
	std::vector<SceneObject *> children;

	void Unparent();

	/// <summary>
	/// Unparents the object if updateObj is false the object is not updated. Use for when the object would be deleted.
	/// </summary>
	void Unparent(bool updateObj);
	//methods for adding children


	std::vector<Component*> components = std::vector<Component*>();
};
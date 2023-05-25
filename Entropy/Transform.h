#pragma once

#include "Matrix3.h"
#include "Vector2.h"
#include "Vector3.h"

class SceneObject;

class Transform
{
private:
	SceneObject * obj = nullptr;

	Math::Matrix3 localMatrix = Math::Matrix3(); //handles local rotation, translation and uniform scale

	Math::Matrix3 globalMatrix = Math::Matrix3();

public:
	Transform() {};
	Transform(SceneObject * sceneObject);

	//methods
	Math::Vector2 GetLocalTranslation();
	void SetLocalTranslation(Math::Vector2 translation);
	void Translate(Math::Vector2 translation);

	void Rotate(float radians);
	void SetLocalRotation(float radians);

	float GetLocalScale();
	/// <summary>
	/// Sets the uniform scale of the transform
	/// </summary>
	void SetLocalScale(float scale);
	void Scale(float scale);

	void UpdateGlobal();

	Math::Matrix3 GetGlobalMatrix();
};
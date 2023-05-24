#pragma once
#include "Matrix3.h"
#include "Vector2.h"
#include "Vector3.h"

class Transform
{
private:
	Math::Matrix3 transformationMatrix; //handles local rotation, translation and uniform scale
public:
	Transform();

	//methods
	Math::Vector2 GetTranslation();
	void SetTranslation(Math::Vector2 translation);
	void Translate(Math::Vector2 translation);

	void Rotate(float radians);

	float GetScale();
	/// <summary>
	/// Sets the uniform scale of the transform
	/// </summary>
	void SetScale(float scale);
};
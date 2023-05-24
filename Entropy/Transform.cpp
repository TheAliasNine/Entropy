#include "Transform.h"

#include "Matrix3.h"
#include "Vector2.h"
#include "Vector3.h"

Transform::Transform()
{
	transformationMatrix = Math::Matrix3();
}


Math::Vector2 Transform::GetTranslation()
{
	return Math::Vector2(transformationMatrix.m02, transformationMatrix.m12);
}

void Transform::SetTranslation(Math::Vector2 translation)
{
	transformationMatrix.m02 = translation.x;
	transformationMatrix.m12 = translation.y;
}

void Transform::Translate(Math::Vector2 translation)
{
	transformationMatrix.m02 += translation.x;
	transformationMatrix.m12 += translation.x;
}



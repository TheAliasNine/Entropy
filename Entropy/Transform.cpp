#include "Transform.h"

#include "SceneObject.h"

#include "Matrix3.h"
#include "Vector2.h"
#include "Vector3.h"

#include <math.h>

Transform::Transform(SceneObject * sceneObject)
{
	obj = sceneObject;
	localMatrix = Math::Matrix3();
	UpdateGlobal();
}


Math::Vector2 Transform::GetLocalTranslation()
{
	return Math::Vector2(localMatrix.m02, localMatrix.m12);
}

void Transform::SetLocalTranslation(const Math::Vector2 translation)
{
	localMatrix.m02 = translation.x;
	localMatrix.m12 = translation.y;

	obj->UpdateTransform();
}

void Transform::Translate(const Math::Vector2 translation)
{
	localMatrix.m02 += translation.x;
	localMatrix.m12 += translation.x;

	obj->UpdateTransform();
}


void Transform::Rotate(float radians)
{
	localMatrix = localMatrix *
		Math::Matrix3((float)cos(radians), (float)sin(radians), 0,
			(float)-sin(radians), (float)cos(radians), 0,
			0, 0, 1);
}

void Transform::SetLocalRotation(float radians)
{
	localMatrix.m00 =  (float)cos(radians);
	localMatrix.m10 = (float)sin(radians);
	localMatrix.m01 = (float)-sin(radians);
	localMatrix.m11 = (float)cos(radians);

	obj->UpdateTransform();

}


float Transform::GetLocalScale()
{
	return Math::Vector2(localMatrix.m00, localMatrix.m10).Magnitude();
}

void Transform::SetLocalScale(float scale)
{
	float oldScale = GetLocalScale();

	localMatrix.m00 /= oldScale;
	localMatrix.m10 /= oldScale;
	localMatrix.m01 /= oldScale;
	localMatrix.m11 /= oldScale;

	Scale(scale);
}

void Transform::Scale(float scale)
{
	localMatrix.m00 *= scale;
	localMatrix.m10 *= scale;
	localMatrix.m01 *= scale;
	localMatrix.m11 *= scale;

	obj->UpdateTransform();
}


void Transform::UpdateGlobal()
{
	SceneObject* parent = obj->GetParent();
	if (parent != nullptr)
	{
		globalMatrix = parent->transform.GetGlobalMatrix() * localMatrix;
	}
	else
	{
		globalMatrix = localMatrix;
	}
}

Math::Matrix3 Transform::GetGlobalMatrix()
{
	return globalMatrix;
}
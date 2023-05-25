#include "SoTransform.h"

#include "SceneObject.h"

#include "Matrix3.h"
#include "Vector2.h"
#include "Vector3.h"

#include <math.h>

SoTransform::SoTransform(SceneObject * sceneObject)
{
	obj = sceneObject;
	localMatrix = Math::Matrix3();
	UpdateGlobal();
}


Math::Vector2 SoTransform::GetLocalTranslation()
{
	return Math::Vector2(localMatrix.m02, localMatrix.m12);
}

void SoTransform::SetLocalTranslation(const Math::Vector2 translation)
{
	localMatrix.m02 = translation.x;
	localMatrix.m12 = translation.y;

	obj->UpdateTransform();
}

void SoTransform::Translate(const Math::Vector2 translation)
{
	localMatrix.m02 += translation.x;
	localMatrix.m12 += translation.x;

	obj->UpdateTransform();
}


void SoTransform::Rotate(float radians)
{
	localMatrix = localMatrix *
		Math::Matrix3((float)cos(radians), (float)sin(radians), 0,
			(float)-sin(radians), (float)cos(radians), 0,
			0, 0, 1);
}

void SoTransform::SetLocalRotation(float radians)
{
	localMatrix.m00 =  (float)cos(radians);
	localMatrix.m10 = (float)sin(radians);
	localMatrix.m01 = (float)-sin(radians);
	localMatrix.m11 = (float)cos(radians);

	obj->UpdateTransform();

}


float SoTransform::GetLocalScale()
{
	return Math::Vector2(localMatrix.m00, localMatrix.m10).Magnitude();
}

void SoTransform::SetLocalScale(float scale)
{
	float oldScale = GetLocalScale();

	localMatrix.m00 /= oldScale;
	localMatrix.m10 /= oldScale;
	localMatrix.m01 /= oldScale;
	localMatrix.m11 /= oldScale;

	Scale(scale);
}

void SoTransform::Scale(float scale)
{
	localMatrix.m00 *= scale;
	localMatrix.m10 *= scale;
	localMatrix.m01 *= scale;
	localMatrix.m11 *= scale;

	obj->UpdateTransform();
}


void SoTransform::UpdateGlobal()
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

Math::Matrix3 SoTransform::GetGlobalMatrix()
{
	return globalMatrix;
}
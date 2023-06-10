#pragma once
#include "Vector3.h"

namespace Math
{
	struct Matrix3
	{
	public:
		float m00, m01, m02;
		float m10, m11, m12;
		float m20, m21, m22;

		Matrix3();
		Matrix3(float f);
		Matrix3(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22);


		//operator
		Vector3 operator * (Vector3 v3);
		Matrix3 operator * (Matrix3 other);
	};
}
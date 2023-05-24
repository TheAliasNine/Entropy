#pragma once
#include "Vector2.h";

namespace Math
{
	class Vector3
	{
	public:
		//values and initialization
		float x, y, z;
		Vector3();
		Vector3(float x, float y, float z);

		//conversions
		Vector3(Vector2 v2);


		//operators
		Vector3 operator + (Vector3 other);
		Vector3 operator - (Vector3 other);
		Vector3 operator * (float f);
		Vector3 operator / (float f);

		//methods
		float Magnitude();

		void Normalize();
		Vector3 Normalized();

		float Dot(Vector3 lhs, Vector3 rhs);
		Vector3 Cross(Vector3 lhs, Vector3 rhs);
	};
}
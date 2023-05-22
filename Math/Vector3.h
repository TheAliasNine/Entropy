#pragma once
#include "Vector2.h";

namespace Math
{
	class Vector3
	{
	public:
		//values and initialization
		float x = 0, y = 0, z = 0;
		Vector3() {};
		Vector3(float x, float y, float z);

		//conversions
		Vector3(Vector2 v2);


		//operators
		static Vector3 operator+(Vector3 lhs, Vector3 rhs);
		static Vector3 operator-(Vector3 lhs, Vector3 rhs);
		static Vector3 operator*(Vector3 v3, float f);
		static Vector3 operator/(Vector3 v3, float f);

		//methods
		float Magnitude();

		void Normalize();
		Vector3 Normalized();

		float Dot(Vector3 lhs, Vector3 rhs);
		Vector3 Cross(Vector3 lhs, Vector3 rhs);
	};
}
#pragma once

namespace Math
{
	struct Vector2
	{
	public:
		float x, y;

		Vector2();
		Vector2(float x, float y);

		//operators
		Vector2 operator + (Vector2 other);
		Vector2 operator - (Vector2 other);
		Vector2 operator * (float f);
		Vector2 operator / (float f);

		//methods
		float Magnitude();
		float MagnitudeSqr();

		void Normalize();
		Vector2 Normalized();

		static float Dot(Vector2 lhs, Vector2 rhs);
		static float Cross(Vector2 lhs, Vector2 rhs);
		static Vector2 Clamp(Vector2 value, Vector2 clampMin, Vector2 clampMax);
	};
}
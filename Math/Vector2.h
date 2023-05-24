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

		void Normalize();
		Vector2 Normalized();

		float Dot(Vector2 lhs, Vector2 rhs);
		Vector2 Cross(Vector2 lhs, Vector2 rhs);
	};
}
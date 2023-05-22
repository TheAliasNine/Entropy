#pragma once

namespace Math
{
	struct Vector2
	{
	public:
		float x = 0, y = 0;

		Vector2() {};
		Vector2(float x, float y);

		//operators
		static Vector2 operator+(Vector2 lhs, Vector2 rhs);
		static Vector2 operator-(Vector2 lhs, Vector2 rhs);
		static Vector2 operator*(Vector2 v2, float f);
		static Vector2 operator/(Vector2 v2, float f);

		//methods
		float Magnitude();

		void Normalize();
		Vector2 Normalized();

		float Dot(Vector2 lhs, Vector2 rhs);
		Vector2 Cross(Vector2 lhs, Vector2 rhs);
	};
}
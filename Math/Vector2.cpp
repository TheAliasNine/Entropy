#include "Vector2.h"

#include "math.h"

namespace Math
{
	Vector2::Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}


	//operators
	Vector2 Vector2::operator+(Vector2 lhs, Vector2 rhs)
	{
		return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
	}

	Vector2 Vector2::operator-(Vector2 lhs, Vector2 rhs)
	{
		return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
	}

	Vector2 Vector2::operator*(Vector2 v2, float f)
	{
		return Vector2(v2.x * f, v2.y * f);
	}

	Vector2 Vector2::operator/(Vector2 v2, float f)
	{
		return Vector2(v2.x / f, v2.y / f);
	}


	//methods
	float Vector2::Magnitude()
	{
		float dSqr = x * x + y * y;
		return sqrt(dSqr);
	}

	void Vector2::Normalize()
	{
		float mag = Magnitude();
		x = x / mag;
		y = y / mag;
	}

	Vector2 Vector2::Normalized()
	{
		float mag = Magnitude();
		return Vector2(x / mag, y / mag);
	}

	float Vector2::Dot(Vector2 lhs, Vector2 rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	Vector2 Vector2::Cross(Vector2 lhs, Vector2 rhs)
	{
		return Vector2(
			lhs.y - rhs.y,
			rhs.x - lhs.x);
	}
}
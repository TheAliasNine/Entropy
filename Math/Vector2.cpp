#include "Vector2.h"

#include "math.h"

namespace Math
{
	Vector2::Vector2()
	{
		x = 0;
		y = 0;
	}

	Vector2::Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}


	//operators
	Vector2 Vector2::operator+(Vector2 other)
	{
		return Vector2(this->x + other.x, this->y + other.y);
	}

	Vector2 Vector2::operator-(Vector2 other)
	{
		return Vector2(this->x - other.x, this->y - other.y);
	}

	Vector2 Vector2::operator*(float f)
	{
		return Vector2(this->x * f, this->y * f);
	}

	Vector2 Vector2::operator/(float f)
	{
		return Vector2(this->x / f, this->y / f);
	}


	//methods
	float Vector2::Magnitude()
	{
		float dSqr = x * x + y * y;
		return sqrt(dSqr);
	}

	float Vector2::MagnitudeSqr()
	{
		return x * x + y * y;
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

	float Vector2::Cross(Vector2 lhs, Vector2 rhs)
	{
		return (lhs.x * rhs.y) - (lhs.y * rhs.x);
	}
	Vector2 Vector2::Clamp(Vector2 value, Vector2 clampMin, Vector2 clampMax)
	{
		Vector2 returnval = Vector2();
		if (value.x > clampMax.x)
		{
			returnval.x = clampMax.x;
		}
		else if (value.x < clampMin.x)
		{
			returnval.x = clampMin.x;
		}
		else
		{
			returnval.x = value.x;
		}
		if (value.y > clampMax.y)
		{
			returnval.y = clampMax.y;
		}
		else if (value.y < clampMin.y)
		{
			returnval.y = clampMin.y;
		}
		else
		{
			returnval.y = value.y;
		}
		return returnval;
	}
}
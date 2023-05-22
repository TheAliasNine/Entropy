#include "Vector3.h"

#include "math.h"

namespace Math
{
	Vector3::Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}


	//operators
	Vector3 Vector3::operator+(Vector3 lhs, Vector3 rhs)
	{
		return Vector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
	}

	Vector3 Vector3::operator-(Vector3 lhs, Vector3 rhs)
	{
		return Vector3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
	}

	Vector3 Vector3::operator*(Vector3 v3, float f)
	{
		return Vector3(v3.x * f, v3.y * f, v3.z * f);
	}

	Vector3 Vector3::operator/(Vector3 v3, float f)
	{
		return Vector3(v3.x / f, v3.y / f, v3.z / f);
	}


	//methods
	float Vector3::Magnitude()
	{
		float dSqr = x * x + y * y + z * z;
		return sqrt(dSqr);
	}

	void Vector3::Normalize()
	{
		float mag = Magnitude();
		x = x / mag;
		y = y / mag;
		z = z / mag;
	}

	Vector3 Vector3::Normalized()
	{
		float mag = Magnitude();
		return Vector3(x / mag, y / mag, z / mag);
	}

	float Vector3::Dot(Vector3 lhs, Vector3 rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	Vector3 Vector3::Cross(Vector3 lhs, Vector3 rhs)
	{
		return Vector3(
			lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.z * rhs.x - lhs.x * rhs.z,
			lhs.x * rhs.y - lhs.y * rhs.x);
	}
}
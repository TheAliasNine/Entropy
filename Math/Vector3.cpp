#include "Vector3.h"

#include "math.h"

namespace Math
{
	Vector3::Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Vector3::Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}


	//Conversions
	Vector3::Vector3(Vector2 v2)
	{
		x = v2.x;
		y = v2.y;
		z = 0;
	}


	//operators
	Vector3 Vector3::operator + (Vector3 other)
	{
		return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
	}

	Vector3 Vector3::operator - (Vector3 other)
	{
		return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
	}

	Vector3 Vector3::operator *(float f)
	{
		return Vector3(this->x * f, this->y * f, this->z * f);
	}

	Vector3 Vector3::operator / (float f)
	{
		return Vector3(this->x / f, this->y / f, this->z / f);
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
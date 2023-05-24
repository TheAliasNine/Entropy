#include "Matrix3.h"

namespace Math
{
	Matrix3::Matrix3()
	{
		m00 = 0;
		m01 = 0;
		m02 = 0;
		m10 = 0;
		m11 = 0;
		m12 = 0;
		m20 = 0;
		m21 = 0;
		m22 = 0;
	}

	Matrix3::Matrix3(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22)
	{
		this->m00 = m00;
		this->m01 = m01;
		this->m02 = m02;
		this->m10 = m10;
		this->m11 = m11;
		this->m12 = m12;
		this->m20 = m20;
		this->m21 = m21;
		this->m22 = m22;
	}

	Vector3 Matrix3::operator*(Vector3 v3)
	{
		return Vector3(
			this->m00 * v3.x + this->m01 * v3.y + this->m02 * v3.z,
			this->m10 * v3.x + this->m11 * v3.y + this->m12 * v3.z,
			this->m20 * v3.x + this->m21 * v3.y + this->m22 * v3.z);
	}

	Matrix3 Matrix3::operator*(Matrix3 other)
	{
		return Matrix3(
			this->m00 * other.m00 + this->m01 * other.m10 + this->m02 * other.m20,
			this->m00 * other.m01 + this->m01 * other.m11 + this->m02 * other.m21,
			this->m00 * other.m02 + this->m01 * other.m12 + this->m02 * other.m22,
			this->m10 * other.m00 + this->m11 * other.m10 + this->m12 * other.m20,
			this->m10 * other.m01 + this->m11 * other.m11 + this->m12 * other.m21,
			this->m10 * other.m02 + this->m11 * other.m12 + this->m12 * other.m22,
			this->m20 * other.m00 + this->m21 * other.m10 + this->m22 * other.m20,
			this->m20 * other.m01 + this->m21 * other.m11 + this->m22 * other.m21,
			this->m20 * other.m02 + this->m21 * other.m12 + this->m22 * other.m22);
	}


}
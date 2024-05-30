//
// * ENGINE-X
//
// + Types.h
// representations of: 2D vector with floats, 2D vector with integers and RBGA color as four bytes
//

#pragma once
#include <vector>

//-----------------------------------------------------------------
//-----------------------------------------------------------------

#define PI 3.14159f

struct Vector3;

struct Time 
{
	static double DeltaTime;
};

struct Matrix4
{
	float m[4][4] = { 0 };

	static Matrix4 Identity() 
	{
		Matrix4 outMat = { 0 };

		outMat.m[0][0] = 1.0f;
		outMat.m[1][1] = 1.0f;
		outMat.m[2][2] = 1.0f;
		outMat.m[3][3] = 1.0f;

		return outMat;

	}

	Matrix4 operator*(const Matrix4& o) 
	{
		return Matrix4
		{
			// 4x4 matrix multiplication
			this->m[0][0] * o.m[0][0] + this->m[0][1] * o.m[1][0] + this->m[0][2] * o.m[2][0] + this->m[0][3] * o.m[3][0],
			this->m[0][0] * o.m[0][1] + this->m[0][1] * o.m[1][1] + this->m[0][2] * o.m[2][1] + this->m[0][3] * o.m[3][1],
			this->m[0][0] * o.m[0][2] + this->m[0][1] * o.m[1][2] + this->m[0][2] * o.m[2][2] + this->m[0][3] * o.m[3][2],
			this->m[0][0] * o.m[0][3] + this->m[0][1] * o.m[1][3] + this->m[0][2] * o.m[2][3] + this->m[0][3] * o.m[3][3],
			
			this->m[1][0] * o.m[0][0] + this->m[1][1] * o.m[1][0] + this->m[1][2] * o.m[2][0] + this->m[1][3] * o.m[3][0],
			this->m[1][0] * o.m[0][1] + this->m[1][1] * o.m[1][1] + this->m[1][2] * o.m[2][1] + this->m[1][3] * o.m[3][1],
			this->m[1][0] * o.m[0][2] + this->m[1][1] * o.m[1][2] + this->m[1][2] * o.m[2][2] + this->m[1][3] * o.m[3][2],
			this->m[1][0] * o.m[0][3] + this->m[1][1] * o.m[1][3] + this->m[1][2] * o.m[2][3] + this->m[1][3] * o.m[3][3],
			
			this->m[2][0] * o.m[0][0] + this->m[2][1] * o.m[1][0] + this->m[2][2] * o.m[2][0] + this->m[2][3] * o.m[3][0],
			this->m[2][0] * o.m[0][1] + this->m[2][1] * o.m[1][1] + this->m[2][2] * o.m[2][1] + this->m[2][3] * o.m[3][1],
			this->m[2][0] * o.m[0][2] + this->m[2][1] * o.m[1][2] + this->m[2][2] * o.m[2][2] + this->m[2][3] * o.m[3][2],
			this->m[2][0] * o.m[0][3] + this->m[2][1] * o.m[1][3] + this->m[2][2] * o.m[2][3] + this->m[2][3] * o.m[3][3],

			this->m[3][0] * o.m[0][0] + this->m[3][1] * o.m[1][0] + this->m[3][2] * o.m[2][0] + this->m[3][3] * o.m[3][0],
			this->m[3][0] * o.m[0][1] + this->m[3][1] * o.m[1][1] + this->m[3][2] * o.m[2][1] + this->m[3][3] * o.m[3][1],
			this->m[3][0] * o.m[0][2] + this->m[3][1] * o.m[1][2] + this->m[3][2] * o.m[2][2] + this->m[3][3] * o.m[3][2],
			this->m[3][0] * o.m[0][3] + this->m[3][1] * o.m[1][3] + this->m[3][2] * o.m[2][3] + this->m[3][3] * o.m[3][3]
		};
	}

	Matrix4 operator*(const Matrix4& o) const
	{
		return Matrix4
		{
			// 4x4 matrix multiplication
			this->m[0][0] * o.m[0][0] + this->m[0][1] * o.m[1][0] + this->m[0][2] * o.m[2][0] + this->m[0][3] * o.m[3][0],
			this->m[0][0] * o.m[0][1] + this->m[0][1] * o.m[1][1] + this->m[0][2] * o.m[2][1] + this->m[0][3] * o.m[3][1],
			this->m[0][0] * o.m[0][2] + this->m[0][1] * o.m[1][2] + this->m[0][2] * o.m[2][2] + this->m[0][3] * o.m[3][2],
			this->m[0][0] * o.m[0][3] + this->m[0][1] * o.m[1][3] + this->m[0][2] * o.m[2][3] + this->m[0][3] * o.m[3][3],

			this->m[1][0] * o.m[0][0] + this->m[1][1] * o.m[1][0] + this->m[1][2] * o.m[2][0] + this->m[1][3] * o.m[3][0],
			this->m[1][0] * o.m[0][1] + this->m[1][1] * o.m[1][1] + this->m[1][2] * o.m[2][1] + this->m[1][3] * o.m[3][1],
			this->m[1][0] * o.m[0][2] + this->m[1][1] * o.m[1][2] + this->m[1][2] * o.m[2][2] + this->m[1][3] * o.m[3][2],
			this->m[1][0] * o.m[0][3] + this->m[1][1] * o.m[1][3] + this->m[1][2] * o.m[2][3] + this->m[1][3] * o.m[3][3],

			this->m[2][0] * o.m[0][0] + this->m[2][1] * o.m[1][0] + this->m[2][2] * o.m[2][0] + this->m[2][3] * o.m[3][0],
			this->m[2][0] * o.m[0][1] + this->m[2][1] * o.m[1][1] + this->m[2][2] * o.m[2][1] + this->m[2][3] * o.m[3][1],
			this->m[2][0] * o.m[0][2] + this->m[2][1] * o.m[1][2] + this->m[2][2] * o.m[2][2] + this->m[2][3] * o.m[3][2],
			this->m[2][0] * o.m[0][3] + this->m[2][1] * o.m[1][3] + this->m[2][2] * o.m[2][3] + this->m[2][3] * o.m[3][3],

			this->m[3][0] * o.m[0][0] + this->m[3][1] * o.m[1][0] + this->m[3][2] * o.m[2][0] + this->m[3][3] * o.m[3][0],
			this->m[3][0] * o.m[0][1] + this->m[3][1] * o.m[1][1] + this->m[3][2] * o.m[2][1] + this->m[3][3] * o.m[3][1],
			this->m[3][0] * o.m[0][2] + this->m[3][1] * o.m[1][2] + this->m[3][2] * o.m[2][2] + this->m[3][3] * o.m[3][2],
			this->m[3][0] * o.m[0][3] + this->m[3][1] * o.m[1][3] + this->m[3][2] * o.m[2][3] + this->m[3][3] * o.m[3][3]
		};
	}

	static Matrix4 Translate(const Matrix4& inMat, const Vector3& inVec);

};

struct Vector3
{
	float x, y, z;

	Vector3 operator*(const Matrix4& mat) 
	{
		Vector3 o;

		o.x = this->x * mat.m[0][0] + this->y * mat.m[1][0] + this->z * mat.m[2][0] + mat.m[3][0];
		o.y = this->x * mat.m[0][1] + this->y * mat.m[1][1] + this->z * mat.m[2][1] + mat.m[3][1];
		o.z = this->x * mat.m[0][2] + this->y * mat.m[1][2] + this->z * mat.m[2][2] + mat.m[3][2];

		float w = this->x * mat.m[0][3] + this->y * mat.m[1][3] + this->z * mat.m[2][3] + mat.m[3][3];

		if (w != 0.0f)
		{
			o.x /= w;
			o.y /= w;
			o.z /= w;
		}

		return *this;

	}

	Vector3 operator*=(const Matrix4& mat) 
	{
		Vector3 o;

		o.x = this->x * mat.m[0][0] + this->y * mat.m[1][0] + this->z * mat.m[2][0] + mat.m[3][0];
		o.y = this->x * mat.m[0][1] + this->y * mat.m[1][1] + this->z * mat.m[2][1] + mat.m[3][1];
		o.z = this->x * mat.m[0][2] + this->y * mat.m[1][2] + this->z * mat.m[2][2] + mat.m[3][2];

		float w = this->x * mat.m[0][3] + this->y * mat.m[1][3] + this->z * mat.m[2][3] + mat.m[3][3];

		if (w != 0.0f)
		{
			o.x /= w;
			o.y /= w;
			o.z /= w;
		}

		this->x = o.x;
		this->y = o.y;
		this->z = o.z;

		return *this;
	}

	Vector3 operator-(const Vector3& other)
	{
		return Vector3{ this->x - other.x, this->y - other.y, this->z - other.z };
	}

	Vector3 operator-(const Vector3& other) const
	{
		return Vector3{ this->x - other.x, this->y - other.y, this->z - other.z };
	}

	Vector3 operator+(const Vector3& other)
	{
		return Vector3{ this->x + other.x, this->y + other.y, this->z + other.z };
	}

	Vector3 operator+(const Vector3& other) const
	{
		return Vector3{ this->x + other.x, this->y + other.y, this->z + other.z };
	}

	Vector3 operator*(const float& multiplicationFactor)
	{
		return { this->x * multiplicationFactor, this->y * multiplicationFactor, this->z * multiplicationFactor };
	}

	Vector3 operator*(const float& multiplicationFactor) const
	{
		return { this->x * multiplicationFactor, this->y * multiplicationFactor, this->z * multiplicationFactor };
	}

	Vector3 operator+=(const Vector3& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		return *this;
	}
};

struct Triangle
{
	Vector3 v[3];
};

struct Mesh 
{
	std::vector<Triangle> tris;
};

struct exVector2
{

	exVector2 operator-(const exVector2& other) 
	{
		return exVector2{ this->x - other.x, this->y - other.y };
	}

	exVector2 operator-(const exVector2& other) const
	{
		return exVector2{ this->x - other.x, this->y - other.y };
	}

	exVector2 operator+(const exVector2& other)
	{
		return exVector2{this->x + other.x, this->y + other.y };
	}

	exVector2 operator*(const float& multiplicationFactor)
	{
		return { this->x * multiplicationFactor, this->y * multiplicationFactor };
	}

	exVector2 operator*(const float& multiplicationFactor) const
	{
		return { this->x * multiplicationFactor, this->y * multiplicationFactor };
	}

	exVector2 operator+=(const exVector2& other) 
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	float x, y;
};

//-----------------------------------------------------------------
//-----------------------------------------------------------------

struct exIntegerVector2
{
	int x, y;
};

//-----------------------------------------------------------------
//-----------------------------------------------------------------

struct exColor
{
	unsigned char mColor[4];
};

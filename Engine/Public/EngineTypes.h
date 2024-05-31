//
// * ENGINE-X
//
// + Types.h
// representations of: 2D vector with floats, 2D vector with integers and RBGA color as four bytes
//

#pragma once
#include <vector>
#include "3rdParty/GLM/glm.hpp"
#include "3rdParty/GLM/gtc/matrix_transform.hpp"
#include "3rdParty/GLM/gtc/type_ptr.hpp"
//-----------------------------------------------------------------
//-----------------------------------------------------------------

#define PI 3.14159f


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

	static Matrix4 Translate(const Matrix4& inMat, const glm::vec3& inVec);

};



struct Triangle
{
	glm::vec3 v[3];
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

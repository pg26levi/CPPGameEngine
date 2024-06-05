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

	static double ElapsedTime;

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

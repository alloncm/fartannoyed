#pragma once
#include <cmath>
class Vector2
{
public:
	float x;
	float y;
public:
	Vector2(float _x, float _y);
	Vector2 operator+(Vector2 & v);
	Vector2 operator-(Vector2 & v);
	float Length();
};
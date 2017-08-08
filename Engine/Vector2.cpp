#include "Vector2.h"

Vector2::Vector2(float _x, float _y)
	:
	x(_x),
	y(_y)
{
}

Vector2 Vector2::operator+(Vector2 & v)
{
	Vector2 t (x + v.x, y + v.y);
	return t;
}

Vector2 Vector2::operator-(Vector2 & v)
{
	Vector2 t(x - v.x, y - v.y);
	return t;
}

Vector2 Vector2::operator*(float num)
{
	Vector2 t(x*num, y* num);
	return t;
}

float Vector2::Length()
{
	return sqrt((x*x) + (y*y));
}

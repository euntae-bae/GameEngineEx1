#include "Math.h"

Vector2::Vector2()
	: Vector2(0.0f, 0.0f)
{
//#ifdef _DEBUG
//	puts("Vector2()");
//#endif
}

Vector2::Vector2(float _x, float _y)
	: x(_x), y(_y)
{
//#ifdef _DEBUG
//	puts("Vector2(float, float)");
//#endif
}

Vector2::Vector2(const Vector2& rhs)
	: Vector2(rhs.x, rhs.y)
{
//#ifdef _DEBUG
//	puts("Vector2(const Vector2&)");
//#endif
}

Vector2::~Vector2()
{
//#ifdef _DEBUG
//	puts("~Vector2()");
//#endif
}

Rect::Rect()
	: Rect(0, 0, 0, 0)
{
#ifdef _DEBUG
	puts("Rect()");
#endif
}

Rect::Rect(int _x, int _y, int _w, int _h)
	: x(_x), y(_y), width(_w), height(_h)
{
#ifdef _DEBUG
	puts("Rect(int, int, int, int)");
#endif
}

Rect::~Rect()
{
#ifdef _DEBUG
	puts("~Rect()");
#endif
}
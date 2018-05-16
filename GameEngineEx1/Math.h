#ifndef __MATH_H__
#define __MATH_H__

#include <cstdio>

class Vector2
{
private:
	float x, y;
public:
	Vector2();
	Vector2(float _x, float _y);
	~Vector2();

	float getX() const;
	float getY() const;
	void setX(float dx);
	void setY(float dy);
	void setXY(float dx, float dy);
};


inline float Vector2::getX() const {
	return x;
}

inline float Vector2::getY() const {
	return y;
}

inline void Vector2::setX(float dx) {
	x = dx;
}

inline void Vector2::setY(float dy) {
	y = dy;
}

inline void Vector2::setXY(float dx, float dy) {
	x = dx;
	y = dy;
}

class Rect
{
private:
	int x, y;
	int width, height;
public:
	Rect();
	Rect(int _x, int _y, int _w, int _h);
	~Rect();

	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
	void setX(int dx);
	void setY(int dy);
	void setXY(int dx, int dy);
	void setXY(const Vector2& vec);
	void setWidth(int dw);
	void setHeight(int dh);
};

inline int Rect::getX() const {
	return x;
}

inline int Rect::getY() const {
	return y;
}

inline int Rect::getWidth() const {
	return width;
}

inline int Rect::getHeight() const {
	return height;
}

inline void Rect::setX(int dx) {
	x = dx;
}

inline void Rect::setY(int dy) {
	y = dy;
}

inline void Rect::setXY(int dx, int dy) {
	x = dx;
	y = dy;
}

inline void Rect::setXY(const Vector2& vec) {
	x = vec.getX();
	y = vec.getY();
}

inline void Rect::setWidth(int dw) {
	width = dw;
}

inline void Rect::setHeight(int dh) {
	height = dh;
}

#endif
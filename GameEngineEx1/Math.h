#ifndef __MATH_H__
#define __MATH_H__

#include <cstdio>
#include <cmath>

const double PI = 3.14159265;
const double RT2 = 1.41421;

class Vector2
{
private:
	float x, y;
public:
	Vector2();
	Vector2(float _x, float _y);
	Vector2(const Vector2& rhs);
	~Vector2();

	float norm() const;
	float getX() const;
	float getY() const;
	Vector2 getXY() const;
	void setX(float dx);
	void setY(float dy);
	void setXY(float dx, float dy);
	void setXY(const Vector2& rhs);
	Vector2 operator+(const Vector2& rhs) const;
	Vector2 operator-() const;
	Vector2 operator-(const Vector2& rhs) const;
	Vector2 operator*(const Vector2& rhs) const;
	Vector2& operator=(const Vector2& rhs);
	Vector2& operator+=(const Vector2& rhs);
	Vector2& operator-=(const Vector2& rhs);
	Vector2& operator*=(const Vector2& rhs);
};

inline float Vector2::norm() const {
	return sqrt((x * x) + (y * y));
}

inline float Vector2::getX() const {
	return x;
}

inline float Vector2::getY() const {
	return y;
}

inline Vector2 Vector2::getXY() const {
	return Vector2(x, y);
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

inline void Vector2::setXY(const Vector2& rhs) {
	x = rhs.x;
	y = rhs.y;
}

inline Vector2 Vector2::operator+(const Vector2& rhs) const {
	return Vector2(x + rhs.x, y + rhs.y);
}

inline Vector2 Vector2::operator-() const {
	return Vector2(-x, -y);
}

inline Vector2 Vector2::operator-(const Vector2& rhs) const {
	return Vector2(x - rhs.x, y - rhs.y);
}

inline Vector2 Vector2::operator*(const Vector2& rhs) const {
	return Vector2(x * rhs.x, y * rhs.y);
}

inline Vector2& Vector2::operator=(const Vector2& rhs) {
	x = rhs.x;
	y = rhs.y;
	return *this;
}

inline Vector2& Vector2::operator+=(const Vector2& rhs) {
	x += rhs.x;
	y += rhs.y;
	return *this;
}

inline Vector2& Vector2::operator-=(const Vector2& rhs) {
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

inline Vector2& Vector2::operator*=(const Vector2& rhs) {
	x *= rhs.x;
	y *= rhs.y;
	return *this;
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
	Rect getRect() const;
	bool containsPoint(const Vector2& point) const;
	bool intersectsRect(const Rect& rc) const;

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

inline Rect Rect::getRect() const {
	return Rect(x, y, width, height);
}

inline bool Rect::containsPoint(const Vector2& point) const {
	int px = (int)point.getX();
	int py = (int)point.getY();

	return ((x <= px) && (x + width >= px)) &&
		((y <= py) && (y + height >= py));
}

inline bool Rect::intersectsRect(const Rect& rc) const {
	return true;
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
	x = (int)vec.getX();
	y = (int)vec.getY();
}

inline void Rect::setWidth(int dw) {
	width = dw;
}

inline void Rect::setHeight(int dh) {
	height = dh;
}

inline double degreeToRad(double d) {
	return d / 180 * PI;
}

inline double radToDegree(double r) {
	return r / PI * 180;
}

#endif
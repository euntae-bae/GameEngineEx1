#ifndef __RENDERABLE_H__
#define __RENDERABLE_H__

#include <allegro5/allegro.h>
#include "Math.h"

class Graphics;

// Opacity -> Alpha
// Alpha값과 Opacity(불투명도)를 구별해야 한다.
// 버전 0.05: 구분돼 있지 않음.
// 버전 0.06: Alpha로 용어 통일
class Renderable
{
protected:
	Vector2 pos;
	Vector2 centerPos;
	Vector2 scale;
	float angle;
	ALLEGRO_COLOR color;
	bool visible;

public:
	Renderable();
	//virtual ~Renderable();

	Vector2 getPosition() const;
	float getX() const;
	float getY() const;
	Vector2 getCenterPosition() const;
	float getCenterX() const;
	float getCenterY() const;
	Vector2 getScaleXY() const;
	float getScaleX() const;
	float getScaleY() const;
	float getAngle() const;
	ALLEGRO_COLOR getColor() const;
	unsigned char getAlpha() const;
	float getAlphaf() const;
	bool isVisible() const;

	void setPosition(float dx, float dy);
	void setPosition(const Vector2& dpos);
	void setX(float dx);
	void setY(float dy);
	void setCenterPosition(float dx, float dy);
	void setCenterPosition(const Vector2& dpos);
	void setCenterX(float dx);
	void setCenterY(float dy);
	void setScale(float dx, float dy);
	void setScale(const Vector2& dscale);
	void setScaleX(float dx);
	void setScaleY(float dy);
	void setAngle(float da);
	void setColor(const ALLEGRO_COLOR& dcolor);
	void setAlphaf(float opacity);
	void setAlpha(unsigned char opacity);
	void setVisible(bool dv);
	void toggleVisible();

	virtual bool init() = 0;
	virtual void draw(Graphics *g) const = 0;
	//	virtual void draw(Graphics *g, const Rect& rc) const = 0;
};

inline Vector2 Renderable::getPosition() const {
	return pos;
}

inline float Renderable::getX() const {
	return pos.getX();
}

inline float Renderable::getY() const {
	return pos.getY();
}

inline Vector2 Renderable::getCenterPosition() const {
	return centerPos;
}

inline float Renderable::getCenterX() const {
	return centerPos.getX();
}

inline float Renderable::getCenterY() const {
	return centerPos.getY();
}

inline Vector2 Renderable::getScaleXY() const {
	return scale;
}

inline float Renderable::getScaleX() const {
	return scale.getX();
}

inline float Renderable::getScaleY() const {
	return scale.getY();
}

inline float Renderable::getAngle() const {
	return angle;
}

inline ALLEGRO_COLOR Renderable::getColor() const {
	return color;
}

inline unsigned char Renderable::getAlpha() const {
	unsigned char alpha;
	al_unmap_rgba(color, NULL, NULL, NULL, &alpha);
	return alpha;
}

inline float Renderable::getAlphaf() const {
	return color.a;
}

inline bool Renderable::isVisible() const {
	return visible;
}

inline void Renderable::setPosition(float dx, float dy) {
	pos.setXY(dx, dy);
}

inline void Renderable::setPosition(const Vector2& dpos) {
	pos.setXY(dpos.getX(), dpos.getY());
}

inline void Renderable::setX(float dx) {
	pos.setX(dx);
}

inline void Renderable::setY(float dy) {
	pos.setY(dy);
}

inline void Renderable::setCenterPosition(float dx, float dy) {
	centerPos.setXY(dx, dy);
}

inline void Renderable::setCenterPosition(const Vector2& dpos) {
	centerPos.setXY(dpos.getX(), dpos.getY());
}

inline void Renderable::setCenterX(float dx) {
	centerPos.setX(dx);
}

inline void Renderable::setCenterY(float dy) {
	centerPos.setY(dy);
}

inline void Renderable::setScale(float dx, float dy) {
	scale.setXY(dx, dy);
}

inline void Renderable::setScale(const Vector2& dscale) {
	scale.setXY(dscale.getX(), dscale.getY());
}

inline void Renderable::setScaleX(float dx) {
	scale.setX(dx);
}

inline void Renderable::setScaleY(float dy) {
	scale.setY(dy);
}

inline void Renderable::setAngle(float da) {
	angle = da;
}

inline void Renderable::setColor(const ALLEGRO_COLOR& dcolor) {
	color = dcolor;
}

inline void Renderable::setAlphaf(float da) {
	color.a = da;
}

inline void Renderable::setAlpha(unsigned char da) {
	ALLEGRO_COLOR nColor = al_map_rgba(color.r, color.g, color.b, da);
	color = nColor;
}

inline void Renderable::setVisible(bool dv) {
	visible = dv;
}

inline void Renderable::toggleVisible() {
	visible = !visible;
}

#endif
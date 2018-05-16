#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "Renderable.h"

// �ؽ�ó(�̹���)�� ������
// ����1: Sprite Ŭ������ ����� �������� ������ ���ΰ�?
// ����2: � ���������� SpriteData�� ���� ���ΰ�?
// ����3: Sprite�� ����ϴ� Entity(GameObject) Ŭ������ ����
// ����4: Sprite�� ������ �̹����� ó���ϴ°�?
// ��, �ִϸ��̼� ����� �����ϴ� ������ Ŭ������ ������ ������, Sprite�� ���Խ�ų ������?
// �߽���ǥ
// ����5: Drawable �������̽��� ����? -> ��ġ, 

// Drawable�� ���Ե� �����
//Vector2 pos;
//Vector2 centerPos;
//Vector2 scale;
//float angle;
struct SpriteData
{
	char *filename;
	int width;
	int height;
	Rect rect;
	ALLEGRO_BITMAP *bitmap;
	ALLEGRO_COLOR colorkey;
};

// AnimData ����
// ������ ����
// �ִϸ��̼� ���� ������, �� ������ ��ȣ
// ���� ������
// ������ ���� �ð�
// �ִϸ��̼� �ݺ� ����
struct AnimData
{
	int rows, cols;
	int startFrame, endFrame;
	int currentFrame;
	float frameDelay;
	float animTimer;
	bool loop;
	bool animComplete;
};

class Sprite : public Renderable
{
private:
	SpriteData sprData;
	bool flipHorizontal;
	bool flipVertical;
	bool visible;

public:
	Sprite();
	Sprite(const char *filename);
	~Sprite();

	int getWidth() const;
	int getHeight() const;
	float getX() const;
	float getY() const;
	Vector2 getPosition() const;

	bool isFlipHorizontal() const;
	bool isFlipVertical() const;

	void setX(float dx);
	void setY(float dy);
	void setPosition(const Vector2& dpos);
	void setFlipHorizontal(bool flip);
	void setFlipVertical(bool flip);

	virtual bool init() = 0;
	virtual void draw(Graphics *g) const = 0;
	//	virtual void draw(Graphics *g, const Rect& rc) const = 0;
};


inline int Sprite::getWidth() const {
	return sprData.width;
}

inline int Sprite::getHeight() const {
	return sprData.height;
}

inline float Sprite::getX() const {
	return pos.getX();
}

inline float Sprite::getY() const {
	return pos.getY();
}

inline Vector2 Sprite::getPosition() const {
	return pos;
}

inline bool Sprite::isFlipHorizontal() const {
	return flipHorizontal;
}

inline bool Sprite::isFlipVertical() const {
	return flipVertical;
}

inline void Sprite::setX(float dx) {
	pos.setX(dx);
}

inline void Sprite::setY(float dy) {
	pos.setY(dy);
}

inline void Sprite::setPosition(const Vector2& dpos) {
	pos.setXY(pos.getX(), pos.getY());
}

inline void Sprite::setFlipHorizontal(bool flip) {
	flipHorizontal = flip;
}

inline void Sprite::setFlipVertical(bool flip) {
	flipVertical = flip;
}

#endif
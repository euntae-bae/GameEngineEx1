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
typedef struct _SpriteData
{
	char *filename;
	int width;
	int height;
	Rect rect;
	ALLEGRO_BITMAP *bitmap;
	Color colorkey;
} SpriteData;

// AnimData ����
// ������ ����
// �ִϸ��̼� ���� ������, �� ������ ��ȣ
// ���� ������
// ������ ���� �ð�
// �ִϸ��̼� �ݺ� ����
typedef struct _AnimData
{
	int rows, cols;
	int startFrame, endFrame;
	int currentFrame;
	float frameDelay;
	float animTimer;
	bool loop;
	bool animComplete;
} AnimData;

// version 0.06: visible ����� Renderable�� ������
class Sprite : public Renderable
{
private:
	SpriteData sprData;
	bool flipHorizontal;
	bool flipVertical;

public:
//	Sprite();
	Sprite(const char *filename);
	Sprite(const char *filename, const Color& colorkey);
	~Sprite();

	int getWidth() const;
	int getHeight() const;
	Rect getRect() const;
	ALLEGRO_BITMAP * getBitmap() const;

	bool isFlipHorizontal() const;
	bool isFlipVertical() const;

	void setFlipHorizontal(bool flip);
	void setFlipVertical(bool flip);
	void toggleFlipHorizontal();
	void toggleFlipVertical();

	bool init();
	void draw(Graphics *g) const;
	//virtual void draw(Graphics *g, const Rect& rc) const = 0;

#ifdef _DEBUG
	void printInfo() const {
		printf("x, y: %f, %f\n", pos.getX(), pos.getY());
		printf("centerPos: %f, %f\n", centerPos.getX(), centerPos.getY());
		printf("scale(x, y): %f, %f\n", scale.getX(), scale.getY());
		printf("angle: %f\n", angle);
		printf("color(r, g, b, a): %f, %f, %f, %f\n", color.r, color.g, color.b, color.a);
		printf("sprData.filename: %s\n", sprData.filename);
		printf("sprData.width: %d\n", sprData.width);
		printf("sprData.height: %d\n", sprData.height);
		printf("sprData.rect.x: %d\n", sprData.rect.getX());
		printf("sprData.rect.y: %d\n", sprData.rect.getY());
		printf("sprData.rect.width: %d\n", sprData.rect.getWidth());
		printf("sprData.rect.height: %d\n", sprData.rect.getHeight());
		printf("flipHorizontal: %d\n", flipHorizontal);
		printf("flipVertical: %d\n", flipVertical);
		printf("visible: %d\n", visible);
	}
#endif
};

inline int Sprite::getWidth() const {
	return sprData.width;
}

inline int Sprite::getHeight() const {
	return sprData.height;
}

inline Rect Sprite::getRect() const {
	return sprData.rect;
}

inline ALLEGRO_BITMAP * Sprite::getBitmap() const {
	return sprData.bitmap;
}

inline bool Sprite::isFlipHorizontal() const {
	return flipHorizontal;
}

inline bool Sprite::isFlipVertical() const {
	return flipVertical;
}

inline void Sprite::setFlipHorizontal(bool flip) {
	flipHorizontal = flip;
}

inline void Sprite::setFlipVertical(bool flip) {
	flipVertical = flip;
}

inline void Sprite::toggleFlipHorizontal() {
	flipHorizontal = !flipHorizontal;
}

inline void Sprite::toggleFlipVertical() {
	flipVertical = !flipVertical;
}

#endif
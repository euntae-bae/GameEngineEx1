#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "Renderable.h"

// 텍스처(이미지)의 데이터
// 쟁점1: Sprite 클래스의 기능을 어디까지로 제한할 것인가?
// 쟁점2: 어떤 정보까지를 SpriteData에 담을 것인가?
// 쟁점3: Sprite를 상속하는 Entity(GameObject) 클래스의 정의
// 쟁점4: Sprite는 정지된 이미지만 처리하는가?
// 즉, 애니메이션 기능을 포함하는 별도의 클래스를 설계할 것인지, Sprite에 포함시킬 것인지?
// 중심좌표
// 쟁점5: Drawable 인터페이스의 설계? -> 위치, 

// Drawable로 포함된 멤버들
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

// AnimData 정의
// 프레임 개수
// 애니메이션 시작 프레임, 끝 프레임 번호
// 현재 프레임
// 프레임 지연 시간
// 애니메이션 반복 여부
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

// version 0.06: visible 멤버가 Renderable로 이전됨
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
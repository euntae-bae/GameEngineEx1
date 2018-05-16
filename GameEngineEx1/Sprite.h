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
struct SpriteData
{
	char *filename;
	int width;
	int height;
	Rect rect;
	ALLEGRO_BITMAP *bitmap;
	ALLEGRO_COLOR colorkey;
};

// AnimData 정의
// 프레임 개수
// 애니메이션 시작 프레임, 끝 프레임 번호
// 현재 프레임
// 프레임 지연 시간
// 애니메이션 반복 여부
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
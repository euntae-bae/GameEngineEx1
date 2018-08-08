#ifndef __STATE_LAB2_H__
#define __STATE_LAB2_H__

#include "State.h"
#include "Sprite.h"

class StateLab2 : public State
{
private:
	ALLEGRO_FONT *font;
	Sprite *ball;
	float vx, vy;
	float x, y;
	float angle;
	Vector2 vel, pos;
	const float SPEED;
	bool ballBlocked;
	float GR;

public:
	StateLab2() : font(NULL), ball(NULL), SPEED(3.0f) {}

	bool init();
	void cleanup();
	void pause();
	void resume();
	void onEnter();
	void onExit();
	void handleEvents(Game *game);
	void update(Game *game);
	void draw(Graphics *g);
};

#endif
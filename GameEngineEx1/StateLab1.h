#ifndef __STATE_LAB1_H__
#define __STATE_LAB1_H__
#include "State.h"
#include "Sprite.h"

class StateLab1 : public State
{
private:
	ALLEGRO_FONT *font;
	Sprite *spr1;
	Sprite *spr2;
	Vector2 vel;
	Vector2 pos1;
	bool keyInputs[4];

public:
	enum { KEY_UP = 0, KEY_DOWN, KEY_LEFT, KEY_RIGHT };

	StateLab1() : font(NULL), spr1(NULL), spr2(NULL) {}

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
#ifndef __STATE_TITLE_H__
#define __STATE_TITLE_H__

#include "State.h"
#include "Sprite.h"

class StateTitle : public State
{
private:
	Sprite *bg;
	Sprite *spr;
	ALLEGRO_FONT *font;
	Vector2 pos;
	Vector2 dv;
	float speed;
public:
	StateTitle() : bg(NULL), spr(NULL), font(NULL) {}

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
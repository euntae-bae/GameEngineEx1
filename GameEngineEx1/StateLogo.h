#ifndef __STATE_LOGO_H__
#define __STATE_LOGO_H__

#include "State.h"
#include "Sprite.h"

class StateLogo : public State
{
private:
	Sprite *logoImage;
	ALLEGRO_FONT *font;
	int count;

public:
	StateLogo() : logoImage(NULL), font(NULL) {}

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
#ifndef __STATE_TITLE_H__
#define __STATE_TITLE_H__

#include "State.h"
#include "Sprite.h"

class StateTitle : public State
{
private:
	Sprite *spr;
public:
	bool init();
	void cleanup();

	void pause();
	void resume();

	void onEnter();
	void onExit();

	void handleEvents(Game *game);
	void update();
	void draw(Graphics *g);
};

#endif
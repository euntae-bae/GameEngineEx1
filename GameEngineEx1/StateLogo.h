#ifndef __STATE_LOGO_H__
#define __STATE_LOGO_H__

#include "State.h"
#include "Sprite.h"

class StateLogo : public State
{
private:
	Sprite *logoImage;

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
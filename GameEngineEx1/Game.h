#ifndef __GAME_H__
#define __GAME_H__
#include "Graphics.h"
#include "Input.h"
const int MAX_TITLE_LENGTH = 256;

// game state -> pause(); resume(); ... etc
// save, load

class Game
{
protected:
	char *gameTitle;
	float fps;
	bool gameLoop;

	ALLEGRO_EVENT_QUEUE *eventQueue;
	ALLEGRO_TIMER *mainTimer;

	Graphics *graphics;
	Input *input;
	//Audio *audio;
public:
	Game(const char *title);
	virtual ~Game();
	virtual bool init(); // ∞‘¿” √ ±‚»≠ √—∞˝(graphics.init(), game.init()....)
	virtual void getInput();
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void loop();
};

#endif
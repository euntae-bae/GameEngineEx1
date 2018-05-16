#ifndef __GAME_H__
#define __GAME_H__
#include "Graphics.h"
const int MAX_TITLE_LENGTH = 256;

// 펄어비스: 검은사막?

class Game
{
private:
	char gameTitle[MAX_TITLE_LENGTH];
	Graphics *graphics;
	ALLEGRO_EVENT_QUEUE *eventQueue;
	// Input *inputState;
	// Audio *audio;
	// game state -> pause(); resume(); ... etc
	// save, load
	// FPS
	// bool loop;
	bool gameLoop;

public:
	Game(const char *title);
	virtual ~Game();
	virtual bool init(const char *title); // 게임 초기화 총괄(graphics.init(), game.init()....)
	//virtual void update();
	//virtual void draw();
	//virtual void loop();
};

#endif
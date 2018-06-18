#ifndef __GAME_H__
#define __GAME_H__
#include "Graphics.h"
#include "Input.h"
const int MAX_TITLE_LENGTH = 256;

// game state -> pause(); resume(); ... etc
// save, load

// TODO: version 0.07
// 프레임 레이트 기능 구현
// const char * getTitle() const;
// void setTitle(const char *title);

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
	virtual bool init(); // 게임 초기화 총괄(graphics.init(), game.init()....)
	virtual void getInput();
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void loop();
};

#endif
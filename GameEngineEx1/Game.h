#ifndef __GAME_H__
#define __GAME_H__
#include "Graphics.h"
const int MAX_TITLE_LENGTH = 256;

// �޾��: �����縷?

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
	virtual bool init(const char *title); // ���� �ʱ�ȭ �Ѱ�(graphics.init(), game.init()....)
	//virtual void update();
	//virtual void draw();
	//virtual void loop();
};

#endif
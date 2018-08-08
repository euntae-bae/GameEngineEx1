#ifndef __MY_GAME_H__
#define __MY_GAME_H__

#include "Game.h"

class MyGame : public Game
{
public:
	MyGame(const char *title);
	~MyGame();
	bool init();
	void update();
	void draw();
};

#endif
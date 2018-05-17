#ifndef __MY_GAME_H__

#include "Game.h"

class MyGame : public Game
{
public:
	MyGame(const char *title);
	~MyGame();
	bool init();
};

#endif
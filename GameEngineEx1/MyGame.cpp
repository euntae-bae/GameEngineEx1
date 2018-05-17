#include "MyGame.h"

MyGame::MyGame(const char *title)
	: Game(title)
{
#ifdef _DEBUG
	puts("MyGame::MyGame()");
#endif
	if (!init()) {
		fprintf(stderr, "Error: MyGame::init()\n");
		// throw exception("error");
	}
}

MyGame::~MyGame()
{
#ifdef _DEBUG
	puts("MyGame::~MyGame()");
#endif
}

bool MyGame::init()
{
#ifdef _DEBUG
	puts("MyGame::init()");
#endif
}
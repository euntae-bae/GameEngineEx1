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

void MyGame::update()
{
#ifdef _DEBUG
	puts("MyGame::update()");
#endif
	if (!states.empty()) {
		states.back()->update();
	}
}

void MyGame::draw()
{
#ifdef _DEBUG
	puts("MyGame::draw()");
#endif
	graphics->clear();
	states.back()->draw(graphics);
	graphics->flip();
}

bool MyGame::init()
{
#ifdef _DEBUG
	puts("MyGame::init()");
#endif
	pushState(&logo);
	return true;
}
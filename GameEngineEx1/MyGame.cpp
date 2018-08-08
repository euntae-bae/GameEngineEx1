#include "MyGame.h"
#include "StateLogo.h"

StateLogo logo;

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
//	puts("MyGame::update()");
#endif
	if (!states.empty()) {
		states.back()->update(this);
	}
}

void MyGame::draw()
{
#ifdef _DEBUG
//	puts("MyGame::draw()");
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
	// 첫 상태(장면)으로 로고 화면을 삽입한다.
	pushState(&logo);
	return true;
}
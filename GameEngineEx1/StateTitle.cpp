#include "StateTitle.h"

bool StateTitle::init()
{
#ifdef _DEBUG
	puts("StateTitle::init()");
#endif
	return true;
}

void StateTitle::cleanup()
{
#ifdef _DEBUG
	puts("StateTitle::cleanup()");
#endif
}

void StateTitle::pause()
{
#ifdef _DEBUG
	puts("StateTitle::pause()");
#endif
}

void StateTitle::resume()
{
#ifdef _DEBUG
	puts("StateTitle::resume()");
#endif
}

void StateTitle::onEnter()
{
#ifdef _DEBUG
	puts("StateTitle::onEnter()");
#endif
}

void StateTitle::onExit()
{
#ifdef _DEBUG
	puts("StateTitle::onExit()");
#endif
}

void StateTitle::handleEvents(Game *game)
{
#ifdef _DEBUG
	puts("StateTitle::handleEvents()");
#endif
}

void StateTitle::update()
{
#ifdef _DEBUG
	puts("StateTitle::update()");
#endif
}

void StateTitle::draw(Graphics *g)
{
#ifdef _DEBUG
	puts("StateTitle::draw()");
#endif
}
#include <cstdio>
#include "Game.h"
#include "StateLogo.h"

bool StateLogo::init()
{
#ifdef _DEBUG
	puts("StateLogo::init()");
#endif
	count = 0;
	logoImage = new Sprite("sprites/logo_sample.png");
	logoImage->setPosition(0, 0);
	font = al_load_font("fonts/consola.ttf", 18, 0);
	return true;
}

void StateLogo::cleanup()
{
#ifdef _DEBUG
	puts("StateLogo::cleanup()");
#endif
	delete logoImage;
	logoImage = NULL;
	al_destroy_font(font);
	font = NULL;
}

void StateLogo::pause()
{
#ifdef _DEBUG
	puts("StateLogo::pause()");
#endif
}

void StateLogo::resume()
{
#ifdef _DEBUG
	puts("StateLogo::resume()");
#endif
}

void StateLogo::onEnter()
{
#ifdef _DEBUG
	puts("StateLogo::onEnter()");
#endif
}

void StateLogo::onExit()
{
#ifdef _DEBUG
	puts("StateLogo::onExit()");
#endif
}

void StateLogo::handleEvents(Game *game)
{
#ifdef _DEBUG
	puts("StateLogo::handleEvents()");
#endif
	if (game->getEvent().type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		game->close();
		return;
	}
}

void StateLogo::update()
{
#ifdef _DEBUG
	puts("StateLogo::update()");
#endif
	if (count >= 1000) {
	}
	count++;
}

void StateLogo::draw(Graphics *g)
{
#ifdef _DEBUG
	puts("StateLogo::draw()");
#endif
	logoImage->draw(g);
	printf("count: %d\n", count);
	al_draw_textf(font, COLOR_RED, DEFAULT_SCREEN_WIDTH - 20, 20, ALLEGRO_ALIGN_RIGHT, "count: %d", count);
}
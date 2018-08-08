#include "StateTitle.h"

#include "Game.h"
#include "StateLab1.h"

StateLab1 stateLab1;

bool StateTitle::init()
{
#ifdef _DEBUG
	puts("StateTitle::init()");
#endif
	font = al_load_font("fonts/consola.ttf", 18, 0);
	if (!font) {
		fprintf(stderr, "Error: al_load_font()");
		return false;
	}
	bg = new Sprite("sprites/title_sample.png");
	spr = new Sprite("sprites/spr03.png");

	bg->setPosition(0, 0);

	spr->setPosition(100, 100);
	spr->setScale(2.0f);
	pos.setXY(spr->getPosition());
	dv.setXY(0.0f, 0.0f);
	speed = 2.0f;
	return true;
}

void StateTitle::cleanup()
{
#ifdef _DEBUG
	puts("StateTitle::cleanup()");
#endif
	if (font) {
		al_destroy_font(font);
	}

	if (bg) {
		delete bg;
		bg = NULL;
	}

	if (spr) {
		delete spr;
		spr = NULL;
	}
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
//	puts("StateTitle::handleEvents()");
#endif
	const ALLEGRO_EVENT& ev = game->getEvent();
	if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		game->close();
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_ESCAPE:
			puts("Escape!");
			game->popState();
			break;
		case ALLEGRO_KEY_SPACE:
			puts("StateLab1!");
			game->pushState(&stateLab1);
			break;
		}
	}
}

void StateTitle::update(Game *game)
{
#ifdef _DEBUG
//	puts("StateTitle::update()");
#endif
	Input *input = game->getInput();
	if (input->isKeyDown(ALLEGRO_KEY_UP)) {
		//dv.setY(speed);
		puts("KEY_UP");
		spr->setScale(4.0f);
	}
	else if (input->isKeyDown(ALLEGRO_KEY_DOWN)) {
		//dv.setY(-speed);
		puts("KEY_DOWN");
		spr->setScale(1.0f);
	}
	else if (input->isKeyDown(ALLEGRO_KEY_LEFT)) {
		//dv.setX(-speed);
		puts("KEY_LEFT");
		spr->setScale(3.0f, 1.0f);
	}
	else if (input->isKeyDown(ALLEGRO_KEY_RIGHT)) {
		//dv.setX(speed);
		puts("KEY_RIGHT");
		spr->setScale(1.0f, 3.0f);
	}
	//pos += dv;
	spr->setPosition(pos);
}

void StateTitle::draw(Graphics *g)
{
#ifdef _DEBUG
//	puts("StateTitle::draw()");
#endif
	bg->draw(g);
	spr->draw(g);
	al_draw_text(font, COLOR_WHITE, 20.0f, 20.0f, 0, "Hello StateTitle!");
}
#include <cstdio>
#include "MyGame.h"
#include "StateLab1.h"

#include "StateLab2.h"
StateLab2 lab2;

bool StateLab1::init()
{
#ifdef _DEBUG
	puts("StateLab1::init()");
#endif
	font = al_load_font("fonts/consola.ttf", 18, 0);

	spr1 = new Sprite("sprites/spr01.png");
	spr2 = new Sprite("sprites/spr02.png");

	spr1->setPosition(0, 0);
	spr2->setPosition(0, 100);

	pos1.setXY(spr1->getPosition());

	keyInputs[4] = { false, };
	return true;
}

void StateLab1::cleanup()
{
#ifdef _DEBUG
	puts("StateLab1::cleanup()");
#endif
	if (spr1) {
		delete spr1;
		spr1 = NULL;
	}
	if (spr2) {
		delete spr2;
		spr2 = NULL;
	}
}

void StateLab1::pause()
{
#ifdef _DEBUG
	puts("StateLab1::pause()");
#endif
}

void StateLab1::resume()
{
#ifdef _DEBUG
	puts("StateLab1::resume()");
#endif
}

void StateLab1::onEnter()
{
#ifdef _DEBUG
	puts("StateLab1::onEnter()");
#endif
}

void StateLab1::onExit()
{
#ifdef _DEBUG
	puts("StateLab1::onExit()");
#endif
}

void StateLab1::handleEvents(Game *game)
{
	const ALLEGRO_EVENT &ev = game->getEvent();
	if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		game->close();
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_ESCAPE:
			puts("#################################");
			puts("StateLab1::pop");
			game->popState();
			break;
		case ALLEGRO_KEY_SPACE:
			puts("#################################");
			puts("StateLab1::push");
			game->pushState(&lab2);
			break;
		}
	}
	/*
	else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			puts("up: KEY_UP");
			break;
		case ALLEGRO_KEY_DOWN:
			puts("up: KEY_DOWN");
			break;
		case ALLEGRO_KEY_LEFT:
			puts("up: KEY_LEFT");
			break;
		case ALLEGRO_KEY_RIGHT:
			puts("up: KEY_RIGHT");
			break;
		}
	}
	*/
}

void StateLab1::update(Game *game)
{
	Input *input = game->getInput();
	const float SPEED = 5.0f;
	const float MAX_XPOS = (float)(DEFAULT_SCREEN_WIDTH - spr1->getWidth());
	const float MAX_YPOS = (float)(DEFAULT_SCREEN_HEIGHT - spr1->getHeight());
	float vx = 0.0f, vy = 0.0f;

	keyInputs[KEY_UP] = input->isKeyDown(ALLEGRO_KEY_UP);
	keyInputs[KEY_DOWN] = input->isKeyDown(ALLEGRO_KEY_DOWN);
	keyInputs[KEY_LEFT] = input->isKeyDown(ALLEGRO_KEY_LEFT);
	keyInputs[KEY_RIGHT] = input->isKeyDown(ALLEGRO_KEY_RIGHT);

	/*
	if (keyInputs[KEY_LEFT]) {
		if (keyInputs[KEY_UP] || keyInputs[KEY_DOWN]) {
			vx -= SPEED / RT2;
		}
		else {
			vx -= SPEED;
		}
	}

	if (keyInputs[KEY_RIGHT]) {
		if (keyInputs[KEY_UP] || keyInputs[KEY_DOWN]) {
			vx += (SPEED / RT2);
		}
		else {
			vx += SPEED;
		}
	}

	if (keyInputs[KEY_UP]) {
		if (keyInputs[KEY_LEFT] || keyInputs[KEY_RIGHT]) {
			vy -= SPEED / RT2;
		}
		else {
			vy -= SPEED;
		}
	}

	if (keyInputs[KEY_DOWN]) {
		if (keyInputs[KEY_LEFT] || keyInputs[KEY_RIGHT]) {
			vy += SPEED / RT2;
		}
		else {
			vy += SPEED;
		}
	}
	*/

	/*

	if (keyInputs[KEY_UP]) {
		vy -= SPEED;
	}
	else if (keyInputs[KEY_DOWN]) {
		vy += SPEED;
	}
	else if (keyInputs[KEY_LEFT]) {
		vx -= SPEED;
	}
	else if (keyInputs[KEY_RIGHT]) {
		vx += SPEED;
	}
	*/

	float angle = PI / 6.0f; // 30도
	vx = SPEED * cosf(angle);
	vy = SPEED * sinf(angle);

	vel.setXY(vx, vy);
	pos1 = spr1->getPosition();
	pos1 += vel;

	// 스프라이트가 화면 경계를 벗어나는지 검사한다.
	if (pos1.getX() < 0.0f) {
		pos1.setX(0.0f);
	}
	else if (pos1.getX() > MAX_XPOS) {
		pos1.setX(MAX_XPOS);
	}

	if (pos1.getY() < 0.0f) {
		pos1.setY(0.0f);
	}
	else if (pos1.getY() > MAX_YPOS) {
		pos1.setY(MAX_YPOS);
	}

	spr1->setPosition(pos1);
}

void StateLab1::draw(Graphics *g)
{
	spr1->draw(g);
	spr2->draw(g);

	al_draw_textf(font, COLOR_WHITE, DEFAULT_SCREEN_WIDTH - 20, 20, ALLEGRO_ALIGN_RIGHT, "up: %d down: %d left: %d right: %d", keyInputs[0], keyInputs[1], keyInputs[2], keyInputs[3]);
}
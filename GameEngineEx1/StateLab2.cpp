#include <cstdio>
#include "MyGame.h"
#include "StateLab2.h"

bool StateLab2::init()
{
	ball = new Sprite("sprites/ball_sample2.png");
	ball->setPosition(0.0f, 0.0f);

	font = al_load_font("fonts/consola.ttf", 18, 0);
	if (!font) {
		fprintf(stderr, "error: al_load_font()\n");
		return false;
	}

	angle = 0.0f;
	GR = 3.0f;

	//vx = SPEED * cosf(angle);
	//vy = SPEED * sinf(angle);
	vx = 0.0f, vy = 0.0f;
	ballBlocked = false;

	x = 0.0f, y = 0.0f;

	vel.setXY(0.0f, 0.0f);
	pos.setXY(0.0f, 0.0f);
	return true;
}

void StateLab2::cleanup()
{
#ifdef _DEBUG
	puts("StateLab2::cleanup()");
#endif
	if (ball)
		delete ball;
}

void StateLab2::pause()
{}

void StateLab2::resume()
{}

void StateLab2::onEnter()
{
#ifdef _DEBUG
	puts("StateLab2::onEnter()");
#endif
}

void StateLab2::onExit()
{
#ifdef _DEBUG
	puts("StateLab2::onExit()");
#endif
}

void StateLab2::handleEvents(Game *game)
{
	const ALLEGRO_EVENT& ev = game->getEvent();

	if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		game->close();
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_ESCAPE:
			game->popState();
			break;
		case ALLEGRO_KEY_SPACE:
			vx = 0.0f, vy = 0.0f;
			x = 50.0f;
			y = 100.0f;
			//ballBlocked = false;
			break;
		case ALLEGRO_KEY_UP:
			GR += 0.1f;
			break;
		case ALLEGRO_KEY_DOWN:
			GR -= 0.1f;
			break;
		}
	}
}

void StateLab2::update(Game *game)
{
	// 키보드 입력에 따른 처리
	/*

	float vx = 0.0f, vy = 0.0f;
	float angle = PI / 6.0f;
	const float SPEED = 5.0f;
	const int BALL_WIDTH = ball->getWidth();
	const int BALL_HEIGHT = ball->getHeight();
	const float MAX_XPOS = (float)(DEFAULT_SCREEN_WIDTH - BALL_WIDTH);
	const float MAX_YPOS = (float)(DEFAULT_SCREEN_HEIGHT - BALL_HEIGHT);

	vx = SPEED * cosf(angle);
	vy = SPEED * sinf(angle);
	vel.setXY(vx, vy);
	pos = ball->getPosition();
	pos += vel;
	*/
	/*
	if (pos.getX() < 0.0f) {
		pos.setX(0.0f);
	}
	else if (pos.getX() > MAX_XPOS) {
		pos.setX(MAX_XPOS);
	}

	if (pos.getY() < 0.0f) {
		pos.setY(0.0f);
	}
	else if (pos.getY() > MAX_YPOS) {
		pos.setY(MAX_YPOS);
	}
	*/
	
	const int BALL_WIDTH = ball->getWidth();
	const int BALL_HEIGHT = ball->getHeight();
	const float MAX_XPOS = (float)(DEFAULT_SCREEN_WIDTH - BALL_WIDTH);
	const float MAX_YPOS = (float)(DEFAULT_SCREEN_HEIGHT - BALL_HEIGHT);

	//if (!ballBlocked) {
	//	x += vx;
	//	y += vy;
	//	vy += GR;
	//}

	y += vy;
	vy += GR;
	/*
	if ((x < -BALL_WIDTH) || (x > MAX_XPOS) || (y < -BALL_HEIGHT) || (y > MAX_YPOS)) {
		x = (float)(DEFAULT_SCREEN_WIDTH - BALL_WIDTH) / 2.0f;
		y = (float)(DEFAULT_SCREEN_HEIGHT - BALL_HEIGHT) / 2.0f;
		angle += 2.0f * PI / 10.0f; // 각도를 1/10바퀴만큼 증가시킨다.
		if (angle > 2.0f * PI) {
			angle -= 2.0f * PI;
		}
		vx = SPEED * cosf(angle);
		vy = SPEED * sinf(angle);
	}
	*/

	if (y < 0) {
		vy = 0.0f;
		y = 0.0f;
		//ballBlocked = true;
	}
	else if (y > MAX_YPOS) {
		vy = 0.0f;
		y = MAX_YPOS;
		//ballBlocked = true;
	}

	ball->setPosition(x, y);
}

void StateLab2::draw(Graphics *g)
{
	ball->draw(g);
	al_draw_textf(font, COLOR_WHITE, 20.0f, 20.0f, 0, "x: %.3f, y: %.3f", ball->getX(), ball->getY());
	al_draw_textf(font, COLOR_YELLOW, 20.0f, 40.0f, 0, "vy: %.3f, GR: %.3f", vy, GR);
}
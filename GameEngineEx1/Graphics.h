#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <cstdio>
#include <allegro5/allegro.h>

const int DEFAULT_SCREEN_WIDTH = 640;
const int DEFAULT_SCREEN_HEIGHT = 480;

/*
const ALLEGRO_COLOR COLOR_BLACK = al_map_rgb(0, 0, 0);
const ALLEGRO_COLOR COLOR_WHITE = al_map_rgb(255, 255, 255);
const ALLEGRO_COLOR COLOR_RED = al_map_rgb(255, 0, 0);
const ALLEGRO_COLOR COLOR_GREEN = al_map_rgb(0, 255, 0);
const ALLEGRO_COLOR COLOR_BLUE = al_map_rgb(0, 0, 255);
*/

#define COLOR_BLACK	al_mab_rgb(0, 0, 0)
#define COLOR_WHITE	al_map_rgb(255, 255, 255)
#define COLOR_RED	al_map_rgb(255, 0, 0)
#define COLOR_GREEN	al_map_rgb(0, 255, 0)
#define COLOR_BLUE	al_map_rgb(0, 0, 255)

class Vector2
{
private:
	float x, y;
public:
	Vector2(float _x = 0.0f, float _y = 0.0f)
		: x(_x), y(_y)
	{
#ifdef _DEBUG
		puts("Vector2(float, float)");
#endif
	}

	~Vector2()
	{
#ifdef _DEBUG
		puts("~Vector2()");
#endif
	}
	
	float getX() const {
		return x;
	}

	float getY() const {
		return y;
	}

	void setX(float _x) {
		x = _x;
	}

	void setY(float _y) {
		y = _y;
	}

	void setXY(const Vector2& vec) {
		x = vec.x;
		y = vec.y;
	}
};

class Rect
{
private:
	int x, y;
	int width, height;
public:
	Rect(int _x = 0, int _y = 0, int _w = 0, int _h = 0)
		: x(_x), y(_y), width(_w), height(_h)
	{
#ifdef _DEBUG
		puts("Rect(int, int, int, int)");
#endif
	}

	~Rect()
	{
#ifdef _DEBUG
		puts("~Rect()");
#endif
	}

	int getX() const {
		return x;
	}

	int getY() const {
		return y;
	}

	int getWidth() const {
		return width;
	}

	int getHeight() const {
		return height;
	}
};

class Graphics
{
private:
	ALLEGRO_DISPLAY *display;
	int width, height; // 디스플레이의 너비와 높이
	ALLEGRO_COLOR bgcolor;
public:
	Graphics(int w = DEFAULT_SCREEN_WIDTH, int h = DEFAULT_SCREEN_HEIGHT)
	{
		puts("Graphics::Graphics()");
		
		if (!init(w, h))
			puts("failed init()");
	}

	~Graphics()
	{
		al_destroy_display(display);
		puts("Graphics::~Graphics()");
	}

	void clear()
	{
		al_clear_to_color(bgcolor);
	}

	void flip()
	{
		al_flip_display();
	}

	int getScreenWidth() const {
		return width;
	}

	int getScreenHeight() const {
		return height;
	}

	ALLEGRO_DISPLAY * getDisplay() const {
		return display;
	}

	void draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const ALLEGRO_COLOR& tint = al_map_rgb(255, 255, 255));
	void draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Rect& rect, const ALLEGRO_COLOR& tint = al_map_rgb(255, 255, 255));
	void draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Vector2& centerPos, const Vector2& scale, float angle, const ALLEGRO_COLOR& tint = al_map_rgb(255, 255, 255));
	void draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Vector2& centerPos, const Rect& rect, const Vector2& scale, float angle, const ALLEGRO_COLOR& tint = al_map_rgb(255, 255, 255));
private:
	bool init(int w = DEFAULT_SCREEN_WIDTH, int h = DEFAULT_SCREEN_HEIGHT);
};

#endif
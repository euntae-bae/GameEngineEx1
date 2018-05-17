#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <cstdio>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#include "Math.h"

const int DEFAULT_SCREEN_WIDTH = 640;
const int DEFAULT_SCREEN_HEIGHT = 480;

#define COLOR_BLACK	al_map_rgb(0, 0, 0)
#define COLOR_WHITE	al_map_rgb(255, 255, 255)
#define COLOR_RED	al_map_rgb(255, 0, 0)
#define COLOR_GREEN	al_map_rgb(0, 255, 0)
#define COLOR_BLUE	al_map_rgb(0, 0, 255)

class Graphics
{
private:
	ALLEGRO_DISPLAY *display;
	int width, height; // 디스플레이의 너비와 높이
	ALLEGRO_COLOR bgcolor;
public:
	Graphics();
	Graphics(int w, int h);
	~Graphics();

	void clear() const;
	void flip() const;
	int getScreenWidth() const;
	int getScreenHeight() const;
	ALLEGRO_COLOR getBackGroundColor() const;
	ALLEGRO_DISPLAY * getDisplay() const;
	void draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const ALLEGRO_COLOR& tint = COLOR_WHITE) const;
	void draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Rect& rect, const ALLEGRO_COLOR& tint = COLOR_WHITE) const;
	void draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Vector2& centerPos, const Vector2& scale, float angle, const ALLEGRO_COLOR& tint = COLOR_WHITE) const;
	void draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Vector2& centerPos, const Rect& rect, const Vector2& scale, float angle, const ALLEGRO_COLOR& tint = COLOR_WHITE) const;
	void draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Vector2& centerPos, const Rect& rect, const Vector2& scale, float angle, bool flipH, bool flipV, const ALLEGRO_COLOR& tint = COLOR_WHITE) const;
	bool init(int w = DEFAULT_SCREEN_WIDTH, int h = DEFAULT_SCREEN_HEIGHT);
};

inline void Graphics::clear() const
{
	al_clear_to_color(bgcolor);
}

inline void Graphics::flip() const
{
	al_flip_display();
}

inline int Graphics::getScreenWidth() const {
	return width;
}

inline int Graphics::getScreenHeight() const {
	return height;
}

inline ALLEGRO_COLOR Graphics::getBackGroundColor() const {
	return bgcolor;
}

inline ALLEGRO_DISPLAY * Graphics::getDisplay() const {
	return display;
}

#endif
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

typedef ALLEGRO_COLOR Color;

class Graphics
{
private:
	ALLEGRO_DISPLAY *display;
	int width, height; // 디스플레이의 너비와 높이
	Color bgcolor;
public:
	Graphics();
	Graphics(int w, int h);
	~Graphics();

	void clear() const;
	void flip() const;
	int getScreenWidth() const;
	int getScreenHeight() const;
	Color getBackGroundColor() const;
	ALLEGRO_DISPLAY * getDisplay() const;
	void showCursor();
	void hideCursor();
	void draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Color& tint = COLOR_WHITE) const;
	void draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Rect& rect, const Color& tint = COLOR_WHITE) const;
	void draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Vector2& centerPos, const Vector2& scale, float angle, const Color& tint = COLOR_WHITE) const;
	void draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Vector2& centerPos, const Rect& rect, const Vector2& scale, float angle, const Color& tint = COLOR_WHITE) const;
	void draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Vector2& centerPos, const Rect& rect, const Vector2& scale, float angle, bool flipH, bool flipV, const Color& tint = COLOR_WHITE) const;
	bool init();
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

inline Color Graphics::getBackGroundColor() const {
	return bgcolor;
}

inline ALLEGRO_DISPLAY * Graphics::getDisplay() const {
	return display;
}

inline void Graphics::showCursor() {
	al_show_mouse_cursor(display);
}
inline void Graphics::hideCursor() {
	al_hide_mouse_cursor(display);
}

#endif
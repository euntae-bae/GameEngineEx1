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

// TODO: version 0.07
// 디스플레이 관련 연산 추가
// - 윈도우 창 크기 조정
// - 전체 화면: 추가함

typedef ALLEGRO_COLOR Color;

class Graphics
{
private:
	ALLEGRO_DISPLAY *display;
	int width, height; // 디스플레이의 너비와 높이
	bool fullScreen;
	bool resizable;
	Color bgcolor;
public:
	Graphics();
	Graphics(int w, int h);
	Graphics(int w, int h, bool fullscreen, bool resize = false);
	~Graphics();

	void clear() const;
	void flip() const;
	int getScreenWidth() const;
	int getScreenHeight() const;
	bool isFullScreen() const;
	bool isResizable() const;
	Color getBackGroundColor() const;
	ALLEGRO_DISPLAY * getDisplay() const;
	void showCursor();
	void hideCursor();
	void setFullScreen(bool f);
	// resizable 설정은 디스플레이 생성 시에만 가능하다.
	//void setResizable(bool r);
	void setScreenWidth(int w);
	void setScreenHeight(int h);
	void setScreenSize(int w, int h);
	void draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Color& tint = COLOR_WHITE) const;
	void draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Rect& rect, const Color& tint = COLOR_WHITE) const;
	void draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Vector2& centerPos, const Vector2& scale, float angle, const Color& tint = COLOR_WHITE) const;
	void draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Vector2& centerPos, const Rect& rect, const Vector2& scale, float angle, const Color& tint = COLOR_WHITE) const;
	void draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Vector2& centerPos, const Rect& rect, const Vector2& scale, float angle, bool flipH, bool flipV, const Color& tint = COLOR_WHITE) const;
	bool init();
};

inline bool Graphics::isFullScreen() const {
	return fullScreen;
}

inline bool Graphics::isResizable() const {
	return resizable;
}

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

inline void Graphics::setFullScreen(bool f) {
	fullScreen = f;
	al_set_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, fullScreen);
}

/*
inline void Graphics::setResizable(bool r) {
	resizable = r;
	al_set_display_flag(display, ALLEGRO_RESIZABLE, resizable);
}
*/

inline void Graphics::setScreenWidth(int w) {
	setScreenSize(w, height);
}

inline void Graphics::setScreenHeight(int h) {
	setScreenSize(width, h);
}

inline void Graphics::setScreenSize(int w, int h) {
	width = w;
	height = h;
	al_resize_display(display, width, height);
}

#endif
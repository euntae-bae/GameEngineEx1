#ifndef __INPUT_H__
#define __INPUT_H__

#include <allegro5/allegro.h>
#include "Math.h"
const int KEY_ARRAY_LENGTH = 256;

// 쟁점
// Input을 싱글톤으로 처리할 것인가?
// isKeyDown을 static으로 처리해야 할까?
// 버전 0.06: 아직까지는 static은 고려하지 않고 설계할 것.

// Mouse Button
// 1: primary(left)
// 2: secondary(right)
// 4: tertiary(middle)
// mouseState.buttons

class Input
{
private:
	bool keyDown[KEY_ARRAY_LENGTH];
	// mouse state <- mouse axis, mouse button down
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_MOUSE_STATE mouseState;
public:
	Input();
	~Input();
	void init();
	
	int getMouseX() const;
	int getMouseY() const;
	Vector2 getMousePosition() const;

	void getKeyState();
	void getMouseState();
	void getInputState();
	bool isKeyDown(int keycode) const;
	bool isKeyTriggered(int keycode);
	bool isMouseButtonDown(int button) const;
	bool isMouseLButtonDown() const;
	bool isMouseRButtonDown() const;
	bool isMouseMButtonDown() const;

	void setMousePosition(ALLEGRO_DISPLAY *display, const Vector2& pos);
	void setMousePosition(ALLEGRO_DISPLAY *display, int dx, int dy);
	void setMouseX(ALLEGRO_DISPLAY *display, int dx);
	void setMouseY(ALLEGRO_DISPLAY *display, int dy);
};

inline int Input::getMouseX() const {
	//int retX;
	//al_get_mouse_cursor_position(&retX, NULL);
	//return retX;
	return mouseState.x;
}

inline int Input::getMouseY() const {
	//int retY;
	//al_get_mouse_cursor_position(NULL, &retY);
	//return retY;
	return mouseState.y;
}

inline Vector2 Input::getMousePosition() const {
	//int retX, retY;
	//al_get_mouse_cursor_position(&retX, &retY);
	//return Vector2(retX, retY);
	return Vector2(mouseState.x, mouseState.y);
}

inline void Input::getKeyState() {
	al_get_keyboard_state(&keyState);
}

inline void Input::getMouseState() {
	al_get_mouse_state(&mouseState);
}

inline void Input::getInputState() {
	al_get_keyboard_state(&keyState);
	al_get_mouse_state(&mouseState);
}

inline bool Input::isKeyDown(int keycode) const {
	return al_key_down(&keyState, keycode);
}

// 이전에 키가 눌리지 않았을 때 키가 눌리면 true 반환
inline bool Input::isKeyTriggered(int keycode) {
	//bool prevDown = isKeyDown(keycode);
	//bool curDown = false;
	//getKeyState();
	//curDown = isKeyDown(keycode);
	//if (!prevDown && curDown)
	//	return true;
	return false;
}

inline bool Input::isMouseButtonDown(int button) const {
	return al_mouse_button_down(&mouseState, button);
}

inline bool Input::isMouseLButtonDown() const {
	return (mouseState.buttons & 1);
}

inline bool Input::isMouseRButtonDown() const {
	return (mouseState.buttons & 2);
}

inline bool Input::isMouseMButtonDown() const {
	return (mouseState.buttons & 4);
}

inline void Input::setMousePosition(ALLEGRO_DISPLAY *display, const Vector2& pos) {
	al_set_mouse_xy(display, pos.getX(), pos.getY());
}

inline void Input::setMousePosition(ALLEGRO_DISPLAY *display, int dx, int dy) {
	al_set_mouse_xy(display, dx, dy);
}

inline void Input::setMouseX(ALLEGRO_DISPLAY *display, int dx) {
	al_set_mouse_xy(display, dx, getMouseY());
}

inline void Input::setMouseY(ALLEGRO_DISPLAY *display, int dy) {
	al_set_mouse_xy(display, getMouseX(), dy);
}

#endif
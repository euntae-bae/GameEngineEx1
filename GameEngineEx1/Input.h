#ifndef __INPUT_H__
#define __INPUT_H__

#include <allegro5/allegro.h>
const int KEY_ARRAY_LENGTH = 256;

class Input
{
private:
	bool keyDown[KEY_ARRAY_LENGTH];
	// mouse axis
	// mouse button down
	// Keyboard State, Mouse State
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_MOUSE_STATE mouseState;
public:
	Input();
	~Input();
	void init();
	bool isKeyDown(int keycode) {
		al_get_keyboard_state(&keyState);
		return al_key_down(&keyState, keycode);
	}
	// bool isKeyTriggered(int keycode);
	
};

#endif
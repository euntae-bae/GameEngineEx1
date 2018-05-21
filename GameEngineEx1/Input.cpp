#include "Input.h"
#include <cstdio>

Input::Input()
{
#ifdef _DEBUG
	puts("Input::Input()");
#endif
	init();
}

Input::~Input()
{
#ifdef _DEBUG
	puts("~Input()");
#endif
	al_uninstall_keyboard();
	al_uninstall_mouse();
}

void Input::init()
{
#ifdef _DEBUG
	puts("Input::init()");
#endif
	al_install_keyboard();
	al_install_mouse();

	getInputState();
}
#include "Game.h"
#include <cstdio>

// TODO: Exception Handling

Game::Game(const char *title)
	: gameLoop(true)
{
#ifdef _DEBUG
	puts("Game(const char*)");
#endif

	gameTitle = new char[strlen(title) + 1];
	strcpy(gameTitle, title);

	if (!init()) {
		fprintf(stderr, "failed to initialize Game\n");
		// throw exception(...);
	}
}

Game::~Game()
{
	puts("~Game()");
	if (gameTitle) {
		delete[] gameTitle;
	}
	if(eventQueue)
		al_destroy_event_queue(eventQueue);
	delete graphics;
}

bool Game::init()
{
	bool result = true;

	puts("Game::init(const char*)");
	if (!al_init()) {
		fprintf(stderr, "failed to init allegro.\n");
		return false;
	}

	al_install_keyboard();
	al_install_mouse();

	eventQueue = al_create_event_queue();

	graphics = new Graphics();

	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_register_event_source(eventQueue, al_get_mouse_event_source());
	//	al_register_event_source(eventQueue, al_get_timer_event_source(timer));
	// 타이머는 
	al_register_event_source(eventQueue, al_get_display_event_source(graphics->getDisplay()));
	
	al_set_window_title(graphics->getDisplay(), gameTitle);

	return result;
}
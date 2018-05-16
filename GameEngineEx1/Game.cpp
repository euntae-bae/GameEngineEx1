#include "Game.h"
#include <cstdio>

// TODO: Exception Handling

Game::Game(const char *title)
	: gameLoop(true)
{
	puts("Game(const char*)");
	if (!init(title)) {
		fprintf(stderr, "failed to initialize Game\n");
		// throw exception(...);
	}
}

Game::~Game()
{
	puts("~Game()");
	if(eventQueue)
		al_destroy_event_queue(eventQueue);
	delete graphics;
}

bool Game::init(const char *title)
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
	al_register_event_source(eventQueue, al_get_display_event_source(graphics->getDisplay()));
	
	strcpy(gameTitle, title);
	al_set_window_title(graphics->getDisplay(), gameTitle);

	return result;
}
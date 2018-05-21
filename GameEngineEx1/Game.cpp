#include "Game.h"
#include <cstdio>

// TODO: Exception Handling

Game::Game(const char *title)
	: fps(60.0f), gameLoop(true)
{
#ifdef _DEBUG
	puts("Game(const char*)");
#endif

	gameTitle = new char[strlen(title) + 1];
	strcpy(gameTitle, title);

	if (!init()) {
		fprintf(stderr, "Error: Game::init()\n");
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
	if (mainTimer)
		al_destroy_timer(mainTimer);
	delete graphics;
	delete input;
}

bool Game::init()
{
#ifdef _DEBUG
	puts("Game::init()");
#endif
	if (!al_init()) {
		fprintf(stderr, "Error: al_init()\n");
		return false;
	}

	eventQueue = al_create_event_queue();
	if (!eventQueue) {
		fputs("Error: al_create_event_queue()\n", stderr);
		return false;
	}

	mainTimer = al_create_timer(1.0f / fps);
	if (!mainTimer) {
		fputs("Error: al_create_timer()\n", stderr);
		return false;
	}
	graphics = new Graphics();
	input = new Input();

	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_register_event_source(eventQueue, al_get_mouse_event_source());
	al_register_event_source(eventQueue, al_get_timer_event_source(mainTimer));
	al_register_event_source(eventQueue, al_get_display_event_source(graphics->getDisplay()));
	
	al_set_window_title(graphics->getDisplay(), gameTitle);
	al_start_timer(mainTimer);
	return true;
}

void Game::getInput()
{
	input->getKeyState();
	input->getMouseState();
}

//void Game::update();
//
//void Game::draw();

void Game::loop()
{
	while (gameLoop) {
		getInput();
		update();
		draw();
	}
}
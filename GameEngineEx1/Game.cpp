#include "Game.h"
#include <cstdio>

// TODO: Exception Handling

Game::Game(const char *title)
	: fps(60.0f), gameLoop(true), gameTitle(title), eventQueue(NULL), mainTimer(NULL), graphics(NULL), input(NULL)
{
#ifdef _DEBUG
	puts("Game(const char*)");
#endif

	if (!init()) {
		fprintf(stderr, "Error: Game::init()\n");
		// throw exception(...);
	}
}

Game::~Game()
{
#ifdef _DEBUG
	puts("~Game()");
#endif
	//quit();
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

	states.clear();
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
	
	setTitle(gameTitle.c_str());
	al_start_timer(mainTimer);
	return true;
}

void Game::getInput()
{
	input->getKeyState();
	input->getMouseState();
}

void Game::loop()
{
	while (gameLoop) {
		handleEvents();
		getInput();
		update();
		draw();
	}
	quit();
}

void Game::handleEvents()
{
	al_wait_for_event(eventQueue, &ev);
	if (!states.empty()) {
		states.back()->handleEvents(this);
	}
}

void Game::changeState(State *state)
{
	/*
	if (!states.empty()) {
		states.back()->cleanup();
		states.pop_back();
	}
	states.push_back(state);
	states.back()->init();
	*/
	state->init();
	if (!states.empty()) {
		states.back()->onExit();
		states.back()->cleanup();
		states.pop_back();
	}
	states.push_back(state);
	states.back()->onEnter();
}

void Game::pushState(State *state)
{
	state->init();
	if (!states.empty()) {
		states.back()->pause();
		states.back()->onExit();
	}
	states.push_back(state);
	states.back()->onEnter();
}

void Game::popState()
{
	if (!states.empty()) {
		states.back()->onExit();
		states.back()->cleanup();
		states.pop_back();
	}
	if (!states.empty()) {
		states.back()->onEnter();
		states.back()->resume();
	}
}

void Game::cleanupStates()
{
#ifdef _DEBUG
	puts("Game::cleanup()");
#endif
	if (!states.empty()) {
		states.back()->onExit();
		states.back()->cleanup();
		states.pop_back();
	}

	while (!states.empty()) {
		states.back()->cleanup();
		states.pop_back();
	}
}

void Game::cleanup()
{
	gameLoop = false;
	cleanupStates();
	if (mainTimer)
		al_destroy_timer(mainTimer);
	if (eventQueue)
		al_destroy_event_queue(eventQueue);
	delete graphics;
	delete input;
}

void Game::close() {
	puts("Game::close()");
	puts("게임 프로그램 종료를 요청합니다.");
	gameLoop = false;
}

void Game::quit()
{
#ifdef _DEBUG
	puts("Game::quit()");
#endif
	cleanup();
	exit(0);
}
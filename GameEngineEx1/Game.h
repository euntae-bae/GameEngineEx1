#ifndef __GAME_H__
#define __GAME_H__
#include <string>
#include <vector>
#include "Graphics.h"
#include "Input.h"
#include "State.h"
using std::string;
using std::vector;

const int MAX_TITLE_LENGTH = 256;

// game state -> pause(); resume(); ... etc
// save, load

// 게임은 상태(State)의 집합으로 구성된다.
// 게임 클래스는 상태를 제어하는 함수를 포함한다.

// close()와 quit()를 구분할 것!
// close()는 사용자에 의해 종료 요청이 들어왔을 때를 처리하는 함수다.
// 즉, close()를 호출하면 즉시 종료를 위한 처리를 수행하는 것이 아니라
// 종료 여부를 묻거나 현재 상태를 저장하는 등 종료가 확정되지 않은 상태에서의
// 여러 작업들을 처리하고자 정의한 함수다.
// 기본적으로는 메인 루프를 false로 설정한다.
// 추가적으로 필요하거나 수정해야 하는 작업이 있는 경우에는 이 함수를 오버라이딩 해야 한다.

// quit()는 종료 여부가 확정된 경우 게임 프로그램 자체의 종료를 위해 정의된 함수다.
// 주로 동적 할당된 메모리를 해제하는 작업들을 수행한다.
// 기본적으로 cleanup() 함수를 호출한다.
// 추가적으로 필요하거나 수정해야 하는 작업이 있는 경우에는 이 함수를 오버라이딩 해야 한다.
class Game
{
protected:
	string gameTitle;
	float fps;
	bool gameLoop;

	ALLEGRO_EVENT_QUEUE *eventQueue;
	ALLEGRO_TIMER *mainTimer;
	ALLEGRO_EVENT ev;

	Graphics *graphics;
	Input *input;
	//Audio *audio;

	vector<State*> states;

public:
	Game(const char *title);
	virtual ~Game();

	bool isRunning() const;
	const ALLEGRO_EVENT& getEvent() const;
	const char * getTitle() const;
	void setTitle(const char *ntitle);

	void changeState(State *state); // 현재 상태(State)를 지정한 상태로 전환한다. 기존의 상태는 메모리에서 해제된다.
	void pushState(State *state); // 현재 상태를 지정한 상태로 전환한다. 기존의 상태는 메모리에 그대로 유지된다.
	void popState(); // 현재 상태를 메모리에서 해제한다.
	void cleanupStates(); // 모든 상태들을 메모리에서 해제한다.

	virtual bool init(); // 게임 초기화 총괄(graphics.init(), game.init()....)
	virtual void getInput();
	virtual void handleEvents(); // 현재 상태에서의 이벤트를 처리한다.
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void loop();
	virtual void cleanup(); // 게임 객체 내부에서 동적할당된 메모리를 해제한다. 이 함수는 기본적으로 cleanupStates()를 호출한다.
	virtual void close(); // 사용자에 의해 게임 종료 요청이 들어왔을 때 처리하는 함수. 기본적으로 게임의 메인 루프를 중단시킨다.
	virtual void quit(); // 게임 프로그램을 즉시 종료하는 것이 아니라 현재 상태를 저장하거나 동적 할당된 메모리들을 해제하는 등 안전한 종료를 위한 처리들을 한다.
};

inline bool Game::isRunning() const {
	return gameLoop;
}

inline const ALLEGRO_EVENT& Game::getEvent() const {
	return ev;
}

inline const char * Game::getTitle() const {
	return gameTitle.c_str();
}

inline void Game::setTitle(const char *ntitle) {
	gameTitle = ntitle;
	al_set_window_title(graphics->getDisplay(), gameTitle.c_str());
}

#endif
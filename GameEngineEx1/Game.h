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

// ������ ����(State)�� �������� �����ȴ�.
// ���� Ŭ������ ���¸� �����ϴ� �Լ��� �����Ѵ�.

// close()�� quit()�� ������ ��!
// close()�� ����ڿ� ���� ���� ��û�� ������ ���� ó���ϴ� �Լ���.
// ��, close()�� ȣ���ϸ� ��� ���Ḧ ���� ó���� �����ϴ� ���� �ƴ϶�
// ���� ���θ� ���ų� ���� ���¸� �����ϴ� �� ���ᰡ Ȯ������ ���� ���¿�����
// ���� �۾����� ó���ϰ��� ������ �Լ���.
// �⺻�����δ� ���� ������ false�� �����Ѵ�.
// �߰������� �ʿ��ϰų� �����ؾ� �ϴ� �۾��� �ִ� ��쿡�� �� �Լ��� �������̵� �ؾ� �Ѵ�.

// quit()�� ���� ���ΰ� Ȯ���� ��� ���� ���α׷� ��ü�� ���Ḧ ���� ���ǵ� �Լ���.
// �ַ� ���� �Ҵ�� �޸𸮸� �����ϴ� �۾����� �����Ѵ�.
// �⺻������ cleanup() �Լ��� ȣ���Ѵ�.
// �߰������� �ʿ��ϰų� �����ؾ� �ϴ� �۾��� �ִ� ��쿡�� �� �Լ��� �������̵� �ؾ� �Ѵ�.
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

	void changeState(State *state); // ���� ����(State)�� ������ ���·� ��ȯ�Ѵ�. ������ ���´� �޸𸮿��� �����ȴ�.
	void pushState(State *state); // ���� ���¸� ������ ���·� ��ȯ�Ѵ�. ������ ���´� �޸𸮿� �״�� �����ȴ�.
	void popState(); // ���� ���¸� �޸𸮿��� �����Ѵ�.
	void cleanupStates(); // ��� ���µ��� �޸𸮿��� �����Ѵ�.

	virtual bool init(); // ���� �ʱ�ȭ �Ѱ�(graphics.init(), game.init()....)
	virtual void getInput();
	virtual void handleEvents(); // ���� ���¿����� �̺�Ʈ�� ó���Ѵ�.
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void loop();
	virtual void cleanup(); // ���� ��ü ���ο��� �����Ҵ�� �޸𸮸� �����Ѵ�. �� �Լ��� �⺻������ cleanupStates()�� ȣ���Ѵ�.
	virtual void close(); // ����ڿ� ���� ���� ���� ��û�� ������ �� ó���ϴ� �Լ�. �⺻������ ������ ���� ������ �ߴܽ�Ų��.
	virtual void quit(); // ���� ���α׷��� ��� �����ϴ� ���� �ƴ϶� ���� ���¸� �����ϰų� ���� �Ҵ�� �޸𸮵��� �����ϴ� �� ������ ���Ḧ ���� ó������ �Ѵ�.
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
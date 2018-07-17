#ifndef __STATE_H__
#define __STATE_H__

class Game;
class Graphics;

class State
{
public:
	//State();
	//virtual ~State();

	virtual bool init() = 0;
	virtual void cleanup() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void onEnter() = 0;
	virtual void onExit() = 0;

	virtual void handleEvents(Game *game) = 0;
	virtual void update() = 0;
	virtual void draw(Graphics *g) = 0;
};

#endif
#include <cstdio>
#include <cassert>
#include "Sprite.h"
#include "Input.h"

const unsigned int FPS = 60;
const double TIME_INTERVAL = 1.0 / FPS;
const double TIME_INTERVAL_MS = 1000 / FPS;

bool loop = true;
long long count = 0;

Sprite *spr1 = NULL;
Graphics *g = NULL;
Input *input = NULL;

void update()
{
	if (input->isKeyDown(ALLEGRO_KEY_ESCAPE))
		loop = false;
	static bool fullScr = g->isFullScreen();

	Vector2 pos = spr1->getPosition();

	const float SPEED = 5.0f;

	static Vector2 v;
	float vx = 0.0f, vy = 0.0f;

	if (input->isKeyDown(ALLEGRO_KEY_LEFT)) {
		vx -= SPEED;
	}
	if (input->isKeyDown(ALLEGRO_KEY_RIGHT)) {
		vx += SPEED;
	}
	if (input->isKeyDown(ALLEGRO_KEY_UP)) {
		vy -= SPEED;
	}
	if (input->isKeyDown(ALLEGRO_KEY_DOWN)) {
		vy += SPEED;
	}
	if (input->isKeyDown(ALLEGRO_KEY_SPACE)) {
		fullScr = !fullScr;
		g->setFullScreen(fullScr);
	}

	v.setXY(vx, vy);
	pos += v;
	spr1->setPosition(pos);
}

void render()
{
	g->clear();
	spr1->draw(g);
	g->flip();
}

int main(int argc, char *argv[])
{
	ALLEGRO_EVENT_QUEUE *eventQueue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_FONT *font = NULL;

#ifdef _DEBUG
	assert(al_init());
#else
	if (!al_init()) {
		fprintf(stderr, "error: al_init()\n");
		return -1;
	}
#endif

	g = new Graphics(640, 480);
	input = new Input();

	// 이벤트 큐를 Game 클래스의 멤버로 포함시킬 것!
	eventQueue = al_create_event_queue();
	// Game 클래스의 멤버에는 전체적인 게임 루프 제어를 위해 main timer를 둔다.
	timer = al_create_timer(TIME_INTERVAL);
	font = al_load_font("fonts/consola.ttf", 18, 0);

#ifdef _DEBUG
	assert(eventQueue);
	assert(timer);
	assert(font);
#else
	if (!eventQueue) {
		fprintf(stderr, "failed to create event queue.\n");
	}
	if (!timer) {
		fprintf(stderr, "failed to create timer.\n");
	}
	if (!font) {
		fprintf(stderr, "failed to load font.\n");
	}
#endif

	spr1 = new Sprite("sprites/spr01.png");

	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_register_event_source(eventQueue, al_get_mouse_event_source());
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));
	al_register_event_source(eventQueue, al_get_display_event_source(g->getDisplay()));

	al_start_timer(timer);

	ALLEGRO_EVENT ev;
	bool redraw = false;

	while (loop) {
		if (!al_is_event_queue_empty(eventQueue)) {
			al_wait_for_event(eventQueue, &ev);
			input->getInputState();

			if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
				loop = false;
			else if (ev.type == ALLEGRO_EVENT_TIMER) {
				update();
				render();
				count++;
			}
		}
	}

	al_destroy_font(font);
	al_destroy_timer(timer);
	al_destroy_event_queue(eventQueue);
	return 0;
}
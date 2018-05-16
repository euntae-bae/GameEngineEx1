#include <cstdlib>
#include "Graphics.h"
#include "Sprite.h"

int main(void)
{
	const double FPS = 60.0;
	bool loop = true;
	long long count = 0;
	Graphics *g = NULL;

	ALLEGRO_EVENT_QUEUE *queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_FONT *font = NULL;

	if (!al_init()) {
		return -1;
	}

	al_install_keyboard();
	al_install_mouse();

	g = new Graphics();
	
	queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);
	font = al_load_font("fonts/consola.ttf", 18, 0);

	if (!font) {
		fprintf(stderr, "failed load font\n");
		return -1;
	}

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_display_event_source(g->getDisplay()));

	al_start_timer(timer);

	ALLEGRO_EVENT ev;
	bool redraw = false;

	Sprite *spr1 = new Sprite("sprites/spr01.png");
	spr1->setPosition(100, 100);
	spr1->setScale(2, 2);
	spr1->printInfo();

	while (loop)
	{
		al_wait_for_event(queue, &ev);
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			loop = false;
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				loop = false;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
		}

		if (redraw && al_is_event_queue_empty(queue)) {
			redraw = false;
			g->clear();
			spr1->draw(g);
			al_draw_text(font, COLOR_WHITE, 20, 20, 0, "HELLO WORLD");
			g->flip();
		}
	}

	delete spr1;
	al_destroy_font(font);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
	delete g;
	return 0;
}
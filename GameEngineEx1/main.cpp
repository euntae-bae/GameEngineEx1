#include <cstdlib>
#include "Graphics.h"

int main(void)
{
	const double FPS = 60.0;
	bool loop = true;
	Graphics *g = NULL;

	ALLEGRO_EVENT_QUEUE *queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	if (!al_init()) {
		return -1;
	}

	al_install_keyboard();
	al_install_mouse();

	g = new Graphics();
	
	queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_display_event_source(g->getDisplay()));

	ALLEGRO_EVENT ev;
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
		g->clear();
		g->flip();
	}

	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
	delete g;
	return 0;
}
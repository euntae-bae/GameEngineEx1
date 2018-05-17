#include <cstdlib>
#include "Graphics.h"
#include "Sprite.h"
// #include "MyGame.h"

// 논점:
// Game 화면이나 스테이지, 상태의 단위를 정의해야 하는가? (Cocos2d-x를 생각해보자)
// Ex) class Scene;
// class Stage1 : public Scene;

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
	float currentAlpha = spr1->getAlphaf();

	puts("spr1:");
	spr1->printInfo();

	Sprite *spr2 = new Sprite("sprites/spr03.png");
	puts("spr2: 거대 냥냥이");
	spr2->printInfo();

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
			case ALLEGRO_KEY_UP:
				currentAlpha += 0.1f;
				if (currentAlpha > 1.0f) {
					currentAlpha = 1.0f;
				}
				spr1->setAlphaf(currentAlpha);
				break;
			case ALLEGRO_KEY_DOWN:
				currentAlpha -= 0.1f;
				if (currentAlpha < 0.0f) {
					currentAlpha = 0.0f;
				}
				spr1->setAlphaf(currentAlpha);
				break;
			case ALLEGRO_KEY_SPACE:
				spr1->toggleVisible();
				break;
			case ALLEGRO_KEY_H:
				spr1->toggleFlipHorizontal();
				printf("spr1->flipHorizontal: %d\n", spr1->isFlipHorizontal());
				break;
			case ALLEGRO_KEY_V:
				spr1->toggleFlipVertical();
				printf("spr1->flipVertical: %d\n", spr1->isFlipVertical());
				break;
			case ALLEGRO_KEY_B:
				spr1->setColor(COLOR_BLACK);
				break;
			}
			printf("spr1->alpha: %f\n", spr1->getAlphaf());
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
		}

		if (redraw && al_is_event_queue_empty(queue)) {
			redraw = false;
			g->clear();

			spr2->setScale(8, 8);
			spr2->setPosition(220, 140);
			spr2->draw(g);

			spr1->setPosition(100, 100);
			spr1->setScale(2, 2);
			spr1->setAngle(0.0f);
			spr1->draw(g);

			//spr1->setPosition(300.0f, 200.0f);
			//spr1->setScaleX(5.0f);
			//spr1->setScaleY(4.0f);
			//spr1->setAngle(5.0f);
			//spr1->draw(g);

			al_draw_textf(font, COLOR_WHITE, 10, 10, 0, "frame: %lld", count);
			al_draw_textf(font, COLOR_WHITE, 10, 30, 0, "FPS: %lf", FPS);
			//al_draw_text(font, COLOR_WHITE, 20, 20, 0, "HELLO PROGRAM");
			g->flip();
			count++;
		}
	}

	delete spr1;
	delete spr2;
	al_destroy_font(font);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
	delete g;
	return 0;
}
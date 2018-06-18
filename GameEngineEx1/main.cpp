#include <cstdlib>
#include "Sprite.h"
#include "Input.h"
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
	Input *input = NULL;

	ALLEGRO_EVENT_QUEUE *queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_FONT *font = NULL;

	if (!al_init()) {
		return -1;
	}

	al_install_keyboard();
	al_install_mouse();

	g = new Graphics(640, 480, false);
	input = new Input();
	
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
	float currentOpacity = spr1->getOpacityf();

	puts("spr1:");
	spr1->printInfo();

	Sprite *spr2 = new Sprite("sprites/spr03.png");
	puts("spr2: 거대 냥냥이");
	spr2->printInfo();

	float speed = 5.0f;
	static bool fullscr = g->isFullScreen();
	static bool resizable = g->isResizable();

	while (loop)
	{
		input->getInputState();
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
			case ALLEGRO_KEY_F2:
				fullscr = !fullscr;
				printf("fullscr: %d\n", fullscr);
				g->setFullScreen(fullscr);
				printf("g->isFullScreen(): %d\n", g->isFullScreen());
				break;
			//case ALLEGRO_KEY_UP:
			//	currentOpacity += 0.1f;
			//	if (currentOpacity > 1.0f) {
			//		currentOpacity = 1.0f;
			//	}
			//	spr1->setOpacityf(currentOpacity);
			//	break;
			//case ALLEGRO_KEY_DOWN:
			//	currentOpacity -= 0.1f;
			//	if (currentOpacity < 0.1f) {
			//		currentOpacity = 0.1f;
			//	}
			//	spr1->setOpacityf(currentOpacity);
			//	break;
			//case ALLEGRO_KEY_SPACE:
			//	spr1->toggleVisible();
			//	break;
			//case ALLEGRO_KEY_H:
			//	spr1->toggleFlipHorizontal();
			//	printf("spr1->flipHorizontal: %d\n", spr1->isFlipHorizontal());
			//	break;
			//case ALLEGRO_KEY_V:
			//	spr1->toggleFlipVertical();
			//	printf("spr1->flipVertical: %d\n", spr1->isFlipVertical());
			//	break;
			//case ALLEGRO_KEY_B:
			//	spr1->setColor(COLOR_GREEN);
			//	break;
			}
			//printf("spr1->opacity: %f\n", spr1->getOpacityf());
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;

			// update
			float curX = spr1->getX();
			float curY = spr1->getY();

			if (input->isKeyDown(ALLEGRO_KEY_UP)) {
				curY -= speed;
			}
			if (input->isKeyDown(ALLEGRO_KEY_DOWN)) {
				curY += speed;
			}
			if (input->isKeyDown(ALLEGRO_KEY_LEFT)) {
				curX -= speed;
			}
			if (input->isKeyDown(ALLEGRO_KEY_RIGHT)) {
				curX += speed;
			}
			//if (input->isKeyTriggered(ALLEGRO_KEY_SPACE)) {
				//puts("SPACE PRESSED");
			//}
			spr1->setPosition(curX, curY);
		}

		if (redraw && al_is_event_queue_empty(queue)) {
			redraw = false;
			g->clear();

			spr1->setScale(3.0f, 3.0f);
			spr1->draw(g);

			spr2->setScale(8, 8);
			spr2->setPosition(220, 140);
			spr2->draw(g);

			//spr1->setPosition(100, 100);
			//spr1->setScale(2, 2);
			//spr1->setAngle(0.0f);
			//spr1->draw(g);

			//spr1->setPosition(300.0f, 200.0f);
			//spr1->setScaleX(5.0f);
			//spr1->setScaleY(4.0f);
			//spr1->setAngle(5.0f);
			//spr1->draw(g);

			al_draw_textf(font, COLOR_WHITE, 10, 10, 0, "frame: %lld", count);
			al_draw_textf(font, COLOR_WHITE, 10, 30, 0, "FPS: %lf", FPS);
			g->flip();
			count++;
		}
	}

	delete spr1;
	delete spr2;
	al_destroy_font(font);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
	delete input;
	delete g;
	return 0;
}
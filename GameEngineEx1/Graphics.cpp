#include "Graphics.h"

bool Graphics::init(int w, int h)
{
	bool result = false;
	width = w;
	height = h;
	bgcolor = COLOR_BLUE;

	printf("width: %d\n", width);
	printf("height: %d\n", height);
	printf("bgcolor.r: %f\n", bgcolor.r);
	printf("bgcolor.g: %f\n", bgcolor.g);
	printf("bgcolor.b: %f\n", bgcolor.b);
	printf("bgcolor.a: %f\n", bgcolor.a);
	/*
	if(al_init() != NULL)
		result = true;
	*/

	display = al_create_display(width, height);
	if (display != NULL)
		result = true;
	puts("Graphics::init(int, int)");
	return result;
}

void Graphics::draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const ALLEGRO_COLOR& tint)
{
	al_draw_tinted_bitmap(bitmap, tint, pos.getX(), pos.getY(), 0);
}

void Graphics::draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Rect& rect, const ALLEGRO_COLOR& tint)
{
	al_draw_tinted_bitmap_region(bitmap, tint, rect.getX(), rect.getY(), rect.getWidth(), rect.getHeight(), pos.getX(), pos.getY(), 0);
}

void Graphics::draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Vector2& centerPos, const Vector2& scale, float angle, const ALLEGRO_COLOR& tint)
{
	al_draw_tinted_scaled_rotated_bitmap(bitmap, tint, centerPos.getX(), centerPos.getY(), pos.getX(), pos.getY(), scale.getX(), scale.getY(), angle, 0);
}

void Graphics::draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Vector2& centerPos, const Rect& rect, const Vector2& scale, float angle, const ALLEGRO_COLOR& tint)
{
	al_draw_tinted_scaled_rotated_bitmap_region(
		bitmap,
		rect.getX(),
		rect.getY(),
		rect.getWidth(),
		rect.getHeight(),
		tint,
		centerPos.getX(),
		centerPos.getY(),
		pos.getX(),
		pos.getY(),
		scale.getX(),
		scale.getY(),
		angle,
		0);
}
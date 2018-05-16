#include "Graphics.h"

Graphics::Graphics()
	: Graphics(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT)
{
	puts("Graphics::Graphics()");
}

Graphics::Graphics(int w, int h)
{
	puts("Graphics::Graphics(int, int)");

	if (!init(w, h))
		puts("failed init()");
}

Graphics::~Graphics()
{
	al_destroy_display(display);
	puts("Graphics::~Graphics()");
}

void Graphics::draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const ALLEGRO_COLOR& tint) const
{
	al_draw_tinted_bitmap(bitmap, tint, pos.getX(), pos.getY(), 0);
}

void Graphics::draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Rect& rect, const ALLEGRO_COLOR& tint) const
{
	al_draw_tinted_bitmap_region(bitmap, tint, rect.getX(), rect.getY(), rect.getWidth(), rect.getHeight(), pos.getX(), pos.getY(), 0);
}

void Graphics::draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Vector2& centerPos, const Vector2& scale, float angle, const ALLEGRO_COLOR& tint) const
{
	al_draw_tinted_scaled_rotated_bitmap(bitmap, tint, centerPos.getX(), centerPos.getY(), pos.getX(), pos.getY(), scale.getX(), scale.getY(), angle, 0);
}

void Graphics::draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Vector2& centerPos, const Rect& rect, const Vector2& scale, float angle, const ALLEGRO_COLOR& tint) const
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

bool Graphics::init(int w, int h)
{
	bool result = true;
	width = w;
	height = h;
	bgcolor = COLOR_BLUE;

#ifdef _DEBUG
	puts("Graphics::init(int, int)");
	printf("width: %d\n", width);
	printf("height: %d\n", height);
	printf("bgcolor.r: %f\n", bgcolor.r);
	printf("bgcolor.g: %f\n", bgcolor.g);
	printf("bgcolor.b: %f\n", bgcolor.b);
	printf("bgcolor.a: %f\n", bgcolor.a);
#endif

	display = al_create_display(width, height);
	if (!display)
		result = false;

	if (!al_init_font_addon())
		result = false;

	if (!al_init_ttf_addon())
		result = false;

	return result;
}
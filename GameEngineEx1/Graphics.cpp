#include "Graphics.h"

Graphics::Graphics()
	: Graphics(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT)
{
	puts("Graphics::Graphics()");
}

Graphics::Graphics(int w, int h)
	: width(w), height(h)
{
	puts("Graphics::Graphics(int, int)");

	if (!init())
		puts("failed init()");
}

Graphics::~Graphics()
{
	if (display) {
		al_destroy_display(display);
	}
	puts("Graphics::~Graphics()");
}

void Graphics::draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Color& tint) const
{
	al_draw_tinted_bitmap(bitmap, tint, pos.getX(), pos.getY(), 0);
}

void Graphics::draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Rect& rect, const Color& tint) const
{
	al_draw_tinted_bitmap_region(bitmap, tint, rect.getX(), rect.getY(), rect.getWidth(), rect.getHeight(), pos.getX(), pos.getY(), 0);
}

void Graphics::draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Vector2& centerPos, 
	const Vector2& scale, float angle, const Color& tint) const
{
	al_draw_tinted_scaled_rotated_bitmap(bitmap, tint, centerPos.getX(), centerPos.getY(), pos.getX(), pos.getY(), scale.getX(), scale.getY(), angle, 0);
}

void Graphics::draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Vector2& centerPos, 
	const Rect& rect, const Vector2& scale, float angle, const Color& tint) const
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

void Graphics::draw(ALLEGRO_BITMAP *bitmap, const Vector2& pos, const Vector2& centerPos, 
	const Rect& rect, const Vector2& scale, float angle, 
	bool flipH, bool flipV, const Color& tint) const
{
	int flags = 0;
	if (flipH)
		flags |= ALLEGRO_FLIP_HORIZONTAL;
	if (flipV)
		flags |= ALLEGRO_FLIP_VERTICAL;

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
		flags);
}

bool Graphics::init()
{
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
	if (!display) {
#ifdef _DEBUG
		fputs("failed to create display.\n", stderr);
#endif
		return false;
	}

	if (!al_init_font_addon()) {
#ifdef _DEBUG
		fputs("Error: al_init_font_addon()\n", stderr);
#endif
		return false;
	}

	if (!al_init_ttf_addon()) {
#ifdef _DEBUG
		fputs("Error: al_init_ttf_addon()\n", stderr);
#endif
		return false;
	}

	if (!al_init_image_addon()) {
#ifdef _DEBUG
		fputs("Error: al_init_image_addon()\n", stderr);
#endif
		return false;
	}

	return true;
}
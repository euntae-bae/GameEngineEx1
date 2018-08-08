#include "Sprite.h"
#include "Graphics.h"

Sprite::Sprite(const char *filename)
{
#ifdef _DEBUG
	puts("Sprite::Sprite(const char *filename)");
#endif
	sprData.filename = new char[strlen(filename) + 1];
	strcpy(sprData.filename, filename);
	if (!init()) {
		puts("Error: Sprite::init()");
	}
}

Sprite::Sprite(const char *filename, const Color& colorkey)
	: Sprite(filename)
{
#ifdef _DEBUG
	puts("Sprite::Sprite(const char *filename, const Color& colorkey)");
#endif
	sprData.colorkey = colorkey;
	al_convert_mask_to_alpha(sprData.bitmap, sprData.colorkey);
}

Sprite::~Sprite()
{
#ifdef _DEBUG
	puts("Sprite::~Sprite()");
#endif
	if (sprData.filename) {
		delete[] sprData.filename;
	}
	if (sprData.bitmap) {
		al_destroy_bitmap(sprData.bitmap);
	}
}

bool Sprite::init()
{
#ifdef _DEBUG
	puts("Sprite::init()");
#endif
	sprData.bitmap = al_load_bitmap(sprData.filename);
	if (!sprData.bitmap) {
#ifdef _DEBUG
		fprintf(stderr, "Error: Sprite::init(), failed to open file: %s\n", sprData.filename);
#endif
		return false;
	}

	sprData.width = al_get_bitmap_width(sprData.bitmap);
	sprData.height = al_get_bitmap_height(sprData.bitmap);
	sprData.rect.setXY(0, 0);
	sprData.rect.setWidth(sprData.width);
	sprData.rect.setHeight(sprData.height);

	flipHorizontal = false;
	flipVertical = false;

	return true;
}

void Sprite::setBitmap(ALLEGRO_BITMAP *bitmap)
{
	if (sprData.bitmap == bitmap || bitmap == NULL) {
		return;
	}
	if (sprData.bitmap) {
		al_destroy_bitmap(sprData.bitmap);
	}
	sprData.bitmap = bitmap;
}

void Sprite::setBitmap(const char *filename)
{
	ALLEGRO_BITMAP *nbitmap = al_load_bitmap(filename);
	if (!nbitmap) {
		return;
	}
	if (sprData.bitmap) {
		al_destroy_bitmap(sprData.bitmap);
	}
	sprData.bitmap = nbitmap;
}

void Sprite::draw(Graphics *g) const
{
	if (visible) {
		g->draw(sprData.bitmap, pos, centerPos, sprData.rect, scale, angle, flipHorizontal, flipVertical, color);
	}
}
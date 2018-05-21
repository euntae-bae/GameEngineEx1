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
	puts("Sprite::init()");
	bool result = true;

	sprData.bitmap = al_load_bitmap(sprData.filename);
	if (!sprData.bitmap) {
		result = false;
#ifdef _DEBUG
		fprintf(stderr, "Error: Sprite::init(), failed to open file: %s\n", sprData.filename);
#endif
		return result;
	}

	sprData.width = al_get_bitmap_width(sprData.bitmap);
	sprData.height = al_get_bitmap_height(sprData.bitmap);
	sprData.rect.setXY(0, 0);
	sprData.rect.setWidth(sprData.width);
	sprData.rect.setHeight(sprData.height);

	flipHorizontal = false;
	flipVertical = false;

	return result;
}

void Sprite::draw(Graphics *g) const
{
	if (visible) {
		g->draw(sprData.bitmap, pos, centerPos, sprData.rect, scale, angle, flipHorizontal, flipVertical, color);
	}
}
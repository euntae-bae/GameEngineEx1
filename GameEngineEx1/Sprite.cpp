#include "Sprite.h"

Sprite::Sprite()
{
#ifdef _DEBUG
	puts("Sprite::Sprite()");
#endif
}

Sprite::Sprite(const char *filename)
{
#ifdef _DEBUG
	puts("Sprite::Sprite(const char *filename)");
#endif
}

Sprite::~Sprite()
{
#ifdef _DEBUG
	puts("Sprite::~Sprite()");
#endif
}

bool Sprite::init()
{
	puts("Sprite::init()");
	bool result = true;
	return result;
}
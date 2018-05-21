#include <cstdio>
#include "Renderable.h"
#include "Graphics.h"

Renderable::Renderable()
	: scale(1.0f, 1.0f), angle(0.0f), color(COLOR_WHITE), opacity(1.0f), visible(true)
{
#ifdef _DEBUG
	puts("Renderable()");
#endif
}

/*
Renderable::~Renderable()
{
	// resource deallocation
}
*/
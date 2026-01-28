#include "Tortoise.h"
#include <cassert>
#include "Field.h"

Tortoise::Tortoise(int x, int y) {
	hImage = LoadGraph("data/image/mob.png");
	assert(hImage > 0);
	position = VECTOR3(x, y, 0);
}

Tortoise::~Tortoise()
{
}

void Tortoise::Update()
{
}

void Tortoise::Draw() {
	DrawRectGraph((int)position.x - Field::scroll, (int)position.y, 0, 64*6, 64, 64, hImage, TRUE);
}

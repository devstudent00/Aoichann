#include "Tortoise.h"
#include <cassert>
#include "Field.h"

Tortoise::Tortoise(int x, int y) : Character(x, y) {
	hImage = LoadGraph("data/image/mob.png");
	assert(hImage > 0);
	position = VECTOR3(x, y, 0);
}

Tortoise::~Tortoise()
{
	DeleteGraph(hImage);
	hImage = -1;
}

void Tortoise::Update() {

}

void Tortoise::Draw() {
	DrawRectGraph((int)position.x - Field::scroll, (int)position.y, 0, 64*6, 64, 64, hImage, TRUE);
}

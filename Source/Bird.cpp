#include "Bird.h"
#include <DxLib.h>
#include <cassert>
#include "Field.h"

Bird::Bird(int x, int y) {
	hImage = LoadGraph("data/image/mob.png");
	assert(hImage > 0);
	position = VECTOR3(x, y, 0);
}

Bird::~Bird() {
}

void Bird::Update() {
}

void Bird::Draw() {
	DrawRectGraph((int)position.x - Field::scroll, (int)position.y, 0, 64 * 0, 64, 64, hImage, TRUE);
}

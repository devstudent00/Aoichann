#include "Bird.h"
#include <DxLib.h>
#include <cassert>

Bird::Bird(int x, int y) {
	hImage = LoadGraph("data/image/bird.png");
	//hImage = LoadGraph("data/image/mob.png");
	assert(hImage > 0);
	position = VECTOR3(x, y, 0);
}

Bird::~Bird() {
}

void Bird::Update() {
}

void Bird::Draw() {
	DrawGraph((int)position.x, (int)position.y, hImage, TRUE);
}

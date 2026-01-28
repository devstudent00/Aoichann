#include "Bird.h"
#include <DxLib.h>
#include <cassert>
#include "Field.h"
#include "Character.h"

Bird::Bird(int x, int y) : Character(x, y) {
	hImage = LoadGraph("data/image/mob.png");
	assert(hImage > 0);

	patX = 0;
	patY = 0;
}

Bird::~Bird() {
	DeleteGraph(hImage);
	hImage = -1; 
}

void Bird::Update() {
}

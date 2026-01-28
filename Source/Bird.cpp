#include "Bird.h"
#include <DxLib.h>
#include <cassert>
#include "Field.h"
#include "Character.h"
#include "Screen.h"
#include "Player.h"

Bird::Bird(int x, int y) : Character(x, y) {
	hImage = LoadGraph("data/image/mob.png");
	assert(hImage > 0);

	patX = 0;
	patY = 0;

	sqhere.center = VECTOR3(32, 32 , 0);
	sqhere.radius = 30.0f;
}

Bird::~Bird() {
	DeleteGraph(hImage);
	hImage = -1; 
}

void Bird::Update() {
	int screenX = position.x - Field::scroll;
	if (screenX < Screen::WIDTH) {
		position.x -= 2.0f;
	}
	if (position.x < -64) {

	}

	Character* player = FindGameObject<Player>();
	if (player != nullptr) {
		VECTOR3 playerCenter = player->GetCenter();
		VECTOR3 myCenter = GetCenter();
		if (VSize(playerCenter - myCenter) < GetRadius() + player->GetRadius()) {
			OnCollision(player);
			player->OnCollision(this);
		}
	}
	patCounter++;
	patX = (patCounter / 4) % 4;
}

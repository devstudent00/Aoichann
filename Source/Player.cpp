#include "Player.h"
#include <cassert>
#include "Field.h"

Player::Player() {
	
}

Player::Player(int x, int y) {
	hImage = LoadGraph("data/image/aoi.png");
	position = VECTOR3(x, y, 0);
	velocity = VECTOR3(2, 0, 0);
}

Player::~Player()
{
}

void Player::Update() {
	Field* field = FindGameObject<Field>();

	if (Input::IsKeyPress(KEY_INPUT_D)) {
		position.x += velocity.x;
		int distance = field->HitWallRight(position.x + 44, position.y + 5);
		int distance2 = field->HitWallRight(position.x + 44, position.y + 63);
		position.x -= max(distance, distance2);
	}
	if (Input::IsKeyPress(KEY_INPUT_A)) {
		position.x -= velocity.x;
		int distance = field->HitWallLeft(position.x + 16, position.y + 5);
		int distance2 = field->HitWallLeft(position.x + 16, position.y + 63);
		position.x += max(distance, distance2);
	}

	const float G = 3.0f; // 重力
	if (Input::IsKeyOnTrig(KEY_INPUT_SPACE)) {
		velocity.y = -10.0f;
	}

	position.y += velocity.y;
	velocity.y += G / 60.0f; // 1フレームの重力加速度
	int downDistance = field->HitWallDown(position.x + 16, position.y + 63);
	int downDistance2 = field->HitWallDown(position.x + 44, position.y + 63);
	int distance = max(downDistance, downDistance2);
	if (distance > 0) {
		position.y -= distance;
		velocity.y = 0.0f;
	}
	


}

void Player::Draw() {
	DrawRectGraph((int)position.x, (int)position.y, 64 * 0, 64 * 0, 64, 64, hImage, true);
	DrawBox(position.x+16, position.y+5, position.x+44, position.y+64, 0xffffff, false);
}

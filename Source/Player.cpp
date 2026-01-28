#include "Player.h"
#include <assert.h>
#include "Field.h"
#include "../ImGui/imgui.h"
#include "Character.h"

Player::Player()
{
}

Player::Player(int x, int y) : Character(x, y){
	hImage = LoadGraph("data/image/aoi.png");
	assert(hImage > 0);
	position = VECTOR3(x, y, 0);
	velocityY = 0.0f;
	patX = 1;
	patY = 0;

	sqhere.center = VECTOR3(32, 32, 0);
	sqhere.radius = 30.0f;
}

Player::~Player()
{
}

void Player::Update()
{
	Field* f = FindGameObject<Field>();
	bool walking = false;
	if (CheckHitKey(KEY_INPUT_D)) { // 右に進む
		position.x += 2.0f;
		int d1 = f->HitWallRight(position.x + 44, position.y + 5);
		int d2 = f->HitWallRight(position.x + 44, position.y + 63);
		position.x -= max(d1,d2);
		walking = true;
		//patCounter++;
		//patX = (patCounter / 4) % 4;
	} else
	if (CheckHitKey(KEY_INPUT_A)) {
		position.x -= 2.0f;
		int d1 = f->HitWallLeft(position.x + 16, position.y + 5);
		int d2 = f->HitWallLeft(position.x + 16, position.y + 63);
		position.x += max(d1, d2);
		walking = true;
		//patCounter++;
		//patX = (patCounter / 4) % 4;
	}
	else {
		patX = 0;
		patCounter = 3;
	}
	const float G = 3.0f/60.0f; // 重力
	const float H = 64.0f * 3.0f;
	if (onGround) {
		if (Input::IsKeyOnTrig(KEY_INPUT_SPACE)) {
			velocityY = -sqrtf(2 * G * H);
		}
	}
	position.y += velocityY;
	velocityY += G; // 1フレームの重力

	
	int d2 = f->HitWallDown(position.x + 44, position.y + 64); // 足の１ドット下
	int d1 = f->HitWallDown(position.x + 16, position.y + 64);
	int d = max(d1, d2);
	if (d > 0) {
		position.y -= (d-1);
		velocityY = 0;
		onGround = true;
	}
	else {
		onGround = false;
	}
	ImGui::Begin("PLAYER");
	ImGui::Checkbox("onGround", &onGround);
	ImGui::InputFloat("POSY", &position.y);
	ImGui::End();

	if (position.x - Field::scroll > 400) {
		Field::scroll = position.x - 400;
	}
	else if (position.x - Field::scroll < 300) {
		Field::scroll = position.x - 300;
		if (Field::scroll < 0) {
			Field::scroll = 0;
		}
	}

	if (onGround) {
		patY = 0;
		if (walking) {
			patCounter++;
			patX = (patCounter / 4) % 4;
		}
		else {
			patX = 0;
			patCounter = 3;
		}
	}
	else {
		patY = 2;
		if (velocityY > 0) {
			patX = 2;
		}
		else {
			patX = 1;
		}
	}
}

void Player::OnCollision(Character* other) {
	DestroyMe();
}

//DrawBox(position.x + 16 - Field::scroll, position.y + 5, position.x + 44 - Field::scroll, position.y + 64, 0xffffff, FALSE);

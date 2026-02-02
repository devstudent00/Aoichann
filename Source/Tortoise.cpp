#include "Tortoise.h"
#include <cassert>
#include "Field.h"
#include "Screen.h"
#include "../ImGui/imgui.h"

Tortoise::Tortoise(int x, int y) : Character(x, y) {
	hImage = LoadGraph("data/image/mob.png");
	assert(hImage > 0);
	position = VECTOR3(x, y, 0);
	velocity = VECTOR3(-1.0f, 0, 0);
}

Tortoise::~Tortoise()
{
	DeleteGraph(hImage);
	hImage = -1;
}

void Tortoise::Update() {
	int screenX = position.x - Field::scroll;
	Field* field = FindGameObject<Field>();

	if (velocity.x <= -1.0f) {
		position.x += velocity.x;
		int leftUp = field->HitWallLeft(position.x, position.y);
		int leftDown = field->HitWallLeft(position.x, position.y + 63);
		int maxLeft = max(leftUp, leftDown);
		position.x += maxLeft;
		if (maxLeft > 0) {
			velocity.x = -velocity.x;
		}
	}
	else if (velocity.x >= 1.0f) {
		position.x += velocity.x;
		int rightUp = field->HitWallRight(position.x + 63, position.y);
		int rightDown = field->HitWallRight(position.x + 63, position.y + 63);
		int maxRight = max(rightUp, rightDown);
		position.x -= maxRight;
		if (maxRight > 0) {
			velocity.x = -velocity.x;
		}
	}
}

void Tortoise::Draw() {
	DrawRectGraph(
		position.x - Field::scroll,
		position.y, 
		0, 64*6, 
		64, 64, 
		hImage, TRUE
	);
	DrawBox(
		position.x - Field::scroll,
		position.y,
		position.x + 63 - Field::scroll,
		position.y + 63 ,
		0xffffff, FALSE
	);
}

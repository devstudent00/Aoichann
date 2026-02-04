#include "Clear.h"
#include <DxLib.h>
#include "Lerp.h"

Clear::Clear() {
	hImage = LoadGraph("data/image/font.png");
	position = VECTOR3(200, 300, 0);

	isDead = false;
	startX = 950;
	endX = 20;
	maxTime = 15.0f;
	time = 0.0f;
}

Clear::~Clear() {
}

void Clear::Update() {
	time += Time::DeltaTime();
	float rate = time / maxTime;
	position.x = Lerp<float>(startX, endX, rate, easeInOutSine);
	if (time >= maxTime) {
		DestroyMe();
	}
}

void Clear::Draw() {
	DrawRectGraph(
		position.x, position.y, 
		0, 64,
		256, 64, 
		hImage, TRUE
	);
}

#include "Start.h"
#include "Screen.h"
#include "Lerp.h"
#define LINEAR(startX, endX, maxTime, time) ((endX - startX) * (time / maxTime) + startX)

Start::Start()
{
	hImage = LoadGraph("data/image/font.png");
	position = VECTOR3(200, 300, 0);

	startX = 1000;
	endX = 20;
	maxTime = 5.0f;
	time = 0.0f;
}

Start::~Start()
{
}

void Start::Update() {
	time += Time::DeltaTime();
	float rate = time / maxTime;
	position.x = Lerp<float>(startX, endX, rate, easeInOutSine);
	if (time >= maxTime) {
		DestroyMe();
	}
}

void Start::Draw()
{
	DrawRectGraph(position.x, position.y, 0, 0, 
		256, 64, hImage, TRUE);
}

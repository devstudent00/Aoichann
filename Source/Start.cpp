#include "Start.h"
#include "Screen.h"
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

float Lerp(float start, float end, float rate) {
	return (end - start) * rate + start;
}

void Start::Update() {
	time += Time::DeltaTime();
	float rate = time / maxTime;
	rate = rate * rate;
	position.x = Lerp(startX, endX, rate);
	if (time >= maxTime) {
		DestroyMe();
	}
}

void Start::Draw()
{
	DrawRectGraph(position.x, position.y, 0, 0, 
		256, 64, hImage, TRUE);
}

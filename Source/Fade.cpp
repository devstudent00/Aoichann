#include "Fade.h"
#include <DxLib.h>
#include "Lerp.h"

Fade::Fade()
{
	SetDrawOrder(-1000); 
	currentAlpha = 0.0f;
	fadeColor = GetColor(0, 0, 0);
	time_ = 1.0f;
	maxTime = 1.0f;
	startAlpha = 0.0f;
	endAlpha = 0.0f;
}

Fade::~Fade()
{
}

void Fade::Update() {
	if (time_ < maxTime) {
		time_ += Time::DeltaTime();
		currentAlpha = Lerp<float>(startAlpha, endAlpha, time_ / maxTime);
	}
}

void Fade::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, currentAlpha);
	DrawBox(0, 0, 1280, 720, fadeColor, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void Fade::FadeIn(float time) {
	startAlpha = 255.0f;
	endAlpha = 0.0f;
	maxTime = time;
	this->time_ = 0.0f;
}

void Fade::FadeOut(float time) {
	startAlpha = 0.0f;
	endAlpha = 255.0f;
	maxTime = time;
	this->time_ = 0.0f;
}

void Fade::SetColor(unsigned int color) {
	fadeColor = color;
}

bool Fade::IsFinished() const {
	return (time_ >= maxTime);
}

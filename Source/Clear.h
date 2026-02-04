#pragma once
#include "../Library/GameObject.h"

/// <summary>
/// ƒNƒŠƒA‚µ‚½‚Æ‚«‚Ì‰æ–Ê
/// </summary>
class Clear : public GameObject {
public:
	Clear();
	~Clear();
	void Update() override;
	void Draw() override;
private:
	int hImage;
	VECTOR3 position;
	float startX;
	float endX;
	float maxTime;
	float time;
	bool isDead;
};
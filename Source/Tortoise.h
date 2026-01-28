#pragma once
#include "../Library/GameObject.h"

class Tortoise : public GameObject {
public:
	//Tortoise();
	Tortoise(int x, int y);
	~Tortoise();
	void Update() override;
	void Draw() override;
private:
	int hImage;
	VECTOR3 position;
	bool onGround;
	int patX, patY; // ‰¡‚É‰½ŒÂ–Ú‚ÌŠGAc‚É‰½ŒÂ–Ú‚ÌŠG
	int patCounter;
};
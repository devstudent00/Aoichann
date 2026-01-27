#pragma once
#include "../Library/GameObject.h"

class Player : public GameObject {
public:
	Player();
	Player(int x, int y);
	~Player();
	void Update() override;
	void Draw() override;
private:
	int hImage;
	VECTOR3 position;
	float velocityY;
	bool onGround;
	int patX, patY; // ‰¡‚É‰½ŒÂ–Ú‚ÌŠGAc‚É‰½ŒÂ–Ú‚ÌŠG
	int patCounter;
};
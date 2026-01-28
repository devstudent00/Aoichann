#pragma once
#include "../Library/GameObject.h"

class Character : public GameObject {
public:
	Character();
	Character(int x, int y);
	virtual ~Character();
	virtual void Draw() override;
protected:
	int hImage;
	VECTOR3 position;
	bool onGround;
	int patX, patY; // ‰¡‚É‰½ŒÂ–Ú‚ÌŠGAc‚É‰½ŒÂ–Ú‚ÌŠG
	int patCounter;
};
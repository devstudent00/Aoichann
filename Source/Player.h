#pragma once
//#include "../Library/GameObject.h"
#include "Character.h"

class Player : public Character {
public:
	Player();
	Player(int x, int y);
	~Player();
	void Update() override;
	void OnCollision(Character* other) override;
private:
	float velocityY;
};
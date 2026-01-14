#pragma once
#include "../Library/GameObject.h"

class Player : public GameObject {
private:
	float gravity;
	bool isJumping;
	int hImage;
	VECTOR3 position;
	VECTOR3 velocity;
public:
	Player();
	Player(int x, int y);
	~Player();
	void Update() override;
	void Draw() override;
};
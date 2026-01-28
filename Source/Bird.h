#pragma once
#include "../Library/GameObject.h"

class Bird : public GameObject {
public:
	//Bird();
	Bird(int x, int y);
	~Bird();
	void Update() override;
	void Draw() override;
private:
	int hImage;
	VECTOR3 position;
	bool onGround;
};
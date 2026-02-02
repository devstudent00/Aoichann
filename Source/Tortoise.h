#pragma once
//#include "../Library/GameObject.h"
#include "Character.h"

class Tortoise : public Character {
public:
	//Tortoise();
	Tortoise(int x, int y);
	~Tortoise();
	void Update() override;
	void Draw() override;
private:

};
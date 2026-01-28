#pragma once
//#include "../Library/GameObject.h"
#include "Character.h"

class Bird : public Character {
public:
	//Bird();
	Bird(int x, int y);
	~Bird();
	void Update() override;
};
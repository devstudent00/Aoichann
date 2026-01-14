#pragma once
#include "../Library/GameObject.h"

class Field : public GameObject {
private:
	int blockImage;
public:
	Field();
	~Field();
	void Update() override;
	void Draw() override;
};
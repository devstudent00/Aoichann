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
	int HitWallRight(int x, int y);
	int HitWallLeft(int x, int y);
	int HitWallDown(int x, int y);
};
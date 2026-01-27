#pragma once
#include "../Library/GameObject.h"

class Field : public GameObject {
public:
	Field();
	~Field();
	void Update() override;
	void Draw() override;

	static int scroll; // staticÇÕÅAê√ìIÇ∆Ç¢Ç§à”ñ°

	int HitWallRight(int x, int y);
	int HitWallLeft(int x, int y);
	int HitWallDown(int x, int y);
	bool IsInWall(int x, int y);
private:
	int hImage;
};
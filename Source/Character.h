#pragma once
#include "../Library/GameObject.h"

struct Collider {
	VECTOR3 center;
	float radius;
};

class Character : public GameObject {
public:
	Character();
	Character(int x, int y);
	virtual ~Character();
	virtual void Draw() override;
	virtual void OnCollision(Character* other) {};
	VECTOR3 GetPosition() const { return position; }
	VECTOR3 GetCenter() const { return position + sqhere.center; }
	float GetRadius() const { return sqhere.radius; }
protected:
	int hImage;
	VECTOR3 position;
	VECTOR3 velocity;
	bool onGround;
	int patX, patY; // ‰¡‚É‰½ŒÂ–Ú‚ÌŠGAc‚É‰½ŒÂ–Ú‚ÌŠG
	int patCounter;
	Collider sqhere;
};
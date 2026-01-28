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
	void PlayStart();
private:
	float velocityY;

	enum State {
		S_READY, //開始前
		S_INPLAY, // プレイ中
		S_CRY, // 泣いている状態
	};

	State state; // 現在の状態
	void UpdateReady();
	void UpdateInplay();
	void UpdateCry();
};
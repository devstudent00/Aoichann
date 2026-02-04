#pragma once
#include "../Library/SceneBase.h"

/// <summary>
/// ゲームプレイのシーンを制御する
/// </summary>

class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;
	void OnClear();
	void OnMiss();
private:
	float time;

	// ステートパターン用
	enum State {
		S_READY,
		S_INPLAY,
		S_CLEAR,
		S_GAMEOVER
	};
	State state;
};

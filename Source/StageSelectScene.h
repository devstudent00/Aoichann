#pragma once
#include "../Library/SceneBase.h"

/// <summary>
///	ステージ選択シーン
/// ステージを選んで、キーを押したらプレイシーンに移行する
/// </summary>
class StageSelectScene : public SceneBase {
private:
public:
	StageSelectScene();
	~StageSelectScene();
	void Update() override;
	void Draw() override;
};
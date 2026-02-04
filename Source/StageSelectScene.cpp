#include "StageSelectScene.h"
#include <DxLib.h>
#include "DataHolder.h"

// AとDでステージを選択
// スペースを押したらPlaySceneへ
// Mを押したらTitleSceneへ
StageSelectScene::StageSelectScene()
{
}

StageSelectScene::~StageSelectScene()
{
}

void StageSelectScene::Update()
{
	DataHolder* dh = FindGameObject<DataHolder>();
	if (Input::IsKeyOnTrig(KEY_INPUT_A)) {
		int result = dh->stageNumber - 1;
		if ((result) < 0) return; //例： -1(=0 - 1) < 0：進めない
		dh->stageNumber = result;
	}
	if (Input::IsKeyOnTrig(KEY_INPUT_D)) {
		int result = dh->stageNumber + 1;
		if ((result) > 1) return; //例： 2 > 1 ： true
		dh->stageNumber = result;
	}
	if (Input::IsKeyOnTrig(KEY_INPUT_SPACE)) {
		SceneManager::ChangeScene("PLAY");
	}
	if (Input::IsKeyOnTrig(KEY_INPUT_M)) {
		SceneManager::ChangeScene("TITLE");
	}
}

void StageSelectScene::Draw()
{
	DrawString(100, 400, "STAGE SELECT SCENE", COL_WHITE);
	DataHolder* dh = FindGameObject<DataHolder>();
	DrawFormatString(100, 200, COL_WHITE, "Stage: %d", dh->stageNumber);
}

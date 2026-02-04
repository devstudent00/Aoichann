#include "TitleScene.h"
#include <fstream>
#include <assert.h>

TitleScene::TitleScene()
{
	// CSVを読む実験
	std::ifstream ifs("data/stage00.csv"); // ファイルを開く
	assert(ifs);

	std::string str; // 読んだものを入れる場所
	std::getline(ifs, str); // 1行読んで、strに入れる
	OutputDebugString(str.c_str());
	OutputDebugString("\n");
	int pos = str.find(','); // posは,の場所
	std::string str2 = str.substr(0, pos);  // 文字列を切り取る関数（引数は、何文字目から、何文字）
	OutputDebugString(str2.c_str());
	int n = stoi(str2); // stoi は string to integerの意味

	ifs.close(); // ファイルを閉じる
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	if (Input::IsKeyOnTrig(KEY_INPUT_P)) {
		SceneManager::ChangeScene("PLAY");
	}
	if (Input::IsKeyOnTrig(KEY_INPUT_S)) {
		SceneManager::ChangeScene("STAGE");
	}
	if (Input::IsKeyOnTrig(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
}


void TitleScene::Draw()
{
	DrawString(0, 0, "TITLE SCENE", COL_WHITE);
	DrawFormatString(0, 50, COL_WHITE, "CoG: %s", Version() );
	DrawFormatString(0, 75, COL_WHITE, "DxLib: %s", DXLIB_VERSION_STR_T );
	DrawFormatString(0, 100, COL_WHITE, "FPS: %4.1f", 1.0f / Time::DeltaTime());
	DrawString(100, 400, "Push [P]Key To Play", COL_WHITE);
}

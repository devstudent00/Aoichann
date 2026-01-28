#include "PlayScene.h"
#include "Field.h"
#include "Player.h"
#include "Start.h"

PlayScene::PlayScene()
{
	new Field();
	time = 0;
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{

	if (time < 1.0f) {
		time += Time::DeltaTime();
		if (time >= 1.0f) {
			Player* player = FindGameObject<Player>();
			player->PlayStart();
			new Start();
		}
	}
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
	}
}

void PlayScene::Draw()
{
	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}

#include "PlayScene.h"
#include "Field.h"
#include "Player.h"
#include "Start.h"
#include "Clear.h"
#include "../ImGui/imgui.h"
#include "Fade.h"

PlayScene::PlayScene()
{
	Fade* fade = new Fade();
	new Field();
	state = State::S_READY;
	time = 0;
	fade->FadeIn(0.5f);
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (state == State::S_READY) {
		if (time < 1.0f) {
			time += Time::DeltaTime();
			if (time >= 1.0f) {
				Player* player = FindGameObject<Player>();
				player->PlayStart();
				new Start();
				state = State::S_INPLAY;
			}
		}
	}
	if (state == State::S_CLEAR || state == State::S_GAMEOVER) {
		if (time < 1.0f) {
			time += Time::DeltaTime();
			if (time >= 1.0f) {
				//SceneManager::ChangeScene("TITLE");
				Fade* fade = FindGameObject<Fade>();
				fade->FadeOut(3.0f);
				state = State::S_FADEOUT;
			}
		}
	}
	if (state == State::S_FADEOUT) {
		Fade* fade = FindGameObject<Fade>();
		fade->Update();
		if (fade->IsFinished()) {
			SceneManager::ChangeScene("TITLE");
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

	ImGui::Begin("PlayScene");
	ImGui::InputInt("state", (int*) &state);
	ImGui::End();
}

// シーンにクリアを通知する関数
void PlayScene::OnClear() {
	if (state == State::S_INPLAY) {
		new Clear();
		state = State::S_CLEAR;
		time = 0.0f;
	}
}

void PlayScene::OnMiss() {
}

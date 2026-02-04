#pragma once
#include "../Library/GameObject.h"

/// <summary>
/// 画面のフェードを行うクラス
/// Author: devstudent01
/// </summary>
class Fade : public GameObject {
private:
	float startAlpha;
	float endAlpha;
	float maxTime;
	float time_;
	float currentAlpha;
	unsigned int fadeColor;
public:
	Fade();
	~Fade();
	void Update() override;
	void Draw() override;

	/// <summary>
	/// フェードインする関数（＝徐々に表示する）
	/// </summary>
	/// <param name="time"></param>
	void FadeIn(float time);

	/// <summary>
	/// フェードアウトする関数（＝徐々に見えなくする）
	/// </summary>
	/// <param name="time"></param>
	void FadeOut(float time);

	/// <summary>
	/// フェードの色を変える関数
	/// </summary>
	/// <param name="color"></param>
	void SetColor(unsigned int color);

	/// <summary>
	/// フェードが終了したかを返す関数
	/// </summary>
	bool IsFinished() const;
};

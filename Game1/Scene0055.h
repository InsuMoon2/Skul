#pragma once

class Scene0055 : public Scene
{
private:
	//Text
	ObImage* text;
	ObImage* next;

	DevilCastle* Devil;

	//Witch
	Witch* witch;
	
	//Player
	Player* pl;

	//Block
	ObRect* block;

	//Quest
	ObImage* reborn;
	ObImage* quest;

	int number = 0;
	float text_Time = 0.0f;

	bool textCheck = false;

	bool scnenChange = false;

	void SceneStart();

public:
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};


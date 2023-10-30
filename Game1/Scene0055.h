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
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};


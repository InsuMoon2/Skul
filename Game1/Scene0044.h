#pragma once

class Scene0044 : public Scene
{
private:
	//플레이어
	Player*	 pl;

	//Witch
	Witch*	 witch;
	Vector2	 cat_dis;
	float	 distance;
	bool	 cat_reverse = false;

	//배경
	ObImage* background;
	ObImage* tutorial_Bg;

	ObRect*  ground;
	ObRect*  mongal_Start_Col;

	//몬갈
	Ogre*	 ogre;

	ObImage* mongal_HpBar;
	ObImage* mongal_Hp;
	ObImage* mongal_HpTop;
	ObImage* mongal_HpBottom;

	//Text
	ObImage* text;
	ObImage* next;

	bool	 hit_Check = false;
	bool	textCheck = false;

	//Hero
	Hero*	 hero;
	bool	 hero_Landing = false;

	float	 hero_time = 0.0f;
	float timeDelta = 0.0f;

	bool bCheck = false;
	bool timeCheck = false;
	bool bDead = false;

	int number = 0;
	float text_Time = 0.0f;

	float hero_shakeTime = 0.0f;

	void Hit();
	void GameStart();
	void SceneStart();
	void SceneEnd();

	float time = 0.0f;

	void Mongal_HpVisible();
	void Mongal_HpInVisible();

public:
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};


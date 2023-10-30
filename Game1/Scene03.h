#pragma once

class Scene03 : public Scene
{
float		 distance;

private:
	Player*		pl;
	Knight*		knight;
	BigEnt*		bigEnt;
	Hammer*		hammer;

	//Scene03 맵
	ObImage*	stage1;
	ObImage*	stage1_bg;

	ObImage*	enemy_Icon;

	//보스방 문
	ObRect*	    boss_gateCol;
	ObImage*	boss_gateWall;
	ObImage*	boss_gateNormal;
	ObImage*	boss_gateOpen;
	ObImage*	input;

	bool		input_Checking = false;

	Vector2		dis2;

	ObRect*		block[8];
	ObRect*		block2[2];
	ObRect*		test;

	Vector2		lastPos;
	Vector2		tacklePos;
	Vector2		dis;
	Vector2		monsterDir = Vector2(0.0f, 0.0f);
	Vector2		monsterDir2 = Vector2(0.0f, 0.0f);

	Vector2		hitDir;

	bool		reverse = false;
	bool		hit_Check = false;

	int			count = 3;
	bool		random_Check = false;
	int			random;


public:
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;

public:
	void Hit();
};


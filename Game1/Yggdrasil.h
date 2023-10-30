#pragma once

enum class BossPattern
{
	START,
	IDLE,
	SLAM,
	SWEEP,
	BALL,
	GROGGY,
	DIE
};

class Yggdrasil
{
private:
	//º¸½º »óÅÂ
	BossPattern bossPattern;

public:
	float		start_time = 0.0f;

	float		move_time = 0.0f;
	float		slam_time = 0.0f;
	float		slam_time2 = 0.0f;

	float		sweep_time = 0.0f;
	float		sweep_time2 = 0.0f;

	int			sweep = 2;

	int			ball = 3;

	float		ball_time = 0.0f;
	bool		ball_Shoot = false;

	float		groggy_time = 0.0f;
	bool		groggy_Check = false;

	float		die_time = 0.0f;
	bool		die_Check = false;

	float		boss_HP = 800.0f;

	float		boss_DieTime = 0.0f;

	ObImage*	groggy_Emerge;
	ObImage*	groggy_Effect;
	ObImage*	die_Effect;
	ObImage*	start_Effect1;
	ObImage*	start_Effect2;

	//Col
	ObRect*		boss_Col;
	ObRect*		boss_Col_LR[2];

	//¸Ó¸®
	ObImage*	face1;
	ObImage*	face2;
	ObImage*	face2_Die;
	ObImage*	bossDie_Face;

	//¸ö
	ObImage*	body1;
	ObImage*	body2;
	ObImage*	bossDie_Boddy;

	//ÅÎ
	ObImage*	bottom1;
	ObImage*	bottom2;
	ObImage*	bossDie_Bottom;

	//¼Õ
	ObRect*		hand_Col;
	ObRect*		hand_Col_Reverse;

	ObImage*	hand_Idle;
	ObImage*	hand_Idle_Reverse;
	ObImage*	hand_Idle2;
	ObImage*	hand_Idle2_Reverse;

	ObImage*	hand_Bomb;
	ObImage*	hand_Bomb_Reverse;
	ObImage*	hand_Bomb2;
	ObImage*	hand_Bomb2_Reverse;

	ObImage*	hand_Slam_Start;
	ObImage*	hand_Slam;
	ObImage*	hand_Slam_Reverse_Start;
	ObImage*	hand_Slam_Reverse;
	ObImage*	hand_Slam2;
	ObImage*	hand_Slam2_Reverse;

	ObImage*	hand_Sweep;
	ObImage*	hand_Sweep_Reverse;
	ObImage*	hand_Sweep2;
	ObImage*	hand_Sweep2_Reverse;

	//³ª¹« ¹Ù´Ú
	ObImage*	boss_TreeGround;
	ObImage*	boss_TreeGround2;

	//º¸½º HP
	ObImage*	bossHpBar;
	ObImage*	bossHp;

	//Ball Energy
	ObImage*	ball_Energy;
	ObImage*	ball_Shooting[8];
	ObCircle*	ball_Col[8];

	ObImage*	ball_Big;
	ObCircle*	ball_BigCol;

	ObImage*	ball_Ex;

public:
	Yggdrasil();
	~Yggdrasil();

	void Update();
	void Render();

	void Start();
	void Idle();
	void Slam();
	void Sweep();
	void Ball();
	void Groggy();
	void Die();

	BossPattern& GetBossPattern()
	{
		return bossPattern;
	}

	void Boss_AllInvisible()
	{
		face1->visible = false;
		face2->visible = false;
		face2_Die->visible = false;
		bossDie_Face->visible = false;

		body1->visible = false;
		body2->visible = false;
		bossDie_Boddy->visible = false;

		bottom1->visible = false;
		bottom2->visible = false;
		bossDie_Bottom->visible = false;

		hand_Idle->visible = false;
		hand_Idle_Reverse->visible = false;
		hand_Idle2->visible = false;
		hand_Idle2_Reverse->visible = false;

		hand_Bomb->visible = false;
		hand_Bomb_Reverse->visible = false;
		hand_Bomb2->visible = false;
		hand_Bomb2_Reverse->visible = false;

		hand_Slam->visible = false;
		hand_Slam_Start->visible = false;
		hand_Slam_Reverse->visible = false;
		hand_Slam_Reverse_Start->visible = false;
		hand_Slam2->visible = false;
		hand_Slam2_Reverse->visible = false;

		hand_Sweep->visible = false;
		hand_Sweep_Reverse->visible = false;
		hand_Sweep2->visible = false;
		hand_Sweep2_Reverse->visible = false;

		ball_Energy->visible = false;

		ball_Big->visible = false;
		ball_BigCol->visible = false;

		for (int i = 0; i < 8; i++)
		{
			ball_Shooting[i]->visible = false;
		}
	}

	void Pase1_Idle()
	{
		face1->visible = true;
		body1->visible = true;
		bottom1->visible = true;

		hand_Idle->visible = true;
		hand_Idle_Reverse->visible = true;
	}

	void Pase2_Idle()
	{
		face2->visible = true;
		body2->visible = true;
		bottom2->visible = true;

		hand_Idle2->visible = true;
		hand_Idle2_Reverse->visible = true;
	}

	void Die_visible()
	{
		bossDie_Face->visible = true;
		bossDie_Boddy->visible = true;
		bossDie_Bottom->visible = true;
		hand_Bomb->visible = true;
		hand_Bomb_Reverse->visible = true;
	}

	void HeadMove_Idle();

};


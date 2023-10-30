#pragma once

//대쉬 그림자 잔상
struct Shadow
{
	ObImage*	born_DashShadow;
	float		s_time = 0.0f;
	float		s_interval = 0.07f;
};

class Player : public Character
{
public:
	bool		headStop = false;
	float		scalar;

	// Skill CoolTime
	ObRect* CoolTime;

private:
	
	//머리통 체크
	bool		A_Check = false;

	GameObject	firePos;
	GameObject	firePos1;

	Vector2		Shoot;
	Vector2		Shoot1;
	

	float		scalar1;
	float		gravity;

	ObImage*	born_Run;
	ObImage*    born_Dash;
	ObImage*	born_JumpAttack;

	Shadow*		shadow[5];
	int			index = 0;
	int			index2 = 0;

	ObImage*	bornLess_Idle;
	ObImage*	bornLess_Run;
	ObImage*	bornLess_Dash;
	ObImage*	bornLess_JumpAttack;


public:
	//Guard* guard;

	ObImage*	born_IDLE_NW;
	ObImage*	born_RUN_NW;
	ObImage*	born_Idle;
	ObImage*	born_GetWeapon;
	ObImage*	born_GetWeapon2;
	

	ObImage*    born_Dead;
	ObImage*	born_Jump;
	ObImage*    born_Attack1;
	ObImage*    born_Attack2;

	ObImage*	bornLess_Jump;
	ObImage*	bornLess_Attack1;
	ObImage*	bornLess_Attack2;

	ObImage*	bornSkill_A;
	ObImage*	bornSkill_B;
	ObImage*	switch_Skul;

	ObCircle*	born_HeadCol;
	ObImage*	born_Head;

	float		die_time = 0.0f;
	bool		born_Check;
	bool		headShoot_Check = false;

	bool		retry = false;
	bool		groundInter = false;

	Vector2		headShoot_LastPos;
	float		shoot_time = 0.0f;
	float		shoot_time2 = 0.0f;

	//Guard
	ObImage* guard_Idle;
	ObImage* guard_Jump;
	ObImage* guard_Walk;
	ObImage* guard_Dash;
	ObImage* guard_JumpAttack;

	ObImage* guard_Attack1;
	ObImage* guard_Attack2;
	ObImage* guard_Attack3;

	ObImage* guard_Skill_A;
	ObImage* guard_Skill_B;

	ObImage* guard_Switch;

	ObImage* fireBall;
	ObRect*  fireBall_Col;
	ObImage* fireSlash;
	ObImage* skill_Slash;

	bool	 fireBall_Check = false;

	Vector2  slashPos;



	bool	 slash_Check = false;
	float	 slash_Time = 0.0f;

	float distance;

	//Attack1 프레임
	int ANI()
	{
		return born_Attack1->frame.x;
	}

	int ANI2()
	{
		return bornLess_Attack1->frame.x;
	}

	int ANI3()
	{
		return guard_Attack1->frame.x;
	}

	int ANI4()
	{
		return guard_Attack2->frame.x;
	}

	//Jump 프레임
	int& JUMPANI()
	{
		return born_Jump->frame.x;
	}

	int& JUMPANI2()
	{
		return bornLess_Jump->frame.x;
	}

	int& JUMPANI3()
	{
		return guard_Jump->frame.x;
	}

public:
	Player();
	~Player();

	void Update();
	void LateUpdate();
	void Render();

	void B_Idle();
	void B_Run();
	void B_Jump();
	void B_DownJump();
	void B_JumpAttack();
	void B_Attack1();
	void B_Attack2();
	void B_Dash();
	void B_Skill_A();
	void B_Skill_B();
	void B_Die();

	bool bCheck = false;

	bool Shooting(ObImage* player, float scalar, Vector2 firePos);
	void Shooting();
	void GetShoot();

	//뚝배기 ON
	void Head_Visible()
	{
		born_Idle->visible = true;
		born_Run->visible = true;
		born_Dash->visible = true;
		born_JumpAttack->visible = true;
		born_Jump->visible = true;
		born_Attack1->visible = true;
		born_Attack2->visible = true;
	}

	//No 뚝배기 ON
	void HeadLess_Visible()
	{
		bornLess_Idle->visible = true;
		bornLess_Run->visible = true;
		bornLess_Dash->visible = true;
		bornLess_JumpAttack->visible = true;
		bornLess_Jump->visible = true;
		bornLess_Attack1->visible = true;
		bornLess_Attack2->visible = true;
	}

	//모든 이미지 Off
	void AllInvisible()
	{
		born_Idle->visible = false;
		born_Run->visible = false;
		born_Dash->visible = false;
		born_JumpAttack->visible = false;
		born_Jump->visible = false;
		born_Attack1->visible = false;
		born_Attack2->visible = false;

		//머리통 X
		bornLess_Idle->visible = false;
		bornLess_Run->visible = false;
		bornLess_Dash->visible = false;
		bornLess_JumpAttack->visible = false;
		bornLess_Jump->visible = false;
		bornLess_Attack1->visible = false;
		bornLess_Attack2->visible = false;

		born_Dead->visible = false;

		//무기 X
		born_IDLE_NW->visible = false;
		born_RUN_NW->visible = false;
	}

	void G_Idle();
	void G_Run();
	void G_Jump();
	void G_DownJump();
	void G_JumpAttack();
	void G_Attack1();
	void G_Attack2();
	void G_Attack3();
	void G_Dash();
	void G_Skill_A();
	void G_Skill_B();
	void G_Die();

	bool G_Shooting(ObImage* player1, float scalar1, Vector2 firePos1);
	void G_GetShoot();

	//Guard 다 끄기
	void G_AllInvisible()
	{
		guard_Idle->visible = false;
		guard_Walk->visible = false;
		guard_Dash->visible = false;
		guard_Jump->visible = false;
		guard_JumpAttack->visible = false;

		guard_Attack1->visible = false;
		guard_Attack2->visible = false;
		guard_Attack3->visible = false;

		guard_Skill_A->visible = false;
		guard_Skill_B->visible = false;

		guard_Switch->visible = false;
	}
};


#pragma once

class Guard : public Character
{
private:

public:
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


	//Attack1 프레임
	int ANI()
	{
		return guard_Attack1->frame.x;
	}

	int ANI2()
	{
		return guard_Attack2->frame.x;
	}

	//Jump 프레임
	int& JUMPANI()
	{
		return guard_Jump->frame.x;
	}

	int& JUMPANI2()
	{
		return guard_JumpAttack->frame.x;
	}

public:
	Guard();
	~Guard();

	void Update();
	void Render();

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


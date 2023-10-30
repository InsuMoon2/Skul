#pragma once
#define BMAX 8

class BigEnt : public Monster
{
private:

public:
	ObRect*		 bigEnt_Recog;
	ObImage*	 bigEnt_Idle;
	ObImage*	 bigEnt_Attack1;
	ObImage*	 bigEnt_Attack1_Effect;
	ObImage*	 bigEnt_Attack2;
	ObCircle*	 bullet_Col[BMAX];
	ObImage*	 bigEnt_Attack2_Bullet[BMAX];
	ObImage*	 bigEnt_Die;

	float		 bigEnt_Hp = 160.0f;
	float		 d_time = 0.0f;

	float		 attack2_time = 0.0f;
	float		 attack2_time2 = 0.0f;
	bool		 attack2_Checking = false;

	BigEnt();
	~BigEnt();

	void Update();
	void Render();

	void E_Idle();
	void E_Attack1();
	void E_Attack2();
	void E_Die();


	void E_AllInvisible()
	{
		bigEnt_Idle->visible = false;
		bigEnt_Attack1->visible = false;
		bigEnt_Attack1_Effect->visible = false;
		bigEnt_Attack2->visible = false;

		for (int i = 0; i < BMAX; i++)
		{
			//bigEnt_Attack2_Bullet[i]->visible = false;
		}
		
		bigEnt_Die->visible = false;
	}
};


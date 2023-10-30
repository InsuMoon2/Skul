#pragma once
class Hammer : public Monster
{
private:
	float	 hammerTime = 0.0f;
	float	 hammerTime2 = 0.0f;
	

public:
	ObImage* hammer_Idle;
	ObImage* hammer_Move;
	ObImage* hammer_Attack1;
	ObImage* hammer_Attack2;
	ObImage* hammer_Die;	

	ObRect*  hammer_Attack1_Col;
	ObRect*  hammer_Attack2_Col;

	float	 hammer_Hp = 200.0f;
	float	 d_time = 0.0f;

	bool	 tackle = false;
	float	 h_attack1_Time = 0.0f;
	float	 h_attack_Time = 0.0f;
	float	 h_attack_Time2 = 0.0f;

	bool	 reverse = false;
	Vector2	 hammerDir = Vector2(0.0f, 0.0f);

	Hammer();
	~Hammer();

	void Update();
	void Render();

	void H_Idle();
	void H_Move();
	void H_Attack1();
	void H_Attack2();
	void H_Die();

	Vector2	GetMonster()
	{
		return monster_Col->GetWorldPos();
	}

	void H_AllInvisible()
	{
		hammer_Idle->visible = false;
		hammer_Move->visible = false;
		hammer_Attack1->visible = false;
		hammer_Attack2->visible = false;
		hammer_Attack1_Col->visible = false;
		hammer_Attack2_Col->visible = false;
		hammer_Die->visible = false;
	}
};


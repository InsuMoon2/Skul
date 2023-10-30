#pragma once
class Knight : public Monster
{
private:
	float	 time = 0.0f;
public:
	ObRect*  knight_AttackCol;

	ObImage* knight_Idle;
	ObImage* knight_Walk;
	ObImage* knight_Attack;
	ObImage* knight_Attack2;
	ObImage* knight_Hit;
	ObImage* knight_Die;

	bool	 hit = false;
	bool	 attack_Checking = false;

	bool	 reverse = false;
	Vector2	 monsterDir = Vector2(0.0f, 0.0f);

	float	 h_time = 0.5f;
	float	 d_time = 0.0f;

	float	 attack_Time = 0.0f;

	int& k_AttackFrame()
	{
		return knight_Attack->frame.x;
	}

	Knight();
	~Knight();

	void Update();
	void Render();

	void K_Idle();
	void K_Move();
	void K_Attack();
	void K_Attack2();
	void K_Hit();
	void K_Die();

	void K_AllInvisible()
	{
		knight_AttackCol->visible = false;
		knight_Idle->visible = false;
		knight_Walk->visible = false;
		knight_Attack->visible = false;
		knight_Attack2->visible = false;
		knight_Hit->visible = false;
		knight_Die->visible = false;
	}
};


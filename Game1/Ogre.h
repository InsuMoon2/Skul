#pragma once
class Ogre : public Monster
{
private:
	ObImage* Idle;

	ObImage* Ogre_Idle;
	ObImage* Ogre_Walk;
	ObImage* Ogre_Attack;
	ObImage* Ogre_Hit;
	ObImage* Ogre_Die;

public:
	ObImage* Ogre_N_WakeUp1;
	ObImage* Ogre_N_WakeUp2;
	ObImage* Ogre_N_Idle;
	ObImage* Ogre_N_Walk;
	ObImage* Ogre_N_Laugh;
	ObImage* Ogre_N_Die;

	float	 laugh_time = 0.0f;

	//몬갈 피통
	float	 mongalHp = 600.0f;

	ObRect*  Ogre_AttackCol;
	ObImage* mongal_DeadEffect1;
	ObImage* mongal_DeadEffect2;
	ObImage* mongal_DeadEffect3;

	bool	 ogre_reverse = false;
	bool	 hit = false;

	Vector2	 mongal_dis;
	float	 mongal_distance;
	float	 monga_attack_Time = 0.0f;
	float	 monga_hit_Time = 0.3f;

	bool	 mongal_Start = false;
	bool	 mongal_Attack = false;

	bool	 mongal_Normal = false;
	bool	 mongal_Normal2 = false;
	bool	 mongal_laugh = false;
	bool	 mongal_Move = false;

	Ogre();
	~Ogre();

	void Update();
	void Render();

	void O_Idle();
	void O_Move();
	void O_Attack();
	void O_Hit();
	void O_Die();

	int& Ogre_AttackFrame()
	{
		return Ogre_Attack->frame.x;
	}

	//Hit
	Color& Ogre_Idle_HitColor()
	{
		return Ogre_Idle->color = Color(0.85f, 0.85f, 0.85f, 0.5f); 
	}

	Color& Ogre_Walk_HitColor()
	{
		return Ogre_Walk->color = Color(0.85f, 0.85f, 0.85f, 0.5f);
	}

	Color& Ogre_Attack_HitColor()
	{
		return Ogre_Attack->color = Color(0.85f, 0.85f, 0.85f, 0.5f);
	}

	Color& Ogre_HitColor()
	{
		return Ogre_Hit->color = Color(0.85f, 0.85f, 0.85f, 0.5f);
	}

	//Return
	Color& Ogre_Idle_ReturnColor()
	{
		return Ogre_Idle->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
	}

	Color& Ogre_Walk_ReturnColor()
	{
		return Ogre_Walk->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
	}

	Color& Ogre_Attack_ReturnColor()
	{
		return Ogre_Attack->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
	}

	Color& Ogre_Hit_ReturnColor()
	{
		return Ogre_Hit->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
	}

	void O_AllInvisible()
	{
		Ogre_AttackCol->visible = false;
		Ogre_Idle->visible = false;
		Ogre_Walk->visible = false;
		Ogre_Attack->visible = false;
		Ogre_Hit->visible = false;
		Ogre_Die->visible = false;
	}
};


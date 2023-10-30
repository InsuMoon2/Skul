#pragma once

enum class MonsterState
{
	IDLE,
	MOVE,
	ATTACK,
	ATTACK2,
	HIT,
	DIE
};

enum class MonsterType
{
	M_Knight,
	M_Hammer,
	M_BigEnt,
	M_GreenEnt,
	M_Ogre,
	M_Ogre_N
};

class Monster// : public Character
{
private:
	//ป๓ลย
	MonsterState monster_State;
	MonsterType  monster_Type;

	Vector2		 mosDir;

public:
	ObImage*	 monster_HpBar;
	ObImage*	 monster_Hp;
	ObRect*		 monster_Col;
	ObRect*		 monster_Recognize;

	ObImage*	 monster_Apperance;
	ObImage*	 monster_Dead;
	bool		 app_Check = false;
	bool		 dead_Check = false;


	float		 knightSpeed = 200.0f;
	

	//Hp
	float		 knight_Hp = 100.0f;

	MonsterState& Get_MonsterState()
	{
		return monster_State;
	}

	MonsterType& Get_MonsterType()
	{
		return monster_Type;
	}

	Monster();
	~Monster();

	void Update();
	void Render();
};


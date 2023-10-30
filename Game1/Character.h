#pragma once

enum class SKUL
{
	LittleBorn,
	Guard
};

enum class PLAYERSTATE
{
	IDLE,
	RUN,
	JUMP,
	DOWNJUMP,
	JUMPATTACK,
	ATTACK1,
	ATTACK2,
	ATTACK3,
	SKILL1,
	SKILL2,
	DASH,
	DIE
};

class Character
{
private:
	friend class PlayerUi;
	
	float		attack_Time = 0.0f;
	float		attack_Time2 = 0.0f;
	float		attack_Time3 = 0.0f;

	ObImage*	dash_Effect;

	Vector2		dashSmoke;
	Vector2		lastDir;
	Vector2		moving;
	Vector2		lastPos;

	float		gravity;
	float		playerSpeed;

	int			dash_Count = 2;
	float		dash_time;
	
public:
	//Player Ui
	PlayerUi*   playerUi;
	bool		getWeapon = false;
	//상태
	float		downjump_Time = 0.0f;
	bool		downjump_Checking = false;

	bool		jumpground_Check = false;

	PLAYERSTATE player_State;
	SKUL	    Skul_State;

	Vector2		moveDir;
	Vector2		jumpSmoke;
	ObImage*	doubleJump;
	ObRect*		player_Col;
	ObRect*		attack_Col;
	ObRect*		attack_Col2;
	ObRect*		Jump_attack_Col;
	ObRect*		player_Head;
	ObRect*		player_Bottom;
	ObRect*		player_Left;
	ObRect*		player_Right;

	ObImage*	Hit_Skul;
	ObImage*	Hit_normal;

	//인벤토리
	ObImage*	inven;
	ObImage*	black;

	bool		jump;
	bool		reverse;
	bool		attack;
	float		distance;

	float		hit_time = 0.0f;

	//Hp = 290.0f
	int			born_Hp = 290;
	bool		HpChecking = false;

	//LittleBorn
	virtual int		ANI() = 0;
	virtual int		ANI2() = 0;
	
	virtual int&	JUMPANI() = 0;
	virtual int&	JUMPANI2() = 0;

	//Guard
	virtual int		ANI3() = 0;
	virtual int		ANI4() = 0;
	virtual int&	JUMPANI3() = 0;

	//플레이어 상태
	PLAYERSTATE& GetState()
	{
		return player_State;
	}
	SKUL& GetSkulState()
	{
		return Skul_State;
	}
	//중력
	float& GetGravity()
	{
		return gravity;
	}
	//대쉬 카운트
	int& GetDashCount()
	{
		return dash_Count;
	}
	//Player
	Vector2 GetPos()
	{
		return player_Col->GetWorldPos();
	}
	//Player Bottom
	Vector2 GetBPos()
	{
		return player_Bottom->GetWorldPos();
	}
	//Player Head
	Vector2 GetHPos()
	{
		return player_Head->GetWorldPos();
	}
	//Player Left
	Vector2 GetLPos()
	{
		return player_Left->GetWorldPos();
	}
	//Player Right
	Vector2 GetRPos()
	{
		return player_Right->GetWorldPos();
	}

	//void DownJump();

public:
	Character();
	~Character();

	void Update();
	void Render();
	void StepBack();

	void Idle();
	void Run();
	void Jump();
	void DownJump();
	void JumpAttack();
	void Attack1();
	void Attack2();
	void Attack3();
	void Dash();
	void Skill_A();
	void Skill_B();
	void Input();
};


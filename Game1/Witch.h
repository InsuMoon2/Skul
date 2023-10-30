#pragma once

enum class WITCHSTATE
{
	CAGE,
	IDLE,
	POLY,
	CAT_IDLE,
	CAT_WALK
};

class Witch
{
private:
	WITCHSTATE witch_State;

public:
	ObRect*  witch_Col;

	ObImage* Cage_Witch;
	ObImage* witch_Idle;
	ObImage* witch_Poly;
	ObImage* cat_Idle;
	ObImage* cat_Walk;

	bool cat_Check = false;
	bool cage_Check = false;

	WITCHSTATE& Witch_State()
	{
		return witch_State;
	}

	Witch();
	void Update();
	void Release();
	void Render();

	void Cage();
	void Idle();
	void Poly();
	void Cat_Idle();
	void Cat_Walk();
};


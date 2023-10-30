#pragma once
class Hero
{
private:
	

public:
	ObRect*	 hero_Col;
	ObImage* hero_Landing;
	ObImage* hero_Fly;
	ObImage* hero_Bigbang_Ready;
	ObImage* hero_Bigbang_Attack;

	ObImage* hero_Landing_Effect1;
	ObImage* hero_Landing_Effect2;
	
	ObImage* hero_Bigbang_Effect_Start;
	ObImage* hero_Bigbang_Effect;
	ObImage* hero_Bigbang_Ball_Ready;
	ObImage* hero_Bigbang_Ball;

	bool	 hero_attack = false;
	bool	 hero_talk = false;

	Hero();
	~Hero();

	void Update();
	void Render();
};


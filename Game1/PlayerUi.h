#pragma once
class PlayerUi
{
private:
	
public:
	//Player Ui Image
	ObImage* player_UiBase;
	ObImage* player_Skill2;
	ObImage* player_Sub1;
	ObImage* player_Sub2;
	ObImage* player_SubSkul;
	ObImage* portrait_Skul;
	ObImage* portrait_Skul_Small;

	//리틀본 스킬 두개
	ObImage* born_A;
	ObImage* born_S;

	ObImage* born_A_Small;
	ObImage* born_S_Small;
	ObRect*  born_A_Gauge;

	ObImage* a;
	ObImage* s;
	ObImage* space;

	ObImage* player_Hp;

	//Guard Ui, Skill
	ObImage* guard_BIcon;
	ObImage* guard_SIcon;

	ObImage* guard_Skill_A;
	ObImage* guard_Skill_S;

	ObImage* guard_Skill_A_Small;
	ObImage* guard_Skill_S_Small;

	ObRect* sceneBlack_Top;
	ObRect* sceneBlack_Bottom;

	bool	 UiChecking = false;

public:
	PlayerUi();
	~PlayerUi();

	void Update();
	void Render();

	void UiBlack();

	void BornVisible()
	{
		born_A->visible = true;
		born_S->visible = true;

		born_A_Small->visible = false;
		born_S_Small->visible = false;

		guard_Skill_A->visible = false;
		guard_Skill_S->visible = false;

		a->visible = true;
		s->visible = true;
		player_Skill2->visible = true;

		player_Sub1->visible = true;
		player_Sub2->visible = true;

		//guard_Skill_A_Small->visible = false;
		//guard_Skill_S_Small->visible = false;

		guard_BIcon->visible = false;
		guard_SIcon->visible = false;
	}

	void GuardVisible()
	{
		guard_Skill_A->visible = true;
		guard_Skill_S->visible = true;

		//guard_Skill_A_Small->visible = true;
		//guard_Skill_S_Small->visible = true;

		born_A->visible = false;
		born_S->visible = false;

		portrait_Skul->visible = false;
		portrait_Skul_Small->visible = true;

		born_A_Small->visible = true;
		born_S_Small->visible = true;

		guard_BIcon->visible = true;
		guard_SIcon->visible = false;
	}

	void StartUi()
	{
		player_UiBase->visible = true;
		portrait_Skul->visible = true;
		player_SubSkul->visible = true;
		space->visible = true;
		player_Hp->visible = true;
	}

	void UiInVisible()
	{
		player_UiBase->visible = false;
		player_Skill2->visible = false;
		player_Sub1->visible = false;
		player_Sub2->visible = false;
		player_SubSkul->visible = false;
		portrait_Skul->visible = false;
		portrait_Skul_Small->visible = false;

		born_A->visible = false;
		born_S->visible = false;

		born_A_Small->visible = false;
		born_S_Small->visible = false;
		born_A_Gauge->visible = false;

		a->visible = false;
		s->visible = false;
		space->visible = false;

		player_Hp->visible = false;

		guard_BIcon->visible = false;
		guard_SIcon->visible = false;

		guard_Skill_A->visible = false;
		guard_Skill_S->visible = false;



		//guard_Skill_A_Small->visible = false;
		//guard_Skill_S_Small->visible = false;
	}

};


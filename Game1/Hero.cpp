#include "stdafx.h"

Hero::Hero()
{
	hero_Col = new ObRect();
	hero_Col->scale = Vector2(909.0f / 9.0f, 86.0f) * 2.5f;
	hero_Col->visible = true;
	hero_Col->isFilled = false;
	hero_Col->pivot = OFFSET_B;

	hero_Landing = new ObImage(L"Hero_Landing.png");
	hero_Landing->scale = Vector2(1107.0f / 9.0f, 125.0f) * 2.5f;
	hero_Landing->SetParentRT(*hero_Col);
	hero_Landing->SetLocalPosX(53.0f);
	hero_Landing->SetLocalPosY(145.0f);
	hero_Landing->maxFrame = Int2(9,1);
	//hero_Landing->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	hero_Landing->visible = false;
	hero_Landing->reverseLR = true;

	hero_Fly = new ObImage(L"Hero_Fly_Idle.png");
	hero_Fly->scale = Vector2(1107.0f / 9.0f, 125.0f) * 2.5f;
	hero_Fly->SetParentRT(*hero_Col);
	hero_Fly->SetLocalPosX(-10.0f);
	hero_Fly->SetLocalPosY(116.0f);
	hero_Fly->maxFrame = Int2(9, 1);
	hero_Fly->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	hero_Fly->visible = false;
	hero_Fly->reverseLR = true;

	hero_Bigbang_Ready = new ObImage(L"Hero_BigBang_Ready.png");
	hero_Bigbang_Ready->scale = Vector2(1107.0f / 9.0f, 125.0f) * 2.5f;
	hero_Bigbang_Ready->SetParentRT(*hero_Col);
	hero_Bigbang_Ready->SetLocalPosX(-20.0f);
	hero_Bigbang_Ready->SetLocalPosY(170.0f);
	hero_Bigbang_Ready->maxFrame = Int2(6, 1);
	hero_Bigbang_Ready->ChangeAnim(ANIMSTATE::ONCE, 0.12f);
	hero_Bigbang_Ready->visible = false;
	hero_Bigbang_Ready->reverseLR = true;

	hero_Bigbang_Attack = new ObImage(L"BigBang_Ready_Loop_0.png");
	hero_Bigbang_Attack->scale = Vector2(1107.0f / 9.0f, 125.0f) * 2.5f;
	hero_Bigbang_Attack->SetParentRT(*hero_Col);
	hero_Bigbang_Attack->SetLocalPosX(23.0f);
	hero_Bigbang_Attack->SetLocalPosY(170.0f);
	hero_Bigbang_Attack->maxFrame = Int2(7, 1);
	hero_Bigbang_Attack->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	hero_Bigbang_Attack->visible = false;
	hero_Bigbang_Attack->reverseLR = true;

	hero_Landing_Effect1 = new ObImage(L"Landing_Effect_01.png");
	hero_Landing_Effect1->scale = Vector2(10948.0f / 17.0f, 557.0f) * 2.0f;
	hero_Landing_Effect1->SetParentRT(*hero_Col);
	hero_Landing_Effect1->SetLocalPosY(355.0f);
	hero_Landing_Effect1->maxFrame = Int2(17, 1);
	hero_Landing_Effect1->ChangeAnim(ANIMSTATE::ONCE, 0.08f);
	hero_Landing_Effect1->visible = false;
	//hero_Landing_Effect1->reverseLR = true;

	hero_Landing_Effect2 = new ObImage(L"Landing_Effect_02.png");
	hero_Landing_Effect2->scale = Vector2(10948.0f / 17.0f, 557.0f) * 2.0f;
	hero_Landing_Effect2->SetParentRT(*hero_Col);
	hero_Landing_Effect2->SetLocalPosY(355.0f);
	hero_Landing_Effect2->maxFrame = Int2(17, 1);
	hero_Landing_Effect2->ChangeAnim(ANIMSTATE::ONCE, 0.08f);
	hero_Landing_Effect2->visible = false;
	//hero_Landing_Effect2->reverseLR = true;

	hero_Bigbang_Effect_Start = new ObImage(L"BigBang_Effect_Start.png");
	hero_Bigbang_Effect_Start->scale = Vector2(7015.0f / 23.0f, 296.0f) * 2.0f;
	hero_Bigbang_Effect_Start->SetParentRT(*hero_Col);
	hero_Bigbang_Effect_Start->SetLocalPosX(-140.0f);
	hero_Bigbang_Effect_Start->SetLocalPosY(325.0f);
	hero_Bigbang_Effect_Start->maxFrame = Int2(23, 1);
	hero_Bigbang_Effect_Start->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
	hero_Bigbang_Effect_Start->visible = false;

	hero_Bigbang_Effect = new ObImage(L"BigBang_Effect.png");
	hero_Bigbang_Effect->scale = Vector2(4598.0f / 22.0f, 187.0f) * 2.0f;
	hero_Bigbang_Effect->SetParentRT(*hero_Bigbang_Effect_Start);
	hero_Bigbang_Effect->SetLocalPosY(-15.0f);
	hero_Bigbang_Effect->maxFrame = Int2(22, 1);
	hero_Bigbang_Effect->ChangeAnim(ANIMSTATE::LOOP, 0.08f);
	hero_Bigbang_Effect->visible = false;

	hero_Bigbang_Ball_Ready = new ObImage(L"BigBang_Ball_Ready.png");
	hero_Bigbang_Ball_Ready->scale = Vector2(725.0f / 5.0f, 132.0f) * 2.0f;
	hero_Bigbang_Ball_Ready->SetParentRT(*hero_Bigbang_Effect_Start);
	//hero_Bigbang_Ball_Ready->SetLocalPosY(235.0f);
	hero_Bigbang_Ball_Ready->maxFrame = Int2(5, 1);
	hero_Bigbang_Ball_Ready->ChangeAnim(ANIMSTATE::ONCE, 0.08f);
	hero_Bigbang_Ball_Ready->visible = false;

	hero_Bigbang_Ball = new ObImage(L"BigBang_Ball.png");
	hero_Bigbang_Ball->scale = Vector2(5510.0f / 38.0f, 132.0f) * 2.3f;
	hero_Bigbang_Ball->SetParentRT(*hero_Bigbang_Effect_Start);
	hero_Bigbang_Ball->SetLocalPosX(-23.0f);
	hero_Bigbang_Ball->SetLocalPosY(5.0f);
	hero_Bigbang_Ball->maxFrame = Int2(38, 1);
	hero_Bigbang_Ball->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	hero_Bigbang_Ball->visible = false;

	SOUND->AddSound("SkulStory5_Chapter4_FirstHero.wav", "Hero_Landing", false);
	SOUND->AddSound("Hero_Charging.wav", "Hero_Charging", false);

}

Hero::~Hero()
{
	SafeDelete(hero_Col);
	SafeDelete(hero_Landing);
	SafeDelete(hero_Fly);
	SafeDelete(hero_Bigbang_Ready);
	SafeDelete(hero_Bigbang_Attack);
	SafeDelete(hero_Landing_Effect1);
	SafeDelete(hero_Landing_Effect2);

	SafeDelete(hero_Bigbang_Effect_Start);
	SafeDelete(hero_Bigbang_Effect);
	SafeDelete(hero_Bigbang_Ball_Ready);
	SafeDelete(hero_Bigbang_Ball);
}

void Hero::Update()
{
	
	

	hero_Col->Update();
	hero_Landing->Update();
	hero_Fly->Update();
	hero_Bigbang_Ready->Update();
	hero_Bigbang_Attack->Update();
	hero_Landing_Effect1->Update();
	hero_Landing_Effect2->Update();

	hero_Bigbang_Effect_Start->Update();
	hero_Bigbang_Effect->Update();
	hero_Bigbang_Ball_Ready->Update();
	hero_Bigbang_Ball->Update();
}

void Hero::Render()
{
	hero_Col->Render();
	hero_Landing->Render();
	hero_Fly->Render();
	hero_Bigbang_Ready->Render();
	hero_Bigbang_Attack->Render();
	hero_Landing_Effect1->Render();
	hero_Landing_Effect2->Render();

	hero_Bigbang_Effect_Start->Render();
	hero_Bigbang_Ball_Ready->Render();
	hero_Bigbang_Ball->Render();
	hero_Bigbang_Effect->Render();
}

#include "stdafx.h"

PlayerUi::PlayerUi()
{
	player_UiBase = new ObImage(L"Player_Normal_Frame.png");
	player_UiBase->scale = Vector2(168.0f, 66.0f) * 2.5f;
	player_UiBase->SetWorldPos(Vector2(-580.0f, -480.0f));
	player_UiBase->pivot = OFFSET_B;
	player_UiBase->visible = true;
	player_UiBase->space = SPACE::SCREEN;

	player_Skill2 = new ObImage(L"Player_Skill2_Frame.png");
	player_Skill2->scale = Vector2(35.0f, 34.0f) * 2.5f;
	player_Skill2->SetParentT(*player_UiBase);
	player_Skill2->SetLocalPos(Vector2(40.0f, 52.5f));
	player_Skill2->pivot = OFFSET_B;
	player_Skill2->visible = true;
	player_Skill2->space = SPACE::SCREEN;

	player_Sub1 = new ObImage(L"Player_Subskill1_Frame.png");
	player_Sub1->scale = Vector2(24.0f, 24.0f) * 2.5f;
	player_Sub1->SetParentT(*player_UiBase);
	player_Sub1->SetLocalPos(Vector2(115.0f, 60.0f));
	player_Sub1->pivot = OFFSET_B;
	player_Sub1->visible = true;
	player_Sub1->space = SPACE::SCREEN;

	player_Sub2 = new ObImage(L"Player_Subskill2_Frame.png");
	player_Sub2->scale = Vector2(26.0f, 24.0f) * 2.5f;
	player_Sub2->SetParentT(*player_UiBase);
	player_Sub2->SetLocalPos(Vector2(167.5f, 60.0f));
	player_Sub2->pivot = OFFSET_B;
	player_Sub2->visible = true;
	player_Sub2->space = SPACE::SCREEN;

	player_SubSkul = new ObImage(L"Player_Subskull_Frame.png");
	player_SubSkul->scale = Vector2(27.0f, 28.0f) * 2.5f;
	player_SubSkul->SetParentT(*player_UiBase);
	player_SubSkul->SetLocalPos(Vector2(-160.0f, 20.0f));
	player_SubSkul->pivot = OFFSET_B;
	player_SubSkul->visible = true;
	player_SubSkul->space = SPACE::SCREEN;

	portrait_Skul = new ObImage(L"portrait_skul.png");
	portrait_Skul->scale = Vector2(21.0f, 19.0f) * 4.5f;
	portrait_Skul->SetParentT(*player_UiBase);
	portrait_Skul->SetLocalPos(Vector2(-135.0f, 65.0f));
	portrait_Skul->pivot = OFFSET_B;
	portrait_Skul->visible = true;
	portrait_Skul->space = SPACE::SCREEN;

	portrait_Skul_Small = new ObImage(L"portrait_skul.png");
	portrait_Skul_Small->scale = Vector2(21.0f, 19.0f) * 2.3f;
	portrait_Skul_Small->SetParentT(*player_UiBase);
	portrait_Skul_Small->SetLocalPos(Vector2(-158.0f, 39.0f));
	portrait_Skul_Small->pivot = OFFSET_B;
	portrait_Skul_Small->visible = false;
	portrait_Skul_Small->space = SPACE::SCREEN;

	a = new ObImage(L"A.png");
	a->scale = Vector2(13.0f, 12.0f) * 2.5f;
	a->SetParentT(*player_UiBase);
	a->SetLocalPos(Vector2(-35.0f, 120.0f));
	a->pivot = OFFSET_B;
	a->visible = true;
	a->space = SPACE::SCREEN;

	born_A = new ObImage(L"LittleBone1.bmp");
	born_A->scale = Vector2(24.0f, 24.0f) * 2.5f;
	born_A->SetParentT(*player_UiBase);
	born_A->SetLocalPos(Vector2(-35.0f, 70.0f));
	born_A->pivot = OFFSET_B;
	born_A->visible = false;
	born_A->space = SPACE::SCREEN;

	born_A_Gauge = new ObRect();
	born_A_Gauge->SetParentT(*player_UiBase);
	born_A_Gauge->SetLocalPos(Vector2(-35.0f, 70.0f));
	born_A_Gauge->scale.x = 60.0f;
	born_A_Gauge->scale.y = 0.0f;
	born_A_Gauge->pivot = OFFSET_B;
	born_A_Gauge->visible = true;
	born_A_Gauge->isFilled = true;
	born_A_Gauge->color = Color(0.5f, 0.5f, 0.5f, 0.3f);
	born_A_Gauge->space = SPACE::SCREEN;

	s = new ObImage(L"S.png");
	s->scale = Vector2(13.0f, 12.0f) * 2.5f;
	s->SetParentT(*player_UiBase);
	s->SetLocalPos(Vector2(40.0f, 120.0f));
	s->pivot = OFFSET_B;
	s->visible = true;
	s->space = SPACE::SCREEN;

	born_S = new ObImage(L"LittleBone2.bmp");
	born_S->scale = Vector2(24.0f, 24.0f) * 2.5f;
	born_S->SetParentT(*player_UiBase);
	born_S->SetLocalPos(Vector2(40.0f, 70.0f));
	born_S->pivot = OFFSET_B;
	born_S->visible = true;
	born_S->space = SPACE::SCREEN;

	born_A_Small = new ObImage(L"LittleBone1.bmp");
	born_A_Small->scale = Vector2(24.0f, 24.0f) * 1.85f;
	born_A_Small->SetParentRT(*a);
	born_A_Small->SetLocalPos(Vector2(150.0f, -52.0f));
	born_A_Small->pivot = OFFSET_B;
	born_A_Small->visible = false;
	born_A_Small->space = SPACE::SCREEN;

	born_S_Small = new ObImage(L"LittleBone2.bmp");
	born_S_Small->scale = Vector2(24.0f, 24.0f) * 1.85f;
	born_S_Small->SetParentRT(*s);
	born_S_Small->SetLocalPos(Vector2(130.0f, -52.0f));
	born_S_Small->pivot = OFFSET_B;
	born_S_Small->visible = false;
	born_S_Small->space = SPACE::SCREEN;

	space = new ObImage(L"Space.png");
	space->scale = Vector2(30.0f, 11.0f) * 2.5f;
	space->SetParentT(*player_UiBase);
	space->SetLocalPos(Vector2(-160.0f, 10.0f));
	space->pivot = OFFSET_B;
	space->visible = true;
	space->space = SPACE::SCREEN;

	//HP 이미지 피통 290
	player_Hp = new ObImage(L"Player_HealthBar.png");
	player_Hp->scale = Vector2(116.0f, 8.0f) * 2.5f;
	player_Hp->SetParentT(*player_UiBase);
	player_Hp->SetLocalPos(Vector2(-100.0f, 52.5f));
	player_Hp->pivot = OFFSET_LT;
	player_Hp->visible = true;
	player_Hp->space = SPACE::SCREEN;

	guard_BIcon = new ObImage(L"ChiefGuard_BIcon.png");
	guard_BIcon->scale = Vector2(45.0f , 45.0f) * 2.5f;
	guard_BIcon->SetParentRT(*player_UiBase);
	guard_BIcon->SetLocalPos(Vector2(-139.0f, 105.0f));
	guard_BIcon->visible = false;
	guard_BIcon->space = SPACE::SCREEN;

	guard_SIcon = new ObImage(L"ChiefGuard_BIcon.png");
	guard_SIcon->scale = Vector2(21.0f, 21.0f) * 5.5f;
	guard_SIcon->SetParentRT(*player_UiBase);
	guard_SIcon->SetLocalPos(Vector2(-139.0f, 45.0f));
	guard_SIcon->pivot = OFFSET_B;
	guard_SIcon->visible = false;
	guard_SIcon->space = SPACE::SCREEN;

	guard_Skill_A = new ObImage(L"ChiefGuard_Skill1.png");
	guard_Skill_A->scale = Vector2(24.0f, 24.0f) * 2.5f;
	guard_Skill_A->SetParentRT(*player_UiBase);
	guard_Skill_A->SetLocalPos(Vector2(-35.0f, 67.0f));
	guard_Skill_A->pivot = OFFSET_B;
	guard_Skill_A->visible = false;
	guard_Skill_A->space = SPACE::SCREEN;

	guard_Skill_S = new ObImage(L"ChiefGuard_Skill2.png");
	guard_Skill_S->scale = Vector2(24.0f, 24.0f) * 2.5f;
	guard_Skill_S->SetParentRT(*player_UiBase);
	guard_Skill_S->SetLocalPos(Vector2(40.0f, 67.0f));
	guard_Skill_S->pivot = OFFSET_B;
	guard_Skill_S->visible = false;
	guard_Skill_S->space = SPACE::SCREEN;

	sceneBlack_Top = new ObRect();
	sceneBlack_Top->scale = Vector2(1700.0f, 150.0f);
	sceneBlack_Top->SetWorldPos(Vector2(-800.0f, 500.0f));
	sceneBlack_Top->pivot = OFFSET_LT;
	sceneBlack_Top->visible = true;
	sceneBlack_Top->color = Color(0.0f, 0.0f, 0.0f, 0.5f);
	sceneBlack_Top->space = SPACE::SCREEN;

	sceneBlack_Bottom = new ObRect();
	sceneBlack_Bottom->scale = Vector2(1700.0f, 150.0f);
	sceneBlack_Bottom->SetWorldPos(Vector2(-800.0f, -350.0f));
	sceneBlack_Bottom->pivot = OFFSET_LT;
	sceneBlack_Bottom->visible = true;
	sceneBlack_Bottom->color = Color(0.0f, 0.0f, 0.0f, 0.5f);
	sceneBlack_Bottom->space = SPACE::SCREEN;
}

PlayerUi::~PlayerUi()
{
	SafeDelete(player_UiBase);
	SafeDelete(player_Skill2);
	SafeDelete(player_Sub1);
	SafeDelete(player_Sub2);
	SafeDelete(player_SubSkul);
	SafeDelete(portrait_Skul);
	SafeDelete(portrait_Skul_Small);

	SafeDelete(a);
	SafeDelete(s);
	SafeDelete(space);
	SafeDelete(player_Hp);
	SafeDelete(born_A);
	SafeDelete(born_S);

	SafeDelete(guard_BIcon);
	SafeDelete(guard_SIcon);
	SafeDelete(born_A_Small);
	SafeDelete(born_S_Small);
	SafeDelete(guard_Skill_A);
	SafeDelete(guard_Skill_S);

	SafeDelete(sceneBlack_Top);
	SafeDelete(sceneBlack_Bottom);
}

void PlayerUi::Update()
{

	player_UiBase->Update();
	player_Skill2->Update();
	player_Sub1->Update();
	player_Sub2->Update();
	player_SubSkul->Update();
	portrait_Skul->Update();

	a->Update();
	s->Update();
	space->Update();
	player_Hp->Update();

	born_A->Update();
	born_S->Update();
	born_A_Gauge->Update();

	guard_BIcon->Update();
	guard_SIcon->Update();
	portrait_Skul_Small->Update();

	born_A_Small->Update();
	born_S_Small->Update();

	guard_Skill_A->Update();
	guard_Skill_S->Update();

	sceneBlack_Top->Update();
	sceneBlack_Bottom->Update();
}

void PlayerUi::Render()
{
	player_UiBase->Render();
	player_Skill2->Render();
	player_Sub1->Render();
	player_Sub2->Render();
	portrait_Skul->Render();
	guard_BIcon->Render();
	guard_SIcon->Render();
	player_SubSkul->Render();
	born_A->Render();
	born_S->Render();

	born_A_Gauge->Render();

	born_A_Small->Render();
	born_S_Small->Render();

	guard_Skill_A->Render();
	guard_Skill_S->Render();

	a->Render();
	s->Render();
	portrait_Skul_Small->Render();
	space->Render();
	player_Hp->Render();

	sceneBlack_Top->Render();
	sceneBlack_Bottom->Render();

}

void PlayerUi::UiBlack()
{
	sceneBlack_Top = new ObRect();
	sceneBlack_Top->scale = Vector2(1700.0f, 250.0f);
	sceneBlack_Top->SetWorldPos(Vector2(-800.0f, 670.0f));
	sceneBlack_Top->pivot = OFFSET_LT;
	sceneBlack_Top->visible = false;
	sceneBlack_Top->color = Color(0.0f, 0.0f, 0.0f, 0.5f);
	sceneBlack_Top->space = SPACE::SCREEN;

	sceneBlack_Bottom = new ObRect();
	sceneBlack_Bottom->scale = Vector2(1700.0f, 250.0f);
	sceneBlack_Bottom->SetWorldPos(Vector2(-800.0f, -650.0f));
	sceneBlack_Bottom->pivot = OFFSET_LB;
	sceneBlack_Bottom->visible = false;
	sceneBlack_Bottom->color = Color(0.0f, 0.0f, 0.0f, 0.5f);
	sceneBlack_Bottom->space = SPACE::SCREEN;
}

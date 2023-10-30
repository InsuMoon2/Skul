#include "stdafx.h"

Witch::Witch()
{
	witch_Col = new ObRect();
	witch_Col->scale = Vector2(65.0f, 62.0f) * 2.3f;
	witch_Col->pivot = OFFSET_B;
	witch_Col->visible = false;
	witch_Col->isFilled = false;
	witch_Col->color = Color(0.5f, 0.0f, 0.5f, 1.0f);

	Cage_Witch = new ObImage(L"Idle_Cage_0.png");
	Cage_Witch->scale = Vector2(65.0f, 62.0f) * 2.3f;
	Cage_Witch->pivot = OFFSET_B;
	Cage_Witch->visible = true;
	Cage_Witch->reverseLR = true;

	witch_Idle = new ObImage(L"Witch_Idle.png");
	witch_Idle->scale = Vector2(65.0f, 90.0f) * 2.3f;
	witch_Idle->pivot = OFFSET_B;
	witch_Idle->visible = false;
	witch_Idle->maxFrame = Int2(5,1);
	witch_Idle->ChangeAnim(ANIMSTATE::LOOP, 0.2f);

	witch_Poly = new ObImage(L"Witch_Poly.png");
	witch_Poly->scale = Vector2(65.0f, 88.0f) * 2.8f;
	witch_Poly->pivot = OFFSET_B;
	witch_Poly->visible = false;
	witch_Poly->reverseLR = true;
	witch_Poly->maxFrame = Int2(20, 1);
	witch_Poly->ChangeAnim(ANIMSTATE::ONCE, 0.1f);

	cat_Idle = new ObImage(L"Witch_Cat_Idle.png");
	cat_Idle->scale = Vector2(270.0f / 6.0f, 37.0f) * 2.3f;
	cat_Idle->pivot = OFFSET_B;
	cat_Idle->visible = false;
	cat_Idle->maxFrame = Int2(6, 1);
	cat_Idle->ChangeAnim(ANIMSTATE::LOOP, 0.2f);

	cat_Walk = new ObImage(L"Witch_Cat_walk.png");
	cat_Walk->scale = Vector2(288.0f / 6.0f, 31.0f) * 2.3f;
	cat_Walk->pivot = OFFSET_B;
	cat_Walk->visible = false;
	cat_Walk->reverseLR = true;
	cat_Walk->maxFrame = Int2(6, 1);
	cat_Walk->ChangeAnim(ANIMSTATE::LOOP, 0.2f);

	witch_State = WITCHSTATE::CAGE;
}

void Witch::Release()
{
	SafeDelete(witch_Col);
	SafeDelete(Cage_Witch);
	SafeDelete(witch_Idle);
	SafeDelete(witch_Poly);
	SafeDelete(cat_Idle);
	SafeDelete(cat_Walk);
}

void Witch::Update()
{
	switch (witch_State)
	{
	case WITCHSTATE::CAGE:
		Cage();
		break;
	case WITCHSTATE::IDLE:
		Idle();
		break;
	case WITCHSTATE::POLY:
		Poly();
		break;
	case WITCHSTATE::CAT_IDLE:
		Cat_Idle();
		break;
	case WITCHSTATE::CAT_WALK:
		Cat_Walk();
		break;
	}

	witch_Col->Update();
	Cage_Witch->Update();
	witch_Idle->Update();
	witch_Poly->Update();
	cat_Idle->Update();
	cat_Walk->Update();
}

void Witch::Render()
{
	witch_Col->Render();
	Cage_Witch->Render();
	witch_Idle->Render();
	witch_Poly->Render();
	cat_Idle->Render();
	cat_Walk->Render();
}

void Witch::Cage()
{
	Cage_Witch->visible = true;
	witch_Col->scale = Vector2(65.0f, 62.0f) * 2.3f;

	//Cage -> Idle
}

void Witch::Idle()
{
	Cage_Witch->visible = false;
	witch_Idle->visible = true;
	witch_Col->scale = Vector2(310.0f / 5.0f, 90.0f) * 2.3f;

	//Idle -> Cate_Idle

}

void Witch::Poly()
{
	Cage_Witch->visible = false;
	witch_Idle->visible = false;
	cat_Idle->visible = false;

	witch_Poly->visible = true;

}

void Witch::Cat_Idle()
{
	Cage_Witch->visible = false;
	witch_Idle->visible = false;
	cat_Walk->visible = false;
	cat_Idle->visible = true;

	witch_Col->scale = Vector2(270.0f / 6.0f, 37.0f) * 2.3f;

	//Cat_Idle -> Cat_Walk
}

void Witch::Cat_Walk()
{
	Cage_Witch->visible = false;
	cat_Idle->visible = false;
	witch_Poly->visible = false;
	cat_Walk->visible = true;

	//Cat_Walk -> Cat_Idle
}

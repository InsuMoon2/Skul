#include "stdafx.h"

Monster::Monster()
{
	monster_Col = new ObRect();
	monster_Col->scale = Vector2(204.0f / 6.0f, 112.0f / 2.0f) * 2.5f;
	monster_Col->isFilled = false;
	monster_Col->visible = false;
	monster_Col->pivot = OFFSET_B;
	monster_Col->collider = COLLIDER::RECT;

	monster_HpBar = new ObImage(L"EnemyHealthBar_Frame_img.png");
	monster_HpBar->scale = Vector2(50.0f, 5.0f) * 2.2f;
	monster_HpBar->SetParentRT(*monster_Col);
	monster_HpBar->SetLocalPos(Vector2(-54.0f , -15.0f));
	monster_HpBar->pivot = OFFSET_LT;
	monster_HpBar->visible = true;

	monster_Hp = new ObImage(L"EnemyHealthBar.png");
	monster_Hp->scale = Vector2(1.0f * 100.0f, 5.0f * 1.5f);
	monster_Hp->SetParentRT(*monster_Col);
	monster_Hp->SetLocalPos(Vector2(-49.0f, -16.0f));
	monster_Hp->pivot = OFFSET_LT;
	monster_Hp->visible = true;
	
	monster_Recognize = new ObRect();
	monster_Recognize->scale = Vector2(500.0f, 350.0f);
	monster_Recognize->SetParentT(*monster_Col);
	monster_Recognize->isFilled = false;
	monster_Recognize->visible = false;
	monster_Recognize->pivot = OFFSET_B;
	monster_Recognize->color = Color(1.0f, 0.0f, 0.1f, 1.0f);
	monster_Recognize->collider = COLLIDER::RECT;

	monster_Apperance = new ObImage(L"Enemy_Appearance.png");
	monster_Apperance->scale = Vector2(1408.0f / 11.0f, 128.0f) * 1.7f;
	monster_Apperance->SetParentRT(*monster_Col);
	monster_Apperance->pivot = OFFSET_LT;
	monster_Apperance->maxFrame = Int2(11,1);
	monster_Apperance->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	monster_Apperance->visible = false;

	monster_Dead = new ObImage(L"Enemy_Dead.png");
	monster_Dead->scale = Vector2(768.0f / 6.0f, 128.0f) * 1.7f;
	monster_Dead->SetParentRT(*monster_Col);
	monster_Dead->pivot = OFFSET_LT;
	monster_Dead->maxFrame = Int2(6, 1);
	monster_Dead->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	monster_Dead->visible = false;

	monster_State = MonsterState::IDLE;
}

Monster::~Monster()
{
	SafeDelete(monster_Recognize);
	SafeDelete(monster_Col);
	SafeDelete(monster_HpBar);
	SafeDelete(monster_Hp);
	SafeDelete(monster_Apperance);
	SafeDelete(monster_Dead);
}

void Monster::Update()
{

	monster_Recognize->Update();
	monster_Col->Update();
	monster_HpBar->Update();
	monster_Hp->Update();
	monster_Apperance->Update();
	monster_Dead->Update();
}

void Monster::Render()
{
	monster_Recognize->Render();
	monster_Col->Render();
	monster_HpBar->Render();
	monster_Hp->Render();
	monster_Apperance->Render();
	monster_Dead->Render();
}



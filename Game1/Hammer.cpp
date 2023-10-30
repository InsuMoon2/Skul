#include "stdafx.h"

Hammer::Hammer()
{
	Get_MonsterType() = MonsterType::M_Hammer;

	monster_Dead->scale * 1.3f;
	monster_Dead->SetLocalPos(Vector2(-120.0f, 170.0f));

	hammer_Idle = new ObImage(L"big_knight_idle.png");
	hammer_Idle->scale = Vector2(640.0f / 4.0f, 160.0f) * 2.5f;
	hammer_Idle->SetParentRT(*monster_Col);
	hammer_Idle->SetLocalPosY(-82.0f);
	hammer_Idle->maxFrame = Int2(4, 1);
	hammer_Idle->pivot = OFFSET_B;
	hammer_Idle->visible = true;

	hammer_Move = new ObImage(L"big_knight_move.png");
	hammer_Move->scale = Vector2(1280.0f / 8.0f, 160.0f) * 2.5f;
	hammer_Move->SetParentRT(*monster_Col);
	hammer_Move->SetLocalPosY(-82.0f);
	hammer_Move->maxFrame = Int2(8, 1);
	hammer_Move->pivot = OFFSET_B;
	hammer_Move->visible = false;

	hammer_Attack1 = new ObImage(L"big_knight_attacka.png");
	hammer_Attack1->scale = Vector2(3200.0f / 20.0f, 160.0f) * 2.5f;
	hammer_Attack1->SetParentRT(*monster_Col);
	hammer_Attack1->SetLocalPosY(-82.0f);
	hammer_Attack1->maxFrame = Int2(20, 1);
	hammer_Attack1->pivot = OFFSET_B;
	hammer_Attack1->visible = false;

	hammer_Attack2 = new ObImage(L"big_knight_attackb.png");
	hammer_Attack2->scale = Vector2(400.0f, 160.0f * 2.5f);
	hammer_Attack2->SetParentRT(*monster_Col);
	hammer_Attack2->SetLocalPosY(-82.0f);
	hammer_Attack2->maxFrame = Int2(2, 1);
	hammer_Attack2->pivot = OFFSET_B;
	//hammer_Attack2->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	hammer_Attack2->visible = false;

	hammer_Die = new ObImage(L"big_knight_die.png");
	hammer_Die->scale = Vector2(160.0f, 160.0f) * 2.5f;
	hammer_Die->SetParentRT(*monster_Col);
	hammer_Die->SetLocalPosY(-82.0f);
	hammer_Die->pivot = OFFSET_B;
	hammer_Die->visible = false;

	hammer_Attack1_Col = new ObRect();
	hammer_Attack1_Col->scale = Vector2(200.0f, 200.0f);
	hammer_Attack1_Col->SetParentT(*monster_Col);
	hammer_Attack1_Col->pivot = OFFSET_B;
	hammer_Attack1_Col->color = Color(0.0f, 1.0f, 0.3f, 1.0f);
	hammer_Attack1_Col->isFilled = false;
	hammer_Attack1_Col->visible = true;
	hammer_Attack1_Col->colOnOff = false;
	hammer_Attack1_Col->collider = COLLIDER::RECT;

	hammer_Attack2_Col = new ObRect();
	hammer_Attack2_Col->scale = Vector2(200.0f, 200.0f);
	hammer_Attack2_Col->SetParentT(*monster_Col);
	hammer_Attack2_Col->pivot = OFFSET_B;
	hammer_Attack2_Col->color = Color(0.0f, 1.0f, 0.3f, 1.0f);
	hammer_Attack2_Col->isFilled = false;
	hammer_Attack2_Col->visible = false;
	hammer_Attack2_Col->colOnOff = false;
	hammer_Attack2_Col->collider = COLLIDER::RECT;

	hammerDir.x = 1.0f;

	Get_MonsterState() = MonsterState::MOVE;

	//Sound
	SOUND->AddSound("MAA_Atk_Ready.wav", "Hammer_Atk1", false);
	SOUND->AddSound("MAA_Tackle_Ready.wav", "Hammer_Atk2", false);
}

Hammer::~Hammer()
{
	SafeDelete(hammer_Idle);
	SafeDelete(hammer_Move);
	SafeDelete(hammer_Attack1);
	SafeDelete(hammer_Attack1_Col);
	SafeDelete(hammer_Attack2);
	SafeDelete(hammer_Attack2_Col);
	SafeDelete(hammer_Die);
}

void Hammer::Update()
{
	Monster::Update();

	switch (Get_MonsterState())
	{
	case MonsterState::IDLE:
		H_Idle();
		break;
	case  MonsterState::MOVE:
		H_Move();
		break;
	case  MonsterState::ATTACK:
		H_Attack1();
		break;
	case  MonsterState::ATTACK2:
		H_Attack2();
		break;
	case  MonsterState::DIE:
		H_Die();
		break;
	}

	if (reverse)
	{
		hammer_Attack1_Col->SetLocalPosX(-70.0f);
		hammer_Attack2_Col->SetLocalPosX(-30.0f);
		hammer_Idle->reverseLR = true;
		hammer_Move->reverseLR = true;
		hammer_Attack1->reverseLR = true;
		hammer_Attack2->reverseLR = true;
		hammer_Die->reverseLR = true;
	}

	else if (!reverse)
	{
		hammer_Attack1_Col->SetLocalPosX(70.0f);
		hammer_Attack2_Col->SetLocalPosX(30.0f);
		hammer_Idle->reverseLR = false;
		hammer_Move->reverseLR = false;
		hammer_Attack1->reverseLR = false;
		hammer_Attack2->reverseLR = false;
		hammer_Die->reverseLR = false;
	}

	hammer_Idle->Update();
	hammer_Move->Update();
	hammer_Attack1->Update();
	hammer_Attack2->Update();
	hammer_Attack1_Col->Update();
	hammer_Attack2_Col->Update();
	hammer_Die->Update();

}

void Hammer::Render()
{
	hammer_Idle->Render();
	hammer_Move->Render();
	hammer_Attack1->Render();
	hammer_Attack2->Render();
	hammer_Attack1_Col->Render();
	hammer_Attack2_Col->Render();
	hammer_Die->Render();

	Monster::Render();
}

void Hammer::H_Idle()
{
	hammerTime += DELTA;
	H_AllInvisible();

	hammer_Attack1->frame.x = 0;
	hammer_Attack2->frame.x = 0;

	h_attack_Time2 = 0.0f;
	h_attack1_Time = 0.0f;

	hammer_Idle->visible = true;
	hammer_Attack1_Col->colOnOff = true;
	hammer_Attack2_Col->colOnOff = true;
	hammer_Idle->ChangeAnim(ANIMSTATE::LOOP, 0.25f);

	if (hammerTime > 4.5f)
	{
		Get_MonsterState() = MonsterState::MOVE;
		hammerTime = 0.0f;
		//hammerDir.x = 1.0f;
	}

	//cout << hammerDir.x << endl;
}

void Hammer::H_Move()
{
	H_AllInvisible();

	hammer_Attack1->frame.x = 0;
	hammer_Attack2->frame.x = 0;

	hammer_Attack1_Col->colOnOff = true;
	hammer_Attack2_Col->colOnOff = true;

	h_attack_Time2 = 0.0f;

	hammer_Move->visible = true;
	hammer_Move->ChangeAnim(ANIMSTATE::LOOP, 0.25f);

	hammerTime2 += DELTA;

	if (reverse)
	{
		monster_Col->MoveWorldPos(LEFT * 120.0f * DELTA);
	}

	else if (!reverse)
	{
		monster_Col->MoveWorldPos(RIGHT * 120.0f * DELTA);
	}

	if (hammerTime2 >= 4.5f)
	{
		Get_MonsterState() = MonsterState::IDLE;
		hammerTime2 = 0.0f;
		//reverse = !reverse;
		//hammerDir.x *= -1.0f;
	}

}

void Hammer::H_Attack1()
{
	H_AllInvisible();
	hammer_Attack1->visible = true;
	hammer_Attack1_Col->visible = false;
	hammer_Attack2->frame.x = 0;
	hammer_Attack1->ChangeAnim(ANIMSTATE::LOOP, 0.05f);

	if (hammer_Attack1->frame.x >= 19.0f)
	{
		hammer_Attack1->ChangeAnim(ANIMSTATE::STOP, 0.0f);
		Get_MonsterState() = MonsterState::MOVE;
		h_attack_Time = 0.0f;
	}

	h_attack1_Time += DELTA;
}

void Hammer::H_Attack2()
{
	H_AllInvisible();
	hammer_Attack2->visible = true;
	hammer_Attack2_Col->visible = false;
	hammer_Attack1->frame.x = 0;
	hammer_Attack2->ChangeAnim(ANIMSTATE::LOOP, 0.25f);

	h_attack_Time2 += DELTA;

	if (hammer_Attack2->frame.x >= 1.0f)
	{
		hammer_Attack2->ChangeAnim(ANIMSTATE::STOP, 0.0f);

		if (reverse)
		{
			monster_Col->MoveWorldPos(LEFT * 800.0f * DELTA);
		}

		else if (!reverse)
		{
			monster_Col->MoveWorldPos(RIGHT * 800.0f * DELTA);
		}
	}

	
}

void Hammer::H_Die()
{
	H_AllInvisible();
	hammer_Die->visible = true;

	d_time += DELTA;
	monster_HpBar->visible = false;
	monster_Hp->visible = false;
	monster_Col->visible = false;
	monster_Recognize->visible = false;

	hammer_Attack1_Col->visible = false;
	hammer_Attack2_Col->visible = false;

	if (d_time > 2.0f)
	{
		hammer_Die->visible = false;
		monster_Dead->visible = true;
	}

	if (d_time > 2.8f)
	{
		monster_Dead->visible = false;
	}

}

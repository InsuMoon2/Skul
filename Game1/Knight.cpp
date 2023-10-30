#include "stdafx.h"

Knight::Knight()
{
	Get_MonsterType() = MonsterType::M_Knight;

	monster_Apperance->SetLocalPos(Vector2(-110.0f, 160.0f));
	monster_Dead->SetLocalPos(Vector2(-110.0f, 160.0f));

	knight_Idle = new ObImage(L"Knight_Idle.bmp");
	knight_Idle->scale = Vector2(204.0f/  6.0f, 102.0f / 2.0f) * 2.5f;
	knight_Idle->SetParentRT(*monster_Col);
	knight_Idle->maxFrame = Int2(6,2);
	knight_Idle->pivot = OFFSET_B;
	knight_Idle->visible = true;

	knight_Walk = new ObImage(L"Knight_Walk.bmp");
	knight_Walk->scale = Vector2(416.0f / 8.0f, 102.0f / 2.0f) * 2.5f;;
	knight_Walk->SetParentRT(*monster_Col);
	knight_Walk->maxFrame = Int2(8,2);
	knight_Walk->pivot = OFFSET_B;
	knight_Walk->visible = false;

	knight_Attack = new ObImage(L"Knight_Attack_Start.bmp");
	knight_Attack->scale = Vector2(78.0f , 102.0f / 2.0f) * 2.5f;
	knight_Attack->SetParentRT(*monster_Col);
	knight_Attack->maxFrame = Int2(1,2);
	knight_Attack->pivot = OFFSET_B;
	knight_Attack->visible = false;

	knight_Attack2 = new ObImage(L"Knight_Attack_ing.bmp");
	knight_Attack2->scale = Vector2(234.0f / 3.0f, 102.0f / 2.0f) * 2.5f;
	knight_Attack2->SetParentRT(*monster_Col);
	knight_Attack2->maxFrame = Int2(3, 2);
	knight_Attack2->pivot = OFFSET_B;
	knight_Attack2->visible = false;

	knight_Hit = new ObImage(L"Knight_Hit.bmp");
	knight_Hit->scale = Vector2(92.0f / 2.0f, 102.0f / 2.0f) * 2.5f;
	knight_Hit->SetParentRT(*monster_Col);
	knight_Hit->maxFrame = Int2(2,2);
	knight_Hit->pivot = OFFSET_B;
	knight_Hit->visible = false;

	knight_Die = new ObImage(L"Knight_Die.bmp");
	knight_Die->scale = Vector2(92.0f / 2.0f * 2.5f * 1.2f , 34.0f * 2.0f);
	knight_Die->SetParentRT(*monster_Col);
	knight_Die->SetLocalPosY(-10.0f);
	knight_Die->pivot = OFFSET_B;
	knight_Die->visible = false;

	knight_AttackCol = new ObRect();
	knight_AttackCol->scale = Vector2(80.0f, 100.0f);
	knight_AttackCol->SetParentT(*monster_Col);
	knight_AttackCol->pivot = OFFSET_B;
	knight_AttackCol->color = Color(0.0f, 1.0f, 0.3f, 1.0f);
	knight_AttackCol->isFilled = false;
	knight_AttackCol->visible = false;
	knight_AttackCol->colOnOff = false;
	knight_AttackCol->collider = COLLIDER::RECT;

	time = 0.5f;

	SOUND->AddSound("Recruit_Atk_Ready01.wav", "Knight_Atk1", false);
	SOUND->AddSound("Recruit_Atk_Ready04.wav", "Knight_Atk2", false);
}

Knight::~Knight()
{
	SafeDelete(knight_Idle);
	SafeDelete(knight_Walk);
	SafeDelete(knight_Attack);
	SafeDelete(knight_Attack2);
	SafeDelete(knight_Hit);
	SafeDelete(knight_Die);
	SafeDelete(knight_AttackCol);
}

void Knight::Update()
{
	Monster::Update();

	switch(Get_MonsterState())
	{
	case MonsterState::IDLE:
		K_Idle();
		break;
	case  MonsterState::MOVE:
		K_Move();
		break;
	case  MonsterState::ATTACK:
		K_Attack();
		break;
	case  MonsterState::ATTACK2:
		K_Attack2();
		break;
	case  MonsterState::HIT:
		K_Hit();
		break;
	case  MonsterState::DIE:
		K_Die();
		break;
	}

	if (monster_Apperance->frame.x < 10)
	{
		monster_Hp->visible = false;
		monster_HpBar->visible = false;
	}

	else
	{
		monster_Hp->visible = true;
		monster_HpBar->visible = true;
	}

	knight_Idle->Update();
	knight_Walk->Update();
	knight_Attack->Update();
	knight_Attack2->Update();
	knight_Hit->Update();
	knight_Die->Update();
	knight_AttackCol->Update();
}

void Knight::Render()
{
	Monster::Render();

	knight_Idle->Render();
	knight_Walk->Render();
	knight_Attack->Render();
	knight_Attack2->Render();
	knight_Hit->Render();
	knight_Die->Render();
	knight_AttackCol->Render();
}

void Knight::K_Idle()
{
	K_AllInvisible();

	monster_Apperance->visible = true;

	if (monster_Apperance->frame.x >= 10.0f)
	{
		monster_Apperance->visible = false;
		app_Check  = true;
	}

	if (app_Check)
	{
		attack_Time = 0.0f;
		knight_Attack->frame.x = 0;
		knight_Attack2->frame.x = 0;
		knight_AttackCol->visible = false;
		knight_AttackCol->colOnOff = true;
		knight_Idle->visible = true;
		knight_Idle->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	}

	//Idle -> Move
	//Scene03
	
	//Idle -> Attack
	//Scene03

	//Idle -> Hit
	//Scene03에서

	//Idle -> Die
}

void Knight::K_Move()
{	
	K_AllInvisible();

	attack_Time = 0.0f;
	knight_Attack->frame.x = 0;
	knight_Attack2->frame.x = 0;
	knight_AttackCol->visible = false;
	knight_AttackCol->colOnOff = true;

	knight_Walk->visible = true;
	knight_Walk->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	//Move -> attack

	//Move -> Hit

	//Move -> Die
}

void Knight::K_Attack()
{
	attack_Time += DELTA;

	knight_Attack2->frame.x = 0.0f;
	//cout << attack_Time << endl;

	if (!hit)
	{
		K_AllInvisible();
		//여기서 계속 들어오는거밖에 없음 이걸 꺼보자
		//knight_AttackCol->colOnOff = true;

		knight_Attack->visible = true;
		knight_Attack->ChangeAnim(ANIMSTATE::LOOP, 0.2f);
	}
}

void Knight::K_Attack2()
{
	//attack_Time = 0.0f;
	//cout << "Attack2" << endl;

	if (!hit)
	{
		K_AllInvisible();
		//knight_AttackCol->colOnOff = true;
		knight_AttackCol->visible = false;

		knight_Attack2->visible = true;
		knight_Attack2->ChangeAnim(ANIMSTATE::LOOP, 0.2f);

		if (knight_Attack2->frame.x >= 2.0f)
		{
			attack_Time = 0.0f;
			Get_MonsterState() = MonsterState::MOVE;

			knight_Attack2->visible = false;
			knight_Attack2->ChangeAnim(ANIMSTATE::STOP, 0.0f);
		}
	}
}

void Knight::K_Hit()
{
	if (hit)
	{
		K_AllInvisible();
		knight_Hit->visible = true;
		knight_Hit->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		attack_Time = 0.0f;

		if (knight_Hit->frame.x == 1)
		{
			knight_Hit->ChangeAnim(ANIMSTATE::STOP, 0);
			h_time -= DELTA;

			//cout << h_time << endl;

			if (h_time < 0.0f)
			{
				//cout << "111111111111111" << endl;
				Get_MonsterState() = MonsterState::IDLE;
				h_time = 0.5f;
				knight_Attack->frame.x = 0;
				hit = false;
			}
			//hit = false;

		}
	}

	//if (knight_Hit->frame.x == 1)
	//{
	//	hit = false;
	//}

}

void Knight::K_Die()
{
	//GG
	d_time += DELTA;
	
	K_AllInvisible();
	monster_HpBar->visible = false;
	monster_Hp->visible = false;
	knight_Die->visible = true;
	monster_Col->visible = false;
	monster_Recognize->visible = false;

	if (d_time > 2.0f)
	{
		knight_Die->visible = false;
		monster_Dead->visible = true;
	}

	if (d_time > 2.8f)
	{
		monster_Dead->visible = false;
	}

}

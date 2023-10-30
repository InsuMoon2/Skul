#include "stdafx.h"

BigEnt::BigEnt()
{	
	Get_MonsterType() = MonsterType::M_BigEnt;

	monster_Dead->scale * 1.2f;
	monster_Dead->SetLocalPos(Vector2(-110.0f, 160.0f));

	bigEnt_Recog = new ObRect();
	bigEnt_Recog->scale = Vector2(170.0f , 197.0f) * 5.0f;
	bigEnt_Recog->SetParentRT(*monster_Col);
	bigEnt_Recog->SetLocalPos(Vector2(-600.0f, 600.0f));
	bigEnt_Recog->visible = false;
	bigEnt_Recog->isFilled = false;
	bigEnt_Recog->pivot = OFFSET_LT;
	bigEnt_Recog->collider = COLLIDER::RECT;
	bigEnt_Recog->color = Color(0.0f, 1.0f, 0.7f, 1.0f);

	bigEnt_Idle = new ObImage(L"BigEnt_Idle.bmp");
	bigEnt_Idle->scale = Vector2(115.0f, 114.0f) * 3.0f;
	bigEnt_Idle->SetParentRT(*monster_Col);
	bigEnt_Idle->SetLocalPos(Vector2(0.0f, -25.0f));
	bigEnt_Idle->maxFrame = Int2(5, 1);
	bigEnt_Idle->pivot = OFFSET_B;
	bigEnt_Idle->visible = true;
	//bigEnt_Idle->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	bigEnt_Attack1 = new ObImage(L"BigEnt_Attack1.bmp");
	bigEnt_Attack1->scale = Vector2(115.0f, 114.0f) * 3.0f;
	bigEnt_Attack1->SetParentRT(*monster_Col);
	bigEnt_Attack1->SetLocalPos(Vector2(0.0f, -25.0f));
	bigEnt_Attack1->maxFrame = Int2(7, 1);
	bigEnt_Attack1->pivot = OFFSET_B;
	bigEnt_Attack1->visible = false;

	bigEnt_Attack1_Effect = new ObImage(L"BigEnt_Attack1_Effect.bmp");
	bigEnt_Attack1_Effect->scale = Vector2(4800.0f / 16.0f, 100.0f);
	bigEnt_Attack1_Effect->SetParentRT(*monster_Col);
	bigEnt_Attack1_Effect->SetLocalPos(Vector2(0.0f, -25.0f));
	bigEnt_Attack1_Effect->maxFrame = Int2(16, 1);
	bigEnt_Attack1_Effect->pivot = OFFSET_B;
	bigEnt_Attack1_Effect->visible = false;

	for (int i = 0; i < BMAX; i++)
	{
		bullet_Col[i] = new ObCircle();
		bullet_Col[i]->scale = Vector2(10.0f, 10.0f) * 5.0f;
		bullet_Col[i]->SetParentRT(*monster_Col);
		bullet_Col[i]->SetLocalPos(Vector2(5.0f, 50.0f));
		bullet_Col[i]->pivot = OFFSET_B;
		bullet_Col[i]->visible = false;
		bullet_Col[i]->isFilled = false;
		bullet_Col[i]->collider = COLLIDER::CIRCLE;

		bigEnt_Attack2_Bullet[i] = new ObImage(L"BigEnt_bullet.bmp");
		bigEnt_Attack2_Bullet[i]->scale = Vector2(10.0f, 10.0f) * 5.0f;
		bigEnt_Attack2_Bullet[i]->SetParentRT(*bullet_Col[i]);
		//bigEnt_Attack2_Bullet[i]->SetLocalPos(Vector2(5.0f, 50.0f));
		bigEnt_Attack2_Bullet[i]->pivot = OFFSET_B;
		bigEnt_Attack2_Bullet[i]->visible = false;
	}
	

	bigEnt_Attack2 = new ObImage(L"attack2.png");
	bigEnt_Attack2->scale = Vector2(794.0f / 4.0f, 210.0f) * 3.0f;
	bigEnt_Attack2->SetParentRT(*monster_Col);
	bigEnt_Attack2->SetLocalPos(Vector2(-10.0f, -165.0f));
	bigEnt_Attack2->maxFrame = Int2(4,1);
	bigEnt_Attack2->pivot = OFFSET_B;
	bigEnt_Attack2->visible = false;

	bigEnt_Die = new ObImage(L"BigEnt_Dead.bmp");
	bigEnt_Die->scale = Vector2(115.0f, 114.0f) * 3.0f;
	bigEnt_Die->SetParentRT(*monster_Col);
	bigEnt_Die->SetLocalPos(Vector2(0.0f, -25.0f));
	bigEnt_Die->pivot = OFFSET_B;
	bigEnt_Die->visible = false;
}

BigEnt::~BigEnt()
{
	SafeDelete(bigEnt_Idle);
	SafeDelete(bigEnt_Attack1);
	SafeDelete(bigEnt_Attack2);
	SafeDelete(bigEnt_Recog);
	SafeDelete(bigEnt_Die);
	SafeDelete(bigEnt_Attack1_Effect);

	for (int i = 0; i < BMAX; i++)
	{
		SafeDelete(bigEnt_Attack2_Bullet[i]);
		SafeDelete(bullet_Col[i]);
	}
}

void BigEnt::Update()
{
	Monster::Update();

	switch (Get_MonsterState())
	{
	case MonsterState::IDLE:
		E_Idle();
		break;
	case  MonsterState::ATTACK:
		E_Attack1();
		break;
	case  MonsterState::ATTACK2:
		E_Attack2();
		break;
	case  MonsterState::HIT:
		break;
	case  MonsterState::DIE:
		E_Die();
		break;
	
	}

	for (int i = 0; i < BMAX; i++)
	{
		Vector2 bul4 = UP + Vector2(0.7f, 0.0f);
		Vector2 bul5 = UP + Vector2(-0.7f, 0.0f);
		Vector2 bul6 = DOWN + Vector2(0.7f, 0.0f);
		Vector2 bul7 = DOWN + Vector2(-0.7f, 0.0f);

		if (bigEnt_Attack2_Bullet[i]->visible)
		{
			bullet_Col[0]->MoveWorldPos(UP * 80.0f * DELTA);
			bullet_Col[1]->MoveWorldPos(DOWN * 80.0f * DELTA);
			bullet_Col[2]->MoveWorldPos(LEFT * 80.0f * DELTA);
			bullet_Col[3]->MoveWorldPos(RIGHT * 80.0f * DELTA);
			bullet_Col[4]->MoveWorldPos(bul4 * 80.0f * DELTA);
			bullet_Col[5]->MoveWorldPos(bul5 * 80.0f * DELTA);
			bullet_Col[6]->MoveWorldPos(bul6 * 80.0f * DELTA);
			bullet_Col[7]->MoveWorldPos(bul7 * 80.0f * DELTA);
		}
	}

	bigEnt_Recog->Update();
	bigEnt_Idle->Update();
	bigEnt_Attack1->Update();
	bigEnt_Attack1_Effect->Update();
	bigEnt_Attack2->Update();

	for (int i = 0; i < BMAX; i++)
	{
		bullet_Col[i]->Update();
		bigEnt_Attack2_Bullet[i]->Update();
	}

	bigEnt_Die->Update();
}

void BigEnt::Render()
{
	bigEnt_Idle->Render();
	bigEnt_Attack1->Render();
	bigEnt_Attack1_Effect->Render();
	bigEnt_Attack2->Render();

	for (int i = 0; i < BMAX; i++)
	{
		bigEnt_Attack2_Bullet[i]->Render();
		bullet_Col[i]->Render();
	}

	bigEnt_Recog->Render();
	bigEnt_Die->Render();
	Monster::Render();
}

void BigEnt::E_Idle()
{
	E_AllInvisible();
	bigEnt_Idle->visible = true;
	bigEnt_Idle->ChangeAnim(ANIMSTATE::LOOP, 0.2f);

}

void BigEnt::E_Attack1()
{
	E_AllInvisible();
	bigEnt_Attack1->visible = true;
	bigEnt_Attack1->ChangeAnim(ANIMSTATE::LOOP, 0.25f);

	//if (bigEnt_Attack1->frame.x >= 5)
	//{
	//	bigEnt_Attack1->ChangeAnim(ANIMSTATE::STOP, 0);
	//}

	bigEnt_Attack1_Effect->visible = false;
	bigEnt_Attack1_Effect->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
}

void BigEnt::E_Attack2()
{
	if (!attack2_Checking)
	{
		//E_AllInvisible();
		//bigEnt_Idle->visible = true;
		//bigEnt_Idle->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

		attack2_time += DELTA;
		
		if (attack2_time > 3.5f)
		{
			attack2_Checking = true;
			attack2_time = 0.0f;
		}
		
		if (attack2_Checking)
		{
			E_AllInvisible();
			bigEnt_Attack2->visible = true;
			bigEnt_Attack2->ChangeAnim(ANIMSTATE::ONCE, 0.3f);
			attack2_Checking = false;
			
			for (int i = 0; i < BMAX; i++)
			{
				bullet_Col[i]->SetLocalPos(Vector2(5.0f, 50.0f));
				bullet_Col[i]->visible = false;
				bullet_Col[i]->colOnOff = true;
				bigEnt_Attack2_Bullet[i]->visible = true;
			}
		}
	}
	
	
}

void BigEnt::E_Die()
{
	E_AllInvisible();
	bigEnt_Die->visible = true;

	d_time += DELTA;
	monster_HpBar->visible = false;
	monster_Hp->visible = false;
	monster_Col->visible = false;
	monster_Recognize->visible = false;

	if (d_time > 2.0f)
	{
		monster_Dead->visible = true;
		bigEnt_Die->visible = false;
	}

	if (d_time > 2.8f)
	{
		monster_Dead->visible = false;
	}
}

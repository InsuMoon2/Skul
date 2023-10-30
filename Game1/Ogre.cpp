#include "stdafx.h"

Ogre::Ogre()
{
	Get_MonsterType() = MonsterType::M_Ogre;
	
	Ogre_Idle = new ObImage(L"Ogre_Idle.png");
	Ogre_Idle->scale = Vector2(552.0f / 6.0f, 88.0f) * 2.5f;
	Ogre_Idle->SetParentRT(*monster_Col);
	Ogre_Idle->maxFrame = Int2(6, 1);
	Ogre_Idle->pivot = OFFSET_B;
	Ogre_Idle->visible = true;
	Ogre_Idle->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	Ogre_Idle->reverseLR = true;

	Ogre_Walk = new ObImage(L"Ogre_Walk.png");
	Ogre_Walk->scale = Vector2(808.0f / 8.0f, 90.0f) * 2.5f;
	Ogre_Walk->SetParentRT(*monster_Col);
	Ogre_Walk->SetLocalPosY(-10.0f);
	Ogre_Walk->maxFrame = Int2(8, 1);
	Ogre_Walk->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	Ogre_Walk->pivot = OFFSET_B;
	Ogre_Walk->visible = false;
	Ogre_Walk->reverseLR = true;

	Ogre_Attack = new ObImage(L"Ogre_Attack.png");
	Ogre_Attack->scale = Vector2(819.0f / 7.0f, 105.0f) * 2.5f;
	Ogre_Attack->SetParentRT(*monster_Col);
	Ogre_Attack->SetLocalPosY(-10.0f);
	Ogre_Attack->maxFrame = Int2(7, 1);
	Ogre_Attack->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	Ogre_Attack->pivot = OFFSET_B;
	Ogre_Attack->visible = false;
	Ogre_Attack->reverseLR = true;

	Ogre_Hit = new ObImage(L"Hit1_0.png");
	Ogre_Hit->scale = Vector2(121.0f , 85.0f) * 2.5f;
	Ogre_Hit->SetParentRT(*monster_Col);
	Ogre_Hit->pivot = OFFSET_B;
	Ogre_Hit->visible = false;
	Ogre_Hit->reverseLR = true;

	Ogre_Die = new ObImage(L"Ogre_Die.png");
	Ogre_Die->scale = Vector2(1554.0f / 14.0f, 79.0f) * 2.5f;
	Ogre_Die->SetParentRT(*monster_Col);
	Ogre_Die->maxFrame = Int2(14, 1);
	Ogre_Die->ChangeAnim(ANIMSTATE::ONCE, 0.2f);
	Ogre_Die->pivot = OFFSET_B;
	Ogre_Die->visible = false;
	Ogre_Die->reverseLR = true;

	Ogre_AttackCol = new ObRect();
	Ogre_AttackCol->scale = Vector2(145.0f, 260.0f);
	Ogre_AttackCol->SetParentT(*monster_Col);
	Ogre_AttackCol->pivot = OFFSET_B;
	Ogre_AttackCol->color = Color(0.0f, 1.0f, 0.3f, 1.0f);
	Ogre_AttackCol->isFilled = false;
	Ogre_AttackCol->visible = false;
	Ogre_AttackCol->colOnOff = true;
	Ogre_AttackCol->collider = COLLIDER::RECT;

	//몬갈 Dead Effect
	mongal_DeadEffect1 = new ObImage(L"mongal_Dead1.png");
	mongal_DeadEffect1->scale = Vector2(1602.0f / 9.0f, 110.0f) * 1.2f;
	mongal_DeadEffect1->SetParentRT(*monster_Col);
	mongal_DeadEffect1->SetLocalPos(Vector2(40.0f, 90.0f));
	mongal_DeadEffect1->maxFrame = Int2(9, 1);
	mongal_DeadEffect1->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	mongal_DeadEffect1->visible = false;

	mongal_DeadEffect2 = new ObImage(L"mongal_Dead2.png");
	mongal_DeadEffect2->scale = Vector2(1908.0f / 9.0f, 113.0f) * 1.2f;
	mongal_DeadEffect2->SetParentRT(*mongal_DeadEffect1);
	mongal_DeadEffect2->maxFrame = Int2(9, 1);
	mongal_DeadEffect2->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	mongal_DeadEffect2->visible = false;
		
	mongal_DeadEffect3 = new ObImage(L"mongal_Dead3.png");
	mongal_DeadEffect3->scale = Vector2(1060.0f / 5.0f, 86.0f) * 1.2f;
	mongal_DeadEffect3->SetParentRT(*mongal_DeadEffect1);
	mongal_DeadEffect3->maxFrame = Int2(5, 1);
	mongal_DeadEffect3->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	mongal_DeadEffect3->visible = false;

	//몬갈 Normal Mode
	Ogre_N_WakeUp1 = new ObImage(L"mongal_N_WakeUp1.png");
	Ogre_N_WakeUp1->scale = Vector2(2040.0f / 15.0f, 58.0f) * 2.5f;
	Ogre_N_WakeUp1->SetParentRT(*monster_Col);
	Ogre_N_WakeUp1->SetLocalPosY(70.0f);
	Ogre_N_WakeUp1->maxFrame = Int2(15, 1);
	Ogre_N_WakeUp1->ChangeAnim(ANIMSTATE::ONCE, 0.15f);
	Ogre_N_WakeUp1->visible = false;
	Ogre_N_WakeUp1->reverseLR = true;

	Ogre_N_WakeUp2 = new ObImage(L"mongal_WakeUp2.png");
	Ogre_N_WakeUp2->scale = Vector2(732.0f / 6.0f, 86.0f) * 2.5f;
	Ogre_N_WakeUp2->SetParentRT(*monster_Col);
	Ogre_N_WakeUp2->SetLocalPos(Vector2(-40.0f, 100.0f));
	Ogre_N_WakeUp2->maxFrame = Int2(6, 1);
	Ogre_N_WakeUp2->ChangeAnim(ANIMSTATE::ONCE, 0.15f);
	Ogre_N_WakeUp2->visible = false;
	Ogre_N_WakeUp2->reverseLR = true;

	Ogre_N_Idle = new ObImage(L"Ogre_N_Idle.png");
	Ogre_N_Idle->scale = Vector2(462.0f / 6.0f, 87.0f) * 2.5f;
	Ogre_N_Idle->SetParentRT(*monster_Col);
	Ogre_N_Idle->SetLocalPosY(115.0f);
	Ogre_N_Idle->maxFrame = Int2(6, 1);
	Ogre_N_Idle->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	Ogre_N_Idle->visible = false;
	Ogre_N_Idle->reverseLR = true;

	Ogre_N_Laugh = new ObImage(L"Ogre_N_Laugh.png");
	Ogre_N_Laugh->scale = Vector2(231.0f / 3.0f, 87.0f) * 2.5f;
	Ogre_N_Laugh->SetParentRT(*monster_Col);
	Ogre_N_Laugh->SetLocalPosX(5.0f);
	Ogre_N_Laugh->SetLocalPosY(115.0f);
	Ogre_N_Laugh->maxFrame = Int2(3, 1);
	Ogre_N_Laugh->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	Ogre_N_Laugh->visible = false;
	Ogre_N_Laugh->reverseLR = true;

	Ogre_N_Walk = new ObImage(L"Ogre_N_Walk.png");
	Ogre_N_Walk->scale = Vector2(680.0f / 8.0f, 86.0f) * 2.5f;
	Ogre_N_Walk->SetParentRT(*monster_Col);
	Ogre_N_Walk->SetLocalPosY(100.0f);
	Ogre_N_Walk->maxFrame = Int2(8, 1);
	Ogre_N_Walk->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	Ogre_N_Walk->visible = false;

	Ogre_N_Die = new ObImage(L"Ogre_N_Die.png");
	Ogre_N_Die->scale = Vector2(111.0f, 33.0f) * 2.5f;
	Ogre_N_Die->SetParentRT(*monster_Col);
	Ogre_N_Die->SetLocalPosY(30.0f);
	Ogre_N_Die->visible = false;

	Get_MonsterState() = MonsterState::IDLE;

	SOUND->AddSound("Tutorial_Ogre_Laugh.wav", "Laugh", false);
	SOUND->AddSound("Tutorial_Ogre_Confuse.wav", "Confuse", false);
}

Ogre::~Ogre()
{
	SafeDelete(Ogre_Idle);
	SafeDelete(Ogre_Walk);
	SafeDelete(Ogre_Attack);
	SafeDelete(Ogre_Hit);
	SafeDelete(Ogre_Die);
	SafeDelete(Ogre_AttackCol);
	SafeDelete(mongal_DeadEffect1);
	SafeDelete(mongal_DeadEffect2);
	SafeDelete(mongal_DeadEffect3);

	SafeDelete(Ogre_N_WakeUp1);
	SafeDelete(Ogre_N_WakeUp2);
	SafeDelete(Ogre_N_Idle);
	SafeDelete(Ogre_N_Laugh);
	SafeDelete(Ogre_N_Walk);
	SafeDelete(Ogre_N_Die);
}

void Ogre::Update()
{
	Monster::Update();

	switch (Get_MonsterState())
	{
	case MonsterState::IDLE:
		O_Idle();
		break;
	case  MonsterState::MOVE:
		O_Move();
		break;
	case  MonsterState::ATTACK:
		O_Attack();
		break;
	case  MonsterState::HIT:
		O_Hit();
		break;
	case  MonsterState::DIE:
		O_Die();
		break;
	}

	if (ogre_reverse)
	{
		Ogre_Idle->reverseLR = false;
		Ogre_Walk->reverseLR = false;
		Ogre_Attack->reverseLR = false;
		Ogre_Hit->reverseLR = false;
		Ogre_Die->reverseLR = false;

		Ogre_AttackCol->SetLocalPosX(70.0f);
	}

	else
	{
		Ogre_Idle->reverseLR = true;
		Ogre_Walk->reverseLR = true;
		Ogre_Attack->reverseLR = true;
		Ogre_Hit->reverseLR = true;
		Ogre_Die->reverseLR = true;

		Ogre_AttackCol->SetLocalPosX(-70.0f);
	}

	if (mongal_Normal)
	{
		Ogre_N_WakeUp1->visible = true;

		if (Ogre_N_WakeUp1->frame.x >= 14.0f)
		{
			Ogre_N_WakeUp1->visible = false;
			Ogre_N_WakeUp2->visible = true;
		}

		if (3.0f <= Ogre_N_WakeUp1->frame.x && Ogre_N_WakeUp1->frame.x <= 4.0f)
		{
			SOUND->Play("Confuse");
		}

		if (Ogre_N_WakeUp2->frame.x >= 5.0f)
		{
			Ogre_N_WakeUp2->visible = false;

			if (!Ogre_N_WakeUp2->visible)
			{
				Ogre_N_Idle->visible = true;
			}
		}
	}

	if (mongal_laugh && !mongal_Move)
	{
		mongal_Normal = false;
		mongal_Normal2 = true;
		laugh_time += DELTA;
		
		if (laugh_time < 1.2f)
		{
			Ogre_N_Idle->visible = false;
			Ogre_N_Laugh->visible = true;
			SOUND->Play("Laugh");
		}

		else
		{
			Ogre_N_Laugh->visible = false;
			Ogre_N_Idle->visible = true;
			laugh_time = 0.0f;
			mongal_laugh = false;
		}
	}

	Ogre_Idle->Update();
	Ogre_Walk->Update();
	Ogre_Attack->Update();
	Ogre_Hit->Update();
	Ogre_Die->Update();
	Ogre_AttackCol->Update();
	mongal_DeadEffect1->Update();
	mongal_DeadEffect2->Update();
	mongal_DeadEffect3->Update();

	Ogre_N_WakeUp1->Update();
	Ogre_N_WakeUp2->Update();
	Ogre_N_Idle->Update();
	Ogre_N_Laugh->Update();
	Ogre_N_Walk->Update();
	Ogre_N_Die->Update();
}

void Ogre::Render()
{
	Monster::Render();

	Ogre_Idle->Render();
	Ogre_Walk->Render();
	Ogre_Attack->Render();
	Ogre_Hit->Render();
	Ogre_Die->Render();
	Ogre_AttackCol->Render();
	mongal_DeadEffect1->Render();
	mongal_DeadEffect2->Render();
	mongal_DeadEffect3->Render();

	Ogre_N_WakeUp1->Render();
	Ogre_N_WakeUp2->Render();
	Ogre_N_Idle->Render();
	Ogre_N_Laugh->Render();
	Ogre_N_Walk->Render();
	Ogre_N_Die->Render();
}

void Ogre::O_Idle()
{
	O_AllInvisible();

	Ogre_Idle->visible = true;

	Ogre_Attack->frame.x = 0;
}

void Ogre::O_Move()
{
	O_AllInvisible();

	Ogre_Walk->visible = true;


	Ogre_Attack->frame.x = 0;
	monga_attack_Time = 0.0f;
}

void Ogre::O_Attack()
{
	O_AllInvisible();
	Ogre_Attack->visible = true;
	Ogre_AttackCol->visible = false;
}

void Ogre::O_Hit()
{
	O_AllInvisible();
	Ogre_Hit->visible = true;
}

void Ogre::O_Die()
{
	O_AllInvisible();
	
	if (!mongal_Normal && !mongal_Normal2)
	{
		Ogre_Die->visible = true;

		mongal_DeadEffect1->visible = true;

		if (mongal_DeadEffect1->frame.x >= 8.0f)
		{
			mongal_DeadEffect1->visible = false;
			mongal_DeadEffect2->visible = true;
		}

		if (mongal_DeadEffect2->frame.x >= 8.0f)
		{
			mongal_DeadEffect2->visible = false;
			mongal_DeadEffect3->visible = true;
		}

		if (mongal_DeadEffect3->frame.x >= 4.0f)
		{
			mongal_DeadEffect1->visible = false;
			mongal_DeadEffect2->visible = false;
			mongal_DeadEffect3->visible = false;
		}
	}
	
	

	
}

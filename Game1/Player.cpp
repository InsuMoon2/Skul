#include "stdafx.h"

Player::Player()
{
	born_Idle = new ObImage(L"LITTLEBONE_IDLE.bmp");
	born_Idle->scale = Vector2(1000.0f / 4.0f, 500.0f / 2.0f);
	born_Idle->SetParentRT(*player_Col);
	born_Idle->SetLocalPosY(-80.0f);
	born_Idle->maxFrame = Int2(4,2);
	born_Idle->frame.y = 0;
	born_Idle->pivot = OFFSET_B;
	born_Idle->visible = true;

	born_Run = new ObImage(L"move_skul.png");
	born_Run->scale = Vector2(768.0f / 8.0f, 96.0f) * 2.55f;
	born_Run->SetParentRT(*player_Col);
	born_Run->SetLocalPosY(-80.0f);
	born_Run->maxFrame = Int2(8, 1);
	born_Run->pivot = OFFSET_B;
	born_Run->visible = false;
	
	born_Jump = new ObImage(L"LITTLEBONE_JUMP2.bmp");
	born_Jump->scale = Vector2(1750.0f / 7.0f, 500.0f / 2.0f);
	born_Jump->SetParentRT(*player_Col);
	born_Jump->SetLocalPosY(-80.0f);
	born_Jump->maxFrame = Int2(7, 2);
	born_Jump->frame.y = 0;
	born_Jump->pivot = OFFSET_B;
	born_Jump->visible = false;

	born_Attack1 = new ObImage(L"LITTLEBONE_ATTACK1.bmp");
	born_Attack1->scale = Vector2(1250.0f / 5.0f, 500.0f / 2.0f);
	born_Attack1->SetParentRT(*player_Col);
	born_Attack1->SetLocalPosY(-80.0f);
	born_Attack1->maxFrame = Int2(5, 2);
	born_Attack1->frame.y = 0;
	born_Attack1->pivot = OFFSET_B;
	born_Attack1->visible = false;

	born_Attack2 = new ObImage(L"LITTLEBONE_ATTACK2.bmp");
	born_Attack2->scale = Vector2(1000.0f / 4.0f, 500.0f / 2.0f);
	born_Attack2->SetParentRT(*player_Col);
	born_Attack2->SetLocalPosY(-80.0f);
	born_Attack2->maxFrame = Int2(4, 2);
	born_Attack2->frame.y = 0;
	born_Attack2->pivot = OFFSET_B;
	born_Attack2->visible = false;

	born_Dash = new ObImage(L"LITTLEBONE_DASH.bmp");
	born_Dash->scale = Vector2(250.0f, 500.0f / 2.0f);
	born_Dash->SetParentRT(*player_Col);
	born_Dash->SetLocalPosY(-80.0f);
	born_Dash->maxFrame = Int2(1, 2);
	born_Dash->frame.y = 0;
	born_Dash->pivot = OFFSET_B;
	born_Dash->visible = false;

	for (int i = 0; i < 5; i++)
	{
		shadow[i] = new Shadow();
		shadow[i]->born_DashShadow = new ObImage(L"LITTLEBONE_DASH.bmp");
		shadow[i]->born_DashShadow->scale = Vector2(250.0f, 500.0f / 2.0f);
		shadow[i]->born_DashShadow->color = Color(0.0f, 0.0f, 0.0f, 0.8f);
		shadow[i]->born_DashShadow->maxFrame = Int2(1, 2);
		shadow[i]->born_DashShadow->frame.y = 0;
		shadow[i]->born_DashShadow->pivot = OFFSET_B;
		shadow[i]->born_DashShadow->visible = false;
	}

	born_Dead = new ObImage(L"skul_die.png");
	born_Dead->scale = Vector2(2576.0f / 23.0f, 112.0f) * 2.5f;
	born_Dead->SetParentRT(*player_Col);
	born_Dead->SetLocalPosY(-100.0f);
	born_Dead->maxFrame = Int2(23, 1);
	born_Dead->pivot = OFFSET_B;
	born_Dead->visible = false;

	born_JumpAttack = new ObImage(L"LITTLEBONE_JUMPATTACK.bmp");
	born_JumpAttack->scale = Vector2(1000.0f / 4.0f, 500.0f / 2.0f);
	born_JumpAttack->SetParentRT(*player_Col);
	born_JumpAttack->SetLocalPosY(-80.0f);
	born_JumpAttack->maxFrame = Int2(4, 2);
	born_JumpAttack->frame.y = 0;
	born_JumpAttack->pivot = OFFSET_B;
	born_JumpAttack->visible = false;

	//bornLess
	bornLess_Idle = new ObImage(L"idle_headless_skul.png");
	bornLess_Idle->scale = Vector2(384.0f / 4.0f, 96.0f) * 2.55f;
	bornLess_Idle->SetParentRT(*player_Col);
	bornLess_Idle->SetLocalPosY(-80.0f);
	bornLess_Idle->maxFrame = Int2(4, 1);
	bornLess_Idle->pivot = OFFSET_B;
	bornLess_Idle->visible = false;

	bornLess_Run = new ObImage(L"move_headless_skul.png");
	bornLess_Run->scale = Vector2(768.0f / 8.0f, 96.0f) * 2.55f;
	bornLess_Run->SetParentRT(*player_Col);
	bornLess_Run->SetLocalPosY(-80.0f);
	bornLess_Run->maxFrame = Int2(8, 1);
	bornLess_Run->pivot = OFFSET_B;
	bornLess_Run->visible = false;

	bornLess_Jump = new ObImage(L"bornLess_Jump.png");
	bornLess_Jump->scale = Vector2(672.0f / 7.0f, 96.0f) * 2.55f;
	bornLess_Jump->SetParentRT(*player_Col);
	bornLess_Jump->SetLocalPosY(-80.0f);
	bornLess_Jump->maxFrame = Int2(7, 1);
	bornLess_Jump->pivot = OFFSET_B;
	bornLess_Jump->visible = false;

	bornLess_Attack1 = new ObImage(L"attackA_headless_skul.png");
	bornLess_Attack1->scale = Vector2(480.0f / 5.0f, 96.0f) * 2.55f;
	bornLess_Attack1->SetParentRT(*player_Col);
	bornLess_Attack1->SetLocalPosY(-80.0f);
	bornLess_Attack1->maxFrame = Int2(5, 1);
	bornLess_Attack1->pivot = OFFSET_B;
	bornLess_Attack1->visible = false;

	bornLess_Attack2 = new ObImage(L"attackB_headless_skul.png");
	bornLess_Attack2->scale = Vector2(384.0f / 4.0f, 96.0f) * 2.55f;
	bornLess_Attack2->SetParentRT(*player_Col);
	bornLess_Attack2->SetLocalPosY(-80.0f);
	bornLess_Attack2->maxFrame = Int2(4, 1);
	bornLess_Attack2->frame.y = 0;
	bornLess_Attack2->pivot = OFFSET_B;
	bornLess_Attack2->visible = false;

	bornLess_Dash = new ObImage(L"dash_headless_skul.png");
	bornLess_Dash->scale = Vector2(96.0f, 96.0f) * 2.55f;
	bornLess_Dash->SetParentRT(*player_Col);
	bornLess_Dash->SetLocalPosY(-80.0f);
	bornLess_Dash->frame.y = 0;
	bornLess_Dash->pivot = OFFSET_B;
	bornLess_Dash->visible = false;

	bornLess_JumpAttack = new ObImage(L"jumpattack_headless_skul.png");
	bornLess_JumpAttack->scale = Vector2(384.0f / 4.0f, 96.0f) * 2.55f;
	bornLess_JumpAttack->SetParentRT(*player_Col);
	bornLess_JumpAttack->SetLocalPosY(-80.0f);
	bornLess_JumpAttack->maxFrame = Int2(4,1);
	bornLess_JumpAttack->pivot = OFFSET_B;
	bornLess_JumpAttack->visible = false;

	//무기 X
	born_IDLE_NW = new ObImage(L"born_IDLE_NW.png");
	born_IDLE_NW->scale = Vector2(820.0f / 4.0f, 170.0f) * 2.55f;
	born_IDLE_NW->SetParentRT(*player_Col);
	born_IDLE_NW->SetLocalPosY(-170.0f);
	born_IDLE_NW->maxFrame.x = 4;
	born_IDLE_NW->maxFrame.y = 1;
	born_IDLE_NW->pivot = OFFSET_B;
	born_IDLE_NW->visible = false;

	born_RUN_NW = new ObImage(L"born_RUN_NW.png");
	born_RUN_NW->scale = Vector2(768.0f / 8.0f, 96.0f) * 2.55f;
	born_RUN_NW->SetParentRT(*player_Col);
	born_RUN_NW->SetLocalPosY(-80.0f);
	born_RUN_NW->maxFrame.x = 8;
	born_RUN_NW->maxFrame.y = 1;
	born_RUN_NW->pivot = OFFSET_B;
	born_RUN_NW->visible = false;

	born_GetWeapon = new ObImage(L"born_GetWeapon.png");
	born_GetWeapon->scale = Vector2(2010.0f / 10.0f, 96.0f) * 2.55f;
	born_GetWeapon->SetParentRT(*player_Col);
	born_GetWeapon->SetLocalPosY(-85.0f);
	born_GetWeapon->SetLocalPosX(20.0f);
	born_GetWeapon->maxFrame.x = 10;
	born_GetWeapon->maxFrame.y = 1;
	born_GetWeapon->pivot = OFFSET_B;
	born_GetWeapon->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	born_GetWeapon->visible = false;

	//스킬
	bornSkill_A = new ObImage(L"skillA_skul.png");
	bornSkill_A->scale = Vector2(384.0f / 4.0f, 96.0f) * 2.55f;
	bornSkill_A->SetParentRT(*player_Col);
	bornSkill_A->SetLocalPosY(-80.0f);
	bornSkill_A->maxFrame = Int2(4, 1);
	bornSkill_A->ChangeAnim(ANIMSTATE::ONCE, 0.15f);
	bornSkill_A->pivot = OFFSET_B;
	bornSkill_A->visible = false;

	bornSkill_B = new ObImage(L"skillB_skul.png");
	bornSkill_B->scale = Vector2(864.0f / 9.0f, 96.0f) * 2.55f;
	bornSkill_B->SetParentRT(*player_Col);
	bornSkill_B->SetLocalPosY(-80.0f);
	bornSkill_B->maxFrame = Int2(9, 1);
	bornSkill_B->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	bornSkill_B->pivot = OFFSET_B;
	bornSkill_B->visible = false;

	switch_Skul = new ObImage(L"switch_skul.png");
	switch_Skul->scale = Vector2(672.0f / 7.0f, 96.0f) * 2.55f;
	switch_Skul->SetParentRT(*player_Col);
	switch_Skul->SetLocalPosY(-80.0f);
	switch_Skul->maxFrame = Int2(7, 1);
	switch_Skul->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	switch_Skul->pivot = OFFSET_B;
	switch_Skul->visible = false;

	born_HeadCol = new ObCircle();
	born_HeadCol->scale = Vector2(16.0f, 16.0f) * 2.3f;
	born_HeadCol->SetWorldPos(player_Col->GetWorldPos());
	born_HeadCol->visible = false;
	born_HeadCol->isFilled = false;
	born_HeadCol->collider = COLLIDER::CIRCLE;

	born_Head = new ObImage(L"skul_head.png");
	born_Head->scale = Vector2(16.0f, 16.0f) * 2.3f;
	born_Head->SetParentRT(*born_HeadCol);
	born_Head->visible = false;

	//머리통 체크
	born_Check = true;

	//무기 체크
	getWeapon = false;

	guard_Idle = new ObImage(L"Guard_Idle.png");
	guard_Idle->scale = Vector2(390.0f / 6.0f, 65.0f) * 2.5f;
	guard_Idle->SetParentRT(*player_Col);
	guard_Idle->SetLocalPos(Vector2(11.0f, 55.0f));
	guard_Idle->maxFrame = Int2(6, 1);
	guard_Idle->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	guard_Idle->visible = false;
	
	guard_Walk = new ObImage(L"Guard_Walk.png");
	guard_Walk->scale = Vector2(455.0f / 7.0f, 65.0f) * 2.5f;
	guard_Walk->SetParentRT(*player_Col);
	guard_Walk->SetLocalPos(Vector2(13.0f, 50.0f));
	guard_Walk->maxFrame = Int2(7, 1);
	guard_Walk->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	guard_Walk->visible = false;
	
	guard_Dash = new ObImage(L"Guard_Dash.png");
	guard_Dash->scale = Vector2(640.0f / 5.0f, 42.0f) * 2.5f;
	guard_Dash->SetParentRT(*player_Col);
	guard_Dash->SetLocalPos(Vector2(13.0f, 50.0f));
	guard_Dash->maxFrame = Int2(5, 1);
	//guard_Dash->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	guard_Dash->visible = false;
	
	guard_Jump = new ObImage(L"Guard_Jump.png");
	guard_Jump->scale = Vector2(1176.0f / 8.0f, 92.0f) * 2.5f;
	guard_Jump->SetParentRT(*player_Col);
	guard_Jump->SetLocalPos(Vector2(13.0f, 50.0f));
	guard_Jump->maxFrame = Int2(8, 1);
	guard_Jump->ChangeAnim(ANIMSTATE::ONCE, 0.15f);
	guard_Jump->visible = false;
	
	guard_JumpAttack = new ObImage(L"Guard_Jump_Attack.png");
	guard_JumpAttack->scale = Vector2(735.0f / 5.0f, 92.0f) * 2.5f;
	guard_JumpAttack->SetParentRT(*player_Col);
	guard_JumpAttack->SetLocalPos(Vector2(13.0f, 50.0f));
	guard_JumpAttack->maxFrame = Int2(5, 1);
	guard_JumpAttack->ChangeAnim(ANIMSTATE::ONCE, 0.15f);
	guard_JumpAttack->visible = false;
	
	guard_Attack1 = new ObImage(L"Guard_Attack1.png");
	guard_Attack1->scale = Vector2(500.0f / 5.0f, 100.0f) * 2.5f;
	guard_Attack1->SetParentRT(*player_Col);
	guard_Attack1->SetLocalPosY(70.0f);
	guard_Attack1->maxFrame = Int2(5, 1);
	guard_Attack1->ChangeAnim(ANIMSTATE::ONCE, 0.15f);
	guard_Attack1->visible = false;

	guard_Attack2 = new ObImage(L"Guard_Attack2.png");
	guard_Attack2->scale = Vector2(550.0f / 5.0f, 110.0f) * 2.3f;
	guard_Attack2->SetParentRT(*player_Col);
	guard_Attack2->SetLocalPosY(83.0f);
	guard_Attack2->maxFrame = Int2(5, 1);
	guard_Attack2->ChangeAnim(ANIMSTATE::ONCE, 0.15f);
	guard_Attack2->visible = false;

	guard_Attack3 = new ObImage(L"Guard_Attack3.png");
	guard_Attack3->scale = Vector2(660.0f / 6.0f, 110.0f) * 2.3f;
	guard_Attack3->SetParentRT(*player_Col);
	guard_Attack3->SetLocalPosY(83.0f);
	guard_Attack3->maxFrame = Int2(6, 1);
	guard_Attack3->ChangeAnim(ANIMSTATE::ONCE, 0.15f);
	guard_Attack3->visible = false;

	guard_Skill_A = new ObImage(L"Guard_Skill1.png");
	guard_Skill_A->scale = Vector2(3234.0f / 22.0f, 92.0f) * 2.3f;
	guard_Skill_A->SetParentRT(*player_Col);
	guard_Skill_A->SetLocalPos(Vector2(13.0f, 55.0f));
	guard_Skill_A->maxFrame = Int2(22, 1);
	guard_Skill_A->ChangeAnim(ANIMSTATE::ONCE, 0.06f);
	guard_Skill_A->visible = false;

	guard_Skill_B = new ObImage(L"Guard_Skill2.png");
	guard_Skill_B->scale = Vector2(1200.0f / 8.0f, 75.0f) * 2.3f;
	guard_Skill_B->SetParentRT(*player_Col);
	guard_Skill_B->SetLocalPos(Vector2(13.0f, 55.0f));
	guard_Skill_B->maxFrame = Int2(8, 1);
	guard_Skill_B->ChangeAnim(ANIMSTATE::ONCE, 0.08f);
	guard_Skill_B->visible = false;

	//스위치를 만들지 말지 생각하기
	guard_Switch = new ObImage(L"Guard_Switch.png");
	guard_Switch->scale = Vector2(1350.0f / 9.0f, 80.0f) * 2.5f;
	guard_Switch->SetParentRT(*player_Col);
	guard_Switch->SetLocalPos(Vector2(13.0f, 50.0f));
	guard_Switch->maxFrame = Int2(9, 1);
	guard_Switch->ChangeAnim(ANIMSTATE::ONCE, 0.15f);
	guard_Switch->visible = false;

	fireBall_Col = new ObRect();
	fireBall_Col->scale = Vector2(1404.0f / 12.0f, 66.0f) * 1.5f;
	//fireBall_Col->SetParentT(*player_Col);
	fireBall_Col->isFilled = false;
	fireBall_Col->visible = false;

	fireBall = new ObImage(L"FireBall.png");
	fireBall->scale = Vector2(1404.0f / 12.0f, 66.0f) * 2.0f;
	fireBall->SetParentRT(*fireBall_Col);
	fireBall->maxFrame = Int2(12,1);
	fireBall->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	fireBall->visible = false;

	fireSlash = new ObImage(L"FireSlash.png");
	fireSlash->scale = Vector2(3234.0f / 22.0f, 92.0f) * 1.5f;
	fireSlash->SetParentRT(*guard_Skill_B);
	fireSlash->SetLocalPosY(-12.0f);
	fireSlash->maxFrame = Int2(22, 1);
	fireSlash->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
	fireSlash->visible = false;

	skill_Slash = new ObImage(L"Skill_B_Slash.png");
	skill_Slash->scale = Vector2(3618.0f / 12.0f, 34.0f) * 2.5f;
	skill_Slash->SetParentRT(*guard_Skill_B);
	//skill_Slash->SetLocalPosY(-45.0f);
	skill_Slash->maxFrame = Int2(12, 1);
	skill_Slash->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
	skill_Slash->visible = false;

	born_HeadCol->colOnOff = false;


	//Sound
	SOUND->AddSound("Skul_SkullBack.wav", "Skill_A", false);
	SOUND->AddSound("Skul_Reborn_Rise.wav", "Skill_B", false);
	SOUND->AddSound("Skul_Switch.wav", "Switch", false);
}

Player::~Player()
{
	SafeDelete(born_Idle);
	SafeDelete(born_Run);
	SafeDelete(born_Jump);
	SafeDelete(born_Attack1);
	SafeDelete(born_Attack2);
	SafeDelete(born_Dash);
	SafeDelete(born_Dead);
	SafeDelete(born_JumpAttack);

	for (int i = 0; i < 5; i++)
	{
		SafeDelete(shadow[i]->born_DashShadow);
	}

	SafeDelete(bornLess_Idle);
	SafeDelete(bornLess_Run);
	SafeDelete(bornLess_Dash);
	SafeDelete(bornLess_JumpAttack);
	SafeDelete(bornLess_Jump);
	SafeDelete(bornLess_Attack1);
	SafeDelete(bornLess_Attack2);

	SafeDelete(born_Head);
	SafeDelete(born_HeadCol);

	SafeDelete(born_IDLE_NW);
	SafeDelete(born_RUN_NW);

	SafeDelete(guard_Idle);
	SafeDelete(guard_Walk);
	SafeDelete(guard_Dash);
	SafeDelete(guard_Jump);
	SafeDelete(guard_JumpAttack);

	SafeDelete(guard_Attack1);
	SafeDelete(guard_Attack2);
	SafeDelete(guard_Attack3);

	SafeDelete(guard_Skill_A);
	SafeDelete(guard_Skill_B);

	SafeDelete(guard_Switch);
	SafeDelete(fireBall);
	SafeDelete(fireSlash);
	SafeDelete(skill_Slash);
}

void Player::Update()
{
	Character::Update();
	
	if (Skul_State == SKUL::LittleBorn)
	{
		switch (GetState())
		{
		case PLAYERSTATE::IDLE:
			B_Idle();
			break;
		case PLAYERSTATE::RUN:
			B_Run();
			break;
		case PLAYERSTATE::JUMP:
			B_Jump();
			break;
		case PLAYERSTATE::DOWNJUMP:
			B_Jump();
			break;
		case PLAYERSTATE::JUMPATTACK:
			B_JumpAttack();
			break;
		case PLAYERSTATE::ATTACK1:
			B_Attack1();
			break;
		case PLAYERSTATE::ATTACK2:
			B_Attack2();
			break;
		case PLAYERSTATE::SKILL1:
			B_Skill_A();
			break;
		case PLAYERSTATE::SKILL2:
			B_Skill_B();
			break;
		case PLAYERSTATE::DASH:
			B_Dash();
			break;
		case PLAYERSTATE::DIE:
			B_Die();
			break;
		}
	}

	else
	{
		switch (GetState())
		{
		case PLAYERSTATE::IDLE:
			G_Idle();
			break;
		case PLAYERSTATE::RUN:
			G_Run();
			break;
		case PLAYERSTATE::JUMP:
			G_Jump();
			break;
		case PLAYERSTATE::DOWNJUMP:
			G_Jump();
			break;
		case PLAYERSTATE::JUMPATTACK:
			G_JumpAttack();
			break;
		case PLAYERSTATE::ATTACK1:
			G_Attack1();
			break;
		case PLAYERSTATE::ATTACK2:
			G_Attack2();
			break;
		case PLAYERSTATE::ATTACK3:
			G_Attack3();
			break;
		case PLAYERSTATE::SKILL1:
			G_Skill_A();
			break;
		case PLAYERSTATE::SKILL2:
			G_Skill_B();
			break;
		case PLAYERSTATE::DASH:
			G_Dash();
			break;
		case PLAYERSTATE::DIE:
			G_Die();
			break;
		}
	}

	if (born_GetWeapon->visible)
	{
		born_IDLE_NW->visible = false;
		born_RUN_NW->visible = false;
	}

	if (born_Check)
	{
		shoot_time = 0.0f;
	}

	if (TIMER->GetTick(shadow[index2]->s_time, 0.07f))
	{
		shadow[index2]->born_DashShadow->visible = false;

		index2++;

		if (index2 == 4)
		{
			index2 = 0;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		shadow[i]->born_DashShadow->Update();
	}

	if (born_Check)
	{
		playerUi->born_A_Gauge->scale.y = 0.0f;
	}

	if (reverse)
	{
		born_Dead->reverseLR = true;

	}

	else
	{
		born_Dead->reverseLR = false;
	}

	if (!getWeapon)
	{
		born_IDLE_NW->visible = false;
		born_RUN_NW->visible = false;
	}

	//LittleBorn
	if (Skul_State == SKUL::LittleBorn)
	{
		born_Idle->Update();
		born_Run->Update();
		born_Dash->Update();
		born_JumpAttack->Update();
		born_Jump->Update();
		born_Attack1->Update();
		born_Attack2->Update();

		bornLess_Idle->Update();
		bornLess_Run->Update();
		bornLess_Dash->Update();
		bornLess_JumpAttack->Update();
		bornLess_Jump->Update();
		bornLess_Attack1->Update();
		bornLess_Attack2->Update();

		bornSkill_A->Update();
		bornSkill_B->Update();
		switch_Skul->Update();
		born_Head->Update();
		born_Dead->Update();
		born_HeadCol->Update();
		born_GetWeapon->Update();

		born_IDLE_NW->Update();
		born_RUN_NW->Update();

		//머리 던지기
		Shooting();

		//cout << "Born_HeadCol : X "<< born_HeadCol->GetWorldPos().x << endl;
		//cout << "Born_HeadCol : Y "<< born_HeadCol->GetWorldPos().y << endl;
	}

	//Guard
	else
	{
		if (slash_Check)
		{
			slash_Time += DELTA;

			//cout << slash_Time << endl;

			player_Col->MoveWorldPos(RIGHT * 1200.0f * DELTA);

			if (slash_Time < 0.3f)
			{
				//cout << "11" << endl;
				player_Col->MoveWorldPos(RIGHT * 1200.0f * DELTA);
			}

			else
			{
				slash_Check = false;
				slash_Time = 0.0f;
			}
		}

		//FireBall - Player
		Vector2 fire = player_Col->GetWorldPos() - fireBall_Col->GetWorldPos();
		float f_distance = fire.Length();

		//cout << f_distance << endl;

		//FireBall Move
		if (fireBall_Check)
		{
			G_GetShoot();
			fireBall_Col->MoveWorldPos(Shoot1 * scalar1 * DELTA);

			if (f_distance >= 2000.0f)
			{
				fireBall_Col->visible = false;
				fireBall->visible = false;
				//fireBall_Check = false;
			}
		}
		
		guard_Idle->Update();
		guard_Walk->Update();
		guard_Dash->Update();
		guard_Jump->Update();
		guard_JumpAttack->Update();

		guard_Attack1->Update();
		guard_Attack2->Update();
		guard_Attack3->Update();

		guard_Skill_A->Update();
		guard_Skill_B->Update();

		guard_Switch->Update();

		fireBall->Update();
		fireSlash->Update();
		skill_Slash->Update();
		fireBall_Col->Update();
	}

}

void Player::LateUpdate()
{
	
}

void Player::Render()
{
	if (Skul_State == SKUL::LittleBorn)
	{
		born_Idle->Render();
		born_Run->Render();
		born_Jump->Render();
		born_Attack1->Render();
		born_Attack2->Render();

		for (int i = 0; i < 5; i++)
		{
			shadow[i]->born_DashShadow->Render();
		}

		born_Dash->Render();
		born_JumpAttack->Render();

		bornLess_Idle->Render();
		bornLess_Run->Render();
		bornLess_Jump->Render();
		bornLess_Attack1->Render();
		bornLess_Attack2->Render();
		bornLess_Dash->Render();
		bornLess_JumpAttack->Render();

		born_IDLE_NW->Render();
		born_RUN_NW->Render();

		bornSkill_A->Render();
		bornSkill_B->Render();
		switch_Skul->Render();

		born_Head->Render();
		born_HeadCol->Render();
		born_Dead->Render();
		born_GetWeapon->Render();
	}

	else
	{
		guard_Idle->Render();
		guard_Walk->Render();
		guard_Dash->Render();
		guard_Jump->Render();
		guard_JumpAttack->Render();

		guard_Attack1->Render();
		guard_Attack2->Render();
		guard_Attack3->Render();

		guard_Skill_A->Render();
		guard_Skill_B->Render();

		guard_Switch->Render();

		skill_Slash->Render();
		fireSlash->Render();
		fireBall->Render();
		fireBall_Col->Render();
	}
	
	Character::Render();
}

void Player::B_Idle()
{
	

	if (reverse)
	{
		born_Idle->reverseLR = true;
		bornLess_Idle->reverseLR = true;
		born_IDLE_NW->reverseLR = true;
		Hit_Skul->reverseLR = true;
	}

	else if(!reverse)
	{
		born_Idle->reverseLR = false;
		bornLess_Idle->reverseLR = false;
		born_IDLE_NW->reverseLR = false;
		Hit_Skul->reverseLR = false;
	}

	AllInvisible();

	if (born_Check)
	{
		born_Attack1->frame.x = 0;
		born_Attack2->frame.x = 0;
		born_Idle->visible = true;
		born_Idle->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	}

	else if (!born_Check)
	{
		bornLess_Attack1->frame.x = 0;
		bornLess_Attack2->frame.x = 0;
		bornLess_Idle->visible = true;
		bornLess_Idle->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
		bornLess_Jump->frame.x = 0;
	}

	if (getWeapon)
	{
		born_Idle->visible = false;
		bornLess_Idle->visible = false;
		born_IDLE_NW->visible = true;
		born_IDLE_NW->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	}

	doubleJump->visible = false;
	//shoot_time = 0.0f;

	bornSkill_A->frame.x = 0;
	bornSkill_B->frame.x = 0;
	switch_Skul->frame.x = 0;

	//스킬 A
	if (INPUT->KeyDown('A') && born_Check)
	{
		player_State = PLAYERSTATE::SKILL1;
		SOUND->Play("Skill_A");

		headShoot_Check = true;
		headShoot_LastPos = player_Col->GetWorldPos();
	}

	//스킬 B
	if (INPUT->KeyDown('S'))
	{
		player_State = PLAYERSTATE::SKILL2;
		SOUND->Play("Skill_B");
		
	}
}

void Player::B_Run()
{
	if (reverse)
	{
		born_Run->SetLocalPosX(-10.0f);
		born_Run->reverseLR = true;

		bornLess_Run->SetLocalPosX(-10.0f);
		bornLess_Run->reverseLR = true;

		born_RUN_NW->SetLocalPosX(-10.0f);
		born_RUN_NW->reverseLR = true;

	}

	else if (!reverse)
	{
		born_Run->SetLocalPosX(10.0f);
		born_Run->reverseLR = false;

		bornLess_Run->SetLocalPosX(10.0f);
		bornLess_Run->reverseLR = false;

		born_RUN_NW->SetLocalPosX(10.0f);
		born_RUN_NW->reverseLR = false;
	}

	AllInvisible();

	if (born_Check)
	{
		born_Attack1->frame.x = 0;
		born_Attack2->frame.x = 0;
		born_Run->visible = true;
		born_Run->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	}

	else if (!born_Check)
	{
		bornLess_Attack1->frame.x = 0;
		bornLess_Attack2->frame.x = 0;
		bornLess_Run->visible = true;
		bornLess_Run->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	}

	if(getWeapon)
	{
		born_Run->visible = false;
		bornLess_Run->visible = false;
		born_RUN_NW->visible = true;
		born_RUN_NW->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	}

	//스킬 A
	if (INPUT->KeyDown('A') && born_Check)
	{
		player_State = PLAYERSTATE::SKILL1;
		SOUND->Play("Skill_A");

		headShoot_Check = true;
		headShoot_LastPos = player_Col->GetWorldPos();
	}

	//스킬 B
	if (INPUT->KeyDown('S'))
	{
		player_State = PLAYERSTATE::SKILL2;
		SOUND->Play("Skill_B");
	}

}

void Player::B_Jump()
{
	if (reverse)
	{
		born_Jump->reverseLR = true;
		bornLess_Jump->reverseLR = true;
	}

	else if (!reverse)
	{
		born_Jump->reverseLR = false;
		bornLess_Jump->reverseLR = false;
	}

	AllInvisible();
	
	if (born_Check)
	{
		born_Jump->visible = true;
		born_JumpAttack->frame.x = 0;
		born_Jump->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	}

	else if (!born_Check)
	{
		bornLess_Jump->visible = true;
		bornLess_JumpAttack->frame.x = 0;
		bornLess_Jump->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	}

	if (born_Jump->frame.x == 6)
	{
		born_Jump->ChangeAnim(ANIMSTATE::STOP, 0);
	}

	else if (bornLess_Jump->frame.x == 6)
	{
		bornLess_Jump->ChangeAnim(ANIMSTATE::STOP, 0);
	}

	//스킬 A
	if (INPUT->KeyDown('A') && born_Check)
	{
		player_State = PLAYERSTATE::SKILL1;
		SOUND->Play("Skill_A");

		headShoot_Check = true;
		headShoot_LastPos = player_Col->GetWorldPos();
	}

	//스킬 B
	if (INPUT->KeyDown('S'))
	{
		player_State = PLAYERSTATE::SKILL2;
		SOUND->Play("Skill_B");
	}
}

void Player::B_DownJump()
{
	if (reverse)
	{
		born_Jump->reverseLR = true;
		bornLess_Jump->reverseLR = true;
	}

	else if (!reverse)
	{
		born_Jump->reverseLR = false;
		bornLess_Jump->reverseLR = false;
	}

	AllInvisible();

	if (born_Check)
	{
		born_Jump->visible = true;
		born_JumpAttack->frame.x = 0;
		born_Jump->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	}

	else if (!born_Check)
	{
		bornLess_Jump->visible = true;
		bornLess_JumpAttack->frame.x = 0;
		bornLess_Jump->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	}

	if (born_Jump->frame.x == 6)
	{
		born_Jump->ChangeAnim(ANIMSTATE::STOP, 0);
	}

	else if (bornLess_Jump->frame.x == 6)
	{
		bornLess_Jump->ChangeAnim(ANIMSTATE::STOP, 0);
	}

	//스킬 A
	if (INPUT->KeyDown('A') && born_Check)
	{
		player_State = PLAYERSTATE::SKILL1;
		SOUND->Play("Skill_A");

		headShoot_Check = true;
		headShoot_LastPos = player_Col->GetWorldPos();
	}

	//스킬 B
	if (INPUT->KeyDown('S'))
	{
		player_State = PLAYERSTATE::SKILL2;
		SOUND->Play("Skill_B");
	}
}

void Player::B_JumpAttack()
{
	//cout << "11" << endl;
	AllInvisible();

	if (reverse)
	{
		born_JumpAttack->reverseLR = true;
		bornLess_JumpAttack->reverseLR = true;
	}

	else if (!reverse)
	{
		born_JumpAttack->reverseLR = false;
		bornLess_JumpAttack->reverseLR = false;
	}

	if (born_Check)
	{
		born_JumpAttack->visible = true;
		born_JumpAttack->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	}

	else if (!born_Check)
	{
		bornLess_JumpAttack->visible = true;
		bornLess_JumpAttack->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	}

	if (born_JumpAttack->frame.x == 3 ||
		bornLess_JumpAttack->frame.x == 3)
	{
		player_State = PLAYERSTATE::JUMP;
	}
}

void Player::B_Attack1()
{
	if (reverse)
	{
		born_Attack1->reverseLR = true;
		bornLess_Attack1->reverseLR = true;
	}

	else if (!reverse)
	{
		born_Attack1->reverseLR = false;
		bornLess_Attack1->reverseLR = false;
	}

	AllInvisible();

	if (born_Check)
	{
		born_Attack1->visible = true;
		born_Attack1->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	}

	else if (!born_Check)
	{
		bornLess_Attack1->visible = true;
		bornLess_Attack1->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	}

	if (born_Attack1->frame.x == 4 ||
		bornLess_Attack1->frame.x == 4)
	{
		born_Attack1->ChangeAnim(ANIMSTATE::STOP, 0);
		bornLess_Attack1->ChangeAnim(ANIMSTATE::STOP, 0);
		player_State = PLAYERSTATE::IDLE;


		if (INPUT->KeyPress(VK_LEFT) || INPUT->KeyPress(VK_RIGHT))
		{
			player_State = PLAYERSTATE::RUN;
		}
	}

}

void Player::B_Attack2()
{
	if (reverse)
	{
		born_Attack2->reverseLR = true;
		bornLess_Attack2->reverseLR = true;
	}

	else if (!reverse)
	{
		born_Attack2->reverseLR = false;
		bornLess_Attack2->reverseLR = false;
	}

	AllInvisible();

	if (born_Check)
	{
		born_Attack2->visible = true; 
		born_Attack2->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	}

	else if (!born_Check)
	{
		bornLess_Attack2->visible = true;
		bornLess_Attack2->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	}

	if (born_Attack2->frame.x == 3 ||
		bornLess_Attack2->frame.x == 3)
	{
		player_State = PLAYERSTATE::IDLE;

		if (INPUT->KeyPress(VK_LEFT) || INPUT->KeyPress(VK_RIGHT))
		{
			player_State = PLAYERSTATE::RUN;
		}
	}
}

void Player::B_Dash()
{
	for (int i = 0; i < 5; i++)
	{
		if (reverse)
		{
			born_Dash->reverseLR = true;
			bornLess_Dash->reverseLR = true;
			shadow[i]->born_DashShadow->reverseLR = true;
		}

		else if (!reverse)
		{
			born_Dash->reverseLR = false;
			bornLess_Dash->reverseLR = false;
			shadow[i]->born_DashShadow->reverseLR = false;
		}
	}
	

	AllInvisible();

	if (born_Check) { born_Dash->visible = true; }
	else if (!born_Check) { bornLess_Dash->visible = true; }
	

	if (TIMER->GetTick(shadow[index]->s_time, shadow[index]->s_interval))
	{
		shadow[index]->born_DashShadow->visible = true;
		shadow[index]->born_DashShadow->SetWorldPos(Vector2(player_Col->GetWorldPos().x - 5.0f, player_Col->GetWorldPos().y - 80.0f));
		shadow[index]->born_DashShadow->Update();
		
		index++;

		if (index == 4)
		{
			index = 0;
		}
	}
}

void Player::B_Skill_A()
{
	if (born_Check)
	{
		if (reverse)
		{
			bornSkill_A->reverseLR = true;
			bornSkill_B->reverseLR = true;
			born_Head->reverseLR = true;
		}

		else if (!reverse)
		{
			bornSkill_A->reverseLR = false;
			bornSkill_B->reverseLR = false;
			born_Head->reverseLR = false;
		}
	
		AllInvisible();
		bornSkill_A->visible = true;
		bCheck = false;

		//IDLE
		if (bornSkill_A->frame.x >= 3.0f)
		{
			//cout << "Skill_A -> IDLE" << endl;
			player_State = PLAYERSTATE::IDLE;
			HeadLess_Visible();
			born_Check = false;
			bornSkill_A->visible = false;
		}
	}
	
}

void Player::B_Skill_B()
{
	if (reverse)
	{
		bornSkill_B->reverseLR = true;
	}

	else if (!reverse)
	{
		bornSkill_B->reverseLR = false;
	}

	AllInvisible();
	bornSkill_B->visible = true;
	bornSkill_A->visible = false;
	//bCheck = true;

	if (bornSkill_B->frame.x == 8)
	{
		//cout << "Skill_B -> IDLE" << endl;
		player_State = PLAYERSTATE::IDLE;
		bornSkill_B->visible = false;
		born_Check = true;
	}
}

void Player::B_Die()
{
	die_time += DELTA;

	AllInvisible();
	born_Dead->visible = true;
	born_Dead->ChangeAnim(ANIMSTATE::LOOP, 0.060f);

	if (born_Dead->frame.x >= 22.0f)
	{
		born_Dead->ChangeAnim(ANIMSTATE::STOP, 0.0f);
		born_Dead->visible = false;
	}

	else
	{
		SOUND->Play("Skill_B");
	}

	if (die_time > 1.5f)
	{
		//cout << "11" << endl;
		SCENE->ChangeScene("마왕성");
	}

	if (retry)
	{
		player_State = PLAYERSTATE::IDLE;
		die_time = 0.0f;
	}
}

bool Player::Shooting(ObImage* player, float scalar, Vector2 firePos)
{
	if (!born_Head->visible)
	{
		born_HeadCol->colOnOff = true;

		born_HeadCol->visible = false;
		born_Head->visible = true;

		born_HeadCol->SetWorldPos(Vector2(0,0));
		born_HeadCol->SetWorldPos(Vector2(firePos.x, firePos.y));

		cout << firePos.y << endl;

		//born_HeadCol->rotation = Utility::DirToRadian(player_Col->GetRight());

		if (!reverse)
		{
			Shoot = player_Col->GetRight();
		}
		
		else if(reverse)
		{
			Shoot = -player_Col->GetRight();
		}
		
		this->scalar = 200.0f + scalar * 5.0f;

		gravity = 0.0f;
		return true;
	}

	return false;
}

void Player::GetShoot()
{
	Shooting(born_Head, 150.0f, Vector2(player_Col->GetWorldPos().x + 1.0f, player_Col->GetWorldPos().y + 58.0f));
}

void Player::Shooting()
{
	Vector2 head2 = headShoot_LastPos - born_HeadCol->GetWorldPos();
	float head2_distance = head2.Length();

	//cout << boolalpha << groundInter << endl;

	if (headShoot_Check)
	{
		GetShoot();
		Vector2 velocity = Shoot * scalar;
		born_HeadCol->MoveWorldPos(velocity * DELTA);
		shoot_time2 += DELTA;

		if (!groundInter)
		{
			born_HeadCol->rotation += 400.0f * ToRadian * DELTA;
		}

		if (head2_distance >= 400.0f && !groundInter)
		{
			scalar = 0.0f;
			born_HeadCol->MoveWorldPos(DOWN * 180.0f * DELTA);

			if(!bCheck)
			{
				//bCheck = true;
				//Hit_Skul->visible = true;
				//Hit_Skul->SetWorldPos(Vector2(born_HeadCol->GetWorldPos().x, born_HeadCol->GetWorldPos().y - 130.0f));
			}
		}

		if (player_Col->Intersect(born_HeadCol) && headShoot_Check)
		{
			if (shoot_time2 >= 0.5f)
			{
				born_Head->visible = false;
				born_HeadCol->visible = false;
				headShoot_Check = false;
				groundInter = false;
				born_Check = true;
				shoot_time2 = 0.0f;
			}
		}
	}

	else if (born_Head->visible == false &&
			 GetState() != PLAYERSTATE::SKILL2)
	{
		born_HeadCol->SetWorldPos(Vector2(player_Col->GetWorldPos().x, player_Col->GetWorldPos().y + 70.0f));
	}
}

void Player::G_Idle()
{
	G_AllInvisible();
	guard_Idle->visible = true;

	if (reverse)
	{
		guard_Idle->reverseLR = true;
		guard_Idle->SetLocalPosX(-20.0f);
		Hit_Skul->reverseLR = true;
	}

	else
	{
		guard_Idle->reverseLR = false;
		guard_Idle->SetLocalPosX(20.0f);
		Hit_Skul->reverseLR = false;
	}

	guard_Attack1->frame.x = 0;
	guard_Attack2->frame.x = 0;
	guard_Attack3->frame.x = 0;
	guard_Jump->frame.x = 0;
	guard_JumpAttack->frame.x = 0;
	guard_Dash->frame.x = 0;

	doubleJump->visible = false;

	guard_Skill_A->frame.x = 0;
	guard_Skill_B->frame.x = 0;
	guard_Switch->frame.x = 0;

	skill_Slash->visible = false;
	skill_Slash->frame.x = 0;

	fireSlash->visible = false;
	fireSlash->frame.x = 0;

	//스킬 A
	if (INPUT->KeyDown('A'))
	{
		player_State = PLAYERSTATE::SKILL1;
		//SOUND->Play("Skill_A");
		slashPos = player_Col->GetWorldPos();
	}

	//스킬 B
	if (INPUT->KeyDown('S'))
	{
		player_State = PLAYERSTATE::SKILL2;
		//SOUND->Play("Skill_B");

		fireBall_Check = true;
	}
}

void Player::G_Run()
{
	G_AllInvisible();

	if (reverse)
	{
		guard_Walk->reverseLR = true;
		guard_Walk->SetLocalPosX(-10.0f);
	}

	else
	{
		guard_Walk->reverseLR = false;
		guard_Walk->SetLocalPosX(10.0f);
	}
	guard_Idle->visible = false;
	guard_Walk->visible = true;
}

void Player::G_Jump()
{
	G_AllInvisible();
	guard_Jump->visible = true;
	guard_Dash->frame.x = 0;

	if (reverse)
	{
		guard_Jump->reverseLR = true;
		guard_Jump->SetLocalPosX(-10.0f);
	}

	else if (!reverse)
	{
		guard_Jump->reverseLR = false;
		guard_Jump->SetLocalPosX(10.0f);
	}

	guard_JumpAttack->frame.x = 0;

	guard_Jump->ChangeAnim(ANIMSTATE::LOOP, 0.15f);

	if (guard_Jump->frame.x == 7.0f)
	{
		guard_Jump->ChangeAnim(ANIMSTATE::STOP, 0);
	}

	//점프상태에선 스킬 X
	////스킬 A
	//if (INPUT->KeyDown('A'))
	//{
	//	player_State = PLAYERSTATE::SKILL1;
	//	//SOUND->Play("Skill_A");
	//}
	//
	////스킬 B
	//if (INPUT->KeyDown('S'))
	//{
	//	player_State = PLAYERSTATE::SKILL2;
	//	//SOUND->Play("Skill_B");
	//}
}

void Player::G_DownJump()
{
	G_AllInvisible();
	guard_Jump->visible = true;

	if (reverse)
	{
		guard_Jump->reverseLR = true;
		guard_Jump->SetLocalPosX(-10.0f);
	}

	else if (!reverse)
	{
		guard_Jump->reverseLR = false;
		guard_Jump->SetLocalPosX(10.0f);
	}

	guard_JumpAttack->frame.x = 0;

	guard_Jump->ChangeAnim(ANIMSTATE::LOOP, 0.15f);

	if (guard_Jump->frame.x == 7.0f)
	{
		guard_Jump->ChangeAnim(ANIMSTATE::STOP, 0);
	}
}

void Player::G_JumpAttack()
{
	G_AllInvisible();
	guard_JumpAttack->visible = true;
	guard_JumpAttack->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	if (reverse)
	{
		guard_JumpAttack->reverseLR = true;
		guard_JumpAttack->SetLocalPosX(-3.0f);
	}

	else if (!reverse)
	{
		guard_JumpAttack->reverseLR = false;
		guard_JumpAttack->SetLocalPosX(3.0f);
	}

	if (guard_JumpAttack->frame.x >= 4.0f)
	{
		player_State = PLAYERSTATE::JUMP;
	}
}

void Player::G_Attack1()
{
	G_AllInvisible();
	guard_Attack1->visible = true;
	guard_Attack1->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	if (reverse)
	{
		guard_Attack1->reverseLR = true;
		guard_Attack1->SetLocalPosX(-35.0f);
	}

	else if (!reverse)
	{
		guard_Attack1->reverseLR = false;
		guard_Attack1->SetLocalPosX(35.0f);
	}

	if (guard_Attack1->frame.x == 4.0f)
	{
		guard_Attack1->ChangeAnim(ANIMSTATE::STOP, 0);
		player_State = PLAYERSTATE::IDLE;

		if (INPUT->KeyPress(VK_LEFT) || INPUT->KeyPress(VK_RIGHT))
		{
			player_State = PLAYERSTATE::RUN;
		}
	}
}

void Player::G_Attack2()
{
	G_AllInvisible();
	guard_Attack2->visible = true;
	guard_Attack2->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	if (reverse)
	{
		guard_Attack2->reverseLR = true;
		guard_Attack2->SetLocalPosX(-35.0f);
	}

	else if (!reverse)
	{
		guard_Attack2->reverseLR = false;
		guard_Attack2->SetLocalPosX(35.0f);
	}

	if (guard_Attack2->frame.x == 4.0f)
	{
		guard_Attack2->ChangeAnim(ANIMSTATE::STOP, 0);
		player_State = PLAYERSTATE::IDLE;

		if (INPUT->KeyPress(VK_LEFT) || INPUT->KeyPress(VK_RIGHT))
		{
			player_State = PLAYERSTATE::RUN;
		}
	}
}

void Player::G_Attack3()
{
	G_AllInvisible();
	guard_Attack3->visible = true;
	guard_Attack3->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	if (reverse)
	{
		guard_Attack3->reverseLR = true;
		guard_Attack3->SetLocalPosX(-55.0f);
	}

	else if (!reverse)
	{
		guard_Attack3->reverseLR = false;
		guard_Attack3->SetLocalPosX(55.0f);
	}

	if (guard_Attack3->frame.x == 4.0f)
	{
		player_State = PLAYERSTATE::IDLE;

		if (INPUT->KeyPress(VK_LEFT) || INPUT->KeyPress(VK_RIGHT))
		{
			player_State = PLAYERSTATE::RUN;
		}
	}
}

void Player::G_Dash()
{
	G_AllInvisible();
	guard_Dash->visible = true;
	guard_Dash->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	if (reverse)
	{
		guard_Dash->reverseLR = true;
	}

	else if (!reverse)
	{
		guard_Dash->reverseLR = false;
	}

	if (guard_Dash->frame.x >= 3.0f)
	{
		guard_Dash->ChangeAnim(ANIMSTATE::STOP, 0);
	}
}

void Player::G_Skill_A()
{
	G_AllInvisible();
	guard_Skill_A->visible = true;

	if (reverse)
	{
		guard_Skill_A->reverseLR = true;
		guard_Skill_A->SetLocalPosX(-5.0f);
		skill_Slash->SetWorldPos(Vector2(slashPos.x - 220.0f, slashPos.y + 40.0f));
		skill_Slash->reverseLR = true;
	}

	else if (!reverse)
	{
		guard_Skill_A->reverseLR = false;
		guard_Skill_A->SetLocalPosX(5.0f);
		skill_Slash->SetWorldPos(Vector2(slashPos.x + 220.0f, slashPos.y + 40.0f));
		skill_Slash->reverseLR = false;
	}

	if (guard_Skill_A->frame.x >= 17.0f)
	{
		slash_Check = true;
		skill_Slash->visible = true;
	}

	if (guard_Skill_A->frame.x >= 21.0f)
	{
		GetState() = PLAYERSTATE::IDLE;
	}
}

void Player::G_Skill_B()
{
	G_AllInvisible();
	//fireBall_Check = true;
	guard_Skill_B->visible = true;

	if (guard_Skill_B->visible)
	{
		if (guard_Skill_B->frame.x >= 2.0f)
		{
			fireSlash->visible = true;
		}
	}

	fireBall->visible = true;
	fireBall_Col->visible = true;
	
	if (reverse)
	{
		guard_Skill_B->reverseLR = true;
		fireBall->reverseLR = true;
		fireSlash->reverseLR = true;
		guard_Skill_B->SetLocalPosX(-55.0f);
	}

	else if (!reverse)
	{
		guard_Skill_B->reverseLR = false;
		fireBall->reverseLR = false;
		fireSlash->reverseLR = false;
		guard_Skill_B->SetLocalPosX(55.0f);
	}

	if (guard_Skill_B->frame.x >= 7.0f)
	{
		GetState() = PLAYERSTATE::IDLE;
	}

	if (fireBall->frame.x >= 11.0f)
	{

	}
}

void Player::G_Die()
{
	G_AllInvisible();
}

bool Player::G_Shooting(ObImage* player1, float scalar1, Vector2 firePos1)
{
	if (!fireBall->visible)
	{
		//fireBall->visible = true;

		fireBall_Col->SetWorldPos(Vector2(firePos1.x, firePos1.y));

		fireBall_Col->rotation = Utility::DirToRadian(player_Col->GetRight());

		if (!reverse)
		{
			Shoot1 = player_Col->GetRight();
		}

		else if (reverse)
		{
			Shoot1 = -player_Col->GetRight();
		}

		this->scalar1 = 200.0f + scalar1 * 5.0f;

		gravity = 0.0f;
		return true;
	}

	return false;
}

void Player::G_GetShoot()
{
	G_Shooting(fireBall, 150.0f, Vector2(player_Col->GetWorldPos().x + 1.0f, player_Col->GetWorldPos().y + 60.0f));
}


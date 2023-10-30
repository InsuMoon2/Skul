#include "stdafx.h"

Guard::Guard()
{
	Skul_State = SKUL::Guard;

	guard_Idle = new ObImage(L"Guard_Idle.png");
	guard_Idle->scale = Vector2(390.0f / 6.0f, 65.0f) * 2.5f;
	guard_Idle->SetLocalPos(Vector2(13.0f, 55.0f));
	guard_Idle->maxFrame = Int2(6,1);
	guard_Idle->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	guard_Idle->visible = false;

	guard_Walk = new ObImage(L"Guard_Walk.png");
	guard_Walk->scale = Vector2(455.0f / 7.0f, 65.0f) * 2.5f;
	guard_Walk->SetLocalPos(Vector2(25.0f, 50.0f));
	guard_Walk->maxFrame = Int2(7, 1);
	guard_Walk->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	guard_Walk->visible = false;

	guard_Dash = new ObImage(L"Guard_Dash.png");
	guard_Dash->scale = Vector2(640.0f / 5.0f, 42.0f) * 2.5f;
	guard_Dash->SetLocalPos(Vector2(25.0f, 50.0f));
	guard_Dash->maxFrame = Int2(5, 1);
	guard_Dash->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	guard_Dash->visible = false;
	
	guard_Jump = new ObImage(L"Guard_Jump.png");
	guard_Jump->scale = Vector2(1176.0f / 8.0f, 92.0f) * 2.5f;
	guard_Jump->SetLocalPos(Vector2(25.0f, 50.0f));
	guard_Jump->maxFrame = Int2(8, 1);
	guard_Jump->ChangeAnim(ANIMSTATE::ONCE, 0.15f);
	guard_Jump->visible = false;

	guard_JumpAttack = new ObImage(L"Guard_Jump_Attack.png");
	guard_JumpAttack->scale = Vector2(735.0f / 5.0f, 92.0f) * 2.5f;
	guard_JumpAttack->SetLocalPos(Vector2(25.0f, 50.0f));
	guard_JumpAttack->maxFrame = Int2(5, 1);
	guard_JumpAttack->ChangeAnim(ANIMSTATE::ONCE, 0.15f);
	guard_JumpAttack->visible = false;
	
	guard_Attack1 = new ObImage(L"Guard_Attack1.png");
	guard_Attack1->scale = Vector2(500.0f / 5.0f, 100.0f) * 2.5f;
	guard_Attack1->SetLocalPos(Vector2(25.0f, 50.0f));
	guard_Attack1->maxFrame = Int2(5, 1);
	guard_Attack1->ChangeAnim(ANIMSTATE::ONCE, 0.15f);
	guard_Attack1->visible = false;
	
	guard_Attack2 = new ObImage(L"Guard_Attack2.png");
	guard_Attack2->scale = Vector2(550.0f / 5.0f, 110.0f) * 2.5f;
	guard_Attack2->SetParentRT(*player_Col);
	guard_Attack2->SetLocalPos(Vector2(25.0f, 50.0f));
	guard_Attack2->maxFrame = Int2(5, 1);
	guard_Attack2->ChangeAnim(ANIMSTATE::ONCE, 0.15f);
	guard_Attack2->visible = false;
	
	guard_Attack3 = new ObImage(L"Guard_Attack3.png");
	guard_Attack3->scale = Vector2(660.0f / 6.0f, 110.0f) * 2.5f;
	guard_Attack3->SetParentRT(*player_Col);
	guard_Attack3->SetLocalPos(Vector2(25.0f, 50.0f));
	guard_Attack3->maxFrame = Int2(6, 1);
	guard_Attack3->ChangeAnim(ANIMSTATE::ONCE, 0.15f);
	guard_Attack3->visible = false;
	
	guard_Skill_A = new ObImage(L"Guard_Skill1.png");
	guard_Skill_A->scale = Vector2(3234.0f / 22.0f, 92.0f) * 2.5f;
	guard_Skill_A->SetParentRT(*player_Col);
	guard_Skill_A->SetLocalPos(Vector2(25.0f, 50.0f));
	guard_Skill_A->maxFrame = Int2(22, 1);
	guard_Skill_A->ChangeAnim(ANIMSTATE::ONCE, 0.15f);
	guard_Skill_A->visible = false;
	
	guard_Skill_B = new ObImage(L"Guard_Skill2.png");
	guard_Skill_B->scale = Vector2(1200.0f / 8.0f, 75.0f) * 2.5f;
	guard_Skill_B->SetParentRT(*player_Col);
	guard_Skill_B->SetLocalPos(Vector2(25.0f, 50.0f));
	guard_Skill_B->maxFrame = Int2(8, 1);
	guard_Skill_B->ChangeAnim(ANIMSTATE::ONCE, 0.15f);
	guard_Skill_B->visible = false;
	
	guard_Switch = new ObImage(L"Guard_Switch.png");
	guard_Switch->scale = Vector2(1350.0f / 9.0f, 80.0f) * 2.5f;
	guard_Switch->SetParentRT(*player_Col);
	guard_Switch->SetLocalPos(Vector2(25.0f, 50.0f));
	guard_Switch->maxFrame = Int2(9, 1);
	guard_Switch->ChangeAnim(ANIMSTATE::ONCE, 0.15f);
	guard_Switch->visible = false;
}

Guard::~Guard()
{
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

}

void Guard::Update()
{
	Character::Update();

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

	if (reverse)
	{
		guard_Walk->reverseLR = true;
		guard_Idle->reverseLR = true;
	}

	else
	{
		guard_Walk->reverseLR = false;
		guard_Idle->reverseLR = false;
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
}

void Guard::Render()
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

	Character::Render();
}

void Guard::G_Idle()
{
	G_AllInvisible();
	guard_Idle->visible = true;

	if (reverse)
	{
		guard_Idle->reverseLR = true;
		Hit_Skul->reverseLR = true;
	}

	else
	{
		guard_Idle->reverseLR = false;
		Hit_Skul->reverseLR = false;
	}

	guard_Attack1->frame.x = 0;
	guard_Attack2->frame.x = 0;
	guard_Attack3->frame.x = 0;
	guard_JumpAttack->frame.x = 0;

	doubleJump->visible = false;

	guard_Skill_A->frame.x = 0;
	guard_Skill_B->frame.x = 0;
	guard_Switch->frame.x = 0;

	//스킬 A
	if (INPUT->KeyDown('A'))
	{
		player_State = PLAYERSTATE::SKILL1;
		//SOUND->Play("Skill_A");
	}

	//스킬 B
	if (INPUT->KeyDown('S'))
	{
		player_State = PLAYERSTATE::SKILL2;
		//SOUND->Play("Skill_B");
	}
}

void Guard::G_Run()
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

	guard_Walk->visible = true;

	//스킬 A
	if (INPUT->KeyDown('A'))
	{
		player_State = PLAYERSTATE::SKILL1;
		//SOUND->Play("Skill_A");
	}

	//스킬 B
	if (INPUT->KeyDown('S'))
	{
		player_State = PLAYERSTATE::SKILL2;
		//SOUND->Play("Skill_B");
	}
}

void Guard::G_Jump()
{
	G_AllInvisible();
	guard_Jump->visible = true;

	if (reverse)
	{
		guard_Jump->reverseLR = true;
	}

	else if (!reverse)
	{
		guard_Jump->reverseLR = false;
	}

	guard_JumpAttack->frame.x = 0;

	if (guard_Jump->frame.x == 7.0f)
	{
		guard_Jump->ChangeAnim(ANIMSTATE::STOP, 0);
	}

	//스킬 A
	if (INPUT->KeyDown('A'))
	{
		player_State = PLAYERSTATE::SKILL1;
		//SOUND->Play("Skill_A");
	}

	//스킬 B
	if (INPUT->KeyDown('S'))
	{
		player_State = PLAYERSTATE::SKILL2;
		//SOUND->Play("Skill_B");
	}
}

void Guard::G_DownJump()
{
	G_AllInvisible();
	guard_Jump->visible = true;

	if (reverse)
	{
		guard_Jump->reverseLR = true;
	}

	else if (!reverse)
	{
		guard_Jump->reverseLR = false;
	}

	guard_JumpAttack->frame.x = 0;

	if (guard_Jump->frame.x == 7.0f)
	{
		guard_Jump->ChangeAnim(ANIMSTATE::STOP, 0);
	}

	//스킬 A
	if (INPUT->KeyDown('A'))
	{
		player_State = PLAYERSTATE::SKILL1;
		//SOUND->Play("Skill_A");
	}

	//스킬 B
	if (INPUT->KeyDown('S'))
	{
		player_State = PLAYERSTATE::SKILL2;
		//SOUND->Play("Skill_B");
	}
}
//----------------------
void Guard::G_JumpAttack()
{
	G_AllInvisible();
	guard_JumpAttack->visible = true;
	guard_JumpAttack->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	if (reverse)
	{
		guard_JumpAttack->reverseLR = true;
	}

	else if (!reverse)
	{
		guard_JumpAttack->reverseLR = false;
	}

	if (guard_JumpAttack->frame.x >= 4.0f)
	{
		player_State = PLAYERSTATE::JUMP;
	}
}

void Guard::G_Attack1()
{
	G_AllInvisible();
	guard_Attack1->visible = true;
	guard_Attack1->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	if (reverse)
	{
		guard_Attack1->reverseLR = true;
	}

	else if (!reverse)
	{
		guard_Attack1->reverseLR = false;
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

void Guard::G_Attack2()
{
	G_AllInvisible();
	guard_Attack2->visible = true;
	guard_Attack2->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	if (reverse)
	{
		guard_Attack2->reverseLR = true;
	}

	else if (!reverse)
	{
		guard_Attack2->reverseLR = false;
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

void Guard::G_Attack3()
{
	G_AllInvisible();
	guard_Attack3->visible = true;
	guard_Attack3->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	if (reverse)
	{
		guard_Attack3->reverseLR = true;
	}

	else if (!reverse)
	{
		guard_Attack3->reverseLR = false;
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

void Guard::G_Dash()
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
}

void Guard::G_Skill_A()
{
	G_AllInvisible();
	guard_Skill_A->visible = true;

	if (reverse)
	{
		guard_Skill_A->reverseLR = true;
		guard_Skill_A->SetWorldPosX(-5.0f);
	}

	else if (!reverse)
	{
		guard_Skill_A->reverseLR = false;
		guard_Skill_A->SetWorldPosX(5.0f);
	}
	
}

void Guard::G_Skill_B()
{
	G_AllInvisible();
	guard_Skill_B->visible = true;
}

void Guard::G_Die()
{
	G_AllInvisible();

}






#include "stdafx.h"

Character::Character()
{
	player_Col = new ObRect();
	player_Col->scale = Vector2(1000.0f / 4.0f * 0.3f, 500.0f / 2.0f * 0.35f);
	player_Col->SetWorldPos(Vector2(-750.0f ,240.0f));
	player_Col->visible = false;
	player_Col->isFilled = false;
	player_Col->pivot = OFFSET_B;
	player_Col->collider = COLLIDER::RECT;

	attack_Col = new ObRect();
	attack_Col->scale = Vector2(60.0f, 120.0f);
	attack_Col->SetParentRT(*player_Col);
	attack_Col->visible = false;
	attack_Col->isFilled = false;
	attack_Col->color = Color(0.0f, 1.0f, 0.0f, 1.0f);
	attack_Col->pivot = OFFSET_B;
	attack_Col->collider = COLLIDER::RECT;

	attack_Col2 = new ObRect();
	attack_Col2->scale = Vector2(60.0f, 120.0f);
	attack_Col2->SetParentRT(*player_Col);
	attack_Col2->visible = false;
	attack_Col2->isFilled = false;
	attack_Col2->color = Color(0.0f, 0.0f, 1.0f, 1.0f);
	attack_Col2->pivot = OFFSET_B;
	attack_Col2->collider = COLLIDER::RECT;

	Jump_attack_Col = new ObRect();
	Jump_attack_Col->scale = Vector2(70.0f, 140.0f);
	Jump_attack_Col->SetParentRT(*player_Col);
	Jump_attack_Col->SetLocalPosY(-30.0f);
	Jump_attack_Col->visible = false;
	Jump_attack_Col->isFilled = false;
	Jump_attack_Col->color = Color(0.0f, 1.0f, 0.0f, 1.0f);
	Jump_attack_Col->pivot = OFFSET_B;
	Jump_attack_Col->collider = COLLIDER::RECT;

	player_Head = new ObRect();
	player_Head->scale = Vector2(50.0f, 10.0f);
	player_Head->SetParentRT(*player_Col);
	player_Head->SetLocalPosY(85.0f);
	player_Head->visible = false;
	player_Head->isFilled = false;
	player_Head->pivot = OFFSET_T;
	player_Head->collider = COLLIDER::RECT;
	player_Head->color = Color(0.5f, 0.0f, 0.0f, 1.0f);

	player_Bottom = new ObRect();
	player_Bottom->scale = Vector2(50.0f, 10.0f);
	player_Bottom->SetParentRT(*player_Col);
	player_Bottom->visible = false;
	player_Bottom->isFilled = false;
	player_Bottom->pivot = OFFSET_B;
	player_Bottom->collider = COLLIDER::RECT;
	player_Bottom->color = Color(0.5f, 0.0f, 0.0f, 1.0f);

	player_Left = new ObRect();
	player_Left->scale = Vector2(10.0f, 50.0f);
	player_Left->SetParentRT(*player_Col);
	player_Left->SetLocalPosX(-38.0f);
	player_Left->SetLocalPosY(42.5f);
	player_Left->visible = false;
	player_Left->isFilled = false;
	player_Left->pivot = OFFSET_L;
	player_Left->collider = COLLIDER::RECT;
	player_Left->color = Color(0.5f, 0.0f, 0.0f, 1.0f);

	player_Right = new ObRect();
	player_Right->scale = Vector2(10.0f, 50.0f);
	player_Right->SetParentRT(*player_Col);
	player_Right->SetLocalPosX(38.0f);
	player_Right->SetLocalPosY(42.5f);
	player_Right->visible = false;
	player_Right->isFilled = false;
	player_Right->pivot = OFFSET_R;
	player_Right->collider = COLLIDER::RECT;
	player_Right->color = Color(0.5f, 0.0f, 0.0f, 1.0f);

	doubleJump = new ObImage(L"DoubleJump_Smoke.png");
	doubleJump->scale = Vector2(960.0f / 10.0f, 96.0f) * 2.0f;
	doubleJump->maxFrame = Int2(10, 1);
	doubleJump->pivot = OFFSET_B;
	doubleJump->visible = false;

	dash_Effect = new ObImage(L"skul_Dash_Effect.bmp");
	dash_Effect->scale = Vector2(4654.0f / 13.0f, 398.0f * 0.8f) * 0.7f;
	dash_Effect->maxFrame = Int2(13, 2);
	dash_Effect->frame.y = 0;
	dash_Effect->pivot = OFFSET_B;
	dash_Effect->visible = false;
	
	Hit_Skul = new ObImage(L"Hit_Skul.png");
	Hit_Skul->scale = Vector2(1920.0f / 10.0f , 192.0f) * 1.6f;
	//Hit_Skul->SetParentT(*player_Col);
	Hit_Skul->maxFrame = Int2(10, 1);
	Hit_Skul->pivot = OFFSET_B;
	Hit_Skul->ChangeAnim(ANIMSTATE::LOOP, 0.06f);
	Hit_Skul->visible = false;

	Hit_normal = new ObImage(L"hit_normal.png");
	Hit_normal->scale = Vector2(1152.0f / 12.0f, 96.0f) * 1.6f;
	//Hit_Skul->SetParentT(*player_Col);
	Hit_normal->maxFrame = Int2(12, 1);
	Hit_normal->pivot = OFFSET_B;
	Hit_normal->ChangeAnim(ANIMSTATE::LOOP, 0.06f);
	Hit_normal->visible = false;

	//인벤토리
	inven = new ObImage(L"Inventory_Frame.png");
	inven->scale = Vector2(1600.0f, 856.0f);
	inven->visible = false;
	inven->space = SPACE::SCREEN;

	black = new ObImage(L"black.bmp");
	black->scale = Vector2(1600.0f, 1000.0f);
	black->visible = false;
	black->color = Color(0.5f, 0.5f, 0.5f, 0.25f);
	black->space = SPACE::SCREEN;

	//Player Ui
	playerUi = new PlayerUi;


	gravity = 0.0f;
	reverse = false;

	//Sound
	SOUND->AddSound("Default_Dash.wav", "대쉬", false);
	SOUND->AddSound("Default_Jump.wav", "점프", false);
	SOUND->AddSound("Default_Jump_Air.wav", "더블점프", false);
	SOUND->AddSound("Skul_Atk 1.wav", "어택1", false);
	SOUND->AddSound("Skul_Atk 2.wav", "어택2", false);
	SOUND->AddSound("Skul_Jump_Atk.wav", "점프어택", false);
	SOUND->AddSound("Hit.wav", "Hit", false);

	SOUND->AddSound("UI_Inventory_Open.wav", "Inventory_Open", false);
	SOUND->AddSound("UI_Inventory_Close.wav", "Inventory_Close", false);

	SOUND->AddSound("DavyJones_AmTheSea_Thunder_Hit.wav", "Thunder", false);
	
	//캐릭터 상태
	player_State = PLAYERSTATE::IDLE;
	Skul_State = SKUL::LittleBorn;
	
	//처음에 바라보는 방향 오른쪽으로
	lastDir.x = 1.0f;
}

Character::~Character()
{
	SafeDelete(player_Col);
	SafeDelete(doubleJump);

	SafeDelete(dash_Effect);
	SafeDelete(player_Head);
	SafeDelete(player_Bottom);
	SafeDelete(player_Left);
	SafeDelete(player_Right);
	SafeDelete(Jump_attack_Col);
	SafeDelete(Hit_Skul);

	SafeDelete(inven);
	SafeDelete(black);

}

void Character::Update()
{
	lastPos = player_Col->GetWorldPos();

	switch (player_State)
	{
	case PLAYERSTATE::IDLE:
		Idle();
		break;
	case PLAYERSTATE::RUN:
		Run();
		break;
	case PLAYERSTATE::JUMP:
		Jump();
		break;
	case PLAYERSTATE::DOWNJUMP:
		DownJump();
		break;
	case PLAYERSTATE::JUMPATTACK:
		JumpAttack();
		break;
	case PLAYERSTATE::ATTACK1:
		Attack1();
		break;
	case PLAYERSTATE::ATTACK2:
		Attack2();
		break;
	case PLAYERSTATE::ATTACK3:
		Attack3();
		break;
	case PLAYERSTATE::SKILL1:
		Skill_A();
		break;
	case PLAYERSTATE::SKILL2:
		Skill_B();
		break;
	case PLAYERSTATE::DASH:
		Dash();
		break;
	}

	if (reverse)
	{
		attack_Col->SetLocalPosX(-50.0f);
		attack_Col2->SetLocalPosX(-50.0f);
		Jump_attack_Col->SetLocalPosX(-50.0f);
	}

	else if(!reverse)
	{
		attack_Col->SetLocalPosX(50.0f);
		attack_Col2->SetLocalPosX(50.0f);
		Jump_attack_Col->SetLocalPosX(50.0f);
	}

	if (dash_Effect->frame.x == 12)
	{
		dash_Effect->visible = false;
	}

	doubleJump->SetWorldPos(jumpSmoke);

	if (INPUT->KeyDown(VK_TAB))
	{
		inven->visible = !inven->visible;
		black->visible = !black->visible;

		if (inven->visible)
		{
			SOUND->Play("Inventory_Open");
		}

		if (!inven->visible)
		{
			SOUND->Play("Inventory_Close");
		}
	}

	dash_Effect->Update();
	player_Col->Update();
	attack_Col->Update();
	attack_Col2->Update();
	doubleJump->Update();

	player_Bottom->Update();
	player_Head->Update();
	player_Left->Update();
	player_Right->Update();
	Jump_attack_Col->Update();
	Hit_Skul->Update();
	Hit_normal->Update();

	inven->Update();
	black->Update();

	playerUi->Update();

	if (Skul_State == SKUL::Guard)
	{
		playerUi->GuardVisible();
	}

	else
	{
		//getWeapon = false가 무기를 들고있을 때임.
		if (!getWeapon)
		{
			//playerUi->BornVisible();
		}

		//무기를 안들고 있을 때
		else
		{
			//처음에 Init 초기값으로 지정
		}
	}
}

void Character::Render()
{
	wstring temp = to_wstring(born_Hp);

	if (HpChecking)
	{
		DWRITE->RenderText(temp, RECT{ 190, 920,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
			30.0f, L"휴먼매직체", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_BOLD);

		DWRITE->RenderText(L" / 290", RECT{ 240, 920,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
			30.0f, L"휴먼매직체", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_BOLD);
	}
	
	player_Col->Render();
	attack_Col->Render();
	attack_Col2->Render();
	Jump_attack_Col->Render();
	player_Head->Render();
	player_Bottom->Render();
	player_Left->Render();
	player_Right->Render();
	doubleJump->Render();

	playerUi->Render();

	dash_Effect->Render();
	Hit_Skul->Render();
	Hit_normal->Render();

	

	black->Render();
	inven->Render();
}

void Character::StepBack()
{
	player_Col->SetWorldPos(Vector2(lastPos.x , lastPos.y));

	player_Col->Update();
	player_Bottom->Update();
	player_Head->Update();
	player_Left->Update();
	player_Right->Update();
}

//IDLE
void Character::Idle()
{
	Input();
	playerSpeed = 500.0f;
	attack_Col->visible = false;
	attack_Col2->visible = false;
	Jump_attack_Col->visible = false;

	player_Col->colOnOff = true;

	attack_Col->colOnOff = true;
	attack_Col2->colOnOff = true;

	Hit_Skul->frame.x = 0;
	Hit_Skul->visible = false;
	
	if (Hit_Skul->frame.x >= 8.5f)
	{
		Hit_Skul->ChangeAnim(ANIMSTATE::STOP, 0);
	}

	attack_Time = 0.0f;
	attack_Time2 = 0.0f;

	//Idle -> Run
	if (INPUT->KeyDown(VK_RIGHT))
	{
		reverse = false;
		player_State = PLAYERSTATE::RUN;
	}

	if (INPUT->KeyDown(VK_LEFT))
	{
		reverse = true;
		player_State = PLAYERSTATE::RUN;
	}

	//Idle -> Attack
	if (INPUT->KeyDown('X'))
	{
		if (Skul_State == SKUL::LittleBorn)
		{
			SOUND->Stop("어택1");
			SOUND->Play("어택1");
			//cout << "Idle -> 공격" << endl;
		}

		player_State = PLAYERSTATE::ATTACK1;
		attack = true;
	}

	//Idle -> Dash
	if (INPUT->KeyDown('Z') && dash_Count > 0)
	{
		SOUND->Stop("대쉬");
		SOUND->Play("대쉬");
		//cout << "Idle -> 대쉬" << endl;
		moving = player_Col->GetWorldPos();
		player_State = PLAYERSTATE::DASH;
		dash_Count--;

		dashSmoke = player_Col->GetWorldPos();
		dash_time = 0.3f;
	}

	//아래 점프
	if (INPUT->KeyPress(VK_DOWN) && INPUT->KeyDown('C'))
	{
		player_State = PLAYERSTATE::DOWNJUMP;
	}
}

//RUN
void Character::Run()
{
	Hit_Skul->frame.x = 0;
	Hit_Skul->visible = false;

	if (Hit_Skul->frame.x >= 8.5f)
	{
		Hit_Skul->ChangeAnim(ANIMSTATE::STOP, 0);
	}

	Input();
	playerSpeed = 500.0f;

	attack_Time = 0.0f;
	attack_Time2 = 0.0f;

	//cout << "RUN!!!!" << endl;
	//Run -> Idle
	if (INPUT->KeyUp(VK_RIGHT))
	{
		moveDir.x = 0.0f;
		player_State = PLAYERSTATE::IDLE;
	}

	if (INPUT->KeyUp(VK_LEFT))
	{
		moveDir.x = 0.0f;
		player_State = PLAYERSTATE::IDLE;
	}

	//Run -> RunAttack
	if (INPUT->KeyDown('X'))
	{
		if (Skul_State == SKUL::LittleBorn)
		{
			SOUND->Stop("어택1");
			SOUND->Play("어택1");
			//cout << "Run -> Run Attack" << endl;
			
			//attack = true;
		}

		player_State = PLAYERSTATE::ATTACK1;
	}
	
	//Run -> Dash
	if (INPUT->KeyDown('Z') && dash_Count > 0)
	{
		SOUND->Stop("대쉬");
		SOUND->Play("대쉬");
		//cout << "런 -> 대쉬" << endl;
		moving = player_Col->GetWorldPos();
		player_State = PLAYERSTATE::DASH;
		dash_Count--;

		dashSmoke = player_Col->GetWorldPos();
		dash_time = 0.3f;
	}

	//아래 점프
	if (INPUT->KeyPress(VK_DOWN) && INPUT->KeyDown('C'))
	{
		player_State = PLAYERSTATE::DOWNJUMP;
	}
	
}

//JUMP
void Character::Jump()
{
	Hit_Skul->frame.x = 0;
	Hit_Skul->visible = false;

	if (Hit_Skul->frame.x >= 8.5f)
	{
		Hit_Skul->ChangeAnim(ANIMSTATE::STOP, 0);
	}

	Input();
	playerSpeed = 500.0f;
	attack_Col->visible = false;
	attack_Col2->visible = false;
	Jump_attack_Col->visible = false;
	Jump_attack_Col->colOnOff = true;

	attack_Time = 0.0f;
	attack_Time2 = 0.0f;

	if (INPUT->KeyDown(VK_LEFT))
	{
		reverse = true;
	}

	if (INPUT->KeyDown(VK_RIGHT))
	{
		reverse = false;
	}

	//더블 점프
	if (INPUT->KeyDown('C') && !jump)
	{
		SOUND->Stop("점프");
		SOUND->Play("더블점프");
		gravity = -650.0f;
		jump = true;
		doubleJump->visible = true;
		//cout << "Double Jump" << endl;
		doubleJump->ChangeAnim(ANIMSTATE::ONCE, 0.07f);

		JUMPANI() = 0;
		JUMPANI2() = 0;
		JUMPANI3() = 0;
	}
	
	//Jump -> JumpAttack
	if (INPUT->KeyDown('X'))
	{
		if (Skul_State == SKUL::LittleBorn)
		{
			SOUND->Stop("점프어택");
			SOUND->Play("점프어택");
		}
		//cout << "점프 공격 zz" << endl;
		player_State = PLAYERSTATE::JUMPATTACK;
	}

	//Jump -> Dash
	if (INPUT->KeyDown('Z') && dash_Count > 0)
	{
		SOUND->Stop("대쉬");
		SOUND->Play("대쉬");
		//cout << "점프 -> 대쉬" << endl;
		moving = player_Col->GetWorldPos();
		player_State = PLAYERSTATE::DASH;
		dash_Count--;

		dashSmoke = player_Col->GetWorldPos();
		dash_time = 0.3f;
	}

	//Jump -> Idle
	//땅 충돌 - 이건 Scene에서
}

void Character::DownJump()
{
	Input();
	
	//아래점프 어케함? zz
	//downjump_Checking = true;
	
	if (downjump_Checking)
	{
		downjump_Time += DELTA;
	}

	if (0.01f < downjump_Time && downjump_Time < 0.2f)
	{
		player_Bottom->colOnOff = false;
		SOUND->Play("점프");
		gravity = 0.0f;
		GetGravity() = 300.0f;
		jump = false;
		doubleJump->visible = false;
	}

	if (downjump_Time > 0.2f)
	{
		player_Bottom->colOnOff = true;
		downjump_Checking = false;
		downjump_Time = 0.0f;
	}

	//더블 점프
	if (INPUT->KeyDown('C') && !jump)
	{
		SOUND->Stop("점프");
		SOUND->Play("더블점프");
		gravity = -650.0f;
		jump = true;
		doubleJump->visible = true;
		//cout << "Double Jump" << endl;
		doubleJump->ChangeAnim(ANIMSTATE::ONCE, 0.07f);

		JUMPANI() = 0;
		JUMPANI2() = 0;
		JUMPANI3() = 0;
	}

	//Jump -> Dash
	if (INPUT->KeyDown('Z') && dash_Count > 0)
	{
		SOUND->Stop("대쉬");
		SOUND->Play("대쉬");
		//cout << "점프 -> 대쉬" << endl;
		moving = player_Col->GetWorldPos();
		player_State = PLAYERSTATE::DASH;
		dash_Count--;

		dashSmoke = player_Col->GetWorldPos();
		dash_time = 0.3f;
	}
	
	//아래점프 -> IDle Or Run은 바닥에 충돌 시 - Scene에서 실행
}

void Character::JumpAttack()
{
	jumpground_Check = false;
	Input();
	playerSpeed = 500.0f;
	//Jump_attack_Col->visible = true;

	//JumpAttack -> Jump
	//Player에서

	//JumpAttack -> Idle
	//땅 충돌 - Scene
}

//ATTACK
void Character::Attack1()
{
	jumpground_Check = false;
	Input();
	playerSpeed = 0.0f;
	attack_Col->visible = false;

	//cout << attack_Time << endl;

	attack_Time += DELTA;

	if (attack_Time < 0.05f)
	{
		player_Col->MoveWorldPos(moveDir * 1200.0f * DELTA);
	}

	//Attack -> Idle
	//Player에서

	//Attack -> Run
	//Player에서

	if (INPUT->KeyDown('X'))
	{
		if (ANI() >= 2 ||
			ANI2() >= 2)
		{
			if (Skul_State == SKUL::LittleBorn)
			{
				SOUND->Stop("어택2");
				SOUND->Play("어택2");
				player_State = PLAYERSTATE::ATTACK2;
			}
			//cout << "ATTACK 2222" << endl;
			
		}

		else if (ANI3() >= 2)
		{
			if (Skul_State == SKUL::Guard)
			{
				//SOUND->Stop("어택2");
				//SOUND->Play("어택2");
				player_State = PLAYERSTATE::ATTACK2;
			}
			//cout << "ATTACK 2222" << endl;
			
		}
	}
}

void Character::Attack2()
{
	jumpground_Check = false;
	Input();
	playerSpeed = 0.0f;
	attack_Col2->visible = false;
	//attack_Col2->colOnOff = true;

	attack_Time2 += DELTA;

	if (attack_Time2 < 0.05f)
	{
		player_Col->MoveWorldPos(moveDir * 1200.0f * DELTA);
	}

	if (INPUT->KeyPress(VK_LEFT) || INPUT->KeyDown(VK_LEFT) ||
		INPUT->KeyUp(VK_LEFT))
	{
		reverse = true;
		moveDir.x = -1.0f;
	}

	else if (INPUT->KeyPress(VK_RIGHT) || INPUT->KeyDown(VK_RIGHT) ||
		INPUT->KeyUp(VK_RIGHT))
	{
		reverse = false;
		moveDir.x = 1.0f;
	}

	if (Skul_State == SKUL::Guard)
	{
		if (INPUT->KeyDown('X'))
		{
			if (ANI4() >= 3.0f)
			{
				//SOUND->Stop("어택2");
				//SOUND->Play("어택2");
				player_State = PLAYERSTATE::ATTACK3;
				
				//cout << "ATTACK 2222" << endl;
			}
		}
	}
}

void Character::Attack3()
{
	jumpground_Check = false;
	Input();
	playerSpeed = 0.0f;

	attack_Time3 += DELTA;

	if (attack_Time3 < 0.05f)
	{
		player_Col->MoveWorldPos(moveDir * 1200.0f * DELTA);
	}

	if (INPUT->KeyPress(VK_LEFT) || INPUT->KeyDown(VK_LEFT) ||
		INPUT->KeyUp(VK_LEFT))
	{
		reverse = true;
		moveDir.x = -1.0f;
	}

	else if (INPUT->KeyPress(VK_RIGHT) || INPUT->KeyDown(VK_RIGHT) ||
		INPUT->KeyUp(VK_RIGHT))
	{
		reverse = false;
		moveDir.x = 1.0f;
	}
}

//DASH
void Character::Dash()
{
	jumpground_Check = false;
	//Input();
	playerSpeed = 500.0f;
	gravity = 0.0f;

	player_Col->colOnOff = false;

	dash_time -= DELTA;

	dash_Effect->visible = true;
	dash_Effect->ChangeAnim(ANIMSTATE::ONCE, 0.02f);
	dash_Effect->SetWorldPos(Vector2(dashSmoke.x, dashSmoke.y - 50.0f));

	//Dash -> Jump
	//player_Col->MoveWorldPos(lastDir * 1300.0f * DELTA);

	////이동거리 제한 거리로
	//Vector2 disDash = player_Col->GetWorldPos() - moving;
	//distance = disDash.Length();
	//if (distance >= 300.0f)
	//{
	//	player_State = PLAYERSTATE::JUMP;
	//}

	//이동거리 제한 시간으로
	//시간제한을 둔 이유 ?
	//이동거리로하면 벽으로 대쉬를 쓰면 거리를 이동을 못해서 대쉬가
	//안끝나서 점프상태로 돌아가지를 않는다.
	//대쉬가 0.3초 이상 지속되면 꺼지게 제한

	if (dash_time > 0.0f)
	{
		player_Col->MoveWorldPos(lastDir * 1300.0f * DELTA);
	}

	else
	{
		player_State = PLAYERSTATE::JUMP;
	}

	if (reverse)
	{
		dash_Effect->reverseLR = true;
	}

	else
	{
		dash_Effect->reverseLR = false;
	}
}

void Character::Input()
{
	moveDir = Vector2(0.0f, 0.0f);

	if (INPUT->KeyDown('C') && !jump)
	{
		SOUND->Play("점프");
		//cout << "점프" << endl;
		jump = false;
		gravity = -650.0f;
		jumpSmoke = player_Col->GetWorldPos();
		player_State = PLAYERSTATE::JUMP;
	}

	if (INPUT->KeyPress(VK_LEFT))
	{
		moveDir.x = -1.0f;
		lastDir = moveDir;
	}

	else if (INPUT->KeyPress(VK_RIGHT))
	{
		moveDir.x = 1.0f;
		lastDir = moveDir;
	}
	
	if (INPUT->KeyPress(VK_LEFT) && INPUT->KeyPress(VK_RIGHT))
	{
		moveDir.x = 0.0f;

		if (!(player_State == PLAYERSTATE::JUMP))
		{
			player_State = PLAYERSTATE::IDLE;
		}
	}

	if (player_State != PLAYERSTATE::JUMP)
	{
		if (INPUT->KeyDown(VK_LEFT) && INPUT->KeyPress(VK_RIGHT))
		{
			player_State = PLAYERSTATE::RUN;
		}

		if (INPUT->KeyDown(VK_RIGHT) && INPUT->KeyPress(VK_LEFT))
		{
			player_State = PLAYERSTATE::RUN;
		}
	}

	//DownJump();

	moveDir.Normalize();

	player_Col->MoveWorldPos(moveDir * playerSpeed * DELTA);
	player_Col->MoveWorldPos(DOWN * gravity * DELTA);

	gravity += 1300.0f * DELTA;
}

void Character::Skill_A()
{
	if (Skul_State == SKUL::LittleBorn)
	{
		//Input();
	}	
}

void Character::Skill_B()
{
	gravity = 0.0f;
}



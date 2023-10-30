#include "stdafx.h"

void Scene03::Init()
{
	pl = new Player();
	pl->player_Col->SetLocalPos(Vector2(-1550.0f, -5.0f));

	knight = new Knight();
	knight->monster_Col->SetLocalPos(Vector2(-1150.0f, 30.0f));

	bigEnt = new BigEnt();
	bigEnt->monster_Col->SetLocalPos(Vector2(77.0f, 111.0f));
	bigEnt->monster_Col->scale = Vector2(100.0f, 100.0f) * 2.2f;
	bigEnt->monster_HpBar->scale = Vector2(170.0f, 16.0f);
	bigEnt->monster_HpBar->SetLocalPosX(-69.0f);
	bigEnt->monster_Hp->scale = Vector2(159.0f, 9.0f);
	bigEnt->monster_Hp->SetLocalPosX(-64.0f);
	bigEnt->monster_Hp->SetLocalPosY(-18.0f);

	hammer = new Hammer();
	hammer->monster_Col->SetLocalPos(Vector2(-260.0f, -584.0f));
	hammer->monster_Col->scale = Vector2(120.0f, 150.0f);
	hammer->monster_Recognize->scale = Vector2(600.0f, 300.0f);
	hammer->monster_HpBar->scale = Vector2(210.0f, 16.0f);
	hammer->monster_HpBar->SetLocalPosX(-97.0f);
	hammer->monster_Hp->scale = Vector2(199.0f, 9.0f);
	hammer->monster_Hp->SetLocalPosX(-92.0f);

	stage1_bg = new ObImage(L"stage01_1.png");
	stage1_bg->scale = Vector2(1920.0f * 2.0f, 800.0f * 2.5f);
	stage1_bg->SetLocalPosY(200.0f);
	stage1_bg->visible = true;

	stage1 = new ObImage(L"stage01_map.png");
	stage1->scale = Vector2(3200.0f, 1728.0f) * 1.2f;
	stage1->visible = true;

	boss_gateCol = new ObRect();
	boss_gateCol->scale = Vector2(1050.0f , 420.0f);
	boss_gateCol->SetWorldPos(Vector2(740.0f, 30.0f));
	boss_gateCol->pivot = OFFSET_LT;
	boss_gateCol->visible = false;
	boss_gateCol->isFilled = false;

	boss_gateWall = new ObImage(L"Gate_Wall.png");
	boss_gateWall->scale = Vector2(960.0f, 250.0f);
	boss_gateWall->SetParentRT(*boss_gateCol);
	boss_gateWall->SetLocalPos(Vector2(50.0f, -160.0f));
	boss_gateWall->pivot = OFFSET_LT;
	boss_gateWall->visible = true;

	boss_gateNormal = new ObImage(L"gate_boss_normal.png");
	boss_gateNormal->scale = Vector2(314.0f, 185.0f) * 1.8f;
	boss_gateNormal->SetParentRT(*boss_gateCol);
	boss_gateNormal->SetLocalPos(Vector2(20.0f, -60.0f));
	boss_gateNormal->pivot = OFFSET_LT;
	boss_gateNormal->visible = true;

	boss_gateOpen = new ObImage(L"gate_boss_Open.png");
	boss_gateOpen->scale = Vector2(2512.0f / 8.0f, 185.0f) * 1.8f;
	boss_gateOpen->SetParentRT(*boss_gateCol);
	boss_gateOpen->SetLocalPos(Vector2(13.0f, -57.0f));
	boss_gateOpen->pivot = OFFSET_LT;
	boss_gateOpen->maxFrame = Int2(8,1);
	boss_gateOpen->visible = false;

	input = new ObImage(L"Input.png");
	input->scale = Vector2(452.0f, 92.0f * 0.5f);
	input->SetParentRT(*boss_gateNormal);
	input->SetLocalPos(Vector2(280.0f, -350.0f));
	input->visible = false;

	//블럭1
	{
	for (int i = 0; i < 8; i++)
	{
		block[i] = new ObRect();
		block[i]->pivot = OFFSET_LT;
		block[i]->visible = false;
		block[i]->isFilled = false;
		block[i]->collider = COLLIDER::RECT;
	}

	block[0]->scale = Vector2(1380.0f, 195.0f);
	block[0]->SetWorldPos(Vector2(-1920.0f, 30.0f));

	block[1]->scale = Vector2(382.0f, 368.0f);
	block[1]->SetWorldPos(Vector2(-75.0f, 108.0f));

	block[2]->scale = Vector2(1300.0f, 45.0f);
	block[2]->SetWorldPos(Vector2(-616.0f, -580.0f));

	block[3]->scale = Vector2(1220.0f, 215.0f);
	block[3]->SetWorldPos(Vector2(695.0f, -355.0f));
	block[3]->color = Color(1.0f, 0.0f, 0.0f, 1.0f);

	block[4]->scale = Vector2(380.0f, 283.0f);
	block[4]->SetWorldPos(Vector2(232.0f, 273.0f));

	block[5]->scale = Vector2(454.0f, 159.0f);
	block[5]->SetWorldPos(Vector2(158.0f, 431.0f));

	block[6]->scale = Vector2(374.0f, 137.0f);
	block[6]->SetWorldPos(Vector2(-222.0f, 566.0f));

	block[7]->scale = Vector2(50.0f, 412.0f);
	block[7]->SetWorldPos(Vector2(-671.0f, -167.0f));
	block[7]->color = Color(1.0f, 0.0f, 0.0f, 1.0f);
	}
	
	//블럭2
	{

	for (int i = 0; i < 2; i++)
	{
		block2[i] = new ObRect();
		block2[i]->pivot = OFFSET_LT;
		block2[i]->visible = false;
		block2[i]->isFilled = false;
		block2[i]->collider = COLLIDER::RECT;
		block2[i]->color = Color(0.0f, 0.3f, 1.0f, 1.0f);
	}

	block2[0]->scale = Vector2(149.0f, 10.0f);
	block2[0]->SetWorldPos(Vector2(-382.0f, -38.0f));

	block2[1]->scale = Vector2(296.0f, 10.0f);
	block2[1]->SetWorldPos(Vector2(-381.0f, -270.0f));

	}

	enemy_Icon = new ObImage(L"Enemy_Icon.png");
	enemy_Icon->scale = Vector2(12.0f, 10.0f) * 4.0f;
	enemy_Icon->SetWorldPos(Vector2(620.0f, -445.0f));
	enemy_Icon->visible = true;
	enemy_Icon->space = SPACE::SCREEN;
}

void Scene03::Release()
{
	SafeDelete(stage1);
	SafeDelete(stage1_bg);
	SafeDelete(boss_gateCol);
	SafeDelete(boss_gateNormal);
	SafeDelete(boss_gateOpen);
	SafeDelete(input);

	for (int i = 0; i < 8; i++)
	{
		SafeDelete(block[i]);
	}

	for (int i = 0; i < 2; i++)
	{
		SafeDelete(block2[i]);
	}
}

void Scene03::Update()
{
	//cout << "마우스 X좌표 : " << INPUT->GetMouseWorldPos().x << endl;
	//cout << "마우스 Y좌표 : " << INPUT->GetMouseWorldPos().y << endl;

	//Knight - Player
	Vector2 dis = knight->monster_Col->GetWorldPos() - pl->player_Col->GetWorldPos();
	dis.Normalize();

	//Hammer - Player
	dis2 = hammer->monster_Col->GetWorldPos() - pl->player_Col->GetWorldPos();
	dis2.Normalize();

	//cout << distance << endl;

	lastPos = pl->player_Col->GetWorldPos();

	stage1_bg->uv.x += DELTA / stage1_bg->scale.x * -25.0f;
	stage1_bg->uv.z += DELTA / stage1_bg->scale.x * -25.0f;

	//Reverse - Attack, Die가 아닐 때
	if (dis.x > 0 && 
		knight->Get_MonsterState() != MonsterState::ATTACK &&
		knight->Get_MonsterState() != MonsterState::DIE &&
		knight->Get_MonsterState() != MonsterState::HIT)
	{
		reverse = false;
		monsterDir.x = -1.0f;
	}

	else if (dis.x < 0 && 
			 knight->Get_MonsterState() != MonsterState::ATTACK &&
			 knight->Get_MonsterState() != MonsterState::DIE &&
			 knight->Get_MonsterState() != MonsterState::HIT)
	{
		reverse = true;
		monsterDir.x = 1.0f;
	}

	//Reverse
	if (reverse)
	{
		knight->knight_AttackCol->SetLocalPosX(50.0f);
		knight->knight_Idle->reverseLR = true;
		knight->knight_Walk->reverseLR = true;
		knight->knight_Attack->reverseLR = true;
		knight->knight_Attack2->reverseLR = true;
		knight->knight_Hit->reverseLR = true;
		knight->knight_Die->reverseLR = true;
	}

	else
	{
		knight->knight_AttackCol->SetLocalPosX(-50.0f);
		knight->knight_Idle->reverseLR = false;
		knight->knight_Walk->reverseLR = false;
		knight->knight_Attack->reverseLR = false;
		knight->knight_Attack2->reverseLR = false;
		knight->knight_Hit->reverseLR = false;
		knight->knight_Die->reverseLR = false;
	}

	//Knight Hit 시 뒤로 조금 밀려나게
	if (knight->hit && knight->Get_MonsterState() != MonsterState::DIE)
	{
		if (reverse)
		{
			knight->monster_Col->MoveWorldPos(-knight->monster_Col->GetRight() * 20.0f * DELTA);
		}
		
		else
		{
			knight->monster_Col->MoveWorldPos(knight->monster_Col->GetRight() * 20.0f * DELTA);
		}
	}

	//Kinght 공격 시 앞으로 조금 움직이게
	if (knight->Get_MonsterState() == MonsterState::ATTACK2)
	{
		if (reverse)
		{
			knight->monster_Col->MoveWorldPos(RIGHT * 30.0f * DELTA);
		}

		else
		{
			knight->monster_Col->MoveWorldPos(LEFT * 30.0f * DELTA);
		}
	}

	pl->Update();
	stage1->Update();
	stage1_bg->Update();
	knight->Update();
	bigEnt->Update();
	hammer->Update();
	boss_gateNormal->Update();
	boss_gateWall->Update();
	boss_gateOpen->Update();
	boss_gateCol->Update();
	input->Update();
	enemy_Icon->Update();

	for (int i = 0; i < 8; i++)
	{
		block[i]->Update();
	}

	for (int i = 0; i < 2; i++)
	{
		block2[i]->Update();
	}


	//cout << "HP : " << knight->knight_Hp << endl;
	//cout << "Player_HP : " << pl->born_Hp << endl;
}

void Scene03::LateUpdate()
{
	//플레이어 가두기
	pl->player_Col->SetWorldPosX(Utility::Saturate(pl->player_Col->GetWorldPos().x, -1850.0f, 1785.0f));
	//캠
	CAM->position.x = Utility::Saturate(pl->player_Col->GetWorldPos().x, -1885.0f + app.GetHalfWidth(), 1815.0f - app.GetHalfWidth());
	CAM->position.y = Utility::Saturate(pl->player_Col->GetWorldPos().y + 250.0f, -800.0f, 530.0f);

	//머리 날리기
	Vector2 dis = pl->player_Col->GetWorldPos() - pl->born_HeadCol->GetWorldPos();
	float distance = dis.Length();

	float	scalar = 100.0f;

	//Shoot Time에 제한을 둔 이유
	//born_Head가 플레이어의 현재 위치에서부터 날라가서
	//시작부터 충돌판정이 나서 0.5초의 제한을 두었음.
	if (pl->shoot_time > 0.5f)
	{
		if (pl->born_HeadCol->Intersect(pl->player_Col))
		{
			pl->born_HeadCol->visible = false;
			pl->born_Head->visible = false;

			pl->born_Check = true;
		}
	}

	//S누르면 머리 자리로 이동하면서, born_Head visible false로 변경
	if (pl->GetState() == PLAYERSTATE::SKILL2)
	{
		pl->born_Head->visible = false;
		pl->player_Col->SetWorldPos(Vector2(pl->born_HeadCol->GetWorldPos().x, pl->born_HeadCol->GetWorldPos().y - 30.0f));
	}

	for (int i = 0; i < 8; i++)
	{
		if (!block[i]->Intersect(pl->born_HeadCol))
		{
			if (distance > 520.0f)
			{
				//cout << "22" << endl;
				pl->born_HeadCol->MoveWorldPos(DOWN * scalar * DELTA);
			}
		}

		if (block[i]->Intersect(pl->born_HeadCol))
		{
			scalar = 0.0f;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		if (!block2[i]->Intersect(pl->born_HeadCol))
		{
			if (distance > 520.0f)
			{
				//cout << "22" << endl;
				pl->born_HeadCol->MoveWorldPos(DOWN * scalar * DELTA);
			}
		}

		if (block2[i]->Intersect(pl->born_HeadCol))
		{
			scalar = 0.0f;
		}
	}

	//player_Col을 밑으로 내리면 LR이 충돌판정이 나서 올려야함.

	//충돌
	{
	if (pl->GetGravity() > 0.0f)
	{
		for (int i = 0; i < 8; i++)
		{
			//블럭 아래 충돌
			if (block[i]->Intersect(pl->GetBPos()))
			{
				pl->player_Col->SetWorldPosY(block[i]->GetLocalPos().y - 1.0f);
				pl->GetGravity() = 0.0f;
				pl->GetDashCount() = 2;

				if (pl->player_State == PLAYERSTATE::JUMP ||
					pl->player_State == PLAYERSTATE::JUMPATTACK)
				{
					pl->player_State = PLAYERSTATE::IDLE;
					pl->born_Jump->frame.x = 0;
					pl->jump = false;

					if (INPUT->KeyPress(VK_LEFT))
					{
						pl->reverse = true;
						pl->player_State = PLAYERSTATE::RUN;
					}

					if (INPUT->KeyPress(VK_RIGHT))
					{
						pl->reverse = false;
						pl->player_State = PLAYERSTATE::RUN;
					}
				}
			}
		}

		for (int i = 0; i < 2; i++)
		{
			if (block2[i]->Intersect(pl->GetBPos()))
			{
				pl->player_Col->SetWorldPosY(block2[i]->GetLocalPos().y - 1.0f);
				pl->GetGravity() = 0.0f;
				pl->GetDashCount() = 2;

				if (pl->player_State == PLAYERSTATE::JUMP ||
					pl->player_State == PLAYERSTATE::JUMPATTACK)
				{
					pl->player_State = PLAYERSTATE::IDLE;
					pl->born_Jump->frame.x = 0;
					pl->jump = false;

					if (INPUT->KeyPress(VK_LEFT))
					{
						pl->reverse = true;
						pl->player_State = PLAYERSTATE::RUN;
					}

					if (INPUT->KeyPress(VK_RIGHT))
					{
						pl->reverse = false;
						pl->player_State = PLAYERSTATE::RUN;
					}
				}
			}
		}
	}

		if (block[3]->Intersect(hammer->monster_Col))
		{
			hammer->monster_Col->SetLocalPosX(block[3]->GetWorldPos().x - hammer->monster_Col->scale.x - 1.0f);

			hammer->reverse = !hammer->reverse;
		}

		if (block[7]->Intersect(hammer->monster_Col))
		{
			hammer->monster_Col->SetLocalPosX(block[7]->GetWorldPos().x + hammer->monster_Col->scale.x + 1.0f);

			hammer->reverse = !hammer->reverse;
		}

	for (int i = 0; i < 8; i++)
	{
		//블럭 머리통 충돌
		if (block[i]->Intersect(pl->GetHPos()))
		{
			//cout << "Head Shot";
			//pl->player_Col->SetWorldPosY(block[i]->GetWorldPos().y + (test->scale.y - 85.0f - 87.5f));
			pl->player_Col->SetWorldPosY(lastPos.y);
			pl->player_Col->Update();
			pl->player_Bottom->Update();
			pl->player_Head->Update();
			pl->player_Left->Update();
			pl->player_Right->Update();
		}

		//블럭 옆 충돌
		if (block[i]->Intersect(pl->GetRPos()))
		{
			//cout << "11";
			pl->player_Col->SetWorldPosX(block[i]->GetLocalPos().x - 38.5f);
			//pl->StepBack();
		}

		if (block[i]->Intersect(pl->GetLPos()))
		{
			//cout << "22";
			pl->player_Col->SetWorldPosX(block[i]->GetLocalPos().x + block[i]->scale.x + 38.5f);
			//pl->StepBack();
		}
	}

	}

	if (knight->monster_Hp->scale.x <= 0.0f)
	{
		knight->monster_Hp->visible = false;
		knight->monster_HpBar->visible = false;
	}

	//몬스터 타입 - Knight
	if (knight->Get_MonsterType() == MonsterType::M_Knight)
	{
		//knight 충돌

		//Hit 상태가 아닐 때, 몬스터 인식범위에 플레이어가 들어오면
		if (knight->monster_Recognize->Intersect(pl->player_Col) && !knight->hit)
		{
			//몬스터 Col이랑 플레이어 Col이 충돌할 때
			if (knight->monster_Col->Intersect(pl->player_Col))
			{
				//cout << "222" << endl;
				knight->Get_MonsterState() = MonsterState::ATTACK;
			}

			if (knight->Get_MonsterState() == MonsterState::ATTACK)
			{
				if (knight->knight_Attack->frame.x >= 2)
				{
					knight->Get_MonsterState() = MonsterState::MOVE;
				}
			}

			//인식범위에 들어왔지만, 충돌하지 않을 때
			//상태가 Move로 바뀌면서 Player쪽으로 이동
			else if(!knight->monster_Col->Intersect(pl->player_Col))
			{
				//cout << "11" << endl;
				knight->monster_Col->MoveWorldPos(monsterDir * 200.0f * DELTA);
				knight->Get_MonsterState() = MonsterState::MOVE;
			}
		}

		//인식 범위에 들어오지 않으면 Knight가 Idle로
		else if (!knight->monster_Recognize->Intersect(pl->player_Col))
		{
			//cout << "22" << endl;
			knight->Get_MonsterState() = MonsterState::IDLE;
		}

		//플레이어 어택1이랑 충돌 시 Hit판정
		if (pl->player_State == PLAYERSTATE::ATTACK1)
		{
			if (knight->monster_Col->Intersect(pl->attack_Col))
			{
				pl->Hit_Skul->visible = true;
				pl->Hit_Skul->SetWorldPos(pl->attack_Col->GetWorldPos());
				pl->Hit_Skul->SetLocalPosY(-60.0f);

				pl->attack_Col->colOnOff = false;
				
				SOUND->Stop("Hit");
				SOUND->Play("Hit");
				
				Hit();

				if (knight->knight_Hp > 0.0f)
				{
					knight->knight_Hp -= 15.0f;
					knight->monster_Hp->scale.x -= 15.0f;
				}
			}
		}

		//플레이어 어택2랑 충돌 시 Hit판정
		else if (pl->player_State == PLAYERSTATE::ATTACK2)
		{
			if (knight->monster_Col->Intersect(pl->attack_Col2))
			{
				pl->Hit_Skul->visible = true;
				pl->Hit_Skul->SetWorldPos(pl->attack_Col2->GetWorldPos());
				pl->Hit_Skul->SetLocalPosY(-60.0f);

				pl->attack_Col2->colOnOff = false;
				SOUND->Stop("Hit");
				SOUND->Play("Hit");
				Hit();

				if (knight->knight_Hp > 0.0f)
				{
					knight->knight_Hp -= 15.0f;
					knight->monster_Hp->scale.x -= 15.0f;
				}
			}
		}

		//플레이어 점프어택이랑 충돌 시 Hit판정
		else if (pl->player_State == PLAYERSTATE::JUMPATTACK)
		{
			if (knight->monster_Col->Intersect(pl->Jump_attack_Col))
			{
				pl->Hit_Skul->visible = true;
				pl->Hit_Skul->SetWorldPos(pl->attack_Col2->GetWorldPos());
				pl->Hit_Skul->SetLocalPosY(-60.0f);

				pl->Jump_attack_Col->colOnOff = false;
				SOUND->Stop("Hit");
				SOUND->Play("Hit");
				Hit();
				//knight->Get_MonsterState() = MonsterState::HIT;
				//knight->hit = true;

				if (knight->knight_Hp > 0.0f)
				{
					knight->knight_Hp -= 15.0f;
					knight->monster_Hp->scale.x -= 15.0f;
				}
			}
		}

		if (knight->Get_MonsterState() == MonsterState::ATTACK)
		{
			if (knight->attack_Time < 0.3f)
			{
				SOUND->Play("Knight_Atk1");
			}
		}

		if (knight->Get_MonsterState() != MonsterState::HIT)
		{
			if (knight->attack_Time >= 0.7f)
			{
				knight->Get_MonsterState() = MonsterState::ATTACK2;
				SOUND->Play("Knight_Atk2");
			}
		}

		//한번만 들어와야하는데 계속 들어옴 Why? 
		//막을거 다 막았는데 얘만그럼. 어디서 꼬였는가
		if (knight->Get_MonsterState() == MonsterState::ATTACK)
		{
			knight->knight_AttackCol->colOnOff = true;
			pl->hit_time = 0.0f;
		}

		if (knight->Get_MonsterState() == MonsterState::ATTACK2)
		{
			if (pl->player_Col->Intersect(knight->knight_AttackCol))
			{
				//cout << "Knight -> Player Hit !!";
				knight->knight_AttackCol->colOnOff = false;
				pl->Hit_normal->visible = true;
				
				if (pl->born_Hp >= 0.0f)
				{
					pl->born_Hp -= 10.0f;
					pl->playerUi->player_Hp->scale.x -= 10.0f;

					SOUND->Stop("Hit");
					SOUND->Play("Hit");

					pl->Hit_normal->SetWorldPos(pl->player_Col->GetWorldPos());
					pl->Hit_normal->SetLocalPosY(0.0f);

					if (reverse)
					{
						pl->player_Col->MoveWorldPos(RIGHT * 1000.0f * DELTA);
					}

					else if (!reverse)
					{
						pl->player_Col->MoveWorldPos(LEFT * 1000.0f * DELTA);
					}

					hit_Check = true;
				}
			}
		}

		//Knight Die
		if (knight->knight_Hp <= 0.0f)
		{
			knight->Get_MonsterState() = MonsterState::DIE;
			knight->monster_Col->colOnOff = false;

			if (knight->d_time < 0.01f)
			{
				count--;
			}
		}

	}

	//몬스터 타입 - BigEnt
	if (bigEnt->Get_MonsterType() == MonsterType::M_BigEnt)
	{
		//Attack1이랑 충돌 시 Hit판정
		if (pl->player_State == PLAYERSTATE::ATTACK1)
		{
			if (bigEnt->monster_Col->Intersect(pl->attack_Col))
			{
				pl->Hit_Skul->visible = true;
				pl->Hit_Skul->SetWorldPos(pl->attack_Col2->GetWorldPos());
				pl->Hit_Skul->SetLocalPos(Vector2(20.0f, 20.0f));

				pl->attack_Col->colOnOff = false;

				SOUND->Stop("Hit");
				SOUND->Play("Hit");

				if (bigEnt->bigEnt_Hp >= 0.0f)
				{
					bigEnt->bigEnt_Hp -= 20.0f;
					bigEnt->monster_Hp->scale.x -= 20.0f;
				}
			}
		}

		//Attack2랑 충돌 시 Hit판정
		else if (pl->player_State == PLAYERSTATE::ATTACK2)
		{
			if (bigEnt->monster_Col->Intersect(pl->attack_Col2))
			{
				pl->Hit_Skul->visible = true;
				pl->Hit_Skul->SetWorldPos(pl->attack_Col2->GetWorldPos());
				pl->Hit_Skul->SetLocalPos(Vector2(20.0f, 20.0f));

				pl->attack_Col2->colOnOff = false;
				SOUND->Stop("Hit");
				SOUND->Play("Hit");

				if (bigEnt->bigEnt_Hp >= 0.0f)
				{
					bigEnt->bigEnt_Hp -= 20.0f;
					bigEnt->monster_Hp->scale.x -= 20.0f;
				}
			}
		}

		//점프어택이랑 충돌 시 Hit판정
		else if (pl->player_State == PLAYERSTATE::JUMPATTACK)
		{
			if (bigEnt->monster_Col->Intersect(pl->Jump_attack_Col))
			{
				pl->Hit_Skul->visible = true;
				pl->Hit_Skul->SetWorldPos(pl->attack_Col2->GetWorldPos());
				pl->Hit_Skul->SetLocalPos(Vector2(20.0f, 20.0f));

				pl->Jump_attack_Col->colOnOff = false;
				SOUND->Stop("Hit");
				SOUND->Play("Hit");

				if (bigEnt->bigEnt_Hp >= 0.0f)
				{
					bigEnt->bigEnt_Hp -= 20.0f;
					bigEnt->monster_Hp->scale.x -= 20.0f;
				}
			}
		}

		//Attack2
		if (bigEnt->bigEnt_Recog->Intersect(pl->player_Col))
		{
			if (!bigEnt->attack2_Checking && 
				!bigEnt->monster_Recognize->Intersect(pl->player_Col))
			{
				if (bigEnt->bigEnt_Attack1->frame.x >= 5)
				{
					bigEnt->bigEnt_Attack1->frame.x = 0;
				}
				
				bigEnt->Get_MonsterState() = MonsterState::ATTACK2;

			}

			//if (bigEnt->monster_Recognize->Intersect(pl->player_Col))
			//{
			//	bigEnt->bigEnt_Attack2->frame.x = 0;
			//	bigEnt->attack2_time = 0.0f;
			//	bigEnt->Get_MonsterState() = MonsterState::ATTACK;
			//}
		}

		//인식범위 충돌 ㄴㄴㄴㄴ
		else if (!bigEnt->bigEnt_Recog->Intersect(pl->player_Col))
		{
			bigEnt->bigEnt_Attack1->frame.x = 0;
			bigEnt->bigEnt_Attack2->frame.x = 0;
			bigEnt->Get_MonsterState() = MonsterState::IDLE;
			bigEnt->attack2_time = 0.0f;
			
		}

		//Bullet이랑 충돌
		for (int i = 0; i < BMAX; i++)
		{
			if (pl->player_Col->Intersect(bigEnt->bullet_Col[i]))
			{
				//cout << "11" <<endl;
				bigEnt->bullet_Col[i]->colOnOff = false;

				pl->born_Hp -= 20.0f;
				pl->playerUi->player_Hp->scale.x -= 20.0f;

				SOUND->Stop("Hit");
				SOUND->Play("Hit");

				if (reverse)
				{
					pl->player_Col->MoveWorldPos(LEFT * 1000.0f * DELTA);
				}

				else if (!reverse)
				{
					pl->player_Col->MoveWorldPos(RIGHT * 1000.0f * DELTA);
				}

				pl->Hit_normal->visible = true;
				pl->Hit_normal->SetWorldPos(Vector2(pl->player_Col->GetWorldPos()));
				//pl->Hit_normal->SetLocalPosY(100.0f);
			}
		}

		//BigEnt Die
		if (bigEnt->bigEnt_Hp <= 0.0f)
		{
			bigEnt->Get_MonsterState() = MonsterState::DIE;
			bigEnt->monster_Col->colOnOff = false;
			if (bigEnt->d_time < 0.01f)
			{
				count--;
			}
		}
		
	}

	//몬스터 타입 - Hammer
	if (hammer->Get_MonsterType() == MonsterType::M_Hammer)
	{
		//몬스터 인식범위에 플레이어가 들어오면
		if (hammer->monster_Recognize->Intersect(pl->player_Col))
		{
			//인써클
			if (dis2.x > 0 &&
				hammer->Get_MonsterState() != MonsterState::ATTACK &&
				hammer->Get_MonsterState() != MonsterState::ATTACK2 &&
				hammer->Get_MonsterState() != MonsterState::DIE)
			{
				hammer->reverse = true;

			}
			else if (dis2.x < 0 &&
				hammer->Get_MonsterState() != MonsterState::ATTACK &&
				hammer->Get_MonsterState() != MonsterState::ATTACK2 &&
				hammer->Get_MonsterState() != MonsterState::DIE)
			{
				hammer->reverse = false;
			}

			hammer->h_attack_Time += DELTA;

			//Attack2 태클 gogo
			if (1.53f <= hammer->h_attack_Time && hammer->h_attack_Time <= 1.55f)
			{
				random_Check = true;

				if (random_Check)
				{
					random = RANDOM->Int(1, 2);

					if (random == 1)
					{
						hammer->monster_Col->MoveWorldPos(dis2 * 200.0f * DELTA);
						hammer->Get_MonsterState() = MonsterState::ATTACK;

						float time = 0.0f;
						time += DELTA;

						if (time < 0.5f)
						{
							SOUND->Play("Hammer_Atk1");
						}
					}

					else if (random == 2)
					{
						hammer->Get_MonsterState() = MonsterState::ATTACK2;

						float time = 0.0f;
						time += DELTA;

						if (time < 0.5f)
						{
							SOUND->Play("Hammer_Atk2");
						}
					}
				}
			}
		}

		else if (!hammer->monster_Recognize->Intersect(pl->player_Col))
		{
			hammer->Get_MonsterState() = MonsterState::MOVE;
			hammer->h_attack_Time = 0.0f;
		}

		//cout << hammer->h_attack_Time2 << endl;

		

		//Hammer Attack1 충돌
		if (hammer->Get_MonsterState() == MonsterState::ATTACK)
		{	
			if (hammer->hammer_Attack1->frame.x >= 8.0f)
			{
				if (pl->player_Col->Intersect(hammer->hammer_Attack1_Col))
				{
					hammer->hammer_Attack1_Col->colOnOff = false;
					pl->Hit_normal->visible = true;

					if (pl->born_Hp >= 1.0f)
					{
						pl->born_Hp -= 20.0f;
						pl->playerUi->player_Hp->scale.x -= 20.0f;

						if (pl->reverse)
						{
							pl->player_Col->MoveWorldPos(RIGHT * 1000.0f * DELTA);
						}

						else if (!pl->reverse)
						{
							pl->player_Col->MoveWorldPos(LEFT * 1000.0f * DELTA);
						}

						SOUND->Stop("Hit");
						SOUND->Play("Hit");

						pl->Hit_normal->SetWorldPos(pl->player_Col->GetWorldPos());
						pl->Hit_normal->SetLocalPosY(-630.0f);
					}
				}
			}
				
				
			}
		
		else if (hammer->Get_MonsterState() == MonsterState::ATTACK2)
		{
			if (pl->player_Col->Intersect(hammer->hammer_Attack2_Col))
			{
				hammer->hammer_Attack2_Col->colOnOff = false;
				pl->Hit_normal->visible = true;
			
				if (pl->born_Hp >= 1.0f)
				{
					pl->born_Hp -= 30.0f;
					pl->playerUi->player_Hp->scale.x -= 30.0f;

					if (pl->reverse)
					{
						pl->player_Col->MoveWorldPos(RIGHT * 1000.0f * DELTA);
					}

					else if (!pl->reverse)
					{
						pl->player_Col->MoveWorldPos(LEFT * 1000.0f * DELTA);
					}

					SOUND->Stop("Hit");
					SOUND->Play("Hit");
			
					pl->Hit_normal->SetWorldPos(pl->player_Col->GetWorldPos());
					pl->Hit_normal->SetLocalPosY(-630.0f);
				}
			}
		}

		//어택1이랑 충돌 시 Hit판정
		if (pl->player_State == PLAYERSTATE::ATTACK1)
		{
			if (hammer->monster_Col->Intersect(pl->attack_Col))
			{
				pl->Hit_Skul->visible = true;
				pl->Hit_Skul->SetWorldPos(Vector2(pl->attack_Col2->GetWorldPos().x, (pl->attack_Col2->GetWorldPos().y - 60.0f)));
				//pl->Hit_Skul->SetWorldPosY(-60.0f);

				pl->attack_Col->colOnOff = false;
				SOUND->Stop("Hit");
				SOUND->Play("Hit");

				if (hammer->hammer_Hp >= 0.0f)
				{
					hammer->hammer_Hp -= 15.0f;
					hammer->monster_Hp->scale.x -= 15.0f;
				}
			}
		}

		//어택2랑 충돌 시 Hit판정
		else if (pl->player_State == PLAYERSTATE::ATTACK2)
		{
			if (hammer->monster_Col->Intersect(pl->attack_Col2))
			{
				pl->Hit_Skul->visible = true;
				pl->Hit_Skul->SetWorldPos(Vector2(pl->attack_Col2->GetWorldPos().x, (pl->attack_Col2->GetWorldPos().y - 60.0f)));
				//pl->Hit_Skul->SetWorldPosY(-60.0f);

				pl->attack_Col2->colOnOff = false;
				SOUND->Stop("Hit");
				SOUND->Play("Hit");

				if (hammer->hammer_Hp > 0.0f)
				{
					hammer->hammer_Hp -= 15.0f;
					hammer->monster_Hp->scale.x -= 15.0f;
				}
			}
		}

		//점프어택이랑 충돌 시 Hit판정
		else if (pl->player_State == PLAYERSTATE::JUMPATTACK)
		{
			if (hammer->monster_Col->Intersect(pl->Jump_attack_Col))
			{
				pl->Hit_Skul->visible = true;
				pl->Hit_Skul->SetWorldPos(Vector2(pl->attack_Col2->GetWorldPos().x , (pl->attack_Col2->GetWorldPos().y - 60.0f)));

				pl->Jump_attack_Col->colOnOff = false;
				SOUND->Stop("Hit");
				SOUND->Play("Hit");

				if (hammer->hammer_Hp >= 0.0f)
				{
					hammer->hammer_Hp -= 15.0f;
					hammer->monster_Hp->scale.x -= 15.0f;
				}
			}
		}

		//cout << hammer->hammer_Hp << endl;

		//Hammer Die
		if (hammer->hammer_Hp <= 0.0f)
		{
			hammer->Get_MonsterState() = MonsterState::DIE;
			hammer->monster_Col->colOnOff = false;

			if (hammer->d_time < 0.01f)
			{
				count--;
			}
		}
	}
	
	if (pl->Hit_normal->frame.x >= 11.0f)
	{
		pl->Hit_normal->visible = false;
		pl->Hit_normal->frame.x = 0.0f;
	}

	//보스방 입장
	if (count == 0)
	{
		input_Checking = true;
	}

	if (input_Checking)
	{
		boss_gateNormal->visible = false;
		boss_gateOpen->visible = true;
		boss_gateOpen->ChangeAnim(ANIMSTATE::LOOP, 0.2f);
		input->visible = false;
	}

	if (boss_gateCol->Intersect(pl->GetPos()))
	{
		if (count == 0)
		{
			input->visible = true;
		}
	}

	else
	{
		input->visible = false;
	}

	if (input->visible)
	{
		if (INPUT->KeyDown('F'))
		{
			cout << "Scene04 Change zz" << endl;
			SCENE->ChangeScene("보스");
			SOUND->Stop("Monster");
		}
	}
}

void Scene03::Render()
{
	wstring temp = to_wstring(count);
	DWRITE->RenderText(temp, RECT{ 1450, 920,(long)app.GetWidth() + (long)900.0f,(long)app.GetHalfHeight() + (long)600.0f },
		50.0f, L"휴먼매직체", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_BOLD);

	stage1_bg->Render();
	stage1->Render();

	boss_gateCol->Render();
	boss_gateWall->Render();
	boss_gateNormal->Render();
	boss_gateOpen->Render();
	input->Render();

	for (int i = 0; i < 8; i++)
	{
		block[i]->Render();
	}

	for (int i = 0; i < 2; i++)
	{
		block2[i]->Render();
	}

	knight->Render();
	bigEnt->Render();
	hammer->Render();
	enemy_Icon->Render();

	pl->Render();
	pl->Hit_normal->Render();

}

void Scene03::ResizeScreen()
{

}

void Scene03::Hit()
{
	knight->Get_MonsterState() = MonsterState::HIT;
	knight->hit = true;
}


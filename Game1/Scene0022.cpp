#include "stdafx.h"

void Scene0022::Init()
{
	pl = new Player();
	pl->player_Col->SetWorldPos(Vector2(-1620.0f, -960.0f));

	//Bg
	background = new ObImage(L"Tutorial_Background.png");
	background->scale = Vector2(1600.0f, 1000.0f * 1.5f) * 1.3f;
	background->SetWorldPos(Vector2(0.0f, 500.0f));
	background->space = SPACE::SCREEN;

	tutorial_Bg = new ObImage(L"Tutorial2.png");
	tutorial_Bg->scale = Vector2(1600.0f, 1000.0f) * 2.4f;

	ground = new ObRect();
	ground->scale = Vector2(3300.0f, 20.0f);
	ground->SetWorldPos(Vector2(-1930.0f, -960.0f));
	ground->pivot = OFFSET_LT;
	ground->visible = false;
	ground->isFilled = false;
	ground->collider = COLLIDER::RECT;

	//Cage
	cage_Col = new ObRect();
	cage_Col->scale = Vector2(220.0f, 160.0f) * 2.0f;
	cage_Col->SetWorldPos(Vector2(-290.0f, -960.0f));
	cage_Col->pivot = OFFSET_B;
	cage_Col->isFilled = false;
	cage_Col->visible = false;
	cage_Col->collider = COLLIDER::RECT;

	cage_Front = new ObImage(L"Cage_Front.png");
	cage_Front->scale = Vector2(198.0f, 135.0f) * 2.3f;
	cage_Front->SetParentRT(*cage_Col);
	cage_Front->pivot = OFFSET_B;
	cage_Front->visible = true;

	cage_Behind = new ObImage(L"Cage_Behind.png");
	cage_Behind->scale = Vector2(155.0f, 135.0f) * 2.3f;
	cage_Behind->SetParentRT(*cage_Col);
	cage_Behind->SetLocalPosX(-15.0f);
	cage_Behind->pivot = OFFSET_B;
	cage_Behind->visible = true;

	cage_Front_Dis = new ObImage(L"Cage_Front_Destroyed.png");
	cage_Front_Dis->scale = Vector2(198.0f, 123.0f) * 2.3f;
	cage_Front_Dis->SetParentRT(*cage_Col);
	cage_Front_Dis->pivot = OFFSET_B;
	cage_Front_Dis->visible = false;

	cage_Behind_Dis = new ObImage(L"Cage_Behind_Destroyed.png");
	cage_Behind_Dis->scale = Vector2(110.0f, 88.0f) * 2.3f;
	cage_Behind_Dis->SetParentRT(*cage_Col);
	cage_Behind_Dis->pivot = OFFSET_B;
	cage_Behind_Dis->visible = false;

	witch = new Witch();
	witch->Cage_Witch->SetWorldPos(Vector2(-290.0f, -920.0f));;
	witch->witch_Col->SetWorldPos(Vector2(-290.0f, -965.0f));
	witch->witch_Idle->SetParentRT(*witch->witch_Col);
	witch->witch_Poly->SetParentRT(*witch->witch_Col);
	witch->witch_Poly->SetLocalPos(Vector2(-15.0f, -20.0f));
	witch->cat_Idle->SetParentRT(*witch->witch_Col);
	witch->cat_Walk->SetParentRT(*witch->witch_Col);
	witch->Witch_State() = WITCHSTATE::CAGE;

	//Gate
	gate_Close = new ObImage(L"gateClose.png");
	gate_Close->scale = Vector2(173.0f, 124.0f) * 2.4f;
	gate_Close->SetWorldPos(Vector2(810.0f, -820.0f));
	gate_Close->visible = true;

	gate_Normal = new ObImage(L"gate_normal.png");
	gate_Normal->scale = Vector2(1536.0f / 8.0f, 192.0f) * 2.4f;
	gate_Normal->maxFrame = Int2(8, 1);
	gate_Normal->SetWorldPos(Vector2(810.0f, -820.0f));
	gate_Normal->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	gate_Normal->visible = false;

	gate_Rect = new ObRect();
	gate_Rect->scale = Vector2(1536.0f / 8.0f, 192.0f) * 2.4f;
	gate_Rect->SetWorldPos(Vector2(820.0f, -810.0f));
	gate_Rect->isFilled = false;
	gate_Rect->visible = false;
	gate_Rect->collider = COLLIDER::RECT;

	gate_Open = new ObRect();
	gate_Open->scale = Vector2(1536.0f / 4.0f, 192.0f) * 2.8f;
	gate_Open->SetWorldPos(Vector2(820.0f, -810.0f));
	gate_Open->isFilled = false;
	gate_Open->visible = false;
	gate_Open->collider = COLLIDER::RECT;

	input = new ObImage(L"Input.png");
	input->scale = Vector2(452.0f, 92.0f * 0.5f);
	input->SetParentRT(*gate_Normal);
	input->SetLocalPos(Vector2(0.0f, -180.0f));
	input->visible = false;

	//Knight 생성
	for (int i = 0; i < 2; i++)
	{
		knight[i] = new Knight();
	}

	knight[0]->monster_Col->SetWorldPos(Vector2(-490.0f, -960.0f));
	knight[1]->monster_Col->SetWorldPos(Vector2(-90.0f, -960.0f));

	enemy_Icon = new ObImage(L"Enemy_Icon.png");
	enemy_Icon->scale = Vector2(12.0f, 10.0f) * 4.0f;
	enemy_Icon->SetWorldPos(Vector2(620.0f, -445.0f));
	enemy_Icon->visible = true;
	enemy_Icon->space = SPACE::SCREEN;

	//Text
	text = new ObImage(L"Text.png");
	text->scale = Vector2(960.0f, 184.0f) * 1.0f;
	text->SetWorldPos(Vector2(30.0f, -380.0f));
	text->visible = false;
	text->space = SPACE::SCREEN;

	//Next
	next = new ObImage(L"Witch_NextLevel.png");
	next->scale = Vector2(3.0f, 5.0f) * 2.5f;
	next->SetWorldPos(Vector2(475.0f, -450.0f));
	next->visible = false;
	next->space = SPACE::SCREEN;

	next = new ObImage(L"Witch_NextLevel.png");
	next->scale = Vector2(15.0f, 14.0f);
	next->SetWorldPos(Vector2(475.0f, -450.0f));
	next->visible = false;
	next->space = SPACE::SCREEN;

	pl->playerUi->sceneBlack_Top->SetWorldPosY(700.0f);
	pl->playerUi->sceneBlack_Bottom->SetWorldPosY(-550.0f);

	pl->HpChecking = true;

	//캠
	CAM->position.x = -1800.0f;
	CAM->position.y = -800.0f;

	SOUND->AddSound("Tutorial_Meow.wav", "Meow", false);
}

void Scene0022::Release()
{
	SafeDelete(tutorial_Bg);
	SafeDelete(background);
	SafeDelete(ground);

	SafeDelete(gate_Normal);
	SafeDelete(gate_Rect);
	SafeDelete(gate_Open);
	SafeDelete(gate_Close);
	SafeDelete(input);

	SafeDelete(cage_Col);
	SafeDelete(cage_Front);
	SafeDelete(cage_Behind);
	SafeDelete(cage_Front_Dis);
	SafeDelete(cage_Behind_Dis);

	SafeDelete(enemy_Icon);

	SafeDelete(text);
	SafeDelete(next);

	for (int i = 0; i < 2; i++)
	{
		SafeDelete(knight[i])
	}
}

void Scene0022::Update()
{
	//cout << "마우스 X좌표 : " << INPUT->GetMouseWorldPos().x << endl;
	//cout << "마우스 Y좌표 : " << INPUT->GetMouseWorldPos().y << endl;

	//cout << cage_Count << endl;
	//cout << cage_hitTime << endl;

	//Knight - Player
	for (int i = 0; i < 2; i++)
	{
		Vector2 dis = knight[i]->monster_Col->GetWorldPos() - pl->player_Col->GetWorldPos();
		dis.Normalize();

		//Vector2 dis2 = knight[1]->monster_Col->GetWorldPos() - pl->player_Col->GetWorldPos();
		//dis2.Normalize();

		lastPos = pl->player_Col->GetWorldPos();

		//Reverse - Attack, Die가 아닐 때

		if (dis.x > 0 &&
			knight[i]->Get_MonsterState() != MonsterState::ATTACK &&
			knight[i]->Get_MonsterState() != MonsterState::ATTACK2 &&
			knight[i]->Get_MonsterState() != MonsterState::DIE &&
			knight[i]->Get_MonsterState() != MonsterState::HIT)
		{
			knight[i]->reverse = false;
			knight[i]->monsterDir.x = -1.0f;
		}

		else if (dis.x < 0 &&
			knight[i]->Get_MonsterState() != MonsterState::ATTACK &&
			knight[i]->Get_MonsterState() != MonsterState::ATTACK2 &&
			knight[i]->Get_MonsterState() != MonsterState::DIE &&
			knight[i]->Get_MonsterState() != MonsterState::HIT)
		{
			knight[i]->reverse = true;
			knight[i]->monsterDir.x = 1.0f;
		}

		//Reverse
		if (knight[i]->reverse)
		{
			knight[i]->knight_AttackCol->SetLocalPosX(50.0f);
			knight[i]->knight_Idle->reverseLR = true;
			knight[i]->knight_Walk->reverseLR = true;
			knight[i]->knight_Attack->reverseLR = true;
			knight[i]->knight_Attack2->reverseLR = true;
			knight[i]->knight_Hit->reverseLR = true;
			knight[i]->knight_Die->reverseLR = true;
		}

		else
		{
			knight[i]->knight_AttackCol->SetLocalPosX(-50.0f);
			knight[i]->knight_Idle->reverseLR = false;
			knight[i]->knight_Walk->reverseLR = false;
			knight[i]->knight_Attack->reverseLR = false;
			knight[i]->knight_Attack2->reverseLR = false;
			knight[i]->knight_Hit->reverseLR = false;
			knight[i]->knight_Die->reverseLR = false;
		}

		//Knight Hit 시 뒤로 조금 밀려나게
		if (knight[i]->hit && knight[i]->Get_MonsterState() != MonsterState::DIE)
		{
			if (knight[i]->reverse)
			{
				knight[i]->monster_Col->MoveWorldPos(-knight[i]->monster_Col->GetRight() * 20.0f * DELTA);
			}

			else
			{
				knight[i]->monster_Col->MoveWorldPos(knight[i]->monster_Col->GetRight() * 20.0f * DELTA);
			}
		}

		//Kinght 공격 시 앞으로 조금 움직이게
		if (knight[i]->Get_MonsterState() == MonsterState::ATTACK2)
		{
			if (knight[i]->reverse)
			{
				knight[i]->monster_Col->MoveWorldPos(RIGHT * 30.0f * DELTA);
			}

			else
			{
				knight[i]->monster_Col->MoveWorldPos(LEFT * 30.0f * DELTA);
			}
		}
	}

	if (text->visible)
	{
		next->visible = true;
		text_Time += DELTA;

		if (INPUT->KeyDown('F'))
		{
			number++;
			text_Time = 0.0f;
		}

		if (number <= 6)
		{
			if (text_Time <= 0.4f)
			{
				SOUND->Play("Talk");
			}
		}
	}

	pl->Update();

	background->Update();
	tutorial_Bg->Update();
	ground->Update();
	gate_Normal->Update();
	gate_Rect->Update();
	gate_Open->Update();
	gate_Close->Update();
	input->Update();

	cage_Col->Update();
	cage_Front->Update();
	cage_Behind->Update();
	cage_Front_Dis->Update();
	cage_Behind_Dis->Update();
	witch->Update();

	enemy_Icon->Update();

	text->Update();
	next->Update();

	for (int i = 0; i < 2; i++)
	{
		knight[i]->Update();
	}

	//캠
	Vector2 dis = Vector2(pl->player_Col->GetWorldPos().x, pl->player_Col->GetWorldPos().y + 250.0f) - CAM->position;
	CAM->position += dis * DELTA * 1.6f;

	CAM->position.x = Utility::Saturate(CAM->position.x, -1900.0f + app.GetHalfWidth(), 1500.0f - app.GetHalfWidth());
	CAM->position.y = Utility::Saturate(CAM->position.y, -700.0f, 200.0f - app.GetHalfHeight());
}

void Scene0022::LateUpdate()
{
	//플레이어
	pl->player_Col->SetWorldPosX(Utility::Saturate(pl->player_Col->GetWorldPos().x, -1850.0f, 1325.0f));

	//LittleBorn Skill_B
	if (pl->GetState() == PLAYERSTATE::SKILL2)
	{
		pl->born_Head->visible = false;
		pl->born_HeadCol->colOnOff = false;
		pl->player_Col->SetWorldPos(Vector2(pl->born_HeadCol->GetWorldPos().x, 
			ground->GetLocalPos().y + 0.0f));
	}

	//머리통 바닥 충돌
	if (pl->born_HeadCol->Intersect(ground))
	{
		if (pl->born_Head->visible)
		{
			//cout << "11" << endl;
			pl->groundInter = true;
			pl->born_HeadCol->SetWorldPosY(ground->GetLocalPos().y + 21.0f);
		}
	}

	cat_dis = pl->player_Col->GetWorldPos() - witch->witch_Col->GetWorldPos();
	distance = cat_dis.Length();

	if (cat_dis.x < -50.0f)
	{
		witch->cat_Idle->reverseLR = false;
		witch->cat_Walk->reverseLR = true;
	}

	else if (cat_dis.x > 50.0f)
	{
		witch->cat_Idle->reverseLR = true;
		witch->cat_Walk->reverseLR = false;
	}

	//Ground 충돌
	if (pl->GetGravity() > 0.0f)
	{
		if (ground->Intersect(pl->player_Bottom))
		{
			pl->player_Col->SetWorldPosY(ground->GetLocalPos().y - 1.0f);
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

	//몬스터 타입 - Knight 충돌
	for (int i = 0; i < 2; i++)
	{
		if (knight[i]->monster_Hp->scale.x <= 0.0f)
		{
			knight[i]->monster_Hp->visible = false;
			knight[i]->monster_HpBar->visible = false;
		}

		if (knight[i]->Get_MonsterType() == MonsterType::M_Knight)
		{
			//Hit 상태가 아닐 때, 몬스터 인식범위에 플레이어가 들어오면
			if (knight[i]->monster_Recognize->Intersect(pl->player_Col) && !knight[i]->hit)
			{
				//몬스터 Col이랑 플레이어 Col이 충돌할 때
				if (knight[i]->monster_Col->Intersect(pl->player_Col))
				{
					//cout << "222" << endl;
					knight[i]->Get_MonsterState() = MonsterState::ATTACK;
				}

				if (knight[i]->Get_MonsterState() == MonsterState::ATTACK)
				{
					if (knight[i]->knight_Attack->frame.x >= 2)
					{
						knight[i]->Get_MonsterState() = MonsterState::MOVE;
					}
				}

				//인식범위에 들어왔지만, 충돌하지 않을 때
				//상태가 Move로 바뀌면서 Player쪽으로 이동
				else if (!knight[i]->monster_Col->Intersect(pl->player_Col))
				{
					//cout << "11" << endl;
					knight[i]->monster_Col->MoveWorldPos(knight[i]->monsterDir * 200.0f * DELTA);
					knight[i]->Get_MonsterState() = MonsterState::MOVE;
				}
			}

			//인식 범위에 들어오지 않으면 Knight가 Idle로
			else if (!knight[i]->monster_Recognize->Intersect(pl->player_Col))
			{
				//cout << "22" << endl;
				knight[i]->Get_MonsterState() = MonsterState::IDLE;
			}

			//플레이어 Head랑 충돌 시 Hit판정
			if (knight[i]->monster_Col->Intersect(pl->born_HeadCol) &&
				pl->headStop == false)
			{
				pl->born_HeadCol->colOnOff = false;
				pl->headStop = true;
				pl->scalar = 0.0f;

				pl->Hit_Skul->visible = true;
				pl->Hit_Skul->SetWorldPos(Vector2(knight[i]->monster_Col->GetWorldPos().x, knight[i]->monster_Col->GetWorldPos().y - 75.0f));

				SOUND->Stop("Hit");
				SOUND->Play("Hit");

				knight[i]->Get_MonsterState() = MonsterState::HIT;
				knight[i]->hit = true;

				if (knight[i]->knight_Hp > 0.0f)
				{
					knight[i]->knight_Hp -= 15.0f;
					knight[i]->monster_Hp->scale.x -= 15.0f;
				}
			}

			if (pl->headStop == true)
			{
				pl->born_HeadCol->MoveWorldPos(DOWN * 180.0f * DELTA);

				timeDelta += DELTA;

				if (timeDelta >= 0.2f)
				{
					pl->born_HeadCol->colOnOff = true;
				}

				if (timeDelta >= 5.0f)
				{
					pl->headStop = false;
					timeDelta = 0.0f;
				}
			}


			if (pl->player_State == PLAYERSTATE::ATTACK1)
			{
				if (knight[i]->monster_Col->Intersect(pl->attack_Col))
				{
					pl->Hit_Skul->visible = true;
					pl->Hit_Skul->SetWorldPos(Vector2(pl->attack_Col->GetWorldPos().x, pl->attack_Col->GetWorldPos().y - 80.0f));

					pl->attack_Col->colOnOff = false;

					SOUND->Stop("Hit");
					SOUND->Play("Hit");

					knight[i]->Get_MonsterState() = MonsterState::HIT;
					knight[i]->hit = true;

					if (knight[i]->knight_Hp > 0.0f)
					{
						knight[i]->knight_Hp -= 15.0f;
						knight[i]->monster_Hp->scale.x -= 15.0f;
					}
				}
			}

			//플레이어 어택2랑 충돌 시 Hit판정
			else if (pl->player_State == PLAYERSTATE::ATTACK2)
			{
				if (knight[i]->monster_Col->Intersect(pl->attack_Col2))
				{
					pl->Hit_Skul->visible = true;
					pl->Hit_Skul->SetWorldPos(Vector2(pl->attack_Col2->GetWorldPos().x, pl->attack_Col2->GetWorldPos().y - 80.0f));

					pl->attack_Col2->colOnOff = false;
					SOUND->Stop("Hit");
					SOUND->Play("Hit");
					knight[i]->Get_MonsterState() = MonsterState::HIT;
					knight[i]->hit = true;

					if (knight[i]->knight_Hp > 0.0f)
					{
						knight[i]->knight_Hp -= 15.0f;
						knight[i]->monster_Hp->scale.x -= 15.0f;
					}
				}
			}

			//플레이어 점프어택이랑 충돌 시 Hit판정
			else if (pl->player_State == PLAYERSTATE::JUMPATTACK)
			{
				if (knight[i]->monster_Col->Intersect(pl->Jump_attack_Col))
				{
					pl->Hit_Skul->visible = true;
					pl->Hit_Skul->SetWorldPos(Vector2(pl->Jump_attack_Col->GetWorldPos().x, pl->Jump_attack_Col->GetWorldPos().y - 80.0f));

					pl->Jump_attack_Col->colOnOff = false;
					SOUND->Stop("Hit");
					SOUND->Play("Hit");
					knight[i]->Get_MonsterState() = MonsterState::HIT;
					knight[i]->hit = true;
					//knight->Get_MonsterState() = MonsterState::HIT;
					//knight->hit = true;

					if (knight[i]->knight_Hp > 0.0f)
					{
						knight[i]->knight_Hp -= 15.0f;
						knight[i]->monster_Hp->scale.x -= 15.0f;
					}
				}
			}

			if (knight[i]->Get_MonsterState() == MonsterState::ATTACK)
			{
				if (knight[i]->attack_Time < 0.3f)
				{
					SOUND->Play("Knight_Atk1");
				}
			}

			if (knight[i]->Get_MonsterState() != MonsterState::HIT)
			{
				if (knight[i]->attack_Time >= 0.7f)
				{
					knight[i]->Get_MonsterState() = MonsterState::ATTACK2;
					SOUND->Play("Knight_Atk2");
				}
			}

			//한번만 들어와야하는데 계속 들어옴 Why? 
			//막을거 다 막았는데 얘만그럼. 어디서 꼬였는가
			if (knight[i]->Get_MonsterState() == MonsterState::ATTACK)
			{
				knight[i]->knight_AttackCol->colOnOff = true;
				pl->hit_time = 0.0f;
			}

			if (knight[i]->Get_MonsterState() == MonsterState::ATTACK2)
			{
				if (pl->player_Col->Intersect(knight[i]->knight_AttackCol))
				{
					//cout << "Knight -> Player Hit !!";
					knight[i]->knight_AttackCol->colOnOff = false;
					pl->Hit_normal->visible = true;

					if (pl->born_Hp >= 0.0f)
					{
						pl->born_Hp -= 10.0f;
						pl->playerUi->player_Hp->scale.x -= 10.0f;

						SOUND->Stop("Hit");
						SOUND->Play("Hit");

						pl->Hit_normal->SetWorldPos(Vector2(pl->player_Col->GetWorldPos().x, pl->player_Col->GetWorldPos().y - 20.0f));

						if (knight[i]->reverse)
						{
							pl->player_Col->MoveWorldPos(RIGHT * 1000.0f * DELTA);
						}

						else if (!knight[i]->reverse)
						{
							pl->player_Col->MoveWorldPos(LEFT * 1000.0f * DELTA);
						}

						hit_Check = true;
					}
				}
			}

			//Knight Die
			if (knight[i]->knight_Hp <= 0.0f)
			{
				knight[i]->Get_MonsterState() = MonsterState::DIE;
				knight[i]->monster_Col->colOnOff = false;

				if (knight[i]->d_time < 0.01f)
				{
					monster_count--;
				}
			}
		}
	}

	//몬스터가 없으면,
	if (monster_count == 0)
	{
		if (cage_Count > 0)
		{
			//Cage Hit
			if (pl->player_State == PLAYERSTATE::ATTACK1)
			{
				if (cage_Col->Intersect(pl->attack_Col))
				{
					pl->Hit_Skul->SetWorldPos(Vector2(pl->attack_Col->GetWorldPos().x, pl->attack_Col->GetWorldPos().y - 80.0f));
					pl->attack_Col->colOnOff = false;

					Hit();
				}
			}

			else if (pl->player_State == PLAYERSTATE::ATTACK2)
			{
				if (cage_Col->Intersect(pl->attack_Col2))
				{
					pl->Hit_Skul->SetWorldPos(Vector2(pl->attack_Col2->GetWorldPos().x, pl->attack_Col->GetWorldPos().y - 80.0f));
					pl->attack_Col2->colOnOff = false;

					Hit();
				}
			}

			else if (pl->player_State == PLAYERSTATE::JUMPATTACK)
			{
				if (pl->player_State == PLAYERSTATE::JUMPATTACK)
				{
					if (cage_Col->Intersect(pl->Jump_attack_Col))
					{
						pl->Hit_Skul->SetWorldPos(Vector2(pl->Jump_attack_Col->GetWorldPos().x, pl->Jump_attack_Col->GetWorldPos().y - 50.0f));
						pl->Jump_attack_Col->colOnOff = false;

						Hit();
					}
				}
			}

			if (cage_timeCheck)
			{
				cage_hitTime -= DELTA;

				cage_Front->color = Color(1.0f, 1.0f, 1.0f, 0.5f);
				cage_Behind->color = Color(1.0f, 1.0f, 1.0f, 0.5f);

				if (cage_hitTime < 0.0f)
				{
					cage_hitTime = 0.3f;
					cage_timeCheck = false;
					cage_Col->colOnOff = true;
					cage_Front->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
					cage_Behind->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
				}
			}
		}

		//Cage가 부숴지면,
		if (cage_Count == 0)
		{
			cage_Front->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			cage_Behind->color = Color(0.5f, 0.5f, 0.5f, 0.5f);

			cage_Front->visible = false;
			cage_Behind->visible = false;
			cage_Front_Dis->visible = true;
			cage_Behind_Dis->visible = true;

			witch->Witch_State() = WITCHSTATE::IDLE;

			if (INPUT->KeyDown('Y'))
			{
				//Cat으로 PolyMoph
				witch->cat_Check = true;
				SOUND->Play("Meow");
			}
		}

		if (witch->cat_Check)
		{
			witch->Witch_State() = WITCHSTATE::POLY;

			if (witch->witch_Poly->frame.x >= 19.0f)
			{
				witch->witch_Poly->visible = false;
				witch->Witch_State() = WITCHSTATE::CAT_IDLE;
			}
		}

		if (witch->Witch_State() == WITCHSTATE::CAT_IDLE)
		{
			cat_dis.Normalize();

			if (distance > 100.0f)
			{
				//cout << "Walk" << endl;
				witch->Witch_State() = WITCHSTATE::CAT_WALK;
				cat_dis.y = 0;
				witch->witch_Col->MoveWorldPos(cat_dis * 200.0f * DELTA);
			}

			else
			{
				witch->Witch_State() = WITCHSTATE::CAT_IDLE;
			}
		}

		//Scene0033으로 이동
		if (monster_count <= 2)
		{
			if (gate_Rect->Intersect(pl->player_Col))
			{
				input->visible = true;
			}

			else
			{
				input->visible = false;
			}

			if (gate_Open->Intersect(pl->player_Col))
			{
				gate_Close->visible = false;
				gate_Normal->visible = true;
			}
		}
	}

	if (pl->Hit_normal->frame.x >= 11.0f)
	{
		pl->Hit_normal->visible = false;
		pl->Hit_normal->frame.x = 0.0f;
	}

	//대사
	if (cage_Count == 0 && number < 7)
	{
		pl->HpChecking = false;
		textCheck = true;
	}

	if (textCheck)
	{
		text->visible = true;
		next->visible = true;
		pl->playerUi->UiInVisible();

		if (pl->playerUi->sceneBlack_Top->GetWorldPos().y >= 550.0f)
		{
			pl->playerUi->sceneBlack_Top->MoveWorldPos(120.0f * DOWN * DELTA);
			pl->playerUi->sceneBlack_Bottom->MoveWorldPos(120.0f * UP * DELTA);
		}

		if (number >= 7)
		{
			textCheck = false;
		}
	}

	else
	{
		text->visible = false;
		next->visible = false;
		pl->playerUi->StartUi();
		pl->playerUi->BornVisible();
		pl->HpChecking = true;
		knight_Check = true;

		if (pl->playerUi->sceneBlack_Top->GetWorldPos().y <= 700.0f)
		{
			pl->playerUi->sceneBlack_Top->MoveWorldPos(100.0f * UP * DELTA);
			pl->playerUi->sceneBlack_Bottom->MoveWorldPos(100.0f * DOWN * DELTA);
		}
	}

	//SceneBlackTop이 630이상 올라가면 HpUi Checking
	if (pl->playerUi->sceneBlack_Top->GetWorldPos().y >= 630.0f)
	{
		pl->HpChecking = true;
		pl->playerUi->StartUi();
	}


	if (input->visible)
	{
		if (INPUT->KeyDown('F'))
		{
			cout << "Scene0033 Change zz" << endl;
			SCENE->ChangeScene("튜토리얼3");
		}
	}
}

void Scene0022::Render()
{
	if (text->visible)
	{
		DWRITE->RenderText(L"마녀", RECT{ 420, 800,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
			24.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);

		switch (number)
		{
		case 0:
			DWRITE->RenderText(L"스컬? 그 난리 통에서 용케 무사했군요.", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;
		case 1:
			DWRITE->RenderText(L"제 마력을 봉인할 정도의 철창이라니, 칼레온에도 쓸만한 마법사가 있나 보네요.", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;
		case 2:
			DWRITE->RenderText(L"조금 전에 스켈레톤 경비대가 여길 지나갔습니다.", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;
		case 3:
			DWRITE->RenderText(L"조금 전에 스켈레톤 경비대가 여길 지나갔습니다.", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			DWRITE->RenderText(L"저는 괜찮으니 마왕님부터 구해달라 그렇게 말했습니다만...", RECT{ 400, 900,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;
		case 4:
			DWRITE->RenderText(L"기어코 몇몇이 저를 구하다가 역으로 당하고 말았습니다.", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;
		case 5:
			DWRITE->RenderText(L"마왕님을 구하려면 앞서 간 스켈레톤 경비대만으로는 분명 역부족일 것입니다.", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;
		case 6:
			DWRITE->RenderText(L"서둘러 쫓아가도록 하죠.", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;
		}
	}

	//몬스터 카운트
	if (pl->HpChecking)
	{
		wstring temp = to_wstring(monster_count);
		DWRITE->RenderText(temp, RECT{ 1450, 920,(long)app.GetWidth() + (long)900.0f,(long)app.GetHalfHeight() + (long)600.0f },
			50.0f, L"휴먼매직체", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_BOLD);
	}


	background->Render();
	tutorial_Bg->Render();
	ground->Render();

	gate_Normal->Render();
	gate_Rect->Render();
	gate_Close->Render();
	gate_Open->Render();
	input->Render();

	cage_Col->Render();
	cage_Behind->Render();
	cage_Behind_Dis->Render();
	witch->Render();
	cage_Front->Render();
	cage_Front_Dis->Render();

	if (cage_Count == 0)
	{
		witch->Render();
	}

	for (int i = 0; i < 2; i++)
	{
		knight[i]->Render();
	}

	enemy_Icon->Render();

	pl->Render();
	pl->Hit_normal->Render();

	text->Render();
	next->Render();
}

void Scene0022::ResizeScreen()
{

}

void Scene0022::Hit()
{
	cage_hitTime = 0.3f;

	pl->Hit_Skul->visible = true;

	SOUND->Stop("Hit");
	SOUND->Play("Hit");

	cage_timeCheck = true;
	cage_Count--;
}

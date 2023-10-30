#include "stdafx.h"

void Scene0044::Init()
{
	//Player
	pl = new Player();
	pl->player_Col->SetWorldPos(Vector2(-1620.0f, -960.0f));

	//Witch
	witch = new Witch();
	witch->witch_Col->SetWorldPos(Vector2(-1770.0f, -965.0f));
	witch->cat_Idle->SetParentRT(*witch->witch_Col);
	witch->cat_Walk->SetParentRT(*witch->witch_Col);
	witch->Witch_State() = WITCHSTATE::CAT_IDLE;

	//Bg
	background = new ObImage(L"Tutorial_Background.png");
	background->scale = Vector2(1600.0f, 1000.0f * 1.5f) * 1.3f;
	background->SetWorldPos(Vector2(0.0f, 500.0f));
	background->space = SPACE::SCREEN;

	tutorial_Bg = new ObImage(L"Tutorial4.png");
	tutorial_Bg->scale = Vector2(1600.0f, 1000.0f) * 2.4f;

	ground = new ObRect();
	ground->scale = Vector2(3300.0f, 20.0f);
	ground->SetWorldPos(Vector2(-1930.0f, -960.0f));
	ground->pivot = OFFSET_LT;
	ground->visible = false;
	ground->isFilled = false;
	ground->collider = COLLIDER::RECT;

	mongal_Start_Col = new ObRect();
	mongal_Start_Col->scale = Vector2(3300.0f, 20.0f);
	mongal_Start_Col->SetWorldPos(Vector2(-1930.0f, -960.0f));
	mongal_Start_Col->pivot = OFFSET_LT;
	mongal_Start_Col->visible = true;
	mongal_Start_Col->isFilled = false;
	mongal_Start_Col->collider = COLLIDER::RECT;

	//몬갈
	ogre = new Ogre();
	ogre->monster_Col->SetWorldPos(Vector2(300.0f, -960.0f));
	ogre->monster_Col->scale = Vector2(552.0f / 6.0f, 88.0f) * 2.5f;
	ogre->monster_Col->visible = false;
	ogre->monster_Hp->visible = false;
	ogre->monster_HpBar->visible = false;

	mongal_HpBar = new ObImage(L"TutorialBoss_Front.png");
	mongal_HpBar->scale = Vector2(730.0f, 145.0f);
	mongal_HpBar->SetWorldPos(Vector2(-360.0f, 425.0f));
	mongal_HpBar->pivot = OFFSET_L;
	mongal_HpBar->visible = false;
	mongal_HpBar->space = SPACE::SCREEN;

	mongal_Hp = new ObImage(L"BossHealthBar_FirstPhase.png");
	mongal_Hp->scale = Vector2(543.0f, 25.0f);
	mongal_Hp->SetParentT(*mongal_HpBar);
	mongal_Hp->SetLocalPos(Vector2(94.0f, -14.0f));
	mongal_Hp->pivot = OFFSET_L;
	mongal_Hp->visible = false;
	mongal_Hp->space = SPACE::SCREEN;

	mongal_HpTop = new ObImage(L"TutorialBoss_Top_Back.png");
	mongal_HpTop->scale = Vector2(306.0f, 58.0f) * 2.5f;
	mongal_HpTop->SetParentT(*mongal_HpBar);
	mongal_HpTop->SetWorldPos(Vector2());
	mongal_HpTop->pivot = OFFSET_L;
	mongal_HpTop->visible = false;
	mongal_HpTop->space = SPACE::SCREEN;

	mongal_HpBottom = new ObImage(L"TutorialBoss_Bottom_Back.png");
	mongal_HpBottom->scale = Vector2(306.0f, 58.0f) * 2.5f;
	mongal_HpBottom->SetParentT(*mongal_HpBar);
	mongal_HpBottom->SetWorldPos(Vector2());
	mongal_HpBottom->pivot = OFFSET_L;
	mongal_HpBottom->visible = false;
	mongal_HpBottom->space = SPACE::SCREEN;

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

	//Hero
	hero = new Hero();
	hero->hero_Col->SetWorldPos(Vector2(860.0f, -960.0f));
	hero->hero_Col->visible = false;

	ogre->Get_MonsterState() = MonsterState::IDLE;
	witch->Witch_State() = WITCHSTATE::IDLE;

	GameStart();
	pl->playerUi->UiBlack();

	ogre->mongal_Start = true;

	SOUND->Stop("Tutorial");
	SOUND->AddSound("Tutorial_Ogre_Atk_Ready.wav", "Ogre_Attack", false);
}

void Scene0044::Release()
{
	SafeDelete(tutorial_Bg);
	SafeDelete(background);
	SafeDelete(ground);

	SafeDelete(mongal_HpBar);
	SafeDelete(mongal_Hp);
	SafeDelete(mongal_HpTop);
	SafeDelete(mongal_HpBottom);

	SafeDelete(text);
	SafeDelete(next);
}

void Scene0044::Update()
{
	//cout << "마우스 Y좌표 : " << INPUT->GetMouseWorldPos().y << endl;
	//cout << "마우스 X좌표 : " << INPUT->GetMouseWorldPos().x << endl;

	if (textCheck)
	{
		text_Time += DELTA;

		if (INPUT->KeyDown('F'))
		{
			number++;
			text_Time = 0.0f;
		}

		if (number >= 2)
		{
			textCheck = false;
			text->visible = false;
			next->visible = false;
		}

		cout << number << endl;

		if (number >= 5)
		{
			textCheck = false;
			text->visible = false;
			next->visible = false;
		}

		if (number <= 4)
		{
			if (text_Time <= 0.4f)
			{
				SOUND->Play("Talk");
			}
		}
	}

	//cout << ogre->monga_attack_Time << endl;

	//Ogre - Player
	ogre->mongal_dis = ogre->monster_Col->GetWorldPos() - pl->player_Col->GetWorldPos();
	//
	//cout << ogre->mongal_dis.x << endl;

	if (ogre->mongal_dis.x > 0 &&
		ogre->Get_MonsterState() != MonsterState::ATTACK &&
		ogre->Get_MonsterState() != MonsterState::DIE &&
		ogre->Get_MonsterState() != MonsterState::HIT)
	{
		ogre->ogre_reverse = false;
	}

	else if (ogre->mongal_dis.x < 0 &&
		ogre->Get_MonsterState() != MonsterState::ATTACK &&
		ogre->Get_MonsterState() != MonsterState::DIE &&
		ogre->Get_MonsterState() != MonsterState::HIT)
	{
		ogre->ogre_reverse = true;
	}

	//Cat Distance
	cat_dis = pl->player_Col->GetWorldPos() - witch->witch_Col->GetWorldPos();
	distance = cat_dis.Length();

	//Ogre Hit 시 뒤로 조금 밀려나게
	if (ogre->hit && ogre->Get_MonsterState() != MonsterState::DIE)
	{
		if (ogre->ogre_reverse)
		{
			ogre->monster_Col->MoveWorldPos(-ogre->monster_Col->GetRight() * 40.0f * DELTA);
		}

		else
		{
			ogre->monster_Col->MoveWorldPos(ogre->monster_Col->GetRight() * 40.0f * DELTA);
		}
	}

	//Ogre 공격 시 앞으로 조금 움직이게
	if (ogre->Get_MonsterState() == MonsterState::ATTACK)
	{
		if (0.1f <= ogre->Ogre_AttackFrame() && ogre->Ogre_AttackFrame() <= 4.0f)
		{
			if (ogre->Ogre_AttackFrame() >= 1.5f)
			{
				SOUND->Play("Ogre_Attack");
			}

			if (ogre->ogre_reverse)
			{
				ogre->monster_Col->MoveWorldPos(RIGHT * 180.0f * DELTA);
			}

			else
			{
				ogre->monster_Col->MoveWorldPos(LEFT * 180.0f * DELTA);
			}
		}
		
	}


	pl->Update();
	background->Update();
	tutorial_Bg->Update();
	ground->Update();
	witch->Update();

	mongal_HpBar->Update();
	mongal_Hp->Update();
	mongal_HpTop->Update();
	mongal_HpBottom->Update();
	ogre->Update();

	text->Update();
	next->Update();
	hero->Update();

	//캠
	Vector2 dis = Vector2(pl->player_Col->GetWorldPos().x, pl->player_Col->GetWorldPos().y + 250.0f) - CAM->position;
	CAM->position += dis * DELTA * 1.6f;

	//cout << CAM->position.x << endl;

	CAM->position.x = Utility::Saturate(pl->player_Col->GetWorldPos().x, -1900.0f + app.GetHalfWidth(), 1270.0f - app.GetHalfWidth());
	CAM->position.y = Utility::Saturate(pl->player_Col->GetWorldPos().y, -700.0f, 200.0f - app.GetHalfHeight());
	
}

void Scene0044::LateUpdate()
{
	//플레이어
	pl->player_Col->SetWorldPosX(Utility::Saturate(pl->player_Col->GetWorldPos().x, -1850.0f, 1225.0f));

	//LittleBorn Skill_B
	if (pl->GetState() == PLAYERSTATE::SKILL2)
	{
		pl->headStop = false;
		pl->born_Head->visible = false;
		pl->born_HeadCol->colOnOff = false;
		pl->player_Col->SetWorldPos(Vector2(pl->born_HeadCol->GetWorldPos().x,
			ground->GetLocalPos().y + 0.0f));
	}

	if (pl->player_Col->Intersect(pl->born_HeadCol) && pl->headStop)
	{
		pl->headStop = false;
		pl->born_HeadCol->colOnOff = false;
	}

	//머리통 바닥 충돌
	if (pl->born_HeadCol->Intersect(ground))
	{
		if (pl->born_Head->visible)
		{
			//cout << "11" << endl;
			pl->groundInter = true;
			pl->born_HeadCol->SetWorldPosY(ground->GetLocalPos().y + 20.0f);
		}
	}

	//Cat Reverse
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

	//Player Hit Effect
	if (pl->Hit_normal->frame.x >= 11.0f)
	{
		pl->Hit_normal->visible = false;
		pl->Hit_normal->frame.x = 0.0f;
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

	//고양이 멈춰, 이제 멈추지마
	//witch->Witch_State() = WITCHSTATE::CAT_WALK;

	cat_dis.Normalize();
	cat_dis.y = 0.0f;

	if (distance > 50.0f)
	{
		witch->witch_Col->MoveWorldPos(cat_dis * 200.0f * DELTA);
		//cout << "Walk" << endl;
		witch->Witch_State() = WITCHSTATE::CAT_WALK;
		cat_dis.y = 0;
	}

	else
	{
		witch->Witch_State() = WITCHSTATE::CAT_IDLE;
	}

	//if (witch->Witch_State() == WITCHSTATE::CAT_IDLE)
	//{
	//	

	//	if (witch->witch_Col->GetWorldPos().x > -1100.0f)
	//	{
	//		witch->Witch_State() = WITCHSTATE::CAT_IDLE;
	//		// 고양이 멈출 때
	//		//ogre->mongal_Start = true;
	//	}

	//	else if (witch->witch_Col->GetWorldPos().x < -1100.0f)
	//	{
	//		if (distance > 100.0f)
	//		{
	//			//cout << "Walk" << endl;
	//			witch->Witch_State() = WITCHSTATE::CAT_WALK;
	//			cat_dis.y = 0;
	//			
	//		}

	//		else
	//		{
	//			witch->Witch_State() = WITCHSTATE::CAT_IDLE;
	//		}
	//	}
	//}

	

	//Cat의 위치가 -1100이 넘으면
	//Boss Move
	if (ogre->Get_MonsterState() != MonsterState::DIE && !ogre->mongal_Normal)
	{
		if (ogre->mongal_Start)
		{
			witch->cat_Idle->reverseLR = true;

			ogre->mongal_distance = ogre->mongal_dis.Length();

			//거리로 상태변경 해보기
			if (ogre->mongal_distance > 140.0f)
			{
				if (ogre->Get_MonsterState() != MonsterState::ATTACK)
				{
					if (ogre->Ogre_AttackFrame() >= 6.0f ||
						ogre->Ogre_AttackFrame() == 0.0f)
					{
						ogre->Get_MonsterState() = MonsterState::MOVE;
						ogre->mongal_dis.y = 0;
						ogre->mongal_dis.Normalize();
						ogre->monster_Col->MoveWorldPos(-ogre->mongal_dis * 200.0f * DELTA);
					}
				}

			}

			else
			{
				ogre->Get_MonsterState() = MonsterState::IDLE;

				ogre->mongal_Attack = true;

				if (ogre->mongal_Attack)
				{
					ogre->monga_attack_Time += DELTA;

					if (ogre->monga_attack_Time > 0.5f)
					{
						ogre->Get_MonsterState() = MonsterState::ATTACK;
					}
				}
			}

			//공격이 끝나면 IDLE로 돌아가라
			if (ogre->Ogre_AttackFrame() >= 6.0f)
			{
				ogre->monga_attack_Time = 0.0f;
				ogre->Get_MonsterState() = MonsterState::IDLE;
				ogre->mongal_Attack = false;
			}
		}

		if (pl->player_State == PLAYERSTATE::IDLE ||
			pl->player_State == PLAYERSTATE::RUN ||
			pl->player_State == PLAYERSTATE::JUMP)
		{
			pl->attack_Col->colOnOff = false;
			pl->attack_Col2->colOnOff = false;
			pl->Jump_attack_Col->colOnOff = false;

			//ogre->hit = false;
		}

		//플레이어 Head랑 충돌 시 Hit판정
		if (ogre->monster_Col->Intersect(pl->born_HeadCol) && pl->headStop == false)
		{
			pl->born_HeadCol->colOnOff = false;
			pl->headStop = true;
			pl->scalar = 0.0f;

			pl->Hit_Skul->SetWorldPos(Vector2(ogre->monster_Col->GetWorldPos().x, 
												ogre->monster_Col->GetWorldPos().y - 75.0f));
			pl->Hit_Skul->visible = true;

			Hit();
		}

		//cout << pl->headStop << endl;

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

		//Ogre Hit
		if (pl->player_State == PLAYERSTATE::ATTACK1)
		{
			if (ogre->monster_Col->Intersect(pl->attack_Col))
			{
				//cout << "1111" << endl;
				pl->Hit_Skul->SetWorldPos(Vector2(pl->attack_Col->GetWorldPos().x, pl->attack_Col->GetWorldPos().y - 80.0f));
				pl->attack_Col->colOnOff = false;

				Hit();
			}
		}

		else if (pl->player_State == PLAYERSTATE::ATTACK2)
		{
			if (ogre->monster_Col->Intersect(pl->attack_Col2))
			{
				//cout << "1111" << endl;
				pl->Hit_Skul->SetWorldPos(Vector2(pl->attack_Col2->GetWorldPos().x, pl->attack_Col->GetWorldPos().y - 80.0f));
				pl->attack_Col2->colOnOff = false;

				Hit();
			}
		}

		else if (pl->player_State == PLAYERSTATE::JUMPATTACK)
		{
			if (ogre->monster_Col->Intersect(pl->Jump_attack_Col))
			{
				//cout << "1111" << endl;
				pl->Hit_Skul->SetWorldPos(Vector2(pl->Jump_attack_Col->GetWorldPos().x, pl->attack_Col->GetWorldPos().y - 50.0f));
				pl->Jump_attack_Col->colOnOff = false;

				Hit();
			}
		}

		//Ogre Hit
		if (ogre->hit)
		{
			ogre->monga_hit_Time -= DELTA;

			ogre->Ogre_Idle_HitColor();
			ogre->Ogre_Walk_HitColor();
			ogre->Ogre_Attack_HitColor();
			ogre->Ogre_HitColor();

			if (ogre->monga_hit_Time <= 0.0f)
			{
				ogre->monga_hit_Time = 0.3f;
				ogre->Ogre_Idle_ReturnColor();
				ogre->Ogre_Walk_ReturnColor();
				ogre->Ogre_Attack_ReturnColor();
				ogre->Ogre_Hit_ReturnColor();

				ogre->hit = false;
			}
		}

		if (ogre->Get_MonsterState() == MonsterState::IDLE ||
			ogre->Get_MonsterState() == MonsterState::MOVE)
		{
			ogre->Ogre_AttackCol->colOnOff = true;
		}

		if (ogre->Get_MonsterState() == MonsterState::ATTACK)
		{
			if (pl->player_Col->Intersect(ogre->Ogre_AttackCol))
			{
				if (ogre->Ogre_AttackFrame() >= 3.0f)
				{
					//cout << "11" << endl;
					ogre->Ogre_AttackCol->colOnOff = false;
					pl->Hit_normal->visible = true;

					if (pl->born_Hp >= 0.0f)
					{
						pl->born_Hp -= 10.0f;
						pl->playerUi->player_Hp->scale.x -= 10.0f;

						SOUND->Stop("Hit");
						SOUND->Play("Hit");

						pl->Hit_normal->SetWorldPos(Vector2(pl->player_Col->GetWorldPos().x, pl->player_Col->GetWorldPos().y - 20.0f));
						hit_Check = true;

						if (ogre->ogre_reverse)
						{
							pl->player_Col->MoveWorldPos(RIGHT * 1000.0f * DELTA);
						}

						else if (!ogre->ogre_reverse)
						{
							pl->player_Col->MoveWorldPos(LEFT * 1000.0f * DELTA);
						}
					}
				}
			}
		}
	}

	if (bCheck == true)
	{
		Vector2 dis = ogre->monster_Col->GetWorldPos() - CAM->position;
		//dis.Normalize();
		CAM->position += dis * DELTA;
	}

	// Mongal UI visible
	if (ogre->mongal_Start == true)
	{
		Mongal_HpVisible();
	}

	// Dead
	if (mongal_Hp->scale.x <= 0.0f)
	{
		ogre->Get_MonsterState() = MonsterState::DIE;
		ogre->monster_Col->colOnOff = false;
		ogre->mongal_Start = false;
		ogre->ogre_reverse = ogre->ogre_reverse;

		Mongal_HpInVisible();
		SceneStart();

		bDead = true;
	}

	if (INPUT->KeyDown('1'))
	{
		ogre->Get_MonsterState() = MonsterState::DIE;
		ogre->mongal_Normal = true;

		textCheck = true;

		ogre->monster_Col->SetWorldPos(Vector2(500.0f, -960.0f));
	}

	if (INPUT->KeyDown('2'))
	{
		ogre->mongal_laugh = true;
	}

	if (INPUT->KeyDown('3'))
	{
		ogre->mongal_Move = true;	
	}
	
	if (ogre->mongal_Move)
	{
		ogre->Ogre_N_Laugh->visible = false;
		ogre->Ogre_N_Idle->visible = false;

		ogre->Ogre_N_Walk->visible = true;

		if (ogre->monster_Col->GetWorldPos().x <= 990.0f)
		{
			ogre->monster_Col->MoveWorldPos(RIGHT * 200.0f * DELTA);
		}

		else
		{
			hero_Landing = true;
			//ogre->mongal_Move = false;
			ogre->Ogre_N_Die->visible = true;
			ogre->Ogre_N_Walk->visible = false;
			ogre->Ogre_N_Idle->visible = false;
		}
	}

	//랜딩
	if (hero_Landing)
	{
		SOUND->Play("Hero_Landing");
		hero->hero_Landing->visible = true;
		hero->hero_Landing_Effect1->visible = true;

		if (hero->hero_Landing_Effect1->frame.x >= 16.0f)
		{
			hero->hero_Landing_Effect1->visible = false;
			hero->hero_Landing_Effect2->visible = true;
		}

		if (hero->hero_Landing_Effect2->frame.x >= 16.0f)
		{
			hero->hero_Landing_Effect1->visible = false;
			hero->hero_Landing_Effect2->visible = false;

			hero->hero_Landing->ChangeAnim(ANIMSTATE::LOOP, 0.15f);

			if (hero->hero_Landing->frame.x >= 8.0f)
			{
				hero->hero_Landing->visible = false;
				hero->hero_Fly->visible = true;

				hero_time += DELTA;
			}

			if (hero_time < 1.0f)
			{
				hero->hero_talk = true;
				hero->hero_Col->MoveWorldPos(UP * 40.0f * sinf(hero_time / 0.8f * DIV2PI) * DELTA);
			}
		}

		if (INPUT->KeyDown('4') || number == 5)
		{
			hero->hero_attack = true;

			hero_shakeTime += DELTA;

			if (1.0f < hero_shakeTime && hero_shakeTime < 3.8f)
			{
				CAM->position += (UP * 1000.0f * sinf(hero_shakeTime / 0.05f * PI) * DELTA);
				CAM->position += (RIGHT * 1000.0f * sinf(hero_shakeTime / 0.05f * PI) * DELTA);
			}
		}
	}

	//Attack - BigBang
	if (hero->hero_attack)
	{
		hero->hero_Fly->visible = false;
		hero->hero_Bigbang_Ready->visible = true;
			
		if (hero->hero_Bigbang_Ready->frame.x >= 5.0f)
		{
			hero->hero_Bigbang_Ready->visible = false;
			hero->hero_Bigbang_Attack->visible = true;
		}

		if (hero->hero_Bigbang_Attack->visible)
		{
			hero->hero_Bigbang_Effect_Start->visible = true;
		}

		if (hero->hero_Bigbang_Effect_Start->frame.x <= 15.0f &&
			hero->hero_Bigbang_Effect_Start->frame.x >= 3.0f)
		{
			SOUND->Play("Hero_Charging");
		}

		if (hero->hero_Bigbang_Effect_Start->frame.x >= 22.0f)
		{
			hero->hero_Bigbang_Effect_Start->visible = false;
			hero->hero_Bigbang_Ball_Ready->visible = true;
		}

		if (hero->hero_Bigbang_Ball_Ready->frame.x >= 4.0f)
		{
			hero->hero_Bigbang_Ball_Ready->visible = false;
			hero->hero_Bigbang_Ball->visible = true;
			hero->hero_Bigbang_Effect->visible = true;
		}
	}

	//죽고, Text가 켜져있을 때
	if (bDead)
	{
		if (textCheck && number != 5)
		{
			text->visible = true;
			next->visible = true;
		}
	}

	if (hero->hero_talk == true && number != 5)
	{
		textCheck = true;
		text->visible = true;
		next->visible = true;
	}

}

void Scene0044::Render()
{
	if (ogre->mongal_Start)
	{
		//HP
		DWRITE->RenderText(L"몬갈", RECT{798, 32,(long)app.GetWidth() + (long)850.0f,(long)app.GetHalfHeight() + (long)600.0f },
			25.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_BOLD);
	
		DWRITE->RenderText(L"오우거", RECT{795, 104,(long)app.GetWidth() + (long)850.0f,(long)app.GetHalfHeight() + (long)600.0f },
			19.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_BOLD);
	}

	if (textCheck)
	{
		if (number <= 2)
		{
			DWRITE->RenderText(L"마녀", RECT{ 430, 800,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				24.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
		}

		else if (number == 3 || number == 4)
		{
			DWRITE->RenderText(L"초대 용사", RECT{ 400, 800,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				24.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
		}
		

		switch (number)
		{
		case 0:
			DWRITE->RenderText(L"정신이 들은 것이냥-!", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 1:
			DWRITE->RenderText(L"정신이 들은 것이냥-! 일단 급하니 성으로 들어가서 이야기 하자냥-!!", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 2:
			DWRITE->RenderText(L"요...용사!?", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 3:
			DWRITE->RenderText(L"쓸모없는 녀석... 고작 스켈레톤에게 패하다니.", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 4:
			DWRITE->RenderText(L"더러운 마족 자식들...", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;
		}
	}

	//오른쪽 아래
	//DWRITE->RenderText(L"몬갈", RECT{1450, 720,(long)app.GetWidth() + (long)900.0f,(long)app.GetHalfHeight() + (long)600.0f},
	//	50.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_BOLD);
	//
	//DWRITE->RenderText(L"오우거", RECT{1456, 800,(long)app.GetWidth() + (long)900.0f,(long)app.GetHalfHeight() + (long)600.0f },
	//	30.0f, L"맑은 고딕", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_BOLD);

	background->Render();
	tutorial_Bg->Render();
	ground->Render();

	mongal_HpTop->Render();
	mongal_HpBottom->Render();
	mongal_HpBar->Render();
	mongal_Hp->Render();

	witch->Render();

	ogre->Render();
	hero->Render();

	pl->Render();
	pl->Hit_normal->Render();

	text->Render();
	next->Render();
}

void Scene0044::ResizeScreen()
{

}

void Scene0044::Hit()
{
	ogre->hit = true;
	ogre->monga_hit_Time = 0.3f;

	pl->Hit_Skul->visible = false;
	pl->Hit_Skul->visible = true;

	SOUND->Stop("Hit");
	SOUND->Play("Hit");

	if (mongal_Hp->scale.x >= 10.0f)
	{
		mongal_Hp->scale.x -= 600.0f;
	}

	else
	{
		mongal_Hp->scale.x = 0.0f;
	}

}

void Scene0044::GameStart()
{
	pl->playerUi->BornVisible();
	//pl->playerUi->UiInVisible();

	pl->HpChecking = true;
	pl->playerUi->sceneBlack_Top->visible = false;
	pl->playerUi->sceneBlack_Bottom->visible = false;
}

void Scene0044::SceneStart()
{
	//pl->playerUi->BornVisible();
	pl->playerUi->UiInVisible();

	pl->HpChecking = false;
	pl->playerUi->sceneBlack_Top->visible = true;
	pl->playerUi->sceneBlack_Bottom->visible = true;

	if (pl->playerUi->sceneBlack_Top->GetWorldPos().y >= 580.0f)
	{
		pl->playerUi->sceneBlack_Top->MoveWorldPos(100.0f * DOWN * DELTA);
		pl->playerUi->sceneBlack_Bottom->MoveWorldPos(100.0f * UP * DELTA);
	}
	
}

void Scene0044::SceneEnd()
{

}

void Scene0044::Mongal_HpVisible()
{
	ogre->monster_Hp->visible = false;
	mongal_HpBar->visible = true;
	mongal_Hp->visible = true;
	mongal_HpTop->visible = true;
	mongal_HpBottom->visible = true;
}

void Scene0044::Mongal_HpInVisible()
{
	ogre->monster_Hp->visible = false;
	mongal_HpBar->visible = false;
	mongal_Hp->visible = false;
	mongal_HpTop->visible = false;
	mongal_HpBottom->visible = false;
}

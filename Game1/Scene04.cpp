#include "stdafx.h"

void Scene04::Init()
{
	pl = new Player();
	pl->player_Col->SetWorldPos(Vector2(0.0f, -380.0f));

	boss = new Yggdrasil();

	for (int i = 0; i < 3; i++)
	{
		ground_Col[i] = new ObRect();
		ground_Col[i]->pivot = OFFSET_LT;
		ground_Col[i]->collider = COLLIDER::RECT;
		ground_Col[i]->isFilled = false;
		ground_Col[i]->visible = false;
	}

	ground_Col[0]->scale = Vector2(2880.0f * 1.3f, 50.0f) * 0.8f;
	ground_Col[0]->SetWorldPos(Vector2(-1500.0f, -505.0f));

	ground_Col[1]->scale = Vector2(400.0f, 25.0f);
	ground_Col[1]->SetWorldPos(Vector2(-831.0f, -340.0f));

	ground_Col[2]->scale = Vector2(400.0f, 25.0f);
	ground_Col[2]->SetWorldPos(Vector2(230.0f, -340.0f));

	ground = new ObImage(L"stage6_backGround.bmp");
	ground->scale = Vector2(2880.0f * 1.3f, 1512.0f * 1.3f) * 0.8f;

	boss_Start = new ObImage(L"bossbg_1.png");
	boss_Start->scale = Vector2(2000.0f * 1.2f, 1244.0f);
	boss_Start->SetLocalPosY(-200.0f);
	boss_Start->visible = true;

	boss_anger = new ObImage(L"bossbg_2.png");
	boss_anger->scale = Vector2(2000.0f * 1.1f, 1244.0f);
	boss_anger->visible = false;

	boss_End = new ObImage(L"bossbg_3.png");
	boss_End->scale = Vector2(2000.0f * 1.1f, 1244.0f);
	boss_End->visible = false;

	slam_Effect = new ObImage(L"BigStomp_Attack_Smoke.png");
	slam_Effect->scale = Vector2(8448.0f / 33.0f, 256.0f) * 2.5f;
	slam_Effect->visible = false;
	slam_Effect->maxFrame = Int2(33, 1);
	slam_Effect->ChangeAnim(ANIMSTATE::ONCE, 0.05f);

	SOUND->AddSound("Chapter1_Boss.wav", "Boss", true);
	SOUND->Play("Boss");

	
}

void Scene04::Release()
{
	for (int i = 0; i < 3; i++)
	{
		SafeDelete(ground_Col[i]);
	}

	SafeDelete(ground);
	SafeDelete(boss_Start);
	SafeDelete(boss_anger);
	SafeDelete(boss_End);
	SafeDelete(slam_Effect);
}

void Scene04::Update()
{
	//cout << "마우스 X좌표 : " << INPUT->GetMouseWorldPos().x << endl;
	//cout << "마우스 Y좌표 : " << INPUT->GetMouseWorldPos().y << endl;

	//돌아갈 때
	slam_Location = Vector2(-560.0f - ground_lastPos.x, 60.0f - ground_lastPos.y);
	slam_Location_Reverse = Vector2(440.0f - ground_lastPos.x, 60.0f - ground_lastPos.y);

	slam_Location.Normalize();
	slam_Location_Reverse.Normalize();

	//올라갈 때
	slam_Location1 = Vector2(boss->boss_Col->GetWorldPos().x - 100.0f, 600.0f);
	slam_Location_Reverse2 = Vector2(boss->boss_Col->GetWorldPos().x + 250.0f, 600.0f);

	slam_Location1.Normalize();
	slam_Location_Reverse2.Normalize();

	//Idle 손 위치
	getHand = boss->boss_Col->GetWorldPos() - Vector2(300.0f, -500.0f);
	getHand.Normalize();

	if (boss->sweep == 0)
	{
		boss->sweep_time2 += DELTA;

		if (boss->sweep_time2 < 0.5f)
		{
			boss->hand_Col->SetWorldPos(Vector2(-500.0f, -800.0f));
			boss->hand_Col_Reverse->SetWorldPos(Vector2(300.0f, -800.0f));
		}

		else if (boss->sweep_time2 < 2.0f)
		{
			boss->hand_Col->MoveWorldPos(UP * 200.0f * DELTA);
			boss->hand_Col_Reverse->MoveWorldPos(UP * 200.0f * DELTA);
		}

		else if (boss->sweep_time2 > 2.1f)
		{
			boss->GetBossPattern() = BossPattern::IDLE;
			sweep_Checking = false;
		}

	}


	for (int i = 0; i < 3; i++)
	{
		ground_Col[i]->Update();
	}

	ground->Update();
	boss_Start->Update();
	boss_anger->Update();
	boss_End->Update();
	boss->Update();
	slam_Effect->Update();
	pl->Update();
}

void Scene04::LateUpdate()
{
	//플레이어 가두기
	pl->player_Col->SetWorldPosX(Utility::Saturate(pl->player_Col->GetWorldPos().x, -1050.0f, 1050.0f));

	//캠	
	CAM->position.x = Utility::Saturate(pl->player_Col->GetWorldPos().x, -1090.0f + app.GetHalfWidth(), 1090.0f - app.GetHalfWidth());
	CAM->position.y = Utility::Saturate(pl->player_Col->GetWorldPos().y + 300.0f, -800.0f, -80.0f);

	Vector2 dis = pl->player_Col->GetWorldPos() - pl->born_HeadCol->GetWorldPos();
	float distance = dis.Length();

	float	scalar = 100.0f;

	if (pl->shoot_time > 0.5f)
	{
		if (pl->born_HeadCol->Intersect(pl->player_Col))
		{
			pl->born_HeadCol->visible = false;
			pl->born_Head->visible = false;

			pl->born_Check = true;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		//S누르면 머리 자리로 이동하면서, born_Head visible false로 변경
		if (pl->GetState() == PLAYERSTATE::SKILL2)
		{
			pl->born_Head->visible = false;
			pl->player_Col->SetWorldPos(Vector2(pl->born_HeadCol->GetWorldPos().x, pl->born_HeadCol->GetWorldPos().y - 30.0f));
		}

		if (!ground_Col[i]->Intersect(pl->born_HeadCol))
		{
			if (distance > 520.0f)
			{
				//cout << "22" << endl;
				pl->born_HeadCol->MoveWorldPos(DOWN * scalar * DELTA);
			}
		}

		if (ground_Col[i]->Intersect(pl->born_HeadCol))
		{
			scalar = 0.0f;
			//cout << "11" << endl;
		}
	}

	//cout << boss->sweep_time2 << endl;

	//충돌
	if (pl->GetGravity() > 0)
	{
		//양옆 GroundTree, 바닥 충돌
		for (int i = 0; i < 3; i++)
		{
			if (ground_Col[i]->Intersect(pl->GetBPos()))
			{
				pl->player_Col->SetWorldPosY(ground_Col[i]->GetLocalPos().y - 1.0f);
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

		//boss_Col_LR 충돌
		for (int i = 0; i < 2; i++)
		{
			if (boss->boss_Col_LR[i]->Intersect(pl->GetBPos()))
			{
				pl->player_Col->SetWorldPosY(boss->boss_Col_LR[i]->GetWorldPos().y - 1.0f);
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

	//보스 패턴
	if (boss->GetBossPattern() == BossPattern::START)
	{
		if (6.0f < boss->start_time && boss->start_time < 6.3f)
		{
			SOUND->Play("Boss");
		}
	}

	else if (boss->GetBossPattern() == BossPattern::IDLE)
	{
		slam = false;
		sweep_Checking = false;
		slam_InterTime = 0.0f;
		slam_InterTime2 = 0.0f;
		slam_finish = 0.0f;

		slam_Checking = false;
		slam_Checking_Re = false;
		slam_Effect->visible = false;
		slam_effect_checking = false;

		slam_Effect->frame.x = 0.0f;
	}

	else if (boss->GetBossPattern() == BossPattern::SLAM)
	{

	}

	else if (boss->GetBossPattern() == BossPattern::SWEEP)
	{

	}

	else if (boss->GetBossPattern() == BossPattern::BALL)
	{

	}

	//Idle
	if (INPUT->KeyDown('1'))
	{
		boss->GetBossPattern() = BossPattern::IDLE;

	}

	//Slam
	if (INPUT->KeyDown('2'))
	{
		boss->GetBossPattern() = BossPattern::SLAM;
	}

	//Sweep
	if (INPUT->KeyDown('3'))
	{
		boss->GetBossPattern() = BossPattern::SWEEP;
	}

	//Ball
	if (INPUT->KeyDown('4'))
	{
		boss->GetBossPattern() = BossPattern::BALL;
	}

	//Die
	if (INPUT->KeyDown('5'))
	{
		boss->GetBossPattern() = BossPattern::DIE;
	}

	//Start 진동
	if (2.6f < boss->start_time && boss->start_time < 4.2f)
	{
		CAM->position += (RIGHT * 1000.0f * sinf(boss->start_time / 0.005f * DIV2PI) * DELTA);
	}

	//Slam 찍기 패턴 두번 찍어야함
	if (boss->GetBossPattern() == BossPattern::SLAM)
	{
		//1초동안 손 올라가게
		if (boss->slam_time < 1.0f)
		{
			boss->hand_Col->MoveWorldPos(UP * 500.0f * DELTA);
			boss->hand_Col_Reverse->MoveWorldPos(UP * 500.0f * DELTA);
		}

		//0.7 ~ 1.0초 사이에 collider On!
		if (0.7f < boss->slam_time && boss->slam_time < 1.0f)
		{
			boss->hand_Slam->colOnOff = true;
			boss->hand_Slam_Reverse->colOnOff = true;
		}

		//Slam 충돌
		if (boss->hand_Slam->Intersect(pl->player_Col))
		{
			boss->hand_Slam->colOnOff = false;

			if (pl->born_Hp > 0.0f)
			{
				pl->born_Hp -= 20.0f;
				pl->playerUi->player_Hp->scale.x -= 20.0f;

				SOUND->Stop("Hit");
				SOUND->Play("Hit");

				if (pl->reverse)
				{
					pl->player_Col->MoveWorldPos(RIGHT * 1000.0f * DELTA);
				}

				else if (!pl->reverse)
				{
					pl->player_Col->MoveWorldPos(LEFT * 1000.0f * DELTA);
				}

				pl->Hit_normal->visible = true;
				pl->Hit_normal->SetWorldPos(Vector2(pl->player_Col->GetWorldPos()));
			}
		}

		else if (boss->hand_Slam_Reverse->Intersect(pl->player_Col))
		{
			boss->hand_Slam_Reverse->colOnOff = false;

			if (pl->born_Hp > 19.0f)
			{
				pl->born_Hp -= 20.0f;
				pl->playerUi->player_Hp->scale.x -= 20.0f;

				SOUND->Stop("Hit");
				SOUND->Play("Hit");

				if (pl->reverse)
				{
					pl->player_Col->MoveWorldPos(RIGHT * 1000.0f * DELTA);
				}

				else if (!pl->reverse)
				{
					pl->player_Col->MoveWorldPos(LEFT * 1000.0f * DELTA);
				}

				pl->Hit_normal->visible = true;
				pl->Hit_normal->SetWorldPos(Vector2(pl->player_Col->GetWorldPos()));
			}
		}

		if (boss->slam_time < 0.5f)
		{
			SOUND->Play("First_Slam");
		}

		//손 올리고 2초 지나면 지금 플레이어의 위치에 찍기
		if (boss->slam_time > 1.92f)
		{
			//손 찍는거 위치 조절
			if (!boss->hand_Col->Intersect(ground_Col[0]) &&
				!boss->hand_Col_Reverse->Intersect(ground_Col[0]) &&
				slam_InterTime <= 0.00001f)
			{
				//왼쪽
				if (pl->GetPos().x <= -114.0f)
				{
					lastPos = Vector2(pl->GetPos().x + 485.0f, pl->GetPos().y);
					lastPos.Normalize();
					boss->hand_Col->MoveWorldPos(lastPos * 2800.0f * DELTA);
					SOUND->Play("First_Slam");

				}

				//오른쪽
				else if (pl->GetPos().x >= -113.0f)
				{
					lastPos = Vector2(pl->GetPos().x - 325.0f, pl->GetPos().y);
					lastPos.Normalize();
					boss->hand_Col_Reverse->MoveWorldPos(lastPos * 2800.0f * DELTA);
					SOUND->Play("First_Slam");
				}
			}
			//두번 찍게 해야함
			//어떻게? wkf

			//왼손이 땅에 닿으면, 부르르 떨리고 Interval이 1.25초가 지나면 다시 손들기
			//근데 손들면서 머리도 같이 올라가야함
			if (ground_Col[0]->Intersect(boss->hand_Col))
			{
				ground_lastPos = pl->GetPos();

				slam_Effect->SetWorldPos(Vector2(slam_location_Ch.x, slam_location_Ch.y + 200.0f));
				slam_Effect->visible = true;

				//slam_Count--;
				slam_InterTime += DELTA;
				//cout << slam_InterTime << endl;

				if (slam_InterTime < 0.05f)
				{
					SOUND->Play("Slam_Stomp");
					slam_location_Ch = pl->GetPos();
				}

				if (0.4f < slam_InterTime && slam_InterTime < 1.2f)
				{
					boss->hand_Col->MoveWorldPos(RIGHT * 250.0f * sinf(boss->slam_time / 0.01f * DIV2PI) * DELTA);
					CAM->position += (RIGHT * 500.0f * sinf(boss->slam_time / 0.01f * DIV2PI) * DELTA);
				}

				else if (slam_InterTime >= 1.25f)
				{
					//cout << "22" << endl;
					slam_Checking = true;
				}
			}

			else if (ground_Col[0]->Intersect(boss->hand_Col_Reverse))
			{
				//땅 찍었을 때 플레이어 위치 받기
				ground_lastPos = pl->GetPos();

				slam_Effect->SetWorldPos(Vector2(slam_location_Ch.x, slam_location_Ch.y + 200.0f));
				slam_Effect->visible = true;

				slam_InterTime += DELTA;
				//cout << slam_InterTime << endl;

				if (slam_InterTime < 0.05f)
				{
					SOUND->Play("Slam_Stomp");
					slam_location_Ch = pl->GetPos();
				}

				if (0.4f < slam_InterTime && slam_InterTime < 1.2f)
				{
					slam_effect_checking = true;
					boss->hand_Col_Reverse->MoveWorldPos(RIGHT * 450.0f * sinf(boss->slam_time / 0.01f * DIV2PI) * DELTA);
					CAM->position += (RIGHT * 300.0f * sinf(boss->slam_time / 0.01f * DIV2PI) * DELTA);
				}

				else if (slam_InterTime >= 1.25f)
				{
					//cout << "11" << endl;
					slam_Checking_Re = true;
					slam_effect_checking = false;
				}

			}

			if (slam_Checking)
			{
				slam_Effect->frame.x = 0.0f;
				slam_Effect->visible = false;
				slam_InterTime2 += DELTA;

				if (slam_InterTime2 < 1.0f)
				{
					boss->hand_Slam->colOnOff = true;
					boss->hand_Col->SetWorldPos(Vector2(-540.0f, 0.0f));
					//boss->hand_Col->MoveWorldPos(slam_Location * 520.0f * DELTA);
					boss->boss_Col->MoveWorldPos(UP * 150.0f * DELTA);
					boss->bottom1->MoveWorldPos(UP * 10.0f * DELTA);
				}

			}

			if (slam_Checking_Re)
			{
				slam_Effect->frame.x = 0.0f;
				slam_Effect->visible = false;
				slam_InterTime2 += DELTA;

				if (slam_InterTime2 < 1.0f)
				{
					boss->hand_Slam_Reverse->colOnOff = true;
					boss->hand_Col_Reverse->SetWorldPos(Vector2(330.0f, 0.0f));
					boss->boss_Col->MoveWorldPos(UP * 150.0f * DELTA);
					boss->bottom1->MoveWorldPos(UP * 10.0f * DELTA);
				}

			}
		}

		if (boss->slam_time > 4.88f && !slam)
		{
			slam_InterTime = 0.0f;
			slam_InterTime2 = 0.0f;
			boss->slam_time = 1.1f;
			slam_Checking = false;
			slam_Checking_Re = false;

			slam = true;
		}

		if (slam)
		{
			slam_finish += DELTA;
			//cout << slam_finish << endl;

			if (3.5f < slam_finish && slam_finish < 4.5f)
			{
				boss->hand_Slam->colOnOff = false;
				boss->hand_Slam_Reverse->colOnOff = false;
				boss->hand_Col->MoveWorldPos(DOWN * 480.0f * DELTA);
				boss->hand_Col_Reverse->MoveWorldPos(DOWN * 480.0f * DELTA);
			}

			if (slam_finish > 5.0f)
			{
				boss->GetBossPattern() = BossPattern::IDLE;
			}
		}
	}

	else if (boss->GetBossPattern() == BossPattern::SWEEP && boss->sweep > 0)
	{
		if (boss->hand_Col->Intersect(pl->player_Col))
		{
			boss->hand_Col->colOnOff = false;

			if (pl->born_Hp > 19.0f)
			{
				pl->born_Hp -= 20.0f;
				pl->playerUi->player_Hp->scale.x -= 20.0f;

				SOUND->Stop("Hit");
				SOUND->Play("Hit");

				if (pl->reverse)
				{
					pl->player_Col->MoveWorldPos(RIGHT * 1000.0f * DELTA);
				}

				else if (!pl->reverse)
				{
					pl->player_Col->MoveWorldPos(LEFT * 1000.0f * DELTA);
				}

				pl->Hit_normal->visible = true;
				pl->Hit_normal->SetWorldPos(Vector2(pl->player_Col->GetWorldPos()));
			}
		}

		else if (boss->hand_Col_Reverse->Intersect(pl->player_Col))
		{
			boss->hand_Col_Reverse->colOnOff = false;

			if (pl->born_Hp > 19.0f)
			{
				pl->born_Hp -= 20.0f;
				pl->playerUi->player_Hp->scale.x -= 20.0f;

				SOUND->Stop("Hit");
				SOUND->Play("Hit");

				if (pl->reverse)
				{
					pl->player_Col->MoveWorldPos(RIGHT * 1000.0f * DELTA);
				}

				else if (!pl->reverse)
				{
					pl->player_Col->MoveWorldPos(LEFT * 1000.0f * DELTA);
				}

				pl->Hit_normal->visible = true;
				pl->Hit_normal->SetWorldPos(Vector2(pl->player_Col->GetWorldPos()));
			}
		}

		//Sweep 위치 조절
		if (boss->sweep_time < 1.0f)
		{
			if (!sweep_Checking)
			{
				SOUND->Play("Sweeping_Start");
	
				boss->hand_Col->MoveWorldPos(LEFT * 1000.0f * DELTA);
				boss->hand_Col_Reverse->MoveWorldPos(RIGHT * 1000.0f * DELTA);
			}

			else if (sweep_Checking)
			{
				SOUND->Play("Sweeping_Start");
				boss->hand_Col->SetWorldPosX(-1200.0f);
				boss->hand_Col_Reverse->SetWorldPosX(1200.0f);
			}

		}

		//왼쪽
		if (pl->GetPos().x <= -114.0f)
		{
			//1초 ~ 1.7초 머리랑 몸 왼쪽으로 이동하면서 각도 틀기
			if (1.0f < boss->sweep_time && boss->sweep_time < 1.7f)
			{
				boss->boss_Col->rotation += 0.2f * ToRadian;
				boss->boss_Col->Update();
				boss->boss_Col->MoveWorldPos(LEFT * 200.0f * DELTA);
				boss->body1->MoveWorldPos(LEFT * 200.0f * DELTA);
			}

			//1.4초 ~ 1.9초 ㅂㄷㅂㄷ
			else if (1.4f < boss->sweep_time && boss->sweep_time < 1.9f)
			{
				boss->boss_Col->MoveWorldPos(RIGHT * 450.0f * sinf(boss->sweep_time / 0.01f * DIV2PI) * DELTA);
				boss->body1->MoveWorldPos(RIGHT * 650.0f * sinf(boss->sweep_time / 0.01f * DIV2PI) * DELTA);
			}

			//2.2초 ~ 2.7초 오른쪽으로 기울이기 이동했던 반대방향으로 X 2배속으로 이동
			else if (2.2f < boss->sweep_time && boss->sweep_time < 2.7f)
			{
				boss->hand_Col->colOnOff = true;
				boss->boss_Col->rotation -= 0.6f * ToRadian;
				boss->body1->rotation -= 0.1f * ToRadian;
				boss->boss_Col->MoveWorldPos((boss->boss_Col->GetRight() + DOWN * 0.5f) * 700.0f * DELTA);
				boss->boss_Col->MoveWorldPos(RIGHT * 350.0f * sinf(boss->sweep_time / 0.02f * DIV2PI) * DELTA);
				boss->body1->MoveWorldPos((boss->boss_Col->GetRight() + DOWN * 0.5f) * 100.0f * DELTA);
				boss->body1->MoveWorldPos(boss->boss_Col->GetRight() * 400.0f * DELTA);
			}

			//2.7초 ~ 4.0초 이동했던 반대방향으로 X 2배속으로 이동
			else if (2.7f < boss->sweep_time && boss->sweep_time < 4.0f)
			{
				//cout << "11" << endl;
				SOUND->Play("Sweeping");
				CAM->position += (RIGHT * 800.0f * sinf(boss->sweep_time / 0.005f * DIV2PI) * DELTA);
				CAM->position += (UP * 800.0f * sinf(boss->sweep_time / 0.005f * DIV2PI) * DELTA);
				boss->hand_Col->MoveWorldPos(RIGHT * 2000.0f * DELTA);
			}

			//4.1초 ~ 4.5초 이동했던 반대로 기울이기 
			if (4.1f < boss->sweep_time && boss->sweep_time < 4.7f)
			{
				//오른쪽으로 손 다시 고정
				boss->boss_Col->rotation -= 0.3f * ToRadian;
				boss->boss_Col->Update();
				boss->boss_Col->MoveWorldPos(RIGHT * 300.0f * DELTA);
				boss->body1->MoveWorldPos(RIGHT * 200.0f * DELTA);
			}

			//다시 오른쪽으로 기울이기
			if (4.1f < boss->sweep_time && boss->sweep_time < 4.6f)
			{
				boss->boss_Col->MoveWorldPos(RIGHT * 550.0f * sinf(boss->sweep_time / 0.01f * DIV2PI) * DELTA);
				boss->body1->MoveWorldPos(RIGHT * 750.0f * sinf(boss->sweep_time / 0.01f * DIV2PI) * DELTA);

				boss->boss_Col->rotation += 0.6f * ToRadian;
				boss->body1->rotation += 0.1f * ToRadian;
				boss->boss_Col->MoveWorldPos((-boss->boss_Col->GetRight() + UP * 0.4f) * 550.0f * DELTA);
				boss->boss_Col->MoveWorldPos(RIGHT * 350.0f * sinf(boss->sweep_time / 0.02f * DIV2PI) * DELTA);
				boss->body1->MoveWorldPos((-boss->boss_Col->GetRight() + UP * 0.4f) * 100.0f * DELTA);
				boss->body1->MoveWorldPos(-boss->boss_Col->GetRight() * 300.0f * DELTA);
			}

			//Rotation 0으로 변경하면서 SetWorldPos 다시 설정
			if (4.6f < boss->sweep_time && boss->sweep_time < 4.65f)
			{
				//cout << "Reset zz" << endl;
				boss->boss_Col->rotation = 0.0f;
				boss->body1->rotation = 0.0f;

				//원래 위치로
				boss->boss_Col->SetWorldPos(Vector2(-100.0f, -150.0f));
				boss->body1->SetWorldPos(Vector2(-100.0f, -150.0f));

				boss->sweep_time = 0.0f;

				sweep_Checking = true;
				boss->sweep--;
			}
		}

		//오른쪽
		else if (pl->GetPos().x >= -113.0f)
		{
			//1초 ~ 1.7초 머리랑 몸 오른쪽으로 이동하면서 각도 틀기
			if (1.0f < boss->sweep_time && boss->sweep_time < 1.7f)
			{
				boss->boss_Col->rotation -= 0.2f * ToRadian;
				boss->boss_Col->Update();
				boss->boss_Col->MoveWorldPos(RIGHT * 200.0f * DELTA);
				boss->body1->MoveWorldPos(RIGHT * 200.0f * DELTA);
			}

			//1.4초 ~ 1.9초 ㅂㄷㅂㄷ
			else if (1.4f < boss->sweep_time && boss->sweep_time < 1.9f)
			{
				boss->boss_Col->MoveWorldPos(RIGHT * 450.0f * sinf(boss->sweep_time / 0.01f * DIV2PI) * DELTA);
				boss->body1->MoveWorldPos(RIGHT * 650.0f * sinf(boss->sweep_time / 0.01f * DIV2PI) * DELTA);
			}

			//2.2초 ~ 2.7초 왼쪽으로 기울이기
			else if (2.2f < boss->sweep_time && boss->sweep_time < 2.7f)
			{
				boss->hand_Col_Reverse->colOnOff = true;
				boss->boss_Col->rotation += 0.6f * ToRadian;
				boss->body1->rotation += 0.2f * ToRadian;
				boss->boss_Col->MoveWorldPos((-boss->boss_Col->GetRight() + DOWN * 0.5f) * 700.0f * DELTA);
				boss->boss_Col->MoveWorldPos(RIGHT * 350.0f * sinf(boss->sweep_time / 0.02f * DIV2PI) * DELTA);
				boss->body1->MoveWorldPos((-boss->boss_Col->GetRight() + DOWN * 0.5f) * 100.0f * DELTA);
				boss->body1->MoveWorldPos(-boss->boss_Col->GetRight() * 400.0f * DELTA);
			}

			//2.7초 ~ 4.0초 이동했던 반대방향으로 X 2배속으로 이동
			else if (2.7f < boss->sweep_time && boss->sweep_time < 4.0f)
			{
				SOUND->Play("Sweeping");
				CAM->position += (RIGHT * 800.0f * sinf(boss->sweep_time / 0.005f * DIV2PI) * DELTA);
				CAM->position += (UP * 800.0f * sinf(boss->sweep_time / 0.005f * DIV2PI) * DELTA);
				boss->hand_Col_Reverse->MoveWorldPos(LEFT * 2000.0f * DELTA);
			}

			//4.1초 ~ 4.5초 이동했던 반대로 기울이기 
			if (4.1f < boss->sweep_time && boss->sweep_time < 4.7f)
			{
				//오른쪽으로 손 다시 고정
				boss->boss_Col->rotation += 0.3f * ToRadian;
				boss->boss_Col->Update();
				boss->boss_Col->MoveWorldPos(LEFT * 300.0f * DELTA);
				boss->body1->MoveWorldPos(LEFT * 200.0f * DELTA);
			}

			//다시 오른쪽으로 기울이기
			if (4.1f < boss->sweep_time && boss->sweep_time < 4.7f)
			{
				boss->boss_Col->MoveWorldPos(LEFT * 550.0f * sinf(boss->sweep_time / 0.01f * DIV2PI) * DELTA);
				boss->body1->MoveWorldPos(LEFT * 750.0f * sinf(boss->sweep_time / 0.01f * DIV2PI) * DELTA);

				boss->boss_Col->rotation -= 0.6f * ToRadian;
				boss->body1->rotation -= 0.2f * ToRadian;
				boss->boss_Col->MoveWorldPos((boss->boss_Col->GetRight() + UP * 0.4f) * 550.0f * DELTA);
				boss->boss_Col->MoveWorldPos(LEFT * 350.0f * sinf(boss->sweep_time / 0.02f * DIV2PI) * DELTA);
				boss->body1->MoveWorldPos((boss->boss_Col->GetRight() * 0.4f) * 100.0f * DELTA);
				boss->body1->MoveWorldPos(boss->boss_Col->GetRight() * 300.0f * DELTA);
			}

			//Rotation 0으로 변경하면서 SetWorldPos 다시 설정
			if (4.62f < boss->sweep_time && boss->sweep_time < 4.65f)
			{
				//cout << "Reset zz" << endl;
				boss->boss_Col->rotation = 0.0f;
				boss->body1->rotation = 0.0f;

				//원래 위치로
				boss->boss_Col->SetWorldPos(Vector2(-100.0f, -150.0f));
				boss->body1->SetWorldPos(Vector2(-100.0f, -150.0f));

				boss->sweep_time = 0.0f;

				sweep_Checking = true;
				boss->sweep--;
			}
		}

	}

	else if (boss->GetBossPattern() == BossPattern::BALL && boss->ball > 0)
	{
		for (int i = 0; i < 8; i++)
		{
			if (boss->ball_Col[i]->Intersect(pl->player_Col))
			{
				boss->ball_Col[i]->colOnOff = false;

				if (pl->born_Hp > 15.0f)
				{
					pl->born_Hp -= 15.0f;
					pl->playerUi->player_Hp->scale.x -= 15.0f;

					SOUND->Stop("Hit");
					SOUND->Play("Hit");

					if (pl->reverse)
					{
						pl->player_Col->MoveWorldPos(RIGHT * 1000.0f * DELTA);
					}

					else if (!pl->reverse)
					{
						pl->player_Col->MoveWorldPos(LEFT * 1000.0f * DELTA);
					}

					pl->Hit_normal->visible = true;
					pl->Hit_normal->SetWorldPos(Vector2(pl->player_Col->GetWorldPos()));
				}
			}
		}

		if (boss->ball_BigCol->Intersect(pl->player_Col))
		{
			boss->ball_BigCol->colOnOff = false;
		
			if (pl->born_Hp > 30.0f)
			{
				pl->born_Hp -= 30.0f;
				pl->playerUi->player_Hp->scale.x -= 30.0f;

				SOUND->Stop("Hit");
				SOUND->Play("Hit");

				if (pl->reverse)
				{
					pl->player_Col->MoveWorldPos(RIGHT * 1000.0f * DELTA);
				}

				else if (!pl->reverse)
				{
					pl->player_Col->MoveWorldPos(LEFT * 1000.0f * DELTA);
				}

				pl->Hit_normal->visible = true;
				pl->Hit_normal->SetWorldPos(Vector2(pl->player_Col->GetWorldPos()));
			}
		}

		//1초 이하면 왼손, 오른손 움직임을 보여주기 위해 DOWN
		if (boss->ball_time < 1.0f)
		{
			boss->hand_Col->MoveWorldPos(DOWN * 20.0f * DELTA);
			boss->hand_Col_Reverse->MoveWorldPos(DOWN * 20.0f * DELTA);
		}

		//0초 ~ 0.7초 머리통 내리기 턱은 조금 올리게 ㅋㅋ
		if (0.0f < boss->ball_time && boss->ball_time < 0.7f)
		{
			boss->boss_Col->MoveWorldPos(DOWN * 300.0f * DELTA);
			boss->bottom1->MoveWorldPos(UP * 60.0f * DELTA);
		}

		if (0.4f < boss->ball_time && boss->ball_time < 0.8f)
		{
			SOUND->Play("EnergyReady");
			CAM->position += (UP * 650.0f * sinf(boss->ball_time / 0.00066f * DIV2PI) * DELTA);
		}

		//2.8초 ~ 3.0초 ball_Dis = GetPlayer위치 받아오고 정규화
		if (2.8f < boss->ball_time && boss->ball_time < 2.9f)
		{
			ball_Dis = boss->ball_BigCol->GetWorldPos() - pl->GetPos();
			ball_Dis.Normalize();

			boss->ball_BigCol->colOnOff = true;

			for (int i = 0; i < 8; i++)
			{
				boss->ball_Col[i]->colOnOff = true;
			}
		}

		//2.8~3.0초에서 ball_BigCol이 ball_Dis로 무빙요
		if (boss->ball_Big->visible)
		{

			boss->ball_BigCol->MoveWorldPos(-ball_Dis * 600.0f * DELTA);

			if (boss->ball > 1)
			{
				SOUND->Play("EnergyFire");
			}
		}

		//4 ~ 4.2초 ball_time 초기화, Shoot false로 변경
		if (4.4f < boss->ball_time && boss->ball_time < 4.6f)
		{
			//SOUND->Play("EnergyFire");

			boss->ball_time = 2.7f;
			boss->ball_Shoot = false;
			boss->ball_BigCol->visible = false;
			//boss->ball_Big->visible = true;
			boss->ball_Energy->ChangeAnim(ANIMSTATE::ONCE, 0.05f);

			boss->ball--;

			for (int i = 0; i < 8; i++)
			{
				boss->ball_Col[i]->SetWorldPos(Vector2(-100.0f, -20.0f));
				boss->ball_BigCol->SetWorldPos(Vector2(boss->ball_Energy->GetWorldPos().x, boss->ball_Energy->GetWorldPos().y + 100.0f));
			}
		}

		if (boss->ball == 0)
		{
			boss->ball_BigCol->visible = false;
			boss->ball_Big->visible = false;

			for (int i = 0; i < 8; i++)
			{
				boss->ball_Col[i]->visible = false;
				boss->ball_Shooting[i]->visible = false;
			}

			boss->GetBossPattern() = BossPattern::GROGGY;
		}
	}

	else if (boss->GetBossPattern() == BossPattern::GROGGY)
	{
		if (boss->groggy_Check)
		{
			if (!ground_Col[0]->Intersect(boss->boss_Col))
			{
				boss->boss_Col->scale.y = 100.0f;

				boss->boss_Col->rotation += 7.0f * ToRadian * DELTA;
				boss->body1->rotation += 7.0f * ToRadian * DELTA;

				boss->boss_Col->MoveWorldPos(DOWN * 150.0f * DELTA);
				boss->body1->MoveWorldPos(DOWN * 150.0f * DELTA);
			}

			else
			{
				boss->groggy_Check = false;
				boss->boss_Col->scale.y = 250.0f;
				boss->groggy_Effect->visible = true;
				boss->groggy_Effect->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
			}
		}

		else if (!boss->groggy_Check)
		{
			if (1.55f < boss->groggy_time && boss->groggy_time < 2.8f)
			{
				CAM->position += (UP * 1200.0f * sinf(boss->groggy_time / 0.01f * DIV2PI) * DELTA);
			}

			if (5.0f < boss->groggy_time && boss->groggy_time < 7.12f)
			{
				boss->boss_Col->rotation -= 7.0f * ToRadian * DELTA;
				boss->body1->rotation -= 7.0f * ToRadian * DELTA;

				boss->boss_Col->MoveWorldPos(UP * 120.0f * DELTA);
				boss->body1->MoveWorldPos(UP * 120.0f * DELTA);

				if (5.2f < boss->groggy_time && boss->groggy_time < 5.5f)
				{
					boss->bottom1->MoveWorldPos(UP * 100.0f * DELTA);
				}


				if (5.0f < boss->groggy_time && boss->groggy_time < 5.22f)
				{
					SOUND->Play("GroggyRecovery");
					boss->groggy_Effect->visible = false;
				}
			}

			if (boss->groggy_time > 7.5f)
			{
				boss->GetBossPattern() = BossPattern::IDLE;
			}
		}
	}

	//Die 패턴
	else if (boss->GetBossPattern() == BossPattern::DIE)
	{
		if (boss->die_Check)
		{
			if (!ground_Col[0]->Intersect(boss->boss_Col))
			{
				boss->boss_Col->scale.y = 100.0f;

				boss->boss_Col->rotation += 7.0f * ToRadian * DELTA;
				boss->body1->rotation += 7.0f * ToRadian * DELTA;

				boss->boss_Col->MoveWorldPos(DOWN * 150.0f * DELTA);
				boss->body1->MoveWorldPos(DOWN * 150.0f * DELTA);
			}

			//땅에 충돌 시
			else
			{
				//cout << boss->die_time << endl;
				if (1.95f < boss->die_time && boss->die_time < 2.5f)
				{
					CAM->position += (UP * 1200.0f * sinf(boss->die_time / 0.005f * DIV2PI) * DELTA);
				}

				boss->die_Check = false;
				boss->boss_Col->scale.y = 250.0f;
				boss->die_Effect->visible = true;
			}
		}

	}

	//cout << "X : " << pl->player_Col->GetWorldPos().x << endl;
	//cout << "Y : " << pl->player_Col->GetWorldPos().y << endl;

	//보스 죽기
	else if (boss->boss_HP <= 0.0f)
	{
		boss->GetBossPattern() = BossPattern::DIE;
	}

	//보스 충돌 데미지 입기
	if (pl->player_State == PLAYERSTATE::ATTACK1)
	{
		if (boss->boss_Col->Intersect(pl->attack_Col))
		{
			pl->Hit_Skul->visible = true;
			pl->Hit_Skul->SetWorldPos(Vector2(pl->attack_Col->GetWorldPos().x, pl->attack_Col2->GetWorldPos().y - 80.0f));

			pl->attack_Col->colOnOff = false;

			//cout << "attack1" << endl;
			boss->bossHp->MoveWorldPos(RIGHT * 69.5f * DELTA);

			if (boss->boss_HP > 19.0f)
			{
				boss->boss_HP -= tw;
				boss->bossHp->scale.x -= tw;
				SOUND->Stop("Hit");
				SOUND->Play("Hit");
			}
		}
	}

	else if (pl->player_State == PLAYERSTATE::ATTACK2)
	{
		if (boss->boss_Col->Intersect(pl->attack_Col2))
		{
			pl->Hit_Skul->visible = true;
			pl->Hit_Skul->SetWorldPos(Vector2(pl->attack_Col->GetWorldPos().x, pl->attack_Col2->GetWorldPos().y - 80.0f));

			pl->attack_Col2->colOnOff = false;
			boss->bossHp->MoveWorldPos(RIGHT * 69.5f * DELTA);

			if (boss->boss_HP > 19.0f)
			{
				boss->boss_HP -= tw;
				boss->bossHp->scale.x -= tw;
				SOUND->Stop("Hit");
				SOUND->Play("Hit");
			}
		}
	}

	//점프어택이랑 충돌 시 Hit판정
	else if (pl->player_State == PLAYERSTATE::JUMPATTACK)
	{
		if (boss->boss_Col->Intersect(pl->Jump_attack_Col))
		{
			pl->Hit_Skul->visible = true;
			pl->Hit_Skul->SetWorldPos(Vector2(pl->attack_Col->GetWorldPos().x, pl->attack_Col2->GetWorldPos().y - 80.0f));

			pl->Hit_Skul->frame.x = 0;
			pl->Jump_attack_Col->colOnOff = false;
			boss->bossHp->MoveWorldPos(RIGHT * 69.5f * DELTA);

			if (boss->boss_HP > 19.0f)
			{
				boss->boss_HP -= tw;
				boss->bossHp->scale.x -= tw;
				SOUND->Stop("Hit");
				SOUND->Play("Hit");
			}
		}
	}

	if (pl->Hit_normal->frame.x >= 11.0f)
	{
		pl->Hit_normal->visible = false;
		pl->Hit_normal->frame.x = 0.0f;
	}

	if (pl->born_Hp <= 0.0f)
	{
		pl->born_Hp = 0.0f;
		pl->playerUi->player_Hp->scale.x = 0.0f;
		SOUND->Stop("Boss");
		pl->player_State = PLAYERSTATE::DIE;
	}

	if (INPUT->KeyDown('Y'))
	{
		pl->born_Hp = 0.0f;
		pl->playerUi->player_Hp->scale.x = 0.0f;
		SOUND->Stop("Boss");
		pl->player_State = PLAYERSTATE::DIE;
	}

	if (boss->GetBossPattern() == BossPattern::DIE)
	{
		if (boss->die_time > 7.0f)
		{
			SCENE->ChangeScene("엔딩");
		}
	}
}

void Scene04::Render()
{
	
	boss_Start->Render();
	boss_anger->Render();
	boss_End->Render();

	boss->Render();
	ground->Render();

	for (int i = 0; i < 3; i++)
	{
		ground_Col[i]->Render();
	}

	boss->hand_Idle->Render();
	boss->hand_Idle_Reverse->Render();
	boss->hand_Slam->Render();
	boss->hand_Slam_Reverse->Render();
	boss->hand_Sweep->Render();
	boss->hand_Sweep_Reverse->Render();
	boss->hand_Bomb->Render();
	boss->hand_Bomb_Reverse->Render();

	if (boss->sweep == 0)
	{
		if (boss->sweep_time2 < 2.0f)
		{
			boss->hand_Idle->Render();
			boss->hand_Idle_Reverse->Render();
			ground->Render();
		}
	}

	if (boss->GetBossPattern() == BossPattern::BALL ||
		boss->GetBossPattern() == BossPattern::GROGGY ||
		boss->GetBossPattern() == BossPattern::DIE)
	{
		ground->Render();
		boss->groggy_Effect->Render();
		boss->hand_Bomb->Render();
		boss->hand_Bomb_Reverse->Render();
	}

	boss->bossHpBar->Render();
	boss->bossHp->Render();

	slam_Effect->Render();

	for (int i = 0; i < 8; i++)
	{
		boss->ball_Shooting[i]->Render();
	}

	boss->ball_Big->Render();

	pl->Render();
	pl->Hit_Skul->Render();
	pl->Hit_normal->Render();

}

void Scene04::ResizeScreen()
{

}

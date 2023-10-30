#include "stdafx.h"

void Scene0033::Init()
{
	//Player
	pl = new Player();
	pl->player_Col->SetWorldPos(Vector2(-1620.0f, -960.0f));

	//Witch
	witch = new Witch();
	witch->witch_Col->SetWorldPos(Vector2(-1770.0f, -960.0f));
	witch->cat_Idle->SetParentRT(*witch->witch_Col);
	witch->cat_Idle->SetLocalPosY(-5.0f);
	witch->cat_Walk->SetParentRT(*witch->witch_Col);
	witch->Witch_State() = WITCHSTATE::CAT_IDLE;

	//Bg
	background = new ObImage(L"Tutorial_Background.png");
	background->scale = Vector2(1600.0f, 1000.0f * 1.5f) * 1.3f;
	background->SetWorldPos(Vector2(0.0f, 500.0f));
	background->space = SPACE::SCREEN;

	tutorial_Bg = new ObImage(L"Tutorial3.png");
	tutorial_Bg->scale = Vector2(1600.0f, 1000.0f) * 2.4f;

	ground = new ObRect();
	ground->scale = Vector2(3300.0f, 20.0f);
	ground->SetWorldPos(Vector2(-1930.0f, -960.0f));
	ground->pivot = OFFSET_LT;
	ground->isFilled = false;
	ground->collider = COLLIDER::RECT;

	//Gate
	gate_Normal = new ObImage(L"gate_normal.png");
	gate_Normal->scale = Vector2(1536.0f / 8.0f, 192.0f) * 2.4f;
	gate_Normal->maxFrame = Int2(8, 1);
	gate_Normal->SetWorldPos(Vector2(930.0f, -810.0f));
	gate_Normal->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	gate_Rect = new ObRect();
	gate_Rect->scale = Vector2(1536.0f / 8.0f, 192.0f) * 2.4f;
	gate_Rect->SetWorldPos(Vector2(940.0f, -810.0f));
	gate_Rect->isFilled = false;
	gate_Rect->visible = true;
	gate_Rect->collider = COLLIDER::RECT;

	input = new ObImage(L"Input.png");
	input->scale = Vector2(452.0f, 92.0f * 0.5f);
	input->SetParentRT(*gate_Normal);
	input->SetLocalPos(Vector2(0.0f, -180.0f));
	input->visible = false;

	guard_Head = new ObImage(L"ChiefGuard_Head.png");
	guard_Head->scale = Vector2(30.0f, 52.0f) * 2.4f;
	guard_Head->SetWorldPos(Vector2(-840.0f, -930.0f));
	guard_Head->visible = true;

	guard_Head_Change = new ObImage(L"Guard_Head_Changing.png");
	guard_Head_Change->scale = Vector2(9000.0f / 45.0f, 200.0f) * 2.5f;
	guard_Head_Change->SetParentRT(*pl->player_Col);
	guard_Head_Change->SetLocalPos(Vector2(6.0f, 80.0f));
	guard_Head_Change->maxFrame = Int2(45, 1);
	guard_Head_Change->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	guard_Head_Change->visible = false;

	thunder = new ObImage(L"Thunder.png");
	thunder->scale = Vector2(2790.0f / 9.0f, 310.0f) * 2.5f;
	thunder->SetParentRT(*pl->player_Col);
	thunder->SetLocalPosX(35.0f);
	thunder->SetLocalPosY(300.0f);
	thunder->maxFrame = Int2(9, 1);
	thunder->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	thunder->visible = false; 

	pl->playerUi->sceneBlack_Top->SetWorldPosY(700.0f);
	pl->playerUi->sceneBlack_Bottom->SetWorldPosY(-550.0f);

	pl->HpChecking = true;
}

void Scene0033::Release()
{
	SafeDelete(tutorial_Bg);
	SafeDelete(background);
	SafeDelete(ground);

	SafeDelete(gate_Normal);
	SafeDelete(gate_Rect);
	SafeDelete(input);

	SafeDelete(guard_Head);
	SafeDelete(guard_Head_Change);
	SafeDelete(thunder);
}

void Scene0033::Update()
{
	//cout << "마우스 X좌표 : " << INPUT->GetMouseWorldPos().x << endl;
	//cout << "마우스 Y좌표 : " << INPUT->GetMouseWorldPos().y << endl;
	
	pl->Update();
	
	thunder->Update();
	background->Update();
	tutorial_Bg->Update();
	ground->Update();
	witch->Update();
	guard_Head->Update();

	gate_Normal->Update();
	gate_Rect->Update();
	input->Update();
	guard_Head_Change->Update();
}

void Scene0033::LateUpdate()
{
	//플레이어
	pl->player_Col->SetWorldPosX(Utility::Saturate(pl->player_Col->GetWorldPos().x, -1850.0f, 1325.0f));
	//캠
	CAM->position.x = Utility::Saturate(pl->player_Col->GetWorldPos().x, -1900.0f + app.GetHalfWidth(), 1370.0f - app.GetHalfWidth());
	CAM->position.y = Utility::Saturate(pl->player_Col->GetWorldPos().y, -700.0f, 200.0f - app.GetHalfHeight());

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
				pl->guard_Jump->frame.x = 0;
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

	//고양이
	witch->Witch_State() = WITCHSTATE::CAT_IDLE;
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

	//Guard 머리로 변경
	if (INPUT->KeyDown('T'))
	{
		guard_Check = true;
	}

	if (guard_Check)
	{
		guard_Head_Change->visible = true;
		guard_Head->visible = false;
		//플레이어 Visible 다 끄기
		pl->AllInvisible();

		//번개 떨구기
		if (guard_Head_Change->frame.x >= 22.0f)
		{
			thunder->visible = true;
			SOUND->Play("Thunder");
		}

		if (thunder->frame.x >= 6.0f)
		{
			thunder->visible = false;
			SOUND->Stop("Thunder");
		}

		if (guard_Head_Change->frame.x >= 44.0f)
		{
			pl->Skul_State = SKUL::Guard;
			//pl->player_State = PLAYERSTATE::IDLE;

			guard_Head_Change->visible = false;
			//pl->guard->guard_Idle->visible = true;
		}
	}

	if (pl->Hit_normal->frame.x >= 11.0f)
	{
		pl->Hit_normal->visible = false;
		pl->Hit_normal->frame.x = 0.0f;
	}

	//Gate
	if (gate_Rect->Intersect(pl->player_Col))
	{
		input->visible = true;
	}

	else
	{
		input->visible = false;
	}

	if (input->visible)
	{
		if (INPUT->KeyDown('F'))
		{
			cout << "Scene0022 Change zz" << endl;
			SCENE->ChangeScene("튜토리얼4");
		}
	}

	//Guard 상태에서 스킬 A쓰면 앞으로 돌진?느낌나게
	if (pl->slash_Check)
	{
		if (pl->reverse)
		{
			pl->player_Col->MoveWorldPos(LEFT * 1600.0f * DELTA);
		}

		else
		{
			pl->player_Col->MoveWorldPos(RIGHT * 1600.0f * DELTA);
		}
		
	}
}

void Scene0033::Render()
{
	//배경
	background->Render();
	tutorial_Bg->Render();
	ground->Render();

	//Guard
	guard_Head->Render();
	guard_Head_Change->Render();
	thunder->Render();

	gate_Normal->Render();
	gate_Rect->Render();
	input->Render();

	witch->Render();

	pl->Render();
	


}

void Scene0033::ResizeScreen()
{

}

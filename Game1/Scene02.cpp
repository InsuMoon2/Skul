#include "stdafx.h"

void Scene02::Init()
{
	pl = new Player();
	pl->player_Col->SetLocalPosX(-870.0f);

	rectGround = new ObRect();
	rectGround->scale = Vector2(2500.0f, 100.0f);
	rectGround->SetWorldPos(Vector2(-1500.0f, -30.0f));
	rectGround->isFilled = false;
	rectGround->visible = false;
	rectGround->pivot = OFFSET_LT;
	rectGround->collider = COLLIDER::RECT;

	bg = new ObImage(L"stage01.png");
	bg->scale = Vector2(1600.0f, 960.0f) * 1.3f;
	bg->SetWorldPos(Vector2(-500.0f, 200.0f));
	
	gate_Wall = new ObImage(L"Gate_Wall.png");
	gate_Wall->scale = Vector2(960.0f, 250.0f) * 1.2f;
	gate_Wall->SetParentRT(*bg);
	gate_Wall->SetLocalPos(Vector2(300.0f, -100.0f));

	gate_Normal = new ObImage(L"gate_normal.png");
	gate_Normal->scale = Vector2(1536.0f / 8.0f, 192.0f) * 2.4f;
	gate_Normal->maxFrame = Int2(8, 1);
	gate_Normal->SetParentRT(*bg);
	gate_Normal->SetLocalPos(Vector2(-100.0f, -80.0f));
	gate_Normal->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	gate_Rect = new ObRect();
	gate_Rect->scale = Vector2(1536.0f / 8.0f, 192.0f) * 2.4f;
	gate_Rect->SetParentRT(*bg);
	gate_Rect->SetLocalPos(Vector2(-100.0f, -80.0f));
	gate_Rect->isFilled = false;
	gate_Rect->visible = false;
	gate_Rect->collider = COLLIDER::RECT;

	input = new ObImage(L"Input.png");
	input->scale = Vector2(452.0f, 92.0f * 0.5f);
	input->SetParentRT(*gate_Normal);
	input->visible = false;
	input->SetLocalPos(Vector2(0.0f, -180.0f));

	pl->player_State = PLAYERSTATE::JUMP;

	SOUND->AddSound("Chapter1.wav", "Monster", false);
	SOUND->Play("Monster");
}

void Scene02::Release()
{
	SafeDelete(bg);
	SafeDelete(gate_Wall);
	SafeDelete(gate_Normal);
	SafeDelete(input);
}

void Scene02::Update()
{
	//cout << "마우스 X좌표 : " << INPUT->GetMouseWorldPos().x << endl;
	//cout << "마우스 Y좌표 : " << INPUT->GetMouseWorldPos().y << endl;

	bg->Update();
	pl->Update();
	rectGround->Update();
	gate_Wall->Update();
	gate_Normal->Update();
	input->Update();
	gate_Rect->Update();


}

void Scene02::LateUpdate()
{
	//플레이어 가두기
	pl->player_Col->SetWorldPosX(Utility::Saturate(pl->player_Col->GetWorldPos().x, -1500.0f, 500.0f));
	//캠
	CAM->position.x = Utility::Saturate(pl->player_Col->GetWorldPos().x, -1540.0f + app.GetHalfWidth(), 540.0f - app.GetHalfWidth());
	CAM->position.y = Utility::Saturate(pl->player_Col->GetWorldPos().y + 350.0f, -500.0f, 800.0f - app.GetHalfHeight());
	
	Vector2 dis = pl->player_Col->GetWorldPos() - pl->born_HeadCol->GetWorldPos();
	float distance = dis.Length();

	float	scalar = 500.0f;

	if (pl->shoot_time > 0.5f)
	{
		if (pl->born_HeadCol->Intersect(pl->player_Col))
		{
			pl->born_HeadCol->visible = false;
			pl->born_Head->visible = false;

			pl->born_Check = true;
		}
	}

	if (pl->GetState() == PLAYERSTATE::SKILL2)
	{
		pl->born_Head->visible = false;
		pl->player_Col->SetWorldPos(Vector2(pl->born_HeadCol->GetWorldPos().x, pl->born_HeadCol->GetWorldPos().y - 30.0f));
	}

	if (!rectGround->Intersect(pl->born_HeadCol))
	{
		if (distance > 520.0f)
		{
			//cout << "22" << endl;
			pl->born_HeadCol->MoveWorldPos(DOWN * scalar * DELTA);
		}
	}

	if (rectGround->Intersect(pl->born_HeadCol))
	{
		scalar = 0.0f;
	}

	//충돌
	if (pl->GetGravity() > 0.0f)
	{
		if (rectGround->Intersect(pl->player_Bottom))
		{
			pl->player_Col->SetWorldPosY(rectGround->GetLocalPos().y - 1.0f);
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
			cout << "Scene03 Change zz" << endl;
			SCENE->ChangeScene("몬스터");
		}
	}
}

void Scene02::Render()
{
	bg->Render();
	gate_Wall->Render();
	gate_Normal->Render();
	rectGround->Render();
	input->Render();
	gate_Rect->Render();
	pl->Render();
}

void Scene02::ResizeScreen()
{

}

#include "stdafx.h"

void Scene0055::Init()
{
	Devil = new DevilCastle();
	
	//Player
	pl = new Player();
	pl->player_Col->SetWorldPos(Vector2(-1800.0f, 235.0f));

	//Witch
	witch = new Witch();
	witch->witch_Col->SetWorldPos(Vector2(-1400.0f, 235.0f));
	witch->witch_Idle->SetParentRT(*witch->witch_Col);
	witch->Witch_State() = WITCHSTATE::IDLE;

	//��
	block = new ObRect();
	block->scale = Vector2(3840.0f * 1.1f, 50.0f);
	block->SetWorldPos(Vector2(-1840.0f * 1.6f, 240.0f));
	block->pivot = OFFSET_LT;
	block->visible = false;
	block->isFilled = false;
	block->collider = COLLIDER::RECT;

	quest = new ObImage(L"Get_Quest.png");
	quest->scale = Vector2(10200.0f / 51.0f, 200.0f) * 2.5f;
	quest->SetParentT(*pl->player_Col);
	quest->SetLocalPosX(10.0f);
	quest->SetLocalPosY(80.0f);
	quest->maxFrame = Int2(51,1);
	quest->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	quest->visible = false;

	reborn = new ObImage(L"reborn_castle_skul.png");
	reborn->scale = Vector2(5184.0f / 27.0f, 192.0f) * 2.5f;
	reborn->SetParentT(*pl->player_Col);
	reborn->SetLocalPosX(-23.0f);
	//reborn->SetLocalPosY(80.0f);
	reborn->maxFrame = Int2(27, 1);
	reborn->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	reborn->visible = true;

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

	SOUND->AddSound("DemonCastle.wav", "DemonCastle", false);
	SOUND->AddSound("Skul_Reborn_Cape.wav", "Cape", false);
	//SOUND->Play("DemonCastle");

	pl->HpChecking = false;
	pl->playerUi->sceneBlack_Top->visible = false;
	pl->playerUi->sceneBlack_Bottom->visible = false;

	pl->playerUi->UiBlack();
	pl->playerUi->UiInVisible();
}

void Scene0055::Release()
{
	SafeDelete(block);
	SafeDelete(text);
	SafeDelete(next);
	SafeDelete(quest);
	SafeDelete(reborn);
}

void Scene0055::Update()
{
	//cout << INPUT->GetMouseWorldPos().x << endl;
	//cout << INPUT->GetMouseWorldPos().y << endl;

	if (textCheck)
	{
		text_Time += DELTA;

		if (INPUT->KeyDown('F'))
		{
			number++;
			text_Time = 0.0f;
		}

		if (number >= 7)
		{
			textCheck = false;
			text->visible = false;
			next->visible = false;
		}

		if (number <= 7)
		{
			if (text_Time <= 0.4f)
			{
				SOUND->Play("Talk");
			}
		}
	}

	if (INPUT->KeyDown('1'))
	{
		quest->visible = true;
	}
	
	if (quest->frame.x >= 50.0f)
	{
		quest->visible = false;
	}

	if (reborn->frame.x <= 13.0f)
	{
		SOUND->Play("Skill_B");
	}

	if (reborn->frame.x >= 13.0f)
	{
		SOUND->Play("Cape");
	}

	if(reborn->frame.x >= 26.0f)
	{
		SOUND->Stop("Cape");

		textCheck = true;
	}

	Devil->Invisible();

	Devil->Update();
	block->Update();
	text->Update();
	next->Update();

	pl->Update();

	witch->Update();
	quest->Update();
	reborn->Update();

}

void Scene0055::LateUpdate()
{
	//�÷��̾� ���α�
	pl->player_Col->SetWorldPosX(Utility::Saturate(pl->player_Col->GetWorldPos().x, -3800.0f * 1.5f / 2.0f, 3840.0f * 1.5f / 2.0f));
	//ķ
	CAM->position.x = Utility::Saturate(pl->player_Col->GetWorldPos().x, -1920.0f * 1.5f + app.GetHalfWidth(), 1920.0f * 1.5f - app.GetHalfWidth());
	CAM->position.y = Utility::Saturate(pl->player_Col->GetWorldPos().y + 500.0f, -2912.0f, 950.0f - app.GetHalfHeight());

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

	if (pl->GetState() == PLAYERSTATE::SKILL2)
	{
		pl->born_Head->visible = false;
		pl->player_Col->SetWorldPos(Vector2(pl->born_HeadCol->GetWorldPos().x, pl->born_HeadCol->GetWorldPos().y - 30.0f));
	}

	//���� head�� �浹���� ������, distance > 520;
	if (!block->Intersect(pl->born_HeadCol))
	{
		if (distance > 520.0f)
		{
			//cout << "22" << endl;
			pl->born_HeadCol->MoveWorldPos(DOWN * scalar * DELTA);
		}
	}

	if (block->Intersect(pl->born_HeadCol))
	{
		scalar = 0.0f;
	}

	if (pl->GetGravity() > 0.0f)
	{
		if (block->Intersect(pl->GetBPos()))
		{
			pl->player_Col->SetWorldPosY(block->GetLocalPos().y - 0.1f);
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

	if (textCheck)
	{
		SceneStart();

		text->visible = true;
		next->visible = true;
	}

	if (quest->visible)
	{
		pl->born_Idle->visible = false;
	}

	if (INPUT->KeyDown('2'))
	{
		scnenChange = true;
	}

	if (scnenChange)
	{
		SCENE->ChangeScene("����");
	}

	if (number >= 8)
	{
		text->visible = false;
		next->visible = false;
		scnenChange = true;
	}
}

void Scene0055::Render()
{
	if (textCheck)
	{
		DWRITE->RenderText(L"����", RECT{ 430, 800,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
			24.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);

		switch (number)
		{
		case 0:
			DWRITE->RenderText(L"���� ������ ����", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;
		case 1:
			DWRITE->RenderText(L"���ݺ��� ���� �ϴ� ���� �� �赵�� �ϼ���.", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;
		case 2:
			DWRITE->RenderText(L"��ȭ������ ������ �� �����ʾ� �̷��Գ� ���� �޽��̶��...", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;
		case 3:
			DWRITE->RenderText(L"�������Ƽ��� �����̶� ��� ��ȯ�Ͽ� Į���� ���� �����ϰ� �ͽ��ϴٸ�...", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;
		case 4:
			DWRITE->RenderText(L"�������� ��翡�� ���� �λ��� ġ���ϴ� �͸����ε� ��������.", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;
		case 5:
			DWRITE->RenderText(L"��¿ �� ���� ��ſ��� ���մ��� ������ ��Ź����� �� �� �����ϴ�.", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;
		case 6:
			DWRITE->RenderText(L"���ó�� ���� ���̷��� ��񺴿��� �̷� ������ ��Ź�� ����� �ϴ� ��Ȳ�� ���ٴ�...", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;
		case 7:
			DWRITE->RenderText(L"���� ���մ԰� �ǿ��Ե�, �׸��� ���� �������� �����ּ���.", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;
		}
	}
	

	Devil->Render();
	block->Render();

	

	reborn->Render();
	quest->Render();
	witch->Render();

	if (reborn->frame.x >= 26.0f)
	{
		reborn->visible = false;
		pl->Render();
	}

	text->Render();
	next->Render();
}

void Scene0055::ResizeScreen()
{

}

void Scene0055::SceneStart()
{
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

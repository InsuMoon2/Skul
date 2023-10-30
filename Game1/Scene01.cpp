#include "stdafx.h"

void Scene01::Init()
{
	character = new Player();
	character->player_Col->SetWorldPosY(400.0f);
	character->player_Col->collider = COLLIDER::RECT;

	Devil = new DevilCastle();

	//블럭
	for (int i = 0; i < 6; i++)
	{
		block[i] = new ObRect();
		block[i]->pivot = OFFSET_LT;
		block[i]->visible = false;
		block[i]->isFilled = false;
		block[i]->collider = COLLIDER::RECT;
	}

	block[0]->scale = Vector2(3840.0f * 1.1f, 50.0f);
	block[0]->SetWorldPos(Vector2(-1840.0f * 1.6f, 240.0f));

	block[1]->scale = Vector2(157.0f, 17.0f);
	block[1]->SetWorldPos(Vector2(-1895.0f, 561.0f));

	block[2]->scale = Vector2(228.0f, 17.0f);
	block[2]->SetWorldPos(Vector2(-1050.0f, 557.0f));

	block[3]->scale = Vector2(298.0f, 35.0f);
	block[3]->SetWorldPos(Vector2(-310.0f, 510.0f));

	block[4]->scale = Vector2(161.0f, 17.0f);
	block[4]->SetWorldPos(Vector2(159.0f, 558.0f));

	block[5]->scale = Vector2(363.0f, 21.0f);
	block[5]->SetWorldPos(Vector2(846.0f, 571.0f));

	SOUND->AddSound("DemonCastle.wav", "DemonCastle", true);
	SOUND->Play("DemonCastle");

	character->HpChecking = true;
	character->playerUi->sceneBlack_Top->visible = false;
	character->playerUi->sceneBlack_Bottom->visible = false;
}

void Scene01::Release()
{
	SafeDelete(character);
	SafeDelete(Devil);

	for (int i = 0; i < 5; i++)
	{
		SafeDelete(block[i]);
	}
}

void Scene01::Update()
{
	//cout << "마우스 X좌표 : " << INPUT->GetMouseWorldPos().x << endl;
	//cout << "마우스 Y좌표 : " << INPUT->GetMouseWorldPos().y << endl;

	character->Update();
	Devil->Update();

	for (int i = 0; i < 6; i++)
	{
		block[i]->Update();
	}

	
}

void Scene01::LateUpdate()
{
	//플레이어 가두기
	character->player_Col->SetWorldPosX(Utility::Saturate(character->player_Col->GetWorldPos().x, -3800.0f * 1.5f / 2.0f, 3840.0f * 1.5f / 2.0f));
	//캠
	CAM->position.x = Utility::Saturate(character->player_Col->GetWorldPos().x, -1920.0f * 1.5f + app.GetHalfWidth(), 1920.0f * 1.5f - app.GetHalfWidth());
	CAM->position.y = Utility::Saturate(character->player_Col->GetWorldPos().y + 500.0f, -2912.0f, 950.0f - app.GetHalfHeight());

	Vector2 dis = character->player_Col->GetWorldPos() - character->born_HeadCol->GetWorldPos();
	float distance = dis.Length();

	float	scalar = 100.0f;

	if (character->shoot_time > 0.5f)
	{
		if (character->born_HeadCol->Intersect(character->player_Col))
		{
			character->born_HeadCol->visible = false;
			character->born_Head->visible = false;

			character->born_Check = true;
		}
	}
	
	for (int i = 0; i < 6; i++)
	{
		if (character->GetState() == PLAYERSTATE::SKILL2)
		{
			character->born_Head->visible = false;
			character->player_Col->SetWorldPos(Vector2(character->born_HeadCol->GetWorldPos().x,
				character->born_HeadCol->GetWorldPos().y - 55.0f));
		}

		//땅에 head가 충돌하지 않으면, distance > 520;
		if (!block[i]->Intersect(character->born_HeadCol))
		{
			if (distance > 520.0f)
			{
				//cout << "22" << endl;
				character->born_HeadCol->MoveWorldPos(DOWN * scalar * DELTA);
			}
		}

		if (block[i]->Intersect(character->born_HeadCol))
		{
			if (character->born_Head->visible)
			{
				character->groundInter = true;
				character->born_HeadCol->SetWorldPosY(block[i]->GetLocalPos().y + 21.0f);
			}

			scalar = 0.0f;
		}
	}

	if (character->GetGravity() > 0.0f)
	{
		for (int i = 0; i < 6; i++)
		{
			if (block[i]->Intersect(character->GetBPos()))
			{
				character->player_Col->SetWorldPosY(block[i]->GetLocalPos().y - 0.1f);
				character->GetGravity() = 0.0f;
				character->GetDashCount() = 2;

				if (character->player_State == PLAYERSTATE::JUMP ||
					character->player_State == PLAYERSTATE::JUMPATTACK)
				{
					character->player_State = PLAYERSTATE::IDLE;
					character->born_Jump->frame.x = 0;
					character->jump = false;

					if (INPUT->KeyPress(VK_LEFT))
					{
						character->reverse = true;
						character->player_State = PLAYERSTATE::RUN;
					}

					if (INPUT->KeyPress(VK_RIGHT))
					{
						character->reverse = false;
						character->player_State = PLAYERSTATE::RUN;
					}
				}
			}
		}
	}
	
	if (character->player_Col->GetWorldPos().y < -3410.0f)
	{
		cout << "Scene02 Change zz" << endl;
		SCENE->ChangeScene("던전 입구");
		SOUND->Stop("DemonCastle");
	}
	
}

void Scene01::Render()
{
	Devil->Render();
	character->Render();

	for (int i = 0; i < 6; i++)
	{
		block[i]->Render();
	}
}

void Scene01::ResizeScreen()
{

}

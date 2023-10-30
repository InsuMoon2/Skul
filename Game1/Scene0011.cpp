#include "stdafx.h"

void Scene0011::Init()
{
	pl = new Player();
	pl->player_Col->SetWorldPos(Vector2(-1620.0f, -960.0f));
	pl->player_Col->visible = false;

	background = new ObImage(L"Tutorial_Background.png");
	background->scale = Vector2(1600.0f, 1000.0f * 1.5f) * 1.3f;
	background->SetWorldPos(Vector2(0.0f, 400.0f));
	background->space = SPACE::SCREEN;

	tutorial_Bg = new ObImage(L"Tutorial.png");
	tutorial_Bg->scale = Vector2(1600.0f, 1000.0f) * 2.4f;

	ground = new ObRect();
	ground->scale = Vector2(3300.0f, 20.0f);
	ground->SetWorldPos(Vector2(-1930.0f, -960.0f));
	ground->pivot = OFFSET_LT;
	ground->isFilled = false;
	ground->visible = false;
	ground->collider = COLLIDER::RECT;

	for (int i = 0; i < 3; i++)
	{
		jump_ground[i] = new ObRect();
		jump_ground[i]->scale = Vector2(300.0f, 20.0f);
		jump_ground[i]->pivot = OFFSET_LT;
		jump_ground[i]->isFilled = false;
		jump_ground[i]->visible = false;
		jump_ground[i]->collider = COLLIDER::RECT;
		jump_ground[i]->color = Color(0.0f, 0.5f, 0.5f, 1.0f);
	}

	jump_ground[0]->SetWorldPos(Vector2(-547.0f, -840.0f));
	jump_ground[1]->SetWorldPos(Vector2(-363.0f, -617.0f));
	jump_ground[2]->SetWorldPos(Vector2(620.0f, -445.0f));
	jump_ground[2]->scale = Vector2(680.0f, 20.0f);

	for (int i = 0; i < 2; i++)
	{
		LR_ground[i] = new ObRect();
		LR_ground[i]->scale = Vector2(600.0f, 520.0f);
		LR_ground[i]->pivot = OFFSET_LT;
		LR_ground[i]->isFilled = false;
		LR_ground[i]->visible = false;
		LR_ground[i]->collider = COLLIDER::RECT;
		LR_ground[i]->color = Color(0.5f, 0.5f, 0.0f, 1.0f);
	}

	LR_ground[0]->SetWorldPos(Vector2(0.0f, -445.0f));
	LR_ground[1]->SetWorldPos(Vector2(1314, -445.0f));

	gate_Normal = new ObImage(L"gate_normal.png");
	gate_Normal->scale = Vector2(1536.0f / 8.0f, 192.0f) * 2.4f;
	gate_Normal->maxFrame = Int2(8, 1);
	gate_Normal->SetWorldPos(Vector2(930.0f, -810.0f));
	gate_Normal->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	gate_Rect = new ObRect();
	gate_Rect->scale = Vector2(1536.0f / 8.0f, 192.0f) * 2.4f;
	gate_Rect->SetWorldPos(Vector2(940.0f, -810.0f));
	gate_Rect->isFilled = false;
	gate_Rect->visible = false;
	gate_Rect->collider = COLLIDER::RECT;
	
	input = new ObImage(L"Input.png");
	input->scale = Vector2(452.0f, 92.0f * 0.5f);
	input->SetParentRT(*gate_Normal);
	input->SetLocalPos(Vector2(0.0f, -180.0f));
	input->visible = false;

	//���̷���
	tong_Col = new ObRect();
	tong_Col->scale = Vector2(114.0f , 41.0f) * 2.5f;
	tong_Col->SetWorldPos(Vector2(-1250.0f, -910.0f));
	tong_Col->isFilled = false;
	tong_Col->visible = false;
	tong_Col->collider = COLLIDER::RECT;

	tong_Idle = new ObImage(L"tongIdle.png");
	tong_Idle->scale = Vector2(114.0f, 41.0f) * 2.5f;
	tong_Idle->SetParentRT(*tong_Col);
	tong_Idle->visible = false;

	tong_Move = new ObImage(L"tongMove.png");
	tong_Move->scale = Vector2(1664.0f / 13.0f, 41.0f) * 2.5f;
	tong_Move->SetParentRT(*tong_Col);
	tong_Move->maxFrame = Int2(13,1);
	tong_Move->ChangeAnim(ANIMSTATE::LOOP, 0.25f);
	tong_Move->visible = true;

	//���� �ִ¾�
	give_WeaponCol = new ObRect();
	give_WeaponCol->scale = Vector2(2124.0f / 18.0f, 54.0f) * 2.5f;
	give_WeaponCol->SetWorldPos(Vector2(138.0f, -410.0f));
	give_WeaponCol->isFilled = false;
	give_WeaponCol->visible = false;
	give_WeaponCol->collider = COLLIDER::RECT;

	give_Weapon = new ObImage(L"give_Weapon.bmp");
	give_Weapon->scale = Vector2(2124.0f / 18.0f, 54.0f) * 1.3f;
	give_Weapon->SetParentRT(*give_WeaponCol);
	give_Weapon->maxFrame = Int2(18,1);
	give_Weapon->visible = true;

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

	left = new ObImage(L"LeftArrow.png");
	left->scale = Vector2(15.0f, 14.0f);
	left->SetWorldPos(Vector2(475.0f, -450.0f));
	left->visible = false;
	left->space = SPACE::SCREEN;

	right = new ObImage(L"RightArrow.png");
	right->scale = Vector2(15.0f, 14.0f);
	right->SetWorldPos(Vector2(475.0f, -450.0f));
	right->visible = false;
	right->space = SPACE::SCREEN;

	down = new ObImage(L"Witch_NextLevel.png");
	down->scale = Vector2(15.0f, 14.0f);
	down->SetWorldPos(Vector2(475.0f, -450.0f));
	down->visible = false;
	down->space = SPACE::SCREEN;

	z = new ObImage(L"Z.png");
	z->scale = Vector2(15.0f, 14.0f) * 2.5f;
	z->SetWorldPos(Vector2(475.0f, -450.0f));
	z->visible = false;
	z->space = SPACE::SCREEN;

	x = new ObImage(L"X.png");
	x->scale = Vector2(15.0f, 14.0f);
	x->SetWorldPos(Vector2(475.0f, -450.0f));
	x->visible = false;
	x->space = SPACE::SCREEN;

	c = new ObImage(L"C.png");
	c->scale = Vector2(15.0f, 14.0f);
	c->SetWorldPos(Vector2(475.0f, -450.0f));
	c->visible = false;
	c->space = SPACE::SCREEN;

	give_Rect = new ObRect();
	give_Rect->scale = Vector2(200.0f, 200.0f);
	give_Rect->SetWorldPos(Vector2(-550.0f, -900.0f));
	give_Rect->visible = false;
	give_Rect->isFilled = false;
	give_Rect->collider = COLLIDER::RECT;

	pl->playerUi->UiInVisible();
	
	SOUND->AddSound("Tutorial.wav", "Tutorial", false);
	//SOUND->Play("Tutorial");
	SOUND->AddSound("Skul_Reborn_Rise.wav", "GetWeapon", false);

	fadeOut = true;
	fadeIn = 1.0f;

	LIGHT->light.radius = 2000.0f;
	LIGHT->light.lightColor = Color(0.0f, 0.0f, 0.0f, 0.5f);

	CAM->position.x = -1800.0f;
	CAM->position.y = -600.0f;
}

void Scene0011::Release()
{
	SafeDelete(tutorial_Bg);
	SafeDelete(background);
	SafeDelete(ground);
	SafeDelete(gate_Normal);
	SafeDelete(gate_Rect);
	SafeDelete(input);

	for (int i = 0; i < 3; i++)
	{
		SafeDelete(jump_ground[i]);
	}

	for (int i = 0; i < 2; i++)
	{
		SafeDelete(LR_ground[i]);
	}
	
	SafeDelete(tong_Col);
	SafeDelete(tong_Idle);
	SafeDelete(tong_Move);
	SafeDelete(give_WeaponCol);
	SafeDelete(give_Weapon);
	SafeDelete(text);
	SafeDelete(next);

	SafeDelete(left);
	SafeDelete(right);
	SafeDelete(down);
	SafeDelete(z);
	SafeDelete(x);
	SafeDelete(c);
}

void Scene0011::Update()
{
	//cout << pl->player_Col->GetWorldPos().x << endl;

	//cout << INPUT->GetMouseWorldPos().x << endl;
	//cout << INPUT->GetMouseWorldPos().y << endl;

	if (text->visible)
	{
		next->visible = true;
		text_Time += DELTA;

		if (INPUT->KeyDown('F'))
		{
			number++;
			text_Time = 0.0f;
		}

		if (number <= 30)
		{
			if (text_Time <= 0.4f)
			{
				SOUND->Play("Talk");
			}
		}
	}

	if (fadeOut)
	{
		if (LIGHT->light.lightColor.x <= 0.5f)
		{
			LIGHT->light.lightColor.x += 0.5 * DELTA;
			LIGHT->light.lightColor.y += 0.5 * DELTA;
			LIGHT->light.lightColor.z += 0.5 * DELTA;
		}

		pl->playerUi->UiInVisible();
	}

	//Weapon
	pl->getWeapon = true;

	//���� ���°� ����, ���� �ִ� �̹��� ���
	if (pl->born_GetWeapon->frame.x >= 9)
	{
		pl->getWeapon = false;
		pl->born_Idle->visible = true;
		pl->born_GetWeapon->visible = false;
		pl->born_IDLE_NW->visible = false;
	}

	//cout << pl->downjump_Time << endl;

	 //�Ʒ����� ��
	for (int i = 0; i < 3; i++)
	{
		if (jump_ground[i]->Intersect(pl->player_Bottom))
		{
			if (INPUT->KeyPress(VK_DOWN) && INPUT->KeyDown('C'))
			{
				pl->downjump_Checking = true;
			}	
		}
	}
	
	pl->Update();
	background->Update();
	tutorial_Bg->Update();
	ground->Update();

	gate_Normal->Update();
	gate_Rect->Update();
	input->Update();
	give_WeaponCol->Update();

	for (int i = 0; i < 3; i++)
	{
		jump_ground[i]->Update();
	}

	for (int i = 0; i < 2; i++)
	{
		LR_ground[i]->Update();
	}

	tong_Col->Update();
	tong_Idle->Update();
	tong_Move->Update();
	give_Weapon->Update();
	text->Update();
	next->Update();

	left->Update();
	right->Update();
	down->Update();
	z->Update();
	x->Update();
	c->Update();
	give_Rect->Update();

	Vector2 dis = Vector2(pl->player_Col->GetWorldPos().x, pl->player_Col->GetWorldPos().y + 250.0f) - CAM->position;
	CAM->position += dis * DELTA * 1.6f;

	CAM->position.x = Utility::Saturate(CAM->position.x, -1900.0f + app.GetHalfWidth(), 1570.0f - app.GetHalfWidth());
	CAM->position.y = Utility::Saturate(CAM->position.y, -700.0f, 200.0f - app.GetHalfHeight());

}

void Scene0011::LateUpdate()
{
	//�÷��̾�
	pl->player_Col->SetWorldPosX(Utility::Saturate(pl->player_Col->GetWorldPos().x, -1850.0f, 1285.0f));
	
	//��-�̷���
	if (give_Rect->Intersect(pl->player_Col))
	{
		give = true;
	}

	else
	{
		give = false;
	}

	if (give_WeaponCol->Intersect(pl->player_Col))
	{
		give2 = true;
	}
	
	//ķ
	if(give)
	{
		if (number >= 13 && number < 17)
		{
			Vector2 dis = give_WeaponCol->GetWorldPos() - CAM->position;
			CAM->position += dis * DELTA;
		}

		else if (number == 17)
		{
			Vector2 dis = CAM->position - Vector2(pl->player_Col->GetWorldPos().x, pl->player_Col->GetWorldPos().y + 250.0f);
			CAM->position -= dis * DELTA;
		}
		
	}

	//�ؽ�Ʈ ����
	if (tong_Move->frame.x >= 12.0f)
	{
		textCheck = true;
	}

	if (textCheck)
	{
		text->visible = true;
		next->visible = true;
	}

	else
	{
		text->visible = false;
		next->visible = false;
	}

	if (!give2)
	{
		if (number == 17)
		{
			textCheck = false;
			text->visible = false;
			next->visible = false;
		}
	}

	//�����ִ� ������ �浹�ϸ�,
	else if(give2)
	{
		if (LR_ground[0]->Intersect(pl->player_Col))
		{
			textCheck = true;
		}
	}

	cout << pl->playerUi->sceneBlack_Top->GetWorldPos().y << endl;

	if (number == 12)
	{
		if (!give)
		{
			text->visible = false;
			next->visible = false;
			//pl->playerUi->UiBlack();

			if (pl->playerUi->sceneBlack_Top->GetWorldPos().y <= 700.0f)
			{
				pl->playerUi->sceneBlack_Top->MoveWorldPos(100.0f * UP * DELTA);
				pl->playerUi->sceneBlack_Bottom->MoveWorldPos(100.0f * DOWN * DELTA);
			}
		}

		//��-�̷���
		if (give)
		{
			text->visible = true;
			next->visible = true;
			pl->HpChecking = false;

			if (pl->playerUi->sceneBlack_Top->GetWorldPos().y >= 550.0f)
			{
				pl->playerUi->sceneBlack_Top->MoveWorldPos(100.0f * DOWN * DELTA);
				pl->playerUi->sceneBlack_Bottom->MoveWorldPos(100.0f * UP * DELTA);
			}
		}
	}

	//���̷��� ��ȭ1 ���� ��
	if (number == 17)
	{
		if (!give2)
		{
			if (pl->playerUi->sceneBlack_Top->GetWorldPos().y <= 700.0f)
			{
				pl->playerUi->sceneBlack_Top->MoveWorldPos(100.0f * UP * DELTA);
				pl->playerUi->sceneBlack_Bottom->MoveWorldPos(100.0f * DOWN * DELTA);
			}
		}

		else if (give2)
		{
			pl->HpChecking = false;

			if (pl->playerUi->sceneBlack_Top->GetWorldPos().y >= 550.0f)
			{
				pl->playerUi->sceneBlack_Top->MoveWorldPos(100.0f * DOWN * DELTA);
				pl->playerUi->sceneBlack_Bottom->MoveWorldPos(100.0f * UP * DELTA);
			}
		}
	}

	//���̷��� ��ȭ2 ��
	if (number >= 26)
	{
		textCheck = false;
		text->visible = false;
		next->visible = false;

		if (pl->playerUi->sceneBlack_Top->GetWorldPos().y <= 700.0f)
		{
			pl->playerUi->sceneBlack_Top->MoveWorldPos(100.0f * UP * DELTA);
			pl->playerUi->sceneBlack_Bottom->MoveWorldPos(100.0f * DOWN * DELTA);
		}
	}

	//SceneBlackTop�� 630�̻� �ö󰡸� HpUi Checking
	if (pl->playerUi->sceneBlack_Top->GetWorldPos().y >= 630.0f)
	{
		pl->HpChecking = true;
		pl->playerUi->StartUi();
	}

	else
	{
		pl->playerUi->UiInVisible();
	}


	//�浹
	if (pl->GetGravity() > 0.0f)
	{
		if (ground->Intersect(pl->player_Bottom))
		{
			pl->player_Col->SetWorldPosY(ground->GetLocalPos().y - 1.0f);
			pl->GetGravity() = 0.0f;
			pl->GetDashCount() = 2;
			pl->jumpground_Check = false;

			if (pl->player_State == PLAYERSTATE::JUMP ||
				pl->player_State == PLAYERSTATE::JUMPATTACK ||
				pl->player_State == PLAYERSTATE::DOWNJUMP)
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

		for (int i = 0; i < 3; i++)
		{
			if (jump_ground[i]->Intersect(pl->player_Bottom))
			{
				pl->player_Col->SetWorldPosY(jump_ground[i]->GetLocalPos().y - 1.0f);
				pl->GetGravity() = 0.0f;
				pl->GetDashCount() = 2;

				if (pl->player_State == PLAYERSTATE::JUMP ||
					pl->player_State == PLAYERSTATE::JUMPATTACK ||
					pl->player_State == PLAYERSTATE::DOWNJUMP)
				{
					pl->player_State = PLAYERSTATE::IDLE;
					pl->born_Jump->frame.x = 0;
					pl->jump = false;
					//pl->downjump_Checking = false;

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
			if (LR_ground[i]->Intersect(pl->player_Bottom))
			{
				if (pl->player_State != PLAYERSTATE::DASH)
				{
					pl->player_Col->SetWorldPosY(LR_ground[i]->GetLocalPos().y - 1.0f);
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
		
	}

	for (int i = 0; i < 2; i++)
	{
		//�� �� �浹
		if (LR_ground[i]->Intersect(pl->GetRPos()))
		{
			//cout << "11";
			pl->player_Col->SetWorldPosX(LR_ground[i]->GetLocalPos().x - 32.5f);
			//pl->StepBack();
		}

		if (LR_ground[i]->Intersect(pl->GetLPos()))
		{
			//cout << "22";
			pl->player_Col->SetWorldPosX(LR_ground[i]->GetLocalPos().x + LR_ground[i]->scale.x + 32.5f);
			//pl->StepBack();
		}
	}

	//���� �ޱ�
	if (give_WeaponCol->Intersect(pl->player_Col) && pl->getWeapon)
	{
		if (number == 23)
		{
			give_Weapon->ChangeAnim(ANIMSTATE::ONCE, 0.1f);

			SOUND->Play("GetWeapon");
			pl->getWeapon = false;
			pl->born_GetWeapon->visible = true;
		}
	}

	//���̷��� ���� �����̱�
	if (tong_Move->frame.x >= 12.0f)
	{
		tong_Move->visible = false;
		tong_Idle->visible = true;
	}

	if (tong_Move->visible)
	{
		tong_Col->MoveWorldPos(LEFT * 20.0f * DELTA);
	}

	else
	{
		tong_Col->MoveWorldPos(RIGHT * 0.0f * DELTA);
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
			cout << "Scene0044 Change zz" << endl;
			SCENE->ChangeScene("Ʃ�丮��2");
		}
	}

	//cout << number << endl;
}

void Scene0011::Render()
{
	if (text->visible)
	{
		if (number <= 11)
		{
			DWRITE->RenderText(L"���̷�-��", RECT{ 400, 800,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				24.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
		}

		else if (number >= 12)
		{
			DWRITE->RenderText(L"��-�̷���", RECT{ 400, 800,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				24.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
		}
		
		switch (number)
		{
		case 0:
			DWRITE->RenderText(L"��!! �����̴�. ���� ����־�����..", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 1:
			DWRITE->RenderText(L"��¦ ��� ������ �Ҿ�������, �ٺ�������!", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 2:
			DWRITE->RenderText(L"��������! ���Ⱑ ����� �� �� ����?", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 3:
			DWRITE->RenderText(L"��, �ϴ� ���� �ȹٷ� ������ ���!", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 4:
			DWRITE->RenderText(L"�ΰ� ����� ������ ���۵Ǿ���!", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 5:
			DWRITE->RenderText(L"���� �ٸ� ���̷������ �༮��� �ο�� ������,", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 6:
			DWRITE->RenderText(L"���� �ٸ� ���̷������ �༮��� �ο�� ������, � ->�� ������ �ΰ����� �Ѿư�.", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 7:
			DWRITE->RenderText(L"�� ������ ���� ����,", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 8:
			DWRITE->RenderText(L"�� ������ ���� ����, �ٸ� ������ ��𼱰� �ϳ� �����ͼ� ���̸� �Ǵϱ�.", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 9:
			DWRITE->RenderText(L"� ��!", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 10:
			DWRITE->RenderText(L"� ��! z�� ������ �� ���� ������ �� ������! �ð��� ����!", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 11:
			DWRITE->RenderText(L"� ��! z�� ������ �� ���� ������ �� ������! �ð��� ����!", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			DWRITE->RenderText(L"�༮���� ������ ȸ���� �� �ִ� ������ε� ���Ǵ� ���� ��!", RECT{ 400, 900,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 12:
			DWRITE->RenderText(L"��!! ��, �� ��Ʋ��!", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 13:
			DWRITE->RenderText(L"��, ��, �����...!", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 14:
			DWRITE->RenderText(L"��, ��, �ʴ� �����߱���..! ��, �� , ���� ��  �̻� ������ ���� ��, �� , ����!", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 15:
			DWRITE->RenderText(L"c�� ���� ������ �� �־�. �� �� ������ 2�� ������ ������.", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 16:
			DWRITE->RenderText(L"��� c�� ���� ������ �Ʒ��� ������ ������.", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);

			DWRITE->RenderText(L"��, ��, � �̸� �ö��...!", RECT{ 400, 900,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 17:
			DWRITE->RenderText(L"ũ, ũ, ū���̾�! ���մ԰� �ǿ��Ե��� ��, ��, �ΰ� ��鿡�� ������ ���Ⱦ�..!", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 18:
			DWRITE->RenderText(L"��, ��, �ΰ� ���... ���ռ� ������ ��, �� , ���ƿ� ����ؿ� ���̾�...", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 19:
			DWRITE->RenderText(L"��, ��, ���� �ٸ� ���̷������ �༮���� ��, ��, �Ѱ� �־�...!", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 20:
			DWRITE->RenderText(L"��, ��, ���� �� ������ ���� �� ����... ", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 21:
			DWRITE->RenderText(L"��, ��, ���� �� ������ ���� �� ����...", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);

			DWRITE->RenderText(L"��, ��, �װ� ��� ���մԵ�� �ǿ��Ե��� ��, �� , ������...!", RECT{ 400, 900,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 22:
			DWRITE->RenderText(L"��, ��, �̰� �޾�..!", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 23:
			DWRITE->RenderText(L"��, ��, �̰� �޾�..! ��, ��, �ٸ�����..! x�� ���� ������ �� �־�.", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 24:
			DWRITE->RenderText(L"��, ��, ������ ���� �ð��̾� ������.", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;

		case 25:
			DWRITE->RenderText(L"�� ��, ��, ���մ԰� ��, ��, �ǿ��Ե��� ������..!", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
				23.0f, L"���� ���", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
			break;
		}
	}

	background->Render();
	tutorial_Bg->Render();
	ground->Render();

	gate_Normal->Render();
	gate_Rect->Render();
	input->Render();

	tong_Col->Render();
	tong_Idle->Render();
	tong_Move->Render();
	give_WeaponCol->Render();
	give_Weapon->Render();

	for (int i = 0; i < 3; i++)
	{
		jump_ground[i]->Render();
	}

	for (int i = 0; i < 2; i++)
	{
		LR_ground[i]->Render();
	}

	left->Render();
	right->Render();
	down->Render();
	z->Render();
	x->Render();
	c->Render();

	pl->Render();
	text->Render();
	next->Render();

	give_Rect->Render();
}

void Scene0011::ResizeScreen()
{

}

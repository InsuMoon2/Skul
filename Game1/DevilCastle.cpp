#include "stdafx.h"

DevilCastle::DevilCastle()
{
	devil_Castle = new ObImage(L"Castle.png");
	devil_Castle->scale = Vector2(3840.0f * 1.5f, 4480.0f * 1.3f);
	devil_Castle->SetWorldPos(Vector2(0.0f , -1900.0f));
	
	witch = new ObImage(L"witch.bmp");
	witch->scale = Vector2(6000.0f / 30.0f, 150.0f) * 2.5f;
	witch->maxFrame.x = 30;
	witch->SetWorldPos(Vector2(-650.0f, 200.0f));
	witch->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	witch->pivot = OFFSET_B;

	fox = new ObImage(L"Fox.bmp");
	fox->scale = Vector2(2400.0f / 8.0f, 200.0f) * 2.5f;
	fox->maxFrame.x = 8;
	fox->SetWorldPos(Vector2(-150.0f, 100.0f));
	fox->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	fox->pivot = OFFSET_B;

	ogre = new ObImage(L"StoreMaster.bmp");
	ogre->scale = Vector2(1816.0f / 8.0f, 151.0f) * 2.2f;
	ogre->maxFrame.x = 8;
	ogre->SetWorldPos(Vector2(450.0f, 250.0f));
	ogre->ChangeAnim(ANIMSTATE::LOOP, 0.15f);
	ogre->pivot = OFFSET_B;

	a = 4;
}

DevilCastle::~DevilCastle()
{
	SafeDelete(devil_Castle);
	SafeDelete(witch);
	SafeDelete(fox);
	SafeDelete(ogre);

}

void DevilCastle::Update()
{
	devil_Castle->Update();
	witch->Update();
	fox->Update();
	ogre->Update();
}

void DevilCastle::Render()
{
	devil_Castle->Render();
	witch->Render();
	fox->Render();
	ogre->Render();
}

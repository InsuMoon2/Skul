#include "stdafx.h"

void Scene00::Init()
{
	main1 = new ObImage(L"Title_Art.png");
	main1->scale = Vector2(1600.0f, 1000.0f);

	main2 = new ObImage(L"Title_Logo.png");
	main2->scale = Vector2(1600.0f, 250.0f);

	main3 = new ObImage(L"startscene_text.png");
	main3->scale = Vector2(550.0f, 60.0f);
	main3->SetWorldPos(Vector2(0.0f, -180.0f));

	SOUND->AddSound("Title.mp3", "타이틀", false);
	SOUND->Play("타이틀");
}

void Scene00::Release()
{
	SafeDelete(main1);
	SafeDelete(main2);
	SafeDelete(main3);
}

void Scene00::Update()
{
	anykey_time += DELTA;

	//cout << anykey_time << endl;

	if (anykey_time <= 1.0f)
	{
		main3->color.w -= 0.006f;
	}

	else if (anykey_time > 1.0f)
	{
		if (main3->color.w < 0.5f)
		{
			main3->color.w += 0.006f;
		}

		else if (main3->color.w >= 0.48f)
		{
			anykey_time = 0.0f;
		}
	}
	
	main1->Update();
	main2->Update();
	main3->Update();

}

void Scene00::LateUpdate()
{
	if (INPUT->KeyDown(VK_SPACE))
	{
		SCENE->ChangeScene("검은화면");
		SOUND->Stop("타이틀");
	}
}

void Scene00::Render()
{
	main1->Render();
	main2->Render();
	main3->Render();
}

void Scene00::ResizeScreen()
{

}

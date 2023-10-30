#include "stdafx.h"
#include "Main.h"

void Main::Init()
{
	cursor = new ObImage(L"skul_cursor.png");
	cursor->scale = Vector2(35.0f, 35.0f);
	cursor->visible = true;

	//Start
	{
		Scene00* temp = new Scene00();
		SCENE->AddScene("시작", temp);
	}

	//Start
	{
		Scene0000* temp = new Scene0000();
		SCENE->AddScene("검은화면", temp);
	}

	//튜토리얼
	{
		Scene0011* temp = new Scene0011();
		SCENE->AddScene("튜토리얼", temp);
	}

	{
		Scene0022* temp = new Scene0022();
		SCENE->AddScene("튜토리얼2", temp);
	}

	{
		Scene0033* temp = new Scene0033();
		SCENE->AddScene("튜토리얼3", temp);
	}

	{
		Scene0044* temp = new Scene0044();
		SCENE->AddScene("튜토리얼4", temp);
	}

	{
		Scene0055* temp = new Scene0055();
		SCENE->AddScene("마왕성1", temp);
	}

	//마왕성
	{
		Scene01* temp = new Scene01();
		SCENE->AddScene("마왕성", temp);
	}
	//던전 입구
	{
		Scene02* temp = new Scene02();
		SCENE->AddScene("던전 입구", temp);
	}
	//잡몹1
	{
		Scene03* temp = new Scene03();
		SCENE->AddScene("몬스터", temp);
	}
	//보스방
	{
		Scene04* temp = new Scene04();
		SCENE->AddScene("보스", temp);
	}
	//엔딩
	{	
		Scene05* temp = new Scene05();
		SCENE->AddScene("엔딩", temp);
	}

	SOUND->AddSound("UI_Talk.wav", "Talk", false);

	SCENE->ChangeScene("마왕성1");

	

}

void Main::Release()
{
	
}

void Main::Update()
{
	SCENE->Update();
	ShowCursor(false);

	cursor->SetWorldPos(INPUT->GetMouseWorldPos());

	cursor->Update();
}

void Main::LateUpdate()
{
	SCENE->LateUpdate();

}

void Main::Render()
{
	SCENE->Render();


	cursor->Render();
	
}

void Main::ResizeScreen()
{
	
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
    app.SetAppName(L"Game1");
    app.SetInstance(instance);
	app.InitWidthHeight(1600,1000.0f);
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	WIN->DeleteSingleton();
	SafeDelete(main);
	return wParam;
}
#include "stdafx.h"

void Scene0000::Init()
{
	black = new ObImage(L"black.bmp");
	black->scale = Vector2(1600.0f, 1000.0f);
	black->visible = true;
	black->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
	black->space = SPACE::SCREEN;

	//Text
	text = new ObImage(L"Text.png");
	text->scale = Vector2(960.0f, 184.0f) * 1.0f;
	text->SetWorldPos(Vector2(30.0f, -380.0f));
	text->visible = true;
	text->space = SPACE::SCREEN;

	//Next
	next = new ObImage(L"Witch_NextLevel.png");
	next->scale = Vector2(3.0f, 5.0f) * 2.5f;
	next->SetWorldPos(Vector2(475.0f, -450.0f));
	next->visible = true;
	next->space = SPACE::SCREEN;

	fadeOut = false;
	fadeIn = 1.0f;

	//LIGHT->light.radius = 2000.0f;
	//LIGHT->light.lightColor = Color(0.5f, 0.5f, 0.5f, 0.5f);
}

void Scene0000::Release()
{
	SafeDelete(black);
	SafeDelete(text);
	SafeDelete(next);
}

void Scene0000::Update()
{
	text_Time += DELTA;

	if (INPUT->KeyDown('F'))
	{
		number++;
		text_Time = 0.0f;
	}

	if (number <= 5)
	{
		if (text_Time <= 0.4f)
		{
			SOUND->Play("Talk");
		}
	}
	

	black->Update();
	text->Update();
	next->Update();
}

void Scene0000::LateUpdate()
{
	//cout << text_Time << endl;

	if (number == 6)
	{
		SCENE->ChangeScene("Æ©Åä¸®¾ó");
	}
}

void Scene0000::Render()
{
	DWRITE->RenderText(L"???", RECT{ 440, 797,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
		25.0f, L"¸¼Àº °íµñ", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);

	switch (number)
	{
	case 0:
		DWRITE->RenderText(L"Á¤½ÅÂ÷·Á!", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
			23.0f, L"¸¼Àº °íµñ", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
		break;

	case 1:
		DWRITE->RenderText(L"Á¤½ÅÂ÷·Á! ¾²·¯Áö¸é ¾ÈµÅ!", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
			23.0f, L"¸¼Àº °íµñ", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
		break;

	case 2:
		DWRITE->RenderText(L"¾ß! ¸®Æ²º»!!", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
			23.0f, L"¸¼Àº °íµñ", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
		break;

	case 3:
		DWRITE->RenderText(L"...", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
			23.0f, L"¸¼Àº °íµñ", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
		break;

	case 4:
		DWRITE->RenderText(L"ÀÌ³ðµµ Á×¾î¹ö¸°°Ç°¡..", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
			23.0f, L"¸¼Àº °íµñ", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
		break;

	case 5:
		DWRITE->RenderText(L"ÀÌ³ðµµ Á×¾î¹ö¸°°Ç°¡.. ÀÌ ³à¼® Á×¾úÀ¸¸é ¾ÈµÇ´Â°Çµ¥..", RECT{ 400, 860,(long)app.GetWidth(),(long)app.GetHalfHeight() + (long)600.0f },
			23.0f, L"¸¼Àº °íµñ", Color(1, 1, 1, 1), DWRITE_FONT_WEIGHT_SEMI_BOLD);
		break;
	}

	
	black->Render();
	text->Render();
	next->Render();
}

void Scene0000::ResizeScreen()
{

}

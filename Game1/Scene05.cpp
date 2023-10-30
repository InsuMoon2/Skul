#include "stdafx.h"

void Scene05::Init()
{
	Ending = new ObImage(L"Ending2.png");
	Ending->scale = Vector2(1600.0f, 1000.0f);

	SOUND->AddSound("SkulStory7_Ending_Epilogue.wav", "Ending", false);
}

void Scene05::Release()
{
	SafeDelete(Ending);
}

void Scene05::Update()
{
	CAM->position = Vector2(0.0f, 0.0f);

	SOUND->Stop("Boss");
	SOUND->Play("Ending");

	Ending->Update();

}

void Scene05::LateUpdate()
{


}

void Scene05::Render()
{
	Ending->Render();
}

void Scene05::ResizeScreen()
{

}

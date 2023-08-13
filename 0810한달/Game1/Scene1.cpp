#include "stdafx.h"
#include "Scene2.h"
#include "SceneChoice.h"
#include "Scene1.h"

Scene1::Scene1()
{
	playButton = new ObRect();
	settingButton = new ObRect();
	quitButton = new ObRect();
	
	play = new ObImage(L"play.png");
	setting = new ObImage(L"setting.png");
	quit = new ObImage(L"quit.png");
	playClickEffect = new ObImage(L"clickEffect.png");
	settingClickEffect = new ObImage(L"clickEffect.png");
	quitClickEffect = new ObImage(L"clickEffect.png");
	bg = new ObImage(L"backGround.bmp");
	
	playButton->isFilled = false;
	settingButton->isFilled = false;
	quitButton->isFilled = false;

	play->scale.x = play->imageSize.x * 3;
	play->scale.y = play->imageSize.y * 3;
	setting->scale.x = setting->imageSize.x * 3;
	setting->scale.y = setting->imageSize.y * 3;
	quit->scale.x = quit->imageSize.x * 2.5;
	quit->scale.y = quit->imageSize.y * 2.5;
	bg->scale.x = 1000;
	bg->scale.y = 600;

	playButton->scale.x = play->imageSize.x * 4;
	playButton->scale.y = play->imageSize.y * 4;
	settingButton->scale.x = setting->imageSize.x * 4;
	settingButton->scale.y = setting->imageSize.y * 4;
	quitButton->scale.x = quit->imageSize.x * 4;
	quitButton->scale.y = quit->imageSize.y * 4;


	playClickEffect->scale.x = playClickEffect->imageSize.x * 3;
	playClickEffect->scale.y = playClickEffect->imageSize.y * 3;
	settingClickEffect->scale.x = settingClickEffect->imageSize.x * 3;
	settingClickEffect->scale.y = settingClickEffect->imageSize.y * 3;
	quitClickEffect->scale.x = quitClickEffect->imageSize.x * 3;
	quitClickEffect->scale.y = quitClickEffect->imageSize.y * 3;

	play->imageSize.x = play->imageSize.x * 3;
	play->imageSize.y = play->imageSize.y * 3;
	setting->imageSize.x = setting->imageSize.x * 3;
	setting->imageSize.y = setting->imageSize.y * 3;
	quit->imageSize.x = quit->imageSize.x * 2.5;
	quit->imageSize.y = quit->imageSize.y * 2.5;

	playClickEffect->imageSize.x = playClickEffect->imageSize.x * 3;
	playClickEffect->imageSize.y = playClickEffect->imageSize.y * 3;
	settingClickEffect->imageSize.x = settingClickEffect->imageSize.x * 3;
	settingClickEffect->imageSize.y = settingClickEffect->imageSize.y * 3;
	quitClickEffect->imageSize.x = quitClickEffect->imageSize.x * 3;
	quitClickEffect->imageSize.y = quitClickEffect->imageSize.y * 3;

	

	play->SetParentT(*playButton);
	setting->SetParentT(*settingButton);
	quit->SetParentT(*quitButton);
	
	playClickEffect->SetParentT(*playButton);
	settingClickEffect->SetParentT(*settingButton);
	quitClickEffect->SetParentT(*quitButton);

	

}

Scene1::~Scene1()
{
}

void Scene1::Init()
{
	playButton->SetWorldPosX(0);
	playButton->SetWorldPosY(150);
	settingButton->SetWorldPosX(0);
	settingButton->SetWorldPosY(0);
	quitButton->SetWorldPosX(0);
	quitButton->SetWorldPosY(-150);
	playClickEffect->SetLocalPosX(25);
	playClickEffect->SetLocalPosY(20);
	settingClickEffect->SetLocalPosX(25);
	settingClickEffect->SetLocalPosY(20);
	quitClickEffect->SetLocalPosX(25);
	quitClickEffect->SetLocalPosY(20);
	
	

}

void Scene1::Release()
{
}

void Scene1::Update()
{
	bg->Update();
	play->Update();
	setting->Update();
	quit->Update();
	playButton->Update();
	settingButton->Update();
	quitButton->Update();
	playClickEffect->Update();
	settingClickEffect->Update();
	quitClickEffect->Update();
}

void Scene1::LateUpdate()
{
	if (playButton->Intersect(INPUT->GetWorldMousePos())) 
	{
		isPlayClick = true;
		
		play->scale.y = play->imageSize.y  + 10;

		if (INPUT->KeyDown(VK_LBUTTON))
		{
			//SCENE->ChangeScene("scene2",1.0f);
			SCENE->ChangeScene("SCC", 0.0f);
		}
	}
	else if (settingButton->Intersect(INPUT->GetWorldMousePos()))
	{
		isSettingClick = true;
		
		setting->scale.y = setting->imageSize.y + 10;
		
		if (INPUT->KeyDown(VK_LBUTTON))
		{
			
		}
	}
	else if (quitButton->Intersect(INPUT->GetWorldMousePos()))
	{
		isQuitClick = true;
		
		quit->scale.y = quit->imageSize.y + 10;

		if (INPUT->KeyDown(VK_LBUTTON))
		{
			
		}
	}
	else
	{
		isPlayClick = false;
		isSettingClick = false;
		isQuitClick = false;
		play->scale.x = play->imageSize.x; 
		play->scale.y = play->imageSize.y; 
		setting->scale.x = setting->imageSize.x; 
		setting->scale.y = setting->imageSize.y; 
		quit->scale.x = quit->imageSize.x; 
		quit->scale.y = quit->imageSize.y; 

		
	}
	
	
}

void Scene1::Render()
{
	bg->Render();
	
	if(isPlayClick)
	playClickEffect->Render();
	
	if (isSettingClick)
	settingClickEffect->Render();
	
	if (isQuitClick)
	quitClickEffect->Render();

	play->Render();
	setting->Render();
	quit->Render();
	//playButton->Render();
	//settingButton->Render();
	//quitButton->Render();
	
}

void Scene1::ResizeScreen()
{
}

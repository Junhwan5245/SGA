#include"stdafx.h"
#include"player.h"
#include "UI.h"

UI::UI()
{
	playerLevelUIin = new ObImage(L"LevelUIIn.png");
	playerLevelUIOut = new ObImage(L"LevelUIOut.png");
	playerLevelUImiddle = new ObImage(L"LevelUIOut3.png");
	playerHpUIin = new ObImage(L"HPInsideUI.png");
	playerHpUIOut = new ObImage(L"HPUI.png");

	playerLevelUIin->scale.x = playerLevelUIin->imageSize.x / 2;
	playerLevelUIin->scale.y = playerLevelUIin->imageSize.y / 2;
	playerLevelUImiddle->scale.x = playerLevelUImiddle->imageSize.x / 2;
	playerLevelUImiddle->scale.y = playerLevelUImiddle->imageSize.y / 2;
	playerLevelUIOut->scale.x = playerLevelUIOut->imageSize.x / 2;
	playerLevelUIOut->scale.y = playerLevelUIOut->imageSize.y / 2;
	playerHpUIin->scale.x = playerHpUIin->imageSize.x / 1.8;
	playerHpUIin->scale.y = playerHpUIin->imageSize.y / 2;
	playerHpUIOut->scale.x = playerHpUIOut->imageSize.x / 1.8;
	playerHpUIOut->scale.y = playerHpUIOut->imageSize.y / 2;

	playerLevelUIOut->space = SPACE::SCREEN;
	playerLevelUIin->space = SPACE::SCREEN;
	playerLevelUImiddle->space = SPACE::SCREEN;
	playerLevelUImiddle->pivot = OFFSET_B;
	playerLevelUIin->pivot = OFFSET_B;
	playerLevelUIOut->pivot = OFFSET_B;
	playerLevelUIOut->SetWorldPos(Vector2(-470, 220));
	playerLevelUIin->SetParentRT(*playerLevelUIOut);
	playerLevelUImiddle->SetParentRT(*playerLevelUIOut);

	playerHpUIOut->space = SPACE::SCREEN;
	playerHpUIin->space = SPACE::SCREEN;
	playerHpUIOut->pivot = OFFSET_L;
	playerHpUIin->pivot = OFFSET_L;
	playerHpUIOut->SetWorldPos(Vector2(-440, 267));
	playerHpUIin->SetParentRT(*playerHpUIOut);

	
	levelUi.left = playerLevelUIOut->GetWorldPos().x+20;
	levelUi.top = playerLevelUIOut->GetWorldPos().y+28;
	levelUi.right = levelUi.left + 300;
	levelUi.bottom = levelUi.top + 300;

	HpUi.left = playerLevelUIOut->GetWorldPos().x+170;
	HpUi.top = playerLevelUIOut->GetWorldPos().y+15;
	HpUi.right = HpUi.left + 500;
	HpUi.bottom = HpUi.top + 500;

	
}

UI::~UI()
{
	delete playerLevelUIin;
	delete playerLevelUImiddle;
	delete playerLevelUIOut;
	delete playerHpUIin;
	delete playerHpUIOut;
	
}

void UI::Init()
{
	
}

void UI::Release()
{
}

void UI::Update()
{
	
	playerLevelUIin->scale.y = playerLevelUIin->imageSize.y / 2 * ((float)GM->pl->exp / 200);

	
	playerHpUIin->scale.x = playerHpUIin->imageSize.x / 1.8* ((float)GM->pl->Hp / (float)GM->pl->maxHp);
	
	
	playerLevelUIin->Update();
	playerLevelUImiddle->Update();
	playerLevelUIOut->Update();
	playerHpUIin->Update();
	playerHpUIOut->Update();
}

void UI::LateUpdate()
{
	
}

void UI::Render()
{
	playerLevelUIOut->Render();
	playerLevelUIin->Render();
	playerLevelUImiddle->Render();
	playerHpUIOut->Render();
	playerHpUIin->Render();

	DWRITE->RenderText(to_wstring(GM->pl->expLevel), levelUi, 35.0f, L"µÕ±Ù¸ð²Ã");
	DWRITE->RenderText(to_wstring(GM->pl->Hp)+L"/" + to_wstring(GM->pl->maxHp), HpUi, 35.0f, L"µÕ±Ù¸ð²Ã");

	
}

void UI::ResizeScreen()
{
}

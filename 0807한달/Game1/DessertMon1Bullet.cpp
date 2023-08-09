#include "stdafx.h"
#include "Bullet.h"
#include "DessertMon1Bullet.h"

DessertMon1Bullet::DessertMon1Bullet()
{
	
}

DessertMon1Bullet::DessertMon1Bullet(GameObject* gun, Vector2 dir) : Bullet(gun, dir)
{
	bulletSpeed = RANDOM->Int(200, 400);
	bulletImg = new ObImage(L"DessertMonster1Bullet.png");
	bulletImg->maxFrame.x = 2;
	bulletImg->scale.x = bulletImg->imageSize.x / bulletImg->maxFrame.x * 3;
	bulletImg->scale.y = bulletImg->imageSize.y * 3;

	bulletImg->ChangeAnim(ANIMSTATE::ONCE, 0.2f);
	bulletImg->SetParentRT(*this);
	isFilled = false;

	cout << "사막몬스터1 총알 생성" << endl;
}

DessertMon1Bullet::~DessertMon1Bullet()
{
	cout << "사막몬스터 총알 삭제" << endl;
}








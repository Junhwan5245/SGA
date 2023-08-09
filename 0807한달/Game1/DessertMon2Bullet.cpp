#include "stdafx.h"
#include "Bullet.h"
#include "DessertMon2Bullet.h"

DessertMon2Bullet::DessertMon2Bullet()
{

}

DessertMon2Bullet::DessertMon2Bullet(GameObject* gun, Vector2 dir) : Bullet(gun, dir)
{
	bulletSpeed = RANDOM->Int(200, 400);
	bulletImg = new ObImage(L"DessertMonster2Bullet.png");
	bulletImg->maxFrame.x = 3;
	bulletImg->scale.x = bulletImg->imageSize.x / bulletImg->maxFrame.x * 3;
	bulletImg->scale.y = bulletImg->imageSize.y * 3;

	bulletImg->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	bulletImg->SetParentRT(*this);
	isFilled = false;

	cout << "사막몬스터2 총알 생성" << endl;
}

DessertMon2Bullet::~DessertMon2Bullet()
{
	cout << "사막몬스터2 총알 삭제" << endl;
}








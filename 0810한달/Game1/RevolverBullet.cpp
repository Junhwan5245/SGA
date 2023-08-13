#include "stdafx.h"
#include "Bullet.h"
#include "RevolverBullet.h"

RevolverBullet::RevolverBullet()
{
	
}

RevolverBullet::RevolverBullet(GameObject* gun, Vector2 dir) : Bullet(gun, dir)
{
	damage = 20;
	bulletSpeed = 700;
	bulletImg = new ObImage(L"RevolverBullet.png");
	bulletImg->maxFrame.x = 2;
	bulletImg->scale.x = bulletImg->imageSize.x / bulletImg->maxFrame.x*1.5;
	bulletImg->scale.y = bulletImg->imageSize.y*1.5;

	bulletImg->ChangeAnim(ANIMSTATE::ONCE, 0.2f);
	bulletImg->SetParentRT(*this);

	cout << "리볼버총알생성" << endl;
}

RevolverBullet::~RevolverBullet()
{
	cout << "리볼버총알삭제" << endl;
}



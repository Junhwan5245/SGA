#include "stdafx.h"
#include "Bullet.h"
#include "ShotgunBullet.h"

ShotgunBullet::ShotgunBullet()
{
}

ShotgunBullet::ShotgunBullet(GameObject* gun, Vector2 dir) : Bullet(gun, dir)
{

	damage = 30;
	bulletSpeed = 400;
	bulletImg = new ObImage(L"ShotgunBullet.png");
	bulletImg->maxFrame.x = 4;
	bulletImg->scale.x = bulletImg->imageSize.x / bulletImg->maxFrame.x * 1.5;
	bulletImg->scale.y = bulletImg->imageSize.y * 1.5;

	bulletImg->ChangeAnim(ANIMSTATE::ONCE, 0.1);
	bulletImg->SetParentRT(*this);

	cout << "¼¦°ÇÃÑ¾Ë»ý¼º" << endl;
}

ShotgunBullet::~ShotgunBullet()
{
	cout << "¼¦°ÇÃÑ¾Ë»èÁ¦" << endl;
}

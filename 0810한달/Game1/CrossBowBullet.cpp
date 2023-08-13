#include "stdafx.h"
#include "Bullet.h"
#include "CrossBowBullet.h"

CrossBowBullet::CrossBowBullet()
{
}

CrossBowBullet::CrossBowBullet(GameObject* gun, Vector2 dir) : Bullet(gun, dir)
{
	damage = 50;
	bulletSpeed = 900;
	bulletImg = new ObImage(L"CrossbowBullet.png");
	bulletImg->maxFrame.x = 1;
	bulletImg->scale.x = bulletImg->imageSize.x / bulletImg->maxFrame.x ;
	bulletImg->scale.y = bulletImg->imageSize.y ;

	bulletImg->ChangeAnim(ANIMSTATE::ONCE, 0.1);
	bulletImg->SetParentRT(*this);

	cout << "¼®±ÃÃÑ¾Ë»ý¼º" << endl;
}

CrossBowBullet::~CrossBowBullet()
{
	cout << "¼®±ÃÃÑ¾Ë»èÁ¦" << endl;
}

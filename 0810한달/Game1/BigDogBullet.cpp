#include "stdafx.h"
#include "Bullet.h"
#include "BigDogBullet.h"

BigDogBullet::BigDogBullet()
{
}

BigDogBullet::BigDogBullet(GameObject* gun, Vector2 dir):Bullet( gun, dir)
{
	damage = 2;
	bulletSpeed = 150;
	bulletImg = new ObImage(L"DessertMonster2Bullet.png");
	bulletImg->maxFrame.x = 3;
	bulletImg->scale.x = bulletImg->imageSize.x / bulletImg->maxFrame.x * 3;
	bulletImg->scale.y = bulletImg->imageSize.y * 3;
	
	bulletImg->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	bulletImg->SetParentRT(*this);
	isFilled = false;

	cout << "보스몬스터 총알 생성" << endl;
}

BigDogBullet::~BigDogBullet()
{
	cout << "보스몬스터 총알 삭제" << endl;
}

void BigDogBullet::Update()
{	
	ObRect::Update();
	bulletImg->Update();

	MoveWorldPos(fireDir * bulletSpeed * DELTA);
}

void BigDogBullet::Render()
{
	Bullet::Render();

}

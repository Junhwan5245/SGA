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

	cout << "�������� �Ѿ� ����" << endl;
}

BigDogBullet::~BigDogBullet()
{
	cout << "�������� �Ѿ� ����" << endl;
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

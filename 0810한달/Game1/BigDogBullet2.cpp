#include "stdafx.h"
#include "Bullet.h"
#include "BigDogBullet2.h"

BigDogBullet2::BigDogBullet2()
{
}

BigDogBullet2::BigDogBullet2(GameObject* gun, Vector2 dir) :Bullet(gun, dir)
{
	
	damage = 7;
	bulletSpeed = 250;
	bulletImg = new ObImage(L"BigDogBullet2.png");
	bulletImg->maxFrame.x = 4;
	bulletImg->scale.x = bulletImg->imageSize.x / bulletImg->maxFrame.x ;
	bulletImg->scale.y = bulletImg->imageSize.y;
	scale.x = bulletImg->imageSize.x / bulletImg->maxFrame.x;
	scale.y = bulletImg->imageSize.y;
	pivot = OFFSET_N;
	rotation.z = atan2f(dir.y, dir.x);
	bulletImg->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	bulletImg->SetParentRT(*this);
	isFilled = false;

	cout << "�������� �Ѿ�2 ����" << endl;
}

BigDogBullet2::~BigDogBullet2()
{
	cout << "�������� �Ѿ�2 ����" << endl;
}

void BigDogBullet2::Update()
{
	ObRect::Update();
	bulletImg->Update();
	
	MoveWorldPos(fireDir * bulletSpeed * DELTA);
}

void BigDogBullet2::Render()
{
	Bullet::Render();
}



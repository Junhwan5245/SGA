#include "stdafx.h"
#include "Bullet.h"
#include "DessertMon2Bullet.h"
#include "Player.h"
#include "Monster.h"
#include "DessertMon2.h"

const float BULLET_CREATION_INTERVAL1 = 1.0f;
float timeSinceLastBulletCreation1 = 0.0f;

DessertMon2::DessertMon2()
{
	mHp = 100;
	mExpNum = 2;
	mIdle = new ObImage(L"Dessert2MonsterIdle.png");
	mIdle->maxFrame.x = 4;
	mWalk = new ObImage(L"Dessert2MonsterWalk.png");
	mWalk->maxFrame.x = 6;
	mHurt = new ObImage(L"Dessert2MonsterHurt.png");
	mHurt->maxFrame.x = 3;
	mAttack = new ObImage(L"Dessert2MonsterWalk.png");
	mAttack->maxFrame.x = 6;
	mDead = new ObImage(L"Dessert2MonsterDead.png");
	mDead->maxFrame.x = 6;
}

DessertMon2::~DessertMon2()
{
}

void DessertMon2::Init()
{
	Monster::Init();
	mIdle->scale.x = mIdle->imageSize.x / mIdle->maxFrame.x * 2;
	mIdle->scale.y = mIdle->imageSize.y * 2;
	mWalk->scale.x = mIdle->imageSize.x / mIdle->maxFrame.x * 2;
	mWalk->scale.y = mIdle->imageSize.y * 2;
	mHurt->scale.x = mIdle->imageSize.x / mIdle->maxFrame.x * 2;
	mHurt->scale.y = mIdle->imageSize.y * 2;
	mAttack->scale.x = mIdle->imageSize.x / mIdle->maxFrame.x * 2;
	mAttack->scale.y = mIdle->imageSize.y * 2;
	mDead->scale.x = mIdle->imageSize.x / mIdle->maxFrame.x * 2;
	mDead->scale.y = mIdle->imageSize.y * 2;

}

void DessertMon2::Update()
{


	Monster::Update();

	if (mState == MonsterState::ATTACK)
	{
		timeSinceLastBulletCreation1 += DELTA;


		if (timeSinceLastBulletCreation1 >= BULLET_CREATION_INTERVAL1)
		{

			timeSinceLastBulletCreation1 = 0.0f;


		/*	const int maxBulletsToCreate = 10;
			for (int i = 0; i < maxBulletsToCreate; i++)
			{*/
				Vector2 tempDir = GM->pl->col->GetWorldPos() + (Vector2(RANDOM->Int(0, 50)), Vector2(RANDOM->Int(0, 100))) - col->GetWorldPos();
				tempDir.Normalize();
				Bullet* monster2Bullets = new DessertMon2Bullet(col, tempDir);
				monbullets.push_back(monster2Bullets);

			/*}*/
		}
	}

	for (vector<Bullet*>::iterator it = monbullets.begin(); it != monbullets.end(); it++)
		(*it)->Update();
}

void DessertMon2::Render()
{
	Monster::Render();

	for (vector<Bullet*>::iterator it = monbullets.begin(); it != monbullets.end(); it++)
		(*it)->Render();
}

void DessertMon2::Move(Vector2 TargetPos)
{
	Monster::Move(TargetPos);
	moveSpeed = 300.0f;
}



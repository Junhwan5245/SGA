#include "stdafx.h"
#include "Bullet.h"
#include "DessertMon1Bullet.h"
#include "Player.h"
#include "Monster.h"
#include "DessertMon1.h"
const float BULLET_CREATION_INTERVAL = 2.0f;
float timeSinceLastBulletCreation = 0.0f;

DessertMon1::DessertMon1()
{	
	mHp = 250;
	mExpNum = 4;
	mIdle = new ObImage(L"DessertMonster1Idle.png");
	mIdle->maxFrame.x = 14;
	mWalk = new ObImage(L"DessertMonster1Walk.png");
	mWalk->maxFrame.x = 6;
	mHurt = new ObImage(L"DessertMonster1Hurt.png");
	mHurt->maxFrame.x = 3;
	mAttack = new ObImage(L"DessertMonster1Fire.png");
	mAttack->maxFrame.x = 2;
	mDead = new ObImage(L"DessertMonster1Dead.png");
	mDead->maxFrame.x = 6;
}

DessertMon1::~DessertMon1()
{
}

void DessertMon1::Init()
{
	Monster::Init();
	mIdle->scale.x = mIdle->imageSize.x / mIdle->maxFrame.x*2;
	mIdle->scale.y = mIdle->imageSize.y*2;
	mWalk->scale.x = mIdle->imageSize.x / mIdle->maxFrame.x*2;
	mWalk->scale.y = mIdle->imageSize.y*2;
	mHurt->scale.x = mIdle->imageSize.x / mIdle->maxFrame.x*2;
	mHurt->scale.y = mIdle->imageSize.y*2;
	mAttack->scale.x = mIdle->imageSize.x / mIdle->maxFrame.x*2;
	mAttack->scale.y = mIdle->imageSize.y*2;
	mDead->scale.x = mIdle->imageSize.x / mIdle->maxFrame.x * 2;
	mDead->scale.y = mIdle->imageSize.y * 2;
	col->SetWorldPosX(2300);
	col->SetWorldPosY(650);
}

void DessertMon1::Update()
{
	

	Monster::Update();

	if (mState == MonsterState::ATTACK)
	{
		timeSinceLastBulletCreation += DELTA;
		

		if (timeSinceLastBulletCreation >= BULLET_CREATION_INTERVAL)
		{
			
			timeSinceLastBulletCreation = 0.0f;

			
			
			
			for (int i = 0; i < 10; i++)
			{
				Vector2 tempDir = GM->pl->col->GetWorldPos() + (Vector2(RANDOM->Int(0, 50)), Vector2(RANDOM->Int(0, 100))) - col->GetWorldPos();
				tempDir.Normalize();
				Bullet* monster1Bullets = new DessertMon1Bullet(col, tempDir);
				monbullets.push_back(monster1Bullets);
			}
				
			
		}
	}

	for (vector<Bullet*>::iterator it = monbullets.begin(); it != monbullets.end(); it++)
		(*it)->Update();
}

void DessertMon1::Render()
{
	Monster::Render();

	for (vector<Bullet*>::iterator it = monbullets.begin(); it != monbullets.end(); it++)
		(*it)->Render();
}

void DessertMon1::Move(Vector2 TargetPos)
{
	Monster::Move(TargetPos);
	moveSpeed = 200.0f;
}





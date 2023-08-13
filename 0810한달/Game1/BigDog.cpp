#include "stdafx.h"
#include "Boss.h"
#include "Player.h"
#include "Bullet.h"
#include "BigDogBullet2.h"
#include "BigDogBullet.h"
#include "BigDog.h"
const float BULLET_CREATION_INTERVAL2 = 0.3f;//bullet1
float timeSinceLastBulletCreation2 = 0.0f;

const float BULLET2_CREATION_INTERVAL2 = 1.0f;//bullet2
float timeSinceLastBullet2Creation2 = 0.0f;


BigDog::BigDog()
{
	
	bHp = 2000;
	mExpNum = 100;
	bSleep = new ObImage(L"BigDogSleep.png");
	bSleep->maxFrame.x = 4;
	bIdle = new ObImage(L"BigDogIdle.png");
	bIdle->maxFrame.x = 6;
	bWalk = new ObImage(L"BigDogIdle.png");
	bWalk->maxFrame.x = 6;
	bAttack = new ObImage(L"BigDogSpin.png");
	bAttack->maxFrame.x = 19;
	bDead = new ObImage(L"BigDogDead.png");
	bDead->maxFrame.x = 1;
	bPortrait = new ObImage(L"BigDogPortrait.png");
	bBossName = new ObImage(L"BossName.png");
	bBossNameEffect = new ObImage(L"BossNameEffect.png");
}

BigDog::~BigDog()
{
}

void BigDog::Init()
{
	Boss::Init();
	bSleep->scale.x = bSleep->imageSize.x / bSleep->maxFrame.x;
	bSleep->scale.y = bSleep->imageSize.y;
	bIdle->scale.x = bIdle->imageSize.x / bIdle->maxFrame.x ;
	bIdle->scale.y = bIdle->imageSize.y ;
	bWalk->scale.x = bIdle->imageSize.x / bIdle->maxFrame.x ;
	bWalk->scale.y = bIdle->imageSize.y ;
	bAttack->scale.x = bIdle->imageSize.x / bIdle->maxFrame.x ;
	bAttack->scale.y = bIdle->imageSize.y ;
	bDead->scale.x = bIdle->imageSize.x / bIdle->maxFrame.x ;
	bDead->scale.y = bIdle->imageSize.y ;
	bPortrait->scale.x = bPortrait->imageSize.x;
	bPortrait->scale.y = bPortrait->imageSize.y;
	bBossName->scale.x = bBossName->imageSize.x;
	bBossName->scale.y = bBossName->imageSize.y;
	bBossNameEffect->scale.x = bBossNameEffect->imageSize.x;
	bBossNameEffect->scale.y = bBossNameEffect->imageSize.y;
	col->SetWorldPosX(3230);
	col->SetWorldPosY(1270);
}

void BigDog::Update()
{
	Boss::Update();

	if(bState == BossState::ATTACK)
	{
		timeSinceLastBulletCreation2 += DELTA;


		if (timeSinceLastBulletCreation2 >= BULLET_CREATION_INTERVAL2)
		{

			timeSinceLastBulletCreation2 = 0.0f;

			

			static int j=0;
			
			
			for (int i = 0; i < 10; i++)
			{
				Vector2 tempDir = Vector2(cosf((i * 36+j) * ToRadian), sinf((i * 36 + j) * ToRadian));
				tempDir.Normalize();
				Bullet* bossBullets = new BigDogBullet(col, tempDir);
				bossbullets.push_back(bossBullets);
				j++;
		
				if (j > 50)
				{
					bState = BossState::ATTACK2;
					j = 0;
				}
				
			}


		}
	}

	if (bState == BossState::ATTACK2)
	{
		timeSinceLastBullet2Creation2 += DELTA;

		if (timeSinceLastBullet2Creation2 >= BULLET2_CREATION_INTERVAL2)
		{
			timeSinceLastBullet2Creation2 = 0.0f;

			Vector2 tempDir = GM->pl->col->GetWorldPos() + (Vector2(RANDOM->Int(0, 100)), Vector2(RANDOM->Int(0, 100))) - col->GetWorldPos();
			tempDir.Normalize();
			Bullet* bossBullet2s = new BigDogBullet2(col, tempDir);
			bossbullets.push_back(bossBullet2s);

		}
	}

	for (vector<Bullet*>::iterator it = bossbullets.begin(); it != bossbullets.end(); it++)
		(*it)->Update();

}

void BigDog::Render()
{
	Boss::Render();

	for (vector<Bullet*>::iterator it = bossbullets.begin(); it != bossbullets.end(); it++)
		(*it)->Render();
}

void BigDog::Move(Vector2 TargetPos)
{
	Boss::Move(TargetPos);
	moveSpeed = 200.0f;
}

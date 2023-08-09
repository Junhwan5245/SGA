#include "stdafx.h"
#include "Monster.h"
#include "Gun.h"
#include "Player.h"
#include "Bullet.h"
#include "ShotgunBullet.h"
#include "Shotgun.h"

Shotgun::Shotgun()
{
	maxBullet = 50;
	currentBullet = maxBullet;
	gunImg = new ObImage(L"Shotgun.png");

	gunImg->scale.x = gunImg->imageSize.x / 1.1;
	gunImg->scale.y = gunImg->imageSize.y / 1.1;
	cout << "¼¦°Ç»ý¼º" << endl;
}

Shotgun::~Shotgun()
{
}

void Shotgun::Update()
{
	Gun::Update();
}

void Shotgun::Render()
{
	Gun::Render();
}

void Shotgun::Fire()
{
	if (currentBullet > 0)
	{
		for (int i = 0; i < 5; i++)
		{
			Vector2 tempDir = INPUT->GetWorldMousePos() - GM->pl->col->GetWorldPos() + Vector2((RANDOM->Int(-40, 70)), (RANDOM->Int(-40, 70)));

			tempDir.Normalize();

			ShotgunBullet* bullet = new ShotgunBullet(col, tempDir);
			bullets.push_back(bullet);
			currentBullet--;
		}
	}
}

#include "stdafx.h"
#include "Monster.h"
#include "Gun.h"
#include "Player.h"
#include "Bullet.h"
#include "RevolverBullet.h"
#include "Revolver.h"

Revolver::Revolver()
{
	
	maxBullet = 40;
	currentBullet = maxBullet;
	gunImg= new ObImage(L"revolver.png");
	
	gunImg ->scale.x = gunImg->imageSize.x;
	gunImg->scale.y = gunImg->imageSize.y;


	cout << "리볼버생성" << endl;
	

}

Revolver::~Revolver()
{
	
}

void Revolver::Update()
{
	Gun::Update();

	
}

void Revolver::Render()
{
	Gun::Render();
	
}

void Revolver::Fire()
{
	if (currentBullet > 0)
	{
		Vector2 tempDir = INPUT->GetWorldMousePos() - GM->pl->col->GetWorldPos();
		tempDir.Normalize();
		RevolverBullet* bullet = new RevolverBullet(col, tempDir);

		bullets.push_back(bullet);
		currentBullet--;
	}


}
//void Revolver::Reload()
//{
//	currentBulletCount = maxBullet;
//}

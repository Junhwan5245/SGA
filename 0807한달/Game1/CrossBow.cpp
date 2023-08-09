#include "stdafx.h"
#include "Monster.h"
#include "Gun.h"
#include "Player.h"
#include "Bullet.h"
#include "CrossBowBullet.h"
#include "CrossBow.h"


CrossBow::CrossBow()
{
	
	
	gunImg = new ObImage(L"Crossbow.png");

	gunImg->scale.x = gunImg->imageSize.x;
	gunImg->scale.y = gunImg->imageSize.y;

	cout << "¼®±Ã»ý¼º" << endl;



}

CrossBow::~CrossBow()
{

}

void CrossBow::Update()
{
	Gun::Update();


}

void CrossBow::Render()
{
	Gun::Render();

}

void CrossBow::Fire()
{

	Vector2 tempDir = INPUT->GetWorldMousePos() - GM->pl->col->GetWorldPos();
	tempDir.Normalize();
	CrossBowBullet* bullet = new CrossBowBullet(col, tempDir);

	bullets.push_back(bullet);


}


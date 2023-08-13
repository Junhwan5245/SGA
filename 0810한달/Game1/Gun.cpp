#include "stdafx.h"
#include "Monster.h"
#include "Player.h"
#include "Bullet.h"
#include "Gun.h"

Gun::Gun()
{
	col = new ObRect();
	gunImg = nullptr;
	

	col->isFilled = false;
	col->scale.x = 30;
	col->scale.y = 30;
	
}

Gun::~Gun()
{

	delete col;
	delete gunImg;

}

void Gun::Init()
{
	
	/*col->SetLocalPosX(28.0f);
	col->SetLocalPosY(-5.0f);*/
	gunImg->SetParentRT(*col);
	
	



}

void Gun::Fire()
{
	Bullet* bullet = new Bullet(col, INPUT->GetWorldMousePos() - GM->pl->col->GetWorldPos());

	
	bullets.push_back(bullet);


	
}

void Gun::Update()
{

	/*lookDir = INPUT->GetWorldMousePos() - GM->pl->col->GetWorldPos();*/
	/*lookDir.Normalize();*/
	
	if (isEquip)
	{
		if (INPUT->GetWorldMousePos().x < GM->pl->col->GetWorldPos().x)
		{
			gunImg->rotation.x = PI;
			/*col->SetWorldPosY(5.0f);*/
		}
		else
		{
			/*col->SetWorldPosY(-5.0f);*/
			gunImg->rotation.x = 0;

		}
	}



	col->Update();
	gunImg->Update();
	
	for (vector<Bullet*>::iterator i = bullets.begin(); i != bullets.end(); i++)
		(*i)->Update();
	

}


void Gun::Render()
{
	

	/*col->Render();*/
	gunImg->Render();
	
	for (vector<Bullet*>::iterator i = bullets.begin(); i != bullets.end(); i++)
		(*i)->Render();
	
}



//void Gun::BulletColWithMon(Monster* monster)
//{
//	for (vector<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); it++)
//	{
//		if ((*it)->Intersect(monster->col))
//		{
//			monster->mHp -= damage;
//		}
//	}
//
//
//}

#include "stdafx.h"
#include "GunOperateManager.h"
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "Boss.h"
#include "BigDog.h"
#include "DessertMon1.h"
#include "DessertMon1Bullet.h"
#include "DessertMon2.h"
#include "DessertMon2Bullet.h"
#include "Gun.h"
#include "Fish.h"
#include "Crystal.h"
#include "Revolver.h"
#include "Shotgun.h"
#include "CrossBow.h"
#include "ItemBox.h"
#include "Item.h"
#include "UI.h"
#include "Exp.h"
#include "GunItemBox.h"
#include "HealItem.h"
#include "HealItemBox.h"
#include "BulletItem.h"
#include "BulletItemBox.h"
#include "Scene2.h"
#include "Scene3.h"



Scene3::Scene3()
{
}

Scene3::~Scene3()
{
}

void Scene3::Init()
{
	map = new ObTileMap();
	floor = new ObTileMap();
	GM->GunOpreateManager = new GunOperateManager();
	/*for (int i = 0; i < 9; i++)
	{
		GM->monster.push_back(new DessertMon1());
		GM->monster.push_back(new DessertMon2());
	}*/
	GM->boss.push_back(new BigDog());
	GM->pl->col->SetWorldPos(Vector2(293, 1110));
	Ui = new UI();
	
	map->file = "map4.txt";
	floor->file = "map5.txt";
	map->Load();
	floor->Load();
	map->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
	map->CreateTileCost();

	for (vector<Monster*>::iterator it = GM->monster.begin(); it != GM->monster.end(); it++)
		(*it)->Init();

	for (vector<Boss*>::iterator it = GM->boss.begin(); it != GM->boss.end(); it++)	
		(*it)->Init();
		

}

void Scene3::Release()
{
}

void Scene3::Update()
{
	static bool isFirst = true;
	ImGui::Text("isMoved : %d", isMove());
	ImGui::Text("Plocationx : %f", GM->pl->col->GetWorldPos().x);
	ImGui::Text("Plocationy : %f", GM->pl->col->GetWorldPos().y);
	ImGui::Text("locationx : %f", INPUT->GetWorldMousePos().x);
	ImGui::Text("locationy : %f", INPUT->GetWorldMousePos().y);







	for (vector<Boss*>::iterator it = GM->boss.begin(); it != GM->boss.end(); it++)
	{
		if ((*it)->bState == BossState::WALK)
		{
			if (map->PathFinding((*it)->col->GetWorldPos(), GM->pl->col->GetWorldPivot(), (*it)->way))
			{
				int k = (*it)->way.size() - 1;
				(*it)->Move((*it)->way[k - 1]->Pos);

			}
		}
	}
	GM->pl->Update();
	floor->Update();
	map->Update();
	for (vector<Monster*>::iterator it = GM->monster.begin(); it != GM->monster.end(); it++)
		(*it)->Update();

	for (vector<Boss*>::iterator it = GM->boss.begin(); it != GM->boss.end(); it++)
		(*it)->Update();
	//for (int i = 0; i < ITEMMAX; i++)
	//	Itembox[i]->Update();

	//for (vector<Item*>::iterator it = GM->ItemManager.begin(); it != GM->ItemManager.end(); it++)
	//	(*it)->Update();

	if (isFirst)
	{
		CAM->position = Vector2(3230, 1270);
		if (INPUT->KeyDown('W') || INPUT->KeyDown('A') || INPUT->KeyDown('S') || INPUT->KeyDown('D'))
		{
		
				isFirst = false;
			
		}
	}
	else
	{
		CAM->position = GM->pl->col->GetWorldPos();
	}

	Ui->Update();

	GM->GunOpreateManager->Update();

	
}

void Scene3::LateUpdate()
{
	
	

	Int2 plIdx;
	if (map->WorldPosToTileIdx(GM->pl->GetFoot(), plIdx))
	{
		if (map->GetTileState(plIdx) == TILE_WALL)
		{
			GM->pl->GoBack();
		}


	}


	GM->pl->gun1->bullets.erase
	(
		std::remove_if
		(
			GM->pl->gun1->bullets.begin(),
			GM->pl->gun1->bullets.end(),
			/*collide((*it))*/
			[&](Bullet* bullet) {
				if (collide(bullet))
				{
					delete bullet;
					return true;
				}

			}
		)
		, GM->pl->gun1->bullets.end()
				);

	for (vector<Monster*>::iterator it = GM->monster.begin(); it != GM->monster.end(); it++)
	{
		(*it)->monbullets.erase
		(
			std::remove_if
			(
				(*it)->monbullets.begin(),
				(*it)->monbullets.end(),

				[&](Bullet* monbullet) {
					if (Moncollide(monbullet))
					{

						delete monbullet;
						return true;
					}

				}
			)
			, (*it)->monbullets.end()
					);

	}



	GM->monster.erase
	(
		std::remove_if
		(
			GM->monster.begin(),
			GM->monster.end(),

			[&](class Monster* monster) {
				if (monster->isFinished)
				{
					
					for (int i = 0; i < monster->mExpNum; i++)
					{
						Exp* exp = new Exp();
						GM->ItemManager.push_back(exp);
						Vector2 tempDir;
						tempDir = Vector2(RANDOM->Int(-10, 10), RANDOM->Int(-10, 10));
						exp->col->rotation.z = atan2f(tempDir.y, tempDir.x);
						exp->col->SetWorldPos(monster->col->GetWorldPos() + Vector2(RANDOM->Int(-25, 25), RANDOM->Int(-25, 25)));
					}
					delete monster;
					return true;
				}

			}
		)
		, GM->monster.end()
				);


	GM->boss.erase
	(
		std::remove_if
		(
			GM->boss.begin(),
			GM->boss.end(),

			[&](class Boss* boss) {
				if (boss->isFinished)
				{
					for (int i = 0; i < boss->mExpNum; i++)
					{
						Exp* exp = new Exp();
						GM->ItemManager.push_back(exp);
						Vector2 tempDir;
						tempDir = Vector2(RANDOM->Int(-10, 10), RANDOM->Int(-10, 10));
						exp->col->rotation.z = atan2f(tempDir.y, tempDir.x);
						exp->col->SetWorldPos(boss->col->GetWorldPos() + Vector2(RANDOM->Int(-25, 25), RANDOM->Int(-25, 25)));
					}
					delete boss;
					return true;
				}

			}
		)
		, GM->boss.end()
				);



	GM->ItemManager.erase
	(
		std::remove_if
		(
			GM->ItemManager.begin(),
			GM->ItemManager.end(),

			[&](class Item* item) {
				if (item->isUsed)
				{
					delete item;
					return true;
				}

			}
		)
		, GM->ItemManager.end()
				);


	for (vector<Boss*>::iterator it = GM->boss.begin(); it != GM->boss.end(); it++)
	{
		(*it)->bossbullets.erase
		(
			std::remove_if
			(
				(*it)->bossbullets.begin(),
				(*it)->bossbullets.end(),

				[&](Bullet* bossbullet) {
					if (Moncollide(bossbullet))
					{

						delete bossbullet;
						return true;
					}

				}
			)
			, (*it)->bossbullets.end()
					);

	}



}

void Scene3::Render()
{
	floor->Render();

	map->Render();



	for (vector<Monster*>::iterator it = GM->monster.begin(); it != GM->monster.end(); it++)
		(*it)->Render();

	for (vector<Boss*>::iterator it = GM->boss.begin(); it != GM->boss.end(); it++)
		(*it)->Render();

	/*for (int i = 0; i < ITEMMAX; i++)
		Itembox[i]->Render();

	for (vector<Item*>::iterator it = GM->ItemManager.begin(); it != GM->ItemManager.end(); it++)
		(*it)->Render();*/
	GM->pl->Render();

	GM->GunOpreateManager->Render();

	Ui->Render();
}

void Scene3::ResizeScreen()
{
}

bool Scene3::collide(Bullet* bullet)
{
	if (!bullet)
	{
		// 유효하지 않은 인자 처리 (예: 예외 또는 오류 처리)
		return false;
	}

	Int2 bulletIdx;
	if (map->WorldPosToTileIdx(bullet->GetWorldPos(), bulletIdx))
	{
		if (map->GetTileState(bulletIdx) == TILE_WALL)
		{
			return true;
		}
	}
	for (vector<Monster*>::iterator it = GM->monster.begin(); it != GM->monster.end(); it++)
	{
		if (bullet->Intersect((*it)->col))
		{
			(*it)->mState = MonsterState::HURT;
			(*it)->mHp -= bullet->damage;

			return true;
		}
	}
	for (vector<Boss*>::iterator it = GM->boss.begin(); it != GM->boss.end(); it++)
	{
		if (bullet->Intersect((*it)->col))
		{
			(*it)->hurtTime = 0.3f;
			(*it)->bHp -= bullet->damage;

			return true;
		}
	}


	return false;
}

bool Scene3::Moncollide(Bullet* monbullet)
{
	if (!monbullet)

	{
		// 유효하지 않은 인자 처리 (예: 예외 또는 오류 처리)
		return false;
	}

	Int2 monbulletIdx;
	if (map->WorldPosToTileIdx(monbullet->GetWorldPos(), monbulletIdx))
	{
		if (map->GetTileState(monbulletIdx) == TILE_WALL)
		{
			return true;
		}
	}
	if (monbullet->Intersect(GM->pl->col))
	{

		GM->pl->Hp = max(0, GM->pl->Hp - monbullet->damage);


		return true;
	}

	return false;
}

bool Scene3::bossCollide(Bullet* bossbullet)
{
	if (!bossbullet)

	{
		// 유효하지 않은 인자 처리 (예: 예외 또는 오류 처리)
		return false;
	}

	Int2 bossbulletIdx;
	if (map->WorldPosToTileIdx(bossbullet->GetWorldPos(), bossbulletIdx))
	{
		if (map->GetTileState(bossbulletIdx) == TILE_WALL)
		{
			return true;
		}
	}
	if (bossbullet->Intersect(GM->pl->col))
	{

		GM->pl->Hp = max(0, GM->pl->Hp - 7);


		return true;
	}

	return false;
}

bool Scene3::isMove()
{
	if (GM->pl->col->GetWorldPos().y ==1110)
	{
		return true;
	}
	else return false;
}



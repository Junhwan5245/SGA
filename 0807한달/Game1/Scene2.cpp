#include "stdafx.h"
#include "GunOperateManager.h"
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
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
#include "SceneChoice.h"
#include "Scene2.h"



Scene2::Scene2()
{
	cout << SCENE->playerNum << endl;
	

}

Scene2::~Scene2()
{
}

void Scene2::Init()
{
	
	map = new ObTileMap();
	floor = new ObTileMap();
	GM->GunOpreateManager = new GunOperateManager();
	GM->monster.push_back(new DessertMon1());
	GM->monster.push_back(new DessertMon2());
	
	int ItemNum = RANDOM->Int(3, 4);
	
	if (ItemNum == 1)
		Itembox = new HealItemBox();
	else if (ItemNum == 2)
		Itembox = new BulletItemBox();
	else Itembox = new GunItemBox();
	
	Itembox->Init();
	Itembox->col->SetWorldPos(Vector2(3300, 500));
	
	
	Ui = new UI();
	

	map->file = "map1.txt";
	floor->file = "map3.txt";
	map->Load();
	floor->Load();
	map->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
	/*BulletItem* bulletItem = new BulletItem();
	GM->Item.emplace(2, bulletItem);
	GM->Item.emplace(1, new HealItem());
	std::cout << "Type of myInt is: " << typeid(new BulletItem()).name() << '\n';*/

	if (SCENE->playerNum == 2)
	{
		
		GM->pl = new Fish();
		
	}

	if (SCENE->playerNum == 3)
	{
		
		GM->pl = new Crystal();
	
	}
	GM->pl->gun1 = new Revolver();
	GM->pl->gun2 = new Shotgun();

	GM->pl->gun1->isEquip = true;
	GM->pl->gun2->isEquip = true;

	GM->GunOpreateManager->GunManager.push_back(GM->pl->gun1);
	GM->GunOpreateManager->GunManager.push_back(GM->pl->gun2);

	map->CreateTileCost();
	GM->pl->Init(Vector2(3500, 500));
	for (vector<Monster*>::iterator it = GM->monster.begin(); it != GM->monster.end(); it++)
		(*it)->Init();
	
	
}

void Scene2::Release()
{
}

void Scene2::Update()
{
	ImGui::Text("FPS : %d", (int)TIMER->GetFramePerSecond());
	ImGui::Text("locationx : %f", GM->pl->col->GetWorldPos().x);
	ImGui::Text("locationy : %f", GM->pl->col->GetWorldPos().y);
	ImGui::Text("ItemVectorSize : %d", GM->ItemManager.size());
	ImGui::Text("PlayerHp : %d", GM->pl->Hp);
	ImGui::Text("EXP : %d", GM->pl->gun1->currentBullet);



	
		
	
	
	for (vector<Monster*>::iterator it = GM->monster.begin(); it != GM->monster.end(); it++)
	{
		if ((*it)->mState == MonsterState::WALK)
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
	
	Itembox->Update();
	
	for (vector<Item*>::iterator it = GM->ItemManager.begin(); it != GM->ItemManager.end(); it++)
		(*it)->Update();
	
	CAM->position = GM->pl->col->GetWorldPos();

	Ui->Update();
	
	GM->GunOpreateManager->Update();
}



void Scene2::LateUpdate()
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
								tempDir =  Vector2(RANDOM->Int(-10, 10), RANDOM->Int(-10, 10));
								exp->col->rotation.z = atan2f(tempDir.y,tempDir.x);
								exp->col->SetWorldPos(monster->col->GetWorldPos()+Vector2(RANDOM->Int(-25,25),RANDOM->Int(-25,25)));
							}
							delete monster;
							return true;
						}

					}
				)
				, GM->monster.end()
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
		

		


		
		
	
}

void Scene2::Render()
{
	
	floor->Render();
	
	map->Render();
	
	
	
	for (vector<Monster*>::iterator it = GM->monster.begin(); it != GM->monster.end(); it++)
		(*it)->Render();
	
	Itembox->Render();

	for (vector<Item*>::iterator it = GM->ItemManager.begin(); it != GM->ItemManager.end(); it++)
		(*it)->Render();
	GM->pl->Render();

	GM->GunOpreateManager->Render();
	
	Ui->Render();
	

	
}

void Scene2::ResizeScreen()
{
}

bool Scene2::collide(class Bullet* bullet)
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
	
	
	return false;
}

bool Scene2::Moncollide(class Bullet* monbullet)
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
		
		GM->pl->Hp = max(0, GM->pl->Hp-1);
		

		return true;
	}

	return false;
}


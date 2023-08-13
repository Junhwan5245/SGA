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
	door = new ObRect();
	doorImg = new ObImage(L"doorImg.png");
	doorImg->maxFrame.x = 4;
	doorImg->scale.x = doorImg->imageSize.x / doorImg->maxFrame.x/3;
	doorImg->scale.y = doorImg->imageSize.y/3;
	door->scale.x= 80;
	door->scale.y = 80;
	doorImg->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	doorImg->SetParentRT(*door);
	killCount = 21;
	map = new ObTileMap();
	floor = new ObTileMap();
	GM->GunOpreateManager = new GunOperateManager();
	for (int i = 0; i < 11; i++)
	{
		GM->monster.push_back(new DessertMon1());
		GM->monster.push_back(new DessertMon2());
	}
	GM->monster[0]->col->SetWorldPosX(2650);
	GM->monster[0]->col->SetWorldPosY(680);
	GM->monster[1]->col->SetWorldPosX(2230);
	GM->monster[1]->col->SetWorldPosY(380);
	GM->monster[2]->col->SetWorldPosX(2200);
	GM->monster[2]->col->SetWorldPosY(900);
	GM->monster[3]->col->SetWorldPosX(1820);
	GM->monster[3]->col->SetWorldPosY(675);
	GM->monster[4]->col->SetWorldPosX(2300);
	GM->monster[4]->col->SetWorldPosY(650);
	GM->monster[5]->col->SetWorldPosX(2880);
	GM->monster[5]->col->SetWorldPosY(710);
	GM->monster[6]->col->SetWorldPosX(1630);
	GM->monster[6]->col->SetWorldPosY(440);
	GM->monster[7]->col->SetWorldPosX(990);
	GM->monster[7]->col->SetWorldPosY(490);
	GM->monster[8]->col->SetWorldPosX(680);
	GM->monster[8]->col->SetWorldPosY(800); 
	GM->monster[9]->col->SetWorldPosX(260);
	GM->monster[9]->col->SetWorldPosY(810);
	GM->monster[10]->col->SetWorldPosX(610);
	GM->monster[10]->col->SetWorldPosY(215);
	GM->monster[11]->col->SetWorldPosX(3000);
	GM->monster[11]->col->SetWorldPosY(980);
	GM->monster[12]->col->SetWorldPosX(3050);
	GM->monster[12]->col->SetWorldPosY(1250);
	GM->monster[13]->col->SetWorldPosX(2350);
	GM->monster[13]->col->SetWorldPosY(1230);
	GM->monster[14]->col->SetWorldPosX(1560);
	GM->monster[14]->col->SetWorldPosY(1225);
	GM->monster[15]->col->SetWorldPosX(1465);
	GM->monster[15]->col->SetWorldPosY(1500);
	GM->monster[16]->col->SetWorldPosX(1760);
	GM->monster[16]->col->SetWorldPosY(1460);
	GM->monster[17]->col->SetWorldPosX(370);
	GM->monster[17]->col->SetWorldPosY(410);
	GM->monster[18]->col->SetWorldPosX(950);
	GM->monster[18]->col->SetWorldPosY(400);
	GM->monster[19]->col->SetWorldPosX(2560);
	GM->monster[19]->col->SetWorldPosY(1350);
	GM->monster[20]->col->SetWorldPosX(1325);
	GM->monster[20]->col->SetWorldPosY(880);
	GM->monster[21]->col->SetWorldPosX(2420);
	GM->monster[21]->col->SetWorldPosY(1530);
	
	/*GM->boss.push_back(new BigDog());*/
	
	for (int i = 0; i < ITEMMAX; i++)
	{
		int ItemNum = RANDOM->Int(1, 3);
		if (ItemNum == 1)
			Itembox[i] = new HealItemBox();
		else if (ItemNum == 2)
			Itembox[i] = new BulletItemBox();
		else Itembox[i] = new GunItemBox();
		
		Itembox[i]->Init();
	}
	Itembox[0]->col->SetWorldPos(Vector2(2750, 1030));
	Itembox[1]->col->SetWorldPos(Vector2(2860, 490));
	Itembox[2]->col->SetWorldPos(Vector2(1860, 500));
	Itembox[3]->col->SetWorldPos(Vector2(1280, 200));
	Itembox[4]->col->SetWorldPos(Vector2(1860, 1350));
	Itembox[5]->col->SetWorldPos(Vector2(270, 1130));
	Itembox[6]->col->SetWorldPos(Vector2(3015, 1585));
	door->SetWorldPos(Vector2(3260, 1330));
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

	/*for (vector<Boss*>::iterator it = GM->boss.begin(); it != GM->boss.end(); it++)
		(*it)->Init();*/
	
	
}

void Scene2::Release()
{

	for (vector<Monster*>::iterator it = GM->monster.begin(); it != GM->monster.end(); it++)
		(*it)->mHp = 0;
	for (vector<Item*>::iterator it = GM->ItemManager.begin(); it != GM->ItemManager.end(); it++)
		(*it)->isUsed = true;
}

void Scene2::Update()
{
	ImGui::Text("FPS : %d", (int)TIMER->GetFramePerSecond());
	ImGui::Text("locationx : %f", INPUT->GetWorldMousePos().x);
	ImGui::Text("locationy : %f", INPUT->GetWorldMousePos().y);
	ImGui::Text("KillCount : %d", killCount);
	if (killCount == 22)
	{
		isChangeScene = true;
	}
		
	
	for (vector<Monster*>::iterator it = GM->monster.begin(); it != GM->monster.end(); it++)
	{
		if ((*it)->mState == MonsterState::WALK)
		{
			if (map->PathFinding((*it)->col->GetWorldPos(), GM->pl->col->GetWorldPivot(), (*it)->way))
			{

				int k = (*it)->way.size() - 1;
				(*it)->Move((*it)->way[k - 1]->Pos);

				/*for (int i = 0; i < 22; i++)
				{
					for (int j = i + 1; j < 22; j++)
					{
						if (GM->monster[i]->col->Intersect(GM->monster[j]->col))
						{
							GM->monster[i]->Spread();
						}
					}
				}*/

		

			}
		}
	}


	//for (vector<Monster*>::iterator it = GM->monster.begin(); it != GM->monster.end(); it++)
	//{
	//	for (vector<Monster*>::iterator it2 = GM->monster.begin() + 1; it2 != GM->monster.end(); it2++)
	//	{
	//		if ((*it)->col->Intersect((*it2)->col))
	//		{
	//			(*it)->Spread();
	//		}
	//	}
	//}

	
	/*for (vector<Boss*>::iterator it = GM->boss.begin(); it != GM->boss.end(); it++)
	{
		if ((*it)->bState == BossState::WALK)
		{
			if (map->PathFinding((*it)->col->GetWorldPos(), GM->pl->col->GetWorldPivot(), (*it)->way))
			{
				int k = (*it)->way.size() - 1;
				(*it)->Move((*it)->way[k - 1]->Pos);

			}
		}
	}*/
	

	if(isChangeScene && door->Intersect(GM->pl->col))
	{
		SCENE->ChangeScene("SC3", 0.1f);		
	}


	
	if (!GM->pl->isDead)
	{
		GM->pl->Update();
		floor->Update();
		map->Update();
		for (vector<Monster*>::iterator it = GM->monster.begin(); it != GM->monster.end(); it++)
			(*it)->Update();

		/*for (vector<Boss*>::iterator it = GM->boss.begin(); it != GM->boss.end(); it++)
			(*it)->Update();*/
		for (int i = 0; i < ITEMMAX; i++)
			Itembox[i]->Update();

		for (vector<Item*>::iterator it = GM->ItemManager.begin(); it != GM->ItemManager.end(); it++)
			(*it)->Update();

		CAM->position = GM->pl->col->GetWorldPos();

		Ui->Update();

		GM->GunOpreateManager->Update();

		door->Update();
		doorImg->Update();
	}
	else
	{
		
		SCENE->ChangeScene("SCC");
	
	}
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
	
	
	for (vector<Monster*>::iterator it = GM->monster.begin(); it != GM->monster.end(); it++)
	{
		for (vector<Bullet*>::iterator it2 = (*it)->monbullets.begin(); it2 != (*it)->monbullets.end(); it2++)
		{
			if (SCENE->playerNum == 3 && GM->pl->state == PlayerState::ABILITY)
			{
				if ((*it2)->Intersect(GM->pl->col))
				{
					(*it2)->ReflectionX();
					(*it2)->ReflectionY();
				}
			}
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
							killCount++;
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

			
			/*GM->boss.erase
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
						);*/
		
		

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
		
		

		//for (vector<Boss*>::iterator it = GM->boss.begin(); it != GM->boss.end(); it++)
		//{
		//	(*it)->bossbullets.erase
		//	(
		//		std::remove_if
		//		(
		//			(*it)->bossbullets.begin(),
		//			(*it)->bossbullets.end(),

		//			[&](Bullet* bossbullet) {
		//				if (Moncollide(bossbullet))
		//				{

		//					delete bossbullet;
		//					return true;
		//				}

		//			}
		//		)
		//		, (*it)->bossbullets.end()
		//				);

		//}


		
		
	
}

void Scene2::Render()
{
	

	
	
	if (!GM->pl->isDead)
	{

		floor->Render();

		map->Render();

		for (vector<Monster*>::iterator it = GM->monster.begin(); it != GM->monster.end(); it++)
			(*it)->Render();

		/*for (vector<Boss*>::iterator it = GM->boss.begin(); it != GM->boss.end(); it++)
			(*it)->Render();*/

		for (int i = 0; i < ITEMMAX; i++)
			Itembox[i]->Render();

		for (vector<Item*>::iterator it = GM->ItemManager.begin(); it != GM->ItemManager.end(); it++)
			(*it)->Render();

		if (isChangeScene)
		{
			door->Render();
			doorImg->Render();
		}

		GM->pl->Render();

		if (!((SCENE->playerNum == 3 && GM->pl->state == PlayerState::ABILITY) || GM->pl->state == PlayerState::DEAD))
			GM->GunOpreateManager->Render();

		
		Ui->Render();
	}
	
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
		if (SCENE->playerNum == 3 && GM->pl->state==PlayerState::ABILITY)
		{
			return false;
		}
		else
		{
			GM->pl->Hp = max(0, GM->pl->Hp - monbullet->damage);
			return true;
		}
	}
	

	return false;
}

bool Scene2::bossCollide(class Bullet* bossbullet)
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


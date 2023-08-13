#include "stdafx.h"
#include "Player.h"
#include "Gun.h"
#include "GunOperateManager.h"


void GunOperateManager::Init()
{
}

void GunOperateManager::Update()
{
	
	for (vector<Gun*>::iterator it = GunManager.begin(); it != GunManager.end(); it++)
	{
		

		if ((*it)->col->Intersect(GM->pl->col))
		{
				if (INPUT->KeyDown('E'))
				{
					if (!(*it)->isEquip)
					{
						SwapItem(*it);
						return;
					}

				}
			
		}
		
	}
	
	for (vector<Gun*>::iterator it = GunManager.begin(); it != GunManager.end(); it++)
		(*it)->Update();
}

void GunOperateManager::Render()
{
	for (vector<Gun*>::iterator it = GunManager.begin(); it != GunManager.end(); it++)
		(*it)->Render();
	
}

void GunOperateManager::SwapItem(Gun* gun)
{
	
	if (GM->pl->gun2 == nullptr)//2가 비어있을때
		GM->pl->gun2 = gun;

	
	else
	{
		Gun* temp = GM->pl->gun1;
		GM->pl->gun1 = move(gun);
		gun = move(temp);
		/*GunManager.push_back(gun);*/
		gun->col->SetWorldPosX(GM->pl->col->GetWorldPos().x);
		gun->col->SetWorldPosY(GM->pl->col->GetWorldPos().y);

		gun->isEquip = false;
		GM->pl->gun1->isEquip = true;
		
		
	}

	
	
}

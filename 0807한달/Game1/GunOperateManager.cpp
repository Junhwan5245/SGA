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
		ImGui::Text("gun LocationX %f", (*it)->col->GetWorldPos().x);
		ImGui::Text("gun LocationY%f", (*it)->col->GetWorldPos().y);

		if ((*it)->col->Intersect(GM->pl->col))
		{
			if (INPUT->KeyDown('E'))
			{
				SwapItem(*it);
				return;
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
		GM->pl->gun1 = gun;
		gun = temp;
		GunManager.push_back(gun);
		gun->col->SetWorldPosX(GM->pl->col->GetWorldPos().x);
		gun->col->SetWorldPosY(GM->pl->col->GetWorldPos().y);
	}

	
	
}

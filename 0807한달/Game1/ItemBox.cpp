#include "stdafx.h"
#include "Player.h"
#include "Item.h"
#include "Gun.h"
#include "Revolver.h"
#include "Shotgun.h"
#include "CrossBow.h"
#include "HealItem.h"
#include "GunItem.h"
#include "BulletItem.h"
#include "ItemBox.h"

ItemBox::ItemBox()
{
	col = new ObRect();
	col->isFilled = false;
	
	ItemBoxClose = nullptr;
	ItemBoxOpen = nullptr;
	/*if (ItemNum == 1)
	{
		ItemBoxClose = new ObImage(L"HealItemBox.png");
		ItemBoxOpen = new ObImage(L"HealItemBoxOpen.png");
	}
	else if (ItemNum ==2)
	{
		ItemBoxClose = new ObImage(L"BulletItemBox.png");
		ItemBoxOpen = new ObImage(L"BulletItemBoxOpen.png");
	}
	else
	{
		ItemBoxClose = new ObImage(L"GunItemBox.png");
		ItemBoxOpen = new ObImage(L"GunItemBoxOpen.png");
	}*/
	
	

}

ItemBox::~ItemBox()
{
	delete col;
	delete ItemBoxClose;
	delete ItemBoxOpen;
}

void ItemBox::Init()
{
	ItemBoxClose->maxFrame.x = 7;
	ItemBoxOpen->maxFrame.x = 1;
	ItemBoxClose->scale.x = ItemBoxClose->imageSize.x / ItemBoxClose->maxFrame.x * 3;
	ItemBoxClose->scale.y = ItemBoxClose->imageSize.y * 3;
	ItemBoxOpen->scale.x = ItemBoxOpen->imageSize.x * 3;
	ItemBoxOpen->scale.y = ItemBoxOpen->imageSize.y * 3;
	col->scale.x = 50;
	col->scale.y = 50;
	ItemBoxClose->SetParentRT(*col);
	ItemBoxOpen->SetParentRT(*col);
	boxState = ItemBoxState::ClOSE;
}

void ItemBox::Update()
{
	ImGui::Text("BoxState %d", boxState);
	
	
	
	if (boxState == ItemBoxState::ClOSE)
	{
		ItemBoxClose->ChangeAnim(ANIMSTATE::LOOP, 0.1);
		if (col->Intersect(GM->pl->col))
		{
			if (INPUT->KeyDown('E'))
			{
				boxState = ItemBoxState::OPEN;
				isOpen = true;
			}
		}
	}
	else if (boxState == ItemBoxState::OPEN)
	{
		if(isOpen)
		CreateItem();
		
		isOpen = false;
	}
	
	

	col->Update();
	ItemBoxClose->Update();
	ItemBoxOpen->Update();
	
	
	
}

void ItemBox::LateUpdate()
{
}

void ItemBox::Render()
{
	col->Render();

	if (boxState == ItemBoxState::ClOSE)
	ItemBoxClose->Render();
	if (boxState == ItemBoxState::OPEN)
	{
		ItemBoxOpen->Render();
		
	}
}

void ItemBox::CreateItem()
{
}

/*if (isOpen)
		{
			Item* item=nullptr;

			if (ItemNum == 1)
			{
				item = new HealItem();
				item->col->SetWorldPos(col->GetWorldPos());
				GM->ItemManager.push_back(item);

			}
			else if (ItemNum == 2)
			{
				item = new BulletItem();
				item->col->SetWorldPos(col->GetWorldPos());
				GM->ItemManager.push_back(item);

			}
			else
			{

				int gunNum = RANDOM->Int(1, 3);

				if (gunNum == 1)
				{
					gun = new Revolver();

				}
				else if (gunNum == 2)
				{
					gun = new Shotgun();
				}
				else
				{
					gun = new CrossBow();

				}


				gun->col->SetWorldPos(col->GetWorldPos());
				GM->GunManager.push_back(gun);


			}

			isOpen = false;

		}*/
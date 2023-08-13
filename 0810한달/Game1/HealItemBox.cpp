#include "stdafx.h"
#include "Item.h"
#include "ItemBox.h"
#include "HealItem.h"
#include "HealItemBox.h"

HealItemBox::HealItemBox()
{
	ItemBoxClose = new ObImage(L"HealItemBox.png");
	ItemBoxOpen = new ObImage(L"HealItemBoxOpen.png");
}

HealItemBox::~HealItemBox()
{
}


void HealItemBox::Update()
{
	ItemBox::Update();
}

void HealItemBox::Render()
{
	ItemBox::Render();
}

void HealItemBox::CreateItem()
{
	Item* item = new HealItem();
	item->col->SetWorldPos(col->GetWorldPos());
	GM->ItemManager.push_back(item);
}

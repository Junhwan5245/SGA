#include "stdafx.h"
#include "ItemBox.h"
#include "Item.h"
#include "BulletItem.h"
#include "BulletItemBox.h"

BulletItemBox::BulletItemBox()
{
	ItemBoxClose = new ObImage(L"BulletItemBox.png");
	ItemBoxOpen = new ObImage(L"BulletItemBoxOpen.png");
}

BulletItemBox::~BulletItemBox()
{
}

void BulletItemBox::Update()
{
	ItemBox::Update();
}

void BulletItemBox::Render()
{
	ItemBox::Render();
}

void BulletItemBox::CreateItem()
{
	Item*item = new BulletItem();
	item->col->SetWorldPos(col->GetWorldPos());
	GM->ItemManager.push_back(item);
}

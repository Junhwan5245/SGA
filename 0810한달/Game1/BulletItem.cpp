#include "stdafx.h"
#include "Player.h"
#include "Item.h"
#include "Item.h"
#include "Player.h"
#include "Gun.h"
#include "BulletItem.h"

BulletItem::BulletItem()
{
	ItemImg = new ObImage(L"AmmoItem.png");
	ItemImg->maxFrame.x = 7;
	ItemImg->scale.x = ItemImg->imageSize.x / ItemImg->maxFrame.x * 3;
	ItemImg->scale.y = ItemImg->imageSize.y * 3;
	ItemImg->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	ItemImg->SetParentRT(*col);
}

//BulletItem::BulletItem(const BulletItem& other)
//{
//	// ���� ���縦 ���� ���ο� ��ü ���� �� ������ ����
//	col = new ObRect(*other.col);
//	ItemImg = new ObImage(*other.ItemImg);
//	ItemImg->maxFrame.x = other.ItemImg->maxFrame.x;
//	ItemImg->scale.x = other.ItemImg->scale.x;
//	ItemImg->scale.y = other.ItemImg->scale.y;
//	ItemNum = other.ItemNum;
//	ItemImg->SetParentRT(*col);
//}


BulletItem::~BulletItem()
{
}

void BulletItem::Init()
{
}

void BulletItem::ApplyItem()
{
	if (GM->pl->gun1->currentBullet + 20 <= GM->pl->gun1->maxBullet)
		GM->pl->gun1->currentBullet += 20;
	else
		GM->pl->gun1->currentBullet = GM->pl->gun1->maxBullet;
}

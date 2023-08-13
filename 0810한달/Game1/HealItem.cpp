#include "stdafx.h"
#include "Item.h"
#include "Player.h"
#include "HealItem.h"

HealItem::HealItem()
{
	ItemImg = new ObImage(L"HealItem.png");
	ItemImg->maxFrame.x = 7;
	ItemImg->scale.x = ItemImg->imageSize.x / ItemImg->maxFrame.x * 3;
	ItemImg->scale.y = ItemImg->imageSize.y*3;
	ItemImg->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	ItemImg->SetParentRT(*col);
}

//HealItem::HealItem(const HealItem& other)
//{
//	// 깊은 복사를 위해 새로운 객체 생성 후 데이터 복사
//	col = new ObRect(*other.col);
//	ItemImg = new ObImage(*other.ItemImg);
//	ItemImg->maxFrame.x = other.ItemImg->maxFrame.x;
//	ItemImg->scale.x = other.ItemImg->scale.x;
//	ItemImg->scale.y = other.ItemImg->scale.y;
//	ItemNum = other.ItemNum;
//	ItemImg->SetParentRT(*col);
//}
HealItem::~HealItem()
{
}

void HealItem::ApplyItem()
{
	if(GM->pl->Hp+2<=8)
	GM->pl->Hp += 2;
	
	else if(GM->pl->Hp + 1 == 8)
	GM->pl->Hp += 1;
}

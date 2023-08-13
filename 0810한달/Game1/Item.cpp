#include "stdafx.h"
#include "Player.h"
#include "Item.h"

Item::Item()
{
	col = new ObRect();
	ItemImg = nullptr;
	/*ItemImg = new ObImage(L"HealItem.png");
	ItemImg->maxFrame.x = 7;
	ItemImg->scale.x = ItemImg->imageSize.x / ItemImg->maxFrame.x * 3;
	ItemImg->scale.y = ItemImg->imageSize.y * 3;
	ItemImg->ChangeAnim(ANIMSTATE::LOOP, 0.1);*/
	col->isFilled = false;
	col->scale.x = 30;
	col->scale.y = 30;
	isUsed = false;
}

//Item::Item(const Item& other)
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

Item::~Item()
{
	delete col;
	delete ItemImg;
}

void Item::Init()
{
	
	
	
}

void Item::Update()
{
	
	col->Update();

	if (col->Intersect(GM->pl->col))
	{
		if (INPUT->KeyDown('E'))
		{
			isUsed = true;
			ApplyItem();
			
		}
	}


	ItemImg->Update();

	
}


void Item::Render()
{
	col->Render();
	ItemImg->Render();
}

void Item::ApplyItem()
{
	
}

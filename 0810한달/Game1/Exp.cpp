#include "stdafx.h"
#include "Item.h"
#include "Player.h"
#include "Exp.h"

Exp::Exp()
{
	col->scale.x = 50;
	col->scale.y = 50;
	ItemImg = new ObImage(L"Exp.png");
	ItemImg->maxFrame.x = 7;
	ItemImg->scale.x = ItemImg->imageSize.x / ItemImg->maxFrame.x * 3;
	ItemImg->scale.y = ItemImg->imageSize.y * 3;
	ItemImg->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	ItemImg->SetParentRT(*col);
}

Exp::~Exp()
{
}

void Exp::Init()
{
	
}

void Exp::Update()
{
	if (col->Intersect(GM->pl->col))
	{
		isUsed = true;
		ApplyItem();		
	}

	col->Update();
	ItemImg->Update();
}



void Exp::ApplyItem()
{
	GM->pl->exp += 10;
}

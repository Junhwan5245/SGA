#include"stdafx.h"
#include "Player.h"
#include "Item.h"
#include "Gun.h"
#include "Revolver.h"
#include "Shotgun.h"
#include "CrossBow.h"
#include "GunItem.h"

GunItem::GunItem()
{
	
	gunNum = RANDOM->Int(1, 3);
	
	if (gunNum == 1)
	{
		ItemImg = new ObImage(L"Revolver.png");
	}
	else if (gunNum == 2)
	{
		ItemImg = new ObImage(L"Shotgun.png");
	}
	else
	{
		ItemImg = new ObImage(L"Crossbow.png");
		
	}

	ItemImg->scale.x = ItemImg->imageSize.x;
	ItemImg->scale.y = ItemImg->imageSize.y;
}

GunItem::~GunItem()
{
}

void GunItem::ApplyItem()
{
	

	if (gunNum == 1)
	{
		gunitem = new Revolver();
	}
	else if (gunNum == 2)
	{
		gunitem = new Shotgun();
	}

	else 
	{
		gunitem = new CrossBow();
	}
	
	

}



#include "stdafx.h"
#include "GunOperateManager.h"
#include "Gun.h"
#include "Player.h"
#include "ItemBox.h"
#include "Revolver.h"
#include "ShotGun.h"
#include "CrossBow.h"
#include "GunItemBox.h"


GunItemBox::GunItemBox()
{
	ItemBoxClose = new ObImage(L"GunItemBox.png");
	ItemBoxOpen = new ObImage(L"GunItemBoxOpen.png");
}

GunItemBox::~GunItemBox()
{
}


void GunItemBox::Update()
{
	ItemBox::Update();
}


void GunItemBox::Render()
{
	ItemBox::Render();
}

void GunItemBox::CreateItem()
{
	int gunNum = RANDOM->Int(1, 3);
	Gun* gun;

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
	GM->GunOpreateManager->GunManager.push_back(gun);
}

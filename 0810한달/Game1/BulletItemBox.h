#pragma once
class BulletItemBox :public ItemBox
{
public:
	BulletItemBox();
	virtual ~BulletItemBox();
	virtual void Update();
	virtual void Render();
	virtual void CreateItem();
};


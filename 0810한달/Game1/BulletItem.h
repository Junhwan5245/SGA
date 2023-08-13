#pragma once
class BulletItem:public Item
{
public:
	BulletItem();
	/*BulletItem(const BulletItem& other);*/
	virtual ~BulletItem();
	void Init();
	void ApplyItem() override;

};


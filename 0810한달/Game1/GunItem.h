#pragma once
class GunItem : public Item
{
public:
	Gun* gunitem;
	int gunNum;
	GunItem();
	~GunItem();
	void ApplyItem() override;
	void Swap();
};


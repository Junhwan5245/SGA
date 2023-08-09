#pragma once
class HealItem : public Item
{
public:
	HealItem();
	/*HealItem(const HealItem& other);*/
	 ~HealItem();
	void ApplyItem() override;
};


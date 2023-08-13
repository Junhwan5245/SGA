#pragma once
class HealItemBox : public ItemBox
{
public:
	HealItemBox();
	virtual ~HealItemBox();
	virtual void Update();
	virtual void Render();
	virtual void CreateItem() override;
};


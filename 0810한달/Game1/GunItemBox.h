#pragma once
class GunItemBox : public ItemBox
{
public:
	GunItemBox();
	virtual ~GunItemBox();
	virtual void Update() override;
	virtual void Render() override;
	void CreateItem() override;
};


#pragma once
enum class ItemBoxState
{
	ClOSE,
	OPEN
};

class ItemBox
{
protected:



	ItemBoxState boxState;

public:
	ObImage* ItemBoxClose;
	ObImage* ItemBoxOpen;
	ObRect* col;
	bool isOpen;

	ItemBox();
	virtual ~ItemBox();
	virtual void Init();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();
	virtual void CreateItem();

};


#pragma once
class DessertMon1:public Monster
{
public:
	

	DessertMon1();
	virtual ~DessertMon1();
	void Init() override;
	void Update()override;
	void Render()override;
	void Move(Vector2 TargetPos) override;
	
};


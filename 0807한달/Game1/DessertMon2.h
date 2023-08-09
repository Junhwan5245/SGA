#pragma once
class DessertMon2 :public Monster
{
public:

	
	

	DessertMon2();
	virtual ~DessertMon2();
	void Init() override;
	void Update()override;
	void Render()override;
	void Move(Vector2 TargetPos) override;

};


#pragma once
class BigDog : public Boss
{
public:
	
	BigDog();
	virtual ~BigDog();
	void Init() override;
	void Update()override;
	void Render()override;
	void Move(Vector2 TargetPos) override;
};


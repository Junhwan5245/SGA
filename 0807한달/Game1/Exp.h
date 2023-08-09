#pragma once
class Exp : public Item
{
public:
	
	
	Exp();
	virtual ~Exp();
	void Update() override;
	void Init();
    void ApplyItem() override;

	
};


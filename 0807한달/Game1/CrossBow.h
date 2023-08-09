#pragma once
class CrossBow : public Gun
{
private:

public:
	CrossBow();
	~CrossBow();
	void Update() override;
	void Render() override;
	void Fire()	  override;

};


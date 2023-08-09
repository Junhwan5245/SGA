#pragma once
class Shotgun:public Gun
{
private:

public:
	Shotgun();
	~Shotgun();
	void Update() override;
	void Render() override;
	void Fire()	  override;
};


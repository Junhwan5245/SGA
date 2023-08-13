#pragma once
class Revolver: public Gun
{

private:

public:
	Revolver();
	~Revolver();
	void Update() override;
	void Render() override;
	void Fire()	  override;
};


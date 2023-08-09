#pragma once
class Crystal: public Player
{
private:
	


public:
	Crystal();
	virtual ~Crystal();
	void Init(Vector2 spawn);
	void Update() override;
	void Render() override;

};




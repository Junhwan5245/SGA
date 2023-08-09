#pragma once
class Fish : public Player
{
private:
	
	

public:
	Fish();
	virtual ~Fish();
	void Init(Vector2 spawn);
	void Update() override;
	void Render() override;

};


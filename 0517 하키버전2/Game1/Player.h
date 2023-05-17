#pragma once
class Player : public ObCircle
{
	class Bullet* bullet[30];

	//시계프레임
	
	float pressPower;
public:
	Player();
	virtual ~Player();
	void Init(Vector2 spawn);
	void Control();
	void Update() override;
	void Render() override;
	bool isPlayer0;
	int score=0;
	Bullet* GetBullet(int i) const { return bullet[i]; }
	bool Touch(GameObject* target);
	//const Bullet** GetBullet() { return bullet; }
};


#pragma once
class BigDogBullet :public Bullet
{
public:

	BigDogBullet();
	BigDogBullet(GameObject* gun, Vector2 dir);
	virtual ~BigDogBullet();
	void Update() override;
	void Render() override;
};


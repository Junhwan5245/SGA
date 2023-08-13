#pragma once
class BigDogBullet2:public Bullet
{
public:

	BigDogBullet2();
	BigDogBullet2(GameObject* gun, Vector2 dir);
	virtual ~BigDogBullet2();
	void Update() override;
	void Render() override;

};


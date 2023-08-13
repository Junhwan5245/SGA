#pragma once
class ShotgunBullet : public Bullet
{
public:

	ShotgunBullet();
	ShotgunBullet(GameObject* gun, Vector2 dir);
	virtual ~ShotgunBullet();

};


#pragma once
class CrossBowBullet:public Bullet
{
public:

	CrossBowBullet();
	CrossBowBullet(GameObject* gun, Vector2 dir);
	virtual ~CrossBowBullet();
};


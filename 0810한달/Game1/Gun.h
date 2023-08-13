#pragma once
class Gun 
{
protected:
	Vector2 lookDir;
	
	float	fireSpeed;
	
	
	
	
public:
	int currentBullet;
	int maxBullet;
	ObImage* gunImg;
	ObRect* col;
	bool isEquip;
	/*int		damage;*/
	vector <class Bullet*> bullets;
	Gun();
	virtual ~Gun();
	virtual void Init();
	virtual void Fire();
	virtual void Update();
	virtual void Render();
	
	
	/*virtual void BulletColWithMon(class Monster* monster);*/

	/*bool GetIsFire() { return isFire; }
	void Release() { isFire = false; }*/

};


#pragma once
class Bullet : public ObRect
{
protected:
	
	
	Vector2   fireDir;
	// ฝ๎ดย ศ๛
	
	ObImage* bulletImg;
	float	  bulletSpeed;

	
public:
	
	int		damage;
	bool      isFire;
	Bullet();
	Bullet(GameObject* gun, Vector2 dir) ;
	virtual ~Bullet();
	void Fire(GameObject* gun, Vector2 dir);
	virtual void Update() override;

	virtual void Render() override;
	bool Touch(GameObject* target);

	bool GetIsFire() { return isFire; }
	void Release() { isFire = false; }
	virtual void BulletColWithMon();

	void ReflectionY()
	{
		fireDir.x = -fireDir.x; 
		/*fireDir=
			Vector2(cosf(rotation.z), sinf(rotation.z));
		rotation.z = atan2f(fireDir.y, -fireDir.x);*/
	}
	void ReflectionX()
	{
		fireDir.y = -fireDir.y; 
		/*fireDir=
			Vector2(cosf(rotation.z), sinf(rotation.z));
		rotation.z = atan2f(-fireDir.y, fireDir.x);*/
	}

};


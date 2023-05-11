#pragma once
class Bullet : public ObRect
{
private:
	bool      isFire;
	Vector2   fireDir;
	float     pressPower;
	float		lifeTime;
	float	  bulletInterval;
	//ObRect* gauge;
public:
	Bullet();
	virtual ~Bullet();
	void Fire(GameObject* shooter, GameObject* player,float pressPower);
	void Update() override;
	void Render() override;
	bool GetIsFire() { return isFire; }
	
	void ReflectionY() 
	{ 
		//fireDir.x = -fireDir.x; 
		Vector2 dir =
			Vector2(cosf(rotation.z), sinf(rotation.z));
		rotation.z = atan2f(dir.y, -dir.x);
	}
	void ReflectionX() 
	{ 
		//fireDir.y = -fireDir.y; 
		Vector2 dir =
			Vector2(cosf(rotation.z), sinf(rotation.z));
		rotation.z = atan2f(-dir.y, dir.x);
	}
};


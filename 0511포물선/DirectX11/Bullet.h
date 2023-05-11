#pragma once
class Bullet : public ObRect
{
private:
	bool      isFire;
	Vector2   fireDir;
	
	
	float     pressPower;
public:
	Bullet();
	virtual ~Bullet();
	void Fire(GameObject* shooter,float pressPower);
	void Update() override;
	void Render() override;
	bool GetIsFire() { return isFire; }
	Vector2	 velocity;
	Vector2 gravity;
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


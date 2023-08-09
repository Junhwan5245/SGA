#pragma once
enum class PlayerState
{
	IDLE,
	WALK,
	HURT,
	ABILITY,
	DEAD
	//DAMAGE
};

class Player 
{
	

protected:
	
	
	ObImage*	walk;
	ObImage*	idle;
	ObImage*	hurt;
	ObImage*	ability;
	ObImage*	dead;
	float		speed;
	Vector2		dir;
	Vector2		dir2;
	
	int Frame[8];
	float abilityTime;
	float hurtTime;
	Vector2 lastPos;
	

	

	
	//시계프레임
public:
	
	int exp;
	int expLevel;
	int maxHp;
	int Hp;
	PlayerState state;
	class Gun* gun1;
	class Gun* gun2;
	int gunNum=0;
	ObRect* col;
	Player();
	~Player();
	virtual void Init(Vector2 spawn);
	virtual void Control();
	virtual void Update();
	virtual void Render();
	void LookTarget(Vector2 target);
	Vector2 GetFoot();
	void GoBack();
	void SwapGun();
	
};


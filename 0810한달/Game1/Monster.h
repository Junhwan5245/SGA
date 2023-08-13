#pragma once
enum class MonsterState
{
	IDLE,
	WALK,
	HURT,
	ATTACK,
	DEAD

};

class Monster
{
protected:
	
	ObCircle* range1;
	ObCircle* range2;
	ObImage* mIdle;
	ObImage* mWalk;
	ObImage* mHurt;
	ObImage* mAttack;
	
	Vector2 moveDir;
	Vector2 target;
	float  moveSpeed;
	

public:
	int mExpNum;
	vector<class Tile*> way;
	vector <class Bullet*> monbullets;
	ObRect* col;
	int		mHp;
	ObImage* mDead;
	MonsterState mState;
	bool isFinished;
	Monster();
	virtual ~Monster();
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Move(Vector2 TargetPos);
	virtual void Release();
	virtual void LookTarget(Vector2 target);
	virtual void Spread();
	
	
};


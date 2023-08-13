#pragma once

enum class BossState
{
	SLEEP,
	IDLE,
	WALK,
	HURT,
	ATTACK,
	ATTACK2,
	DEAD

};

class Boss 
{
protected:

	ObCircle* range1;
	ObCircle* range2;
	ObCircle* range3;
	ObImage* bSleep;
	ObImage* bIdle;
	ObImage* bWalk;
	ObImage* bAttack;
	ObImage* bAttack2;
	ObImage* bPortrait;
	ObImage* bBossNameEffect;
	ObImage* bBossName;

	Vector2 moveDir;
	Vector2 target;
	float  moveSpeed;
	SYSTEMTIME time;

public:
	bool	isBossInit;
	float	hurtTime;
	int		mExpNum;
	vector<class Tile*> way;
	vector <class Bullet*> bossbullets;
	ObRect* col;
	int		bHp;
	ObImage* bDead;
	BossState bState;
	bool isSleep;
	bool isFinished;
	Boss();
	virtual ~Boss();
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Move(Vector2 TargetPos);
	virtual void Release();
	virtual void LookTarget(Vector2 target);
	


};


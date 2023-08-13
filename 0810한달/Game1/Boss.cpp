#include "stdafx.h"
#include "Player.h"
#include "Boss.h"
float Speed = 500;
Boss::Boss()
{
	col = new ObRect();
	range1 = new ObCircle();
	range2 = new ObCircle();
	range3 = new ObCircle();
	bSleep = nullptr;
	bIdle = nullptr;
	bWalk = nullptr;
	bAttack = nullptr;
	bDead = nullptr;
	bBossName = nullptr;
	bBossNameEffect = nullptr;
	bPortrait = nullptr;
	col->isFilled = false;
	range1->isFilled = false;
	range2->isFilled = false;
	range3->isFilled = false;
	isFinished = false;
}

Boss::~Boss()
{
	delete	bSleep;
	delete  bIdle;
	delete 	bWalk;
	delete 	bAttack;
	delete  bDead;
	delete  col;
	delete  range1;
	delete  range2;
	delete  range3;
}

void Boss::Init()
{
	range1->scale.x = 600;
	range1->scale.y = 600;
	range2->scale.x = 900;
	range2->scale.y = 900;
	range3->scale.x = 2000;
	range3->scale.y = 2000;
	col->scale.x = bIdle->imageSize.x / bIdle->maxFrame.x;
	col->scale.y = bIdle->imageSize.y;
	bState = BossState::SLEEP;
	range1->SetParentRT(*col);
	range2->SetParentRT(*col);
	range3->SetParentRT(*col);
	bSleep->SetParentRT(*col);
	bIdle->SetParentRT(*col);
	bWalk->SetParentRT(*col);
	bAttack->SetParentRT(*col);
	bDead->SetParentRT(*col);
	
	
}

void Boss::Update()
{
	ImGui::Text("BossHp : %d", bHp);
	ImGui::Text("BossState : %d", bState);

	if (bHp <= 0)
	{
		bState = BossState::DEAD;
		/*return;*/
	}
	
	if (bState == BossState::SLEEP)
	{
		
		
		bSleep->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		if (range3->Intersect(GM->pl->col))
		{
			
			bState = BossState::IDLE;
			bIdle->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		}
	}
	
	//idle->walk
	if (bState == BossState::IDLE)
	{
		LookTarget(GM->pl->col->GetWorldPos());
		bIdle->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		if (range2->Intersect(GM->pl->col))
		{
			bState = BossState::WALK;
			bWalk->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		}

	}
	//walk->attack
	else if (bState == BossState::WALK)
	{
		LookTarget(GM->pl->col->GetWorldPos());
		col->MoveWorldPos(moveDir * moveSpeed * DELTA);

		if (range1->Intersect(GM->pl->col))
		{
			bState = BossState::ATTACK;
			bAttack->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
		}

		else if (range2->Intersect(GM->pl->col))
		{
			bState = BossState::WALK;
		}

		else
		{
			bState = BossState::IDLE;
		}
	}

	else if (bState == BossState::ATTACK)
	{
		
		LookTarget(GM->pl->col->GetWorldPos());
		if (bAttack->isAniStop())
		{
			bState = BossState::ATTACK2;
		}
	}
	else if (bState == BossState::ATTACK2)
	{
		LookTarget(GM->pl->col->GetWorldPos());
		bWalk->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		static float attackTime = 5.0f;
		attackTime -=DELTA;
		if (attackTime < 0)
		{
			bState = BossState::IDLE;
			attackTime = 5.0f;
		}
		
	}


	else if (bState == BossState::DEAD)
	{
		static float deadTime = 0.0f;
		static int   temp = 0;


		if (temp == 0)
		{
			bDead->ChangeAnim(ANIMSTATE::ONCE, 0.2f);
			temp++;
		}
		if (bDead->isAniStop())
		{
			deadTime += DELTA;
			if (deadTime > 3.0)
			{
				isFinished = true;
			}

		}
	}
	
	if (hurtTime>0)
	{
		LookTarget(GM->pl->col->GetWorldPos());
		bIdle->color = Color(1, 1, 1,0.5);
		bWalk->color = Color(1, 1, 1,0.5);
		bAttack->color = Color(1, 1, 1,0.5);

		hurtTime -= DELTA;

	}
	else
	{
		bIdle->color = Color(0.5, 0.5, 0.5,0.5);
		bWalk->color = Color(0.5, 0.5, 0.5,0.5);
		bAttack->color = Color(0.5, 0.5, 0.5,0.5);
		
	}

	

	bSleep->Update();
	bIdle->Update();
	bWalk->Update();
	
	bAttack->Update();
	bDead->Update();


	col->Update();
	range1->Update();
	range2->Update();
	range3->Update();
	

}

void Boss::Render()
{
	switch (bState)
	{
	case BossState::SLEEP:
		bSleep->Render();
		break;
	case BossState::IDLE:
		bIdle->Render();
		break;
	case BossState::WALK:
		bWalk->Render();
		break;
	case BossState::ATTACK:
		bAttack->Render();
		break;
	case BossState::ATTACK2:
		bWalk->Render();
		break;
	case BossState::DEAD:
		bDead->Render();
		break;
	}

	range3->Render();

	bPortrait->Update();
}

void Boss::Move(Vector2 TargetPos)
{
	target = TargetPos;
	moveDir = target - col->GetWorldPos();
	moveDir.Normalize();
}

void Boss::Release()
{
}

void Boss::LookTarget(Vector2 target)
{
	if (target.x < col->GetWorldPos().x)
	{
		// 왼쪽을 바라보는 경우

		bIdle->rotation.y = PI;
		bWalk->rotation.y = PI;
		/*bHurt->rotation.y = PI;*/
		bAttack->rotation.y = PI;
		bDead->rotation.y = PI;
	}
	else
	{
		bIdle->rotation.y = 0;
		bWalk->rotation.y = 0;
		/*bHurt->rotation.y = 0;*/
		bAttack->rotation.y = 0;
		bDead->rotation.y = 0;
	}
}



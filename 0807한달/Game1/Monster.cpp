#include "stdafx.h"
#include "Player.h"
#include "Monster.h"





Monster::Monster()
{
	col = new ObRect();
	range1 = new ObCircle();
	range2 = new ObCircle();
	mIdle = nullptr;
	mWalk = nullptr;
	mHurt = nullptr;
	mAttack = nullptr;
	mDead = nullptr;
	col->isFilled = false;
	range1->isFilled = false;
	range2->isFilled = false;
	isFinished = false;
}

Monster::~Monster()
{
	delete  mIdle;
	delete 	mWalk;
	delete 	mHurt;
	delete 	mAttack;
	delete  mDead;
	delete  col;
	delete  range1;
	delete  range2;

}

void Monster::Init()
{
	range1->scale.x = 500;
	range1->scale.y = 500;
	range2->scale.x = 800;
	range2->scale.y = 800;
	col->scale.x = mIdle->imageSize.x/mIdle->maxFrame.x;
	col->scale.y = mIdle->imageSize.y;
	mState = MonsterState::IDLE;
	range1->SetParentRT(*col);
	range2->SetParentRT(*col);
	mIdle->SetParentRT(*col);
	mWalk->SetParentRT(*col);
	mHurt->SetParentRT(*col);
	mAttack->SetParentRT(*col);
	mDead->SetParentRT(*col);
	
}


void Monster::Update()
{
	ImGui::Text("MonlocationX : %f", col->GetWorldPos().x);
	ImGui::Text("MonlocationY : %f",col->GetWorldPos().y);
	ImGui::Text("M1state, %d", mState);
	ImGui::Text("M1Hp, %d", mHp);
	
	
	if (mHp <= 0)
	{
		mState = MonsterState::DEAD;
		/*return;*/
	}
	

	//idle->walk
	if (mState == MonsterState::IDLE)
	{
		mIdle->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		if (range2->Intersect(GM->pl->col))
		{
			mState = MonsterState::WALK;
			mWalk->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		}

	}
	//walk->attack
	else if (mState == MonsterState::WALK)
	{
		col->MoveWorldPos(moveDir * moveSpeed * DELTA);

		if (range1->Intersect(GM->pl->col))
		{
			mState = MonsterState::ATTACK;
			mAttack->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
		}

		else if (range2->Intersect(GM->pl->col))
		{
			mState = MonsterState::WALK;
		}

		else
		{
			mState = MonsterState::IDLE;
		}
	}

	else if (mState == MonsterState::ATTACK)
	{
		if (mAttack->isAniStop())
		{
			mState = MonsterState::IDLE;
		}
	}

	else if (mState == MonsterState::HURT)
	{
		static float hurtTime = 0.4f;
		mHurt->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		
		hurtTime -= DELTA;

		if (hurtTime <= 0)
		{
			mState = MonsterState::IDLE;
			hurtTime = 0.4f;
		}
		
	}


	else if (mState == MonsterState::DEAD)
	{
		static float deadTime = 0.0f;
		static int   temp=0;
		

		if (temp==0)
		{
			mDead->ChangeAnim(ANIMSTATE::ONCE, 0.2f);
			temp++;
		}
		if (mDead->isAniStop())
		{
			deadTime += DELTA;
			if (deadTime >3.0)
			{
				isFinished = true;
			}

		}
	}

	
	
	
		mIdle->Update();
		mWalk->Update();
		mHurt->Update();
		mAttack->Update();
		mDead->Update();


		col->Update();
		range1->Update();
		range2->Update();
	
	
}

void Monster::Render()
{
	//if (mHp <= 0)
	//{/*
	//	static float deadTime = 0.6f;
	//	mDead->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	//	deadTime -= DELTA;

	//	if (deadTime <= 0)*/
	//	return;
	//}
	
	
	switch (mState)
	{
	case MonsterState::IDLE:
		mIdle->Render();
		break;
	case MonsterState::WALK:
		mWalk->Render();
		break;
	case MonsterState::HURT:
		mHurt->Render();
		break;
	case MonsterState::ATTACK:
		mAttack->Render();
		break;
	case MonsterState::DEAD:
		mDead->Render();
		break;
	}

		
		
		col->Render();
		range1->Render();
		range2->Render();

	
}

void Monster::Move(Vector2 TargetPos)
{
	target = TargetPos;
	moveDir = target - col->GetWorldPos();
	moveDir.Normalize();
}

void Monster::Release()
{
	delete col;
}





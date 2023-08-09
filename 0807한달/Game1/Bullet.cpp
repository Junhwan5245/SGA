#include "stdafx.h"
#include "Monster.h"
#include "Gun.h"
#include "Bullet.h"

Bullet::Bullet()
{
   
}
Bullet::Bullet(GameObject* gun, Vector2 dir)
{
    scale.x = 20.0f;
    scale.y = 20.0f;
    isFire = true;
    pivot = OFFSET_L;
    fireDir = dir;
    SetWorldPos(gun->GetWorldPos());
    isFilled = false;
    bulletImg = nullptr;
}

Bullet::~Bullet()
{
    delete bulletImg;
    cout << "총알정보삭제" << endl;
}

//void Bullet::Fire(GameObject* gun,Vector2 dir)
//{
//    fireDir = dir;
//   
//    isFire = true;
//    
//    SetWorldPos(gun->GetWorldPos());
//
//
//    
//    //rotation.z = atan2f(shooter->GetRight().y, shooter->GetRight().x);
//}


void Bullet::Update()
{
    ImGui::Text("locationBulletX %f", GetWorldPos().x);
    ImGui::Text("locationBulletY %f", GetWorldPos().y);

   
   


   rotation.z = atan2f(fireDir.y, fireDir.x);
    
    ObRect::Update();
    bulletImg->Update();
    
    MoveWorldPos(fireDir * bulletSpeed * DELTA);
    
}



void Bullet::Render()
{


    ObRect::Render();
    bulletImg->Render();
}

bool Bullet::Touch(GameObject* target)
{
    if ((GetWorldPos() - target->GetWorldPos()).Length() <
        7 + target->scale.x * 0.5f)
    {
        return true;
    }

    return false;
}

void Bullet::BulletColWithMon()
{
    for (vector<Monster*>::iterator it = GM->monster.begin(); it != GM->monster.end(); it++)
	{
		if ((*it)->col->Intersect(this))
		{
            (*it)->mHp -= damage;
		}
	}

    
}

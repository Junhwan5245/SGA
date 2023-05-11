#include "framework.h"
#include "Bullet.h"



Bullet::Bullet()
{
    scale.x = 20.0f;
    scale.y = 20.0f;
    isFire = false;
    pivot = OFFSET_L;
    Vector2 gravity = Vector2(0, -20.0f);
}

Bullet::~Bullet()
{
}

void Bullet::Fire(GameObject* shooter, float pressPower)
{
    scale.x = 0.1f*pressPower;
    scale.y = scale.x;
    this->pressPower = pressPower;
    isFire = true;
    SetWorldPos(shooter->GetWorldPos());
    //fireDir = shooter->GetRight();
    rotation.z = atan2f(shooter->GetRight().y, shooter->GetRight().x);
}

void Bullet::Update()
{
    if (not isFire) return;
    Vector2 gravity = Vector2(0, -20.0f);
    velocity += gravity * DELTA / 5;


    //MoveWorldPos(fireDir * DELTA * pressPower);
    MoveWorldPos(GetRight() * DELTA * pressPower - velocity);//x와 y가 좌표값이니까 빼서 좌표가 나온다

    ObRect::Update();


    //이동후 화면 벗어남 체크
    /*if (0.0f > GetWorldPos().x or GetWorldPos().x > 800.0f or
        0.0f > GetWorldPos().y or GetWorldPos().y > 600.0f)
    {
        isFire = false;
    }*/
}

//void Bullet::Fire(GameObject* shooter, float pressPower)
//{
//    scale.x = pressPower * 0.1f;
//    scale.y = pressPower * 0.1f;
//    this->pressPower = pressPower;
//    isFire = true;
//    SetWorldPos(shooter->GetWorldPos());
//    velocity = shooter->GetRight() * pressPower * 1.0f;//1.0은 초기속도임
//    rotation.z = atan2f(velocity.y, velocity.x);
//}
//
//void Bullet::Update()
//{
//   
//    if (not isFire) return;
//    Vector2 gravity =  Vector2(0, 0.0f);
//    velocity += gravity * DELTA;
//    MoveWorldPos(velocity * DELTA);
//    
//    
//    ObRect::Update();
//}

void Bullet::Render()
{
    if (not isFire) return;

    ObRect::Render();
}
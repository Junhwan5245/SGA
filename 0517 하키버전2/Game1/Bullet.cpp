#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet()
{
    scale.x = 40.0f;
    scale.y = 40.0f;
    pressPower = 500.0f;
}

Bullet::~Bullet()
{
}

void Bullet::Fire(GameObject* shooter, GameObject* target)
{
    scale.x = 30.0f;
    scale.y = scale.x;


    // Calculate the direction vector from shooter to target
    fireDir = target->GetWorldPos() - shooter->GetWorldPos();
    fireDir.Normalize(); // Normalize the direction vector to have a unit length

    // Set the rotation of the bullet based on the direction vector
    rotation.z = atan2f(fireDir.y, fireDir.x);


    //fireDir = shooter->GetRight();
    //rotation.z = atan2f(shooter->GetRight().y, shooter->GetRight().x);
}

//void Bullet::Fire(Vector2 pos, Vector2 dir, float pressPower)
//{
//    lifeTime = 10.0f;
//    scale.x = 20;
//    scale.y = 5;
//    this->pressPower = pressPower;
//    isFire = true;
//    SetWorldPos(pos);
//    //fireDir = shooter->GetRight();
//    rotation.z = atan2f(dir.y, dir.x);
//}

//void Bullet::Drop(Vector2 pos)
//{
//    lifeTime = 30.0f;
//    scale.x = 20;
//    scale.y = 5;
//    isFire = true;
//    SetWorldPos(pos);
//
//    //½î´ÂÈû ³ª¾Æ°¥¹æÇâ
//    this->pressPower = 0.0f;
//    fireDir = Vector2(0, 0);
//
//    gravityDir = DOWN;
//    gravityForce = 0.0f;
//    //rotation.z = atan2f(DOWN.y, DOWN.x);
//}

void Bullet::Update()
{
    Vector2 velocity = (fireDir * pressPower
        );
    MoveWorldPos(velocity * DELTA);


    rotation.z = atan2f(velocity.y, velocity.x);

    ObCircle::Update();

}

void Bullet::Render()
{
   

    ObCircle::Render();
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

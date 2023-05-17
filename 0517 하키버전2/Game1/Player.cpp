#include "stdafx.h"
#include "Bullet.h"
#include "Player.h"

Player::Player()
{

    hasAxis = false;




    scale.x = 800.0f * 0.1f;
    scale.y = 800.0f * 0.1f;




}

Player::~Player()
{
}

void Player::Init(Vector2 spawn)
{
    SetWorldPosX(spawn.x);
    SetWorldPosY(spawn.y);
    


    rotation.y = isPlayer0 ? PI : 0.0f;


}

void Player::Control()
{



    //계속 누를때
    if (isPlayer0)
    {
        // Player0의 이동 방향키 설정
        if (INPUT->KeyPress('W'))
        {
            MoveWorldPos(UP * DELTA * 400);
        }
        if (INPUT->KeyPress('S'))
        {
            MoveWorldPos(DOWN * DELTA * 400);
        }
        if (INPUT->KeyPress('A'))
        {
            MoveWorldPos(LEFT * DELTA * 400);
        }
        if (INPUT->KeyPress('D'))
        {
            MoveWorldPos(RIGHT * DELTA * 400);
        }
    }
    else
    {
        // Player1의 이동 방향키 설정
        if (INPUT->KeyPress(VK_UP))
        {
            MoveWorldPos(UP * DELTA * 400);
        }
        if (INPUT->KeyPress(VK_DOWN))
        {
            MoveWorldPos(DOWN * DELTA * 400);
        }
        if (INPUT->KeyPress(VK_LEFT))
        {
            MoveWorldPos(LEFT * DELTA * 400);
        }
        if (INPUT->KeyPress(VK_RIGHT))
        {
            MoveWorldPos(RIGHT * DELTA * 400);
        }
    }
}

void Player::Update()
{


    ObCircle::Update();
    /*for (int i = 0; i < 30; i++)
    {
        bullet[i]->Update();
    }*/
    
  
}

void Player::Render()
{
    ObCircle::Render();
    
    /*for (int i = 0; i < 30; i++)
    {
        bullet[i]->Render();
    }*/
}


bool Player::Touch(GameObject* target)
{

    if ((GetWorldPos() - target->GetWorldPos()).Length() <
        40 + target->scale.x * 0.5f)
    {
        return true;
    }

    return false;
}

//bool Player::Touch(GameObject* target)
//{
//
//    if ((GetWorldPos() - target->GetWorldPos()).Length() <
//        7 + target->scale.x * 0.5f)
//    {
//        return true;
//    }
//
//    return false;
//}

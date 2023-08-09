#include "stdafx.h"
#include "Gun.h"
#include "Monster.h"
#include "Revolver.h"
#include "Shotgun.h"
#include "Bullet.h"
#include "Player.h"

Player::Player()
{
    col = new ObRect();
   
    
    idle = nullptr;
    walk = nullptr;
    hurt = nullptr;
    ability = nullptr;
    exp = 0;
    expLevel = 1;
  
}

Player::~Player()
{
    delete col;
    delete idle;
    delete walk;
    delete hurt;
    delete ability;
    delete gun1;
    delete gun2;
}

void Player::Init(Vector2 spawn)
{
    col->SetWorldPosX(spawn.x);
    col->SetWorldPosY(spawn.y);
    state = PlayerState::IDLE;
    speed = 200.0f;
    gun1->Init();
   
    gun2->Init();
    
   
   
}


void Player::Control()
{
    dir = Vector2();

    //계속 누를때
    if (INPUT->KeyDown(VK_LBUTTON))
    {
        gun1->Fire();
    }
    if (INPUT->KeyDown(VK_SPACE))
    {
       
       SwapGun();
       
       
    }
    if (INPUT->KeyPress('W'))
    {
        dir.y = 1.0f;
    }
    else if (INPUT->KeyPress('S'))
    {
        dir.y = -1.0f;
    }
    if (INPUT->KeyPress('A'))
    {
        dir.x = -1.0f;
    }
    else if (INPUT->KeyPress('D'))
    {
        dir.x = 1.0f;
    }
   
    dir2 = dir;
    dir.Normalize();

    col->MoveWorldPos(dir * DELTA * speed);
}

void Player::Update()
{
    ImGui::Text("gun1 X,%d", (int)gun1->gunImg->GetWorldPos().x);
    ImGui::Text("gun1 Y,%d", (int)gun1->gunImg->GetWorldPos().y);
    ImGui::Text("gun2 X,%d", (int)gun2->gunImg->GetWorldPos().x);
    ImGui::Text("gun2 Y,%d", (int)gun2->gunImg->GetWorldPos().y);
    ImGui::Text("CurrentAmmo : %d", gun1->currentBullet);
    Vector2 tempDir = INPUT->GetWorldMousePos() - GM->pl->col->GetWorldPos();
    
    int xWeight=0;
    int yWeight=0;

    if (tempDir.x > 0)
    {
        if (tempDir.x > 20) xWeight = 20;            
        else if (tempDir.x > 15) xWeight = 15;       
        else if (tempDir.x > 10) xWeight = 10;      
        else xWeight = 5;       
    }
    else if (tempDir.x < 0)
    {
        if (tempDir.x < -20) xWeight = -20;
        else if (tempDir.x < -15) xWeight = -15;
        else if (tempDir.x < -10) xWeight = -10;
        else xWeight = -5;
    }
    else
    {
        xWeight = 0;
    }

    if (tempDir.y > 0)
    {
        if (tempDir.y > 20) yWeight = 20;
        else if (tempDir.y > 15) yWeight = 15;
        else if (tempDir.y > 10) yWeight = 10;
        else yWeight = 5;
    }
    else if (tempDir.y < 0)
    {
        if (tempDir.y < -20) yWeight = -20;
        else if (tempDir.y < -15) yWeight = -15;
        else if (tempDir.y < -10) yWeight = -10;
        else yWeight = -5;
    }
    else
    {
        yWeight = 0;
    }

   /* gun1->col->SetWorldPosX(col->GetWorldPos().x + (tempDir.x > 0 ? (tempDir.x > 10 ? (tempDir.x > 20 ? 20 : 10) : 0) : (tempDir.x < -10 ? (tempDir.x < -20 ? -20 : -10) : 0)));
    gun1->col->SetWorldPosY(col->GetWorldPos().y + (tempDir.y > 0 ? (tempDir.y > 10 ? (tempDir.y > 20 ? 20 : 10) : 0) : (tempDir.y < -10 ? (tempDir.y < -20 ? -20 : -10) : 0)));*/

   
    gun1->col->SetWorldPosX(col->GetWorldPos().x + xWeight);
    gun1->col->SetWorldPosY(col->GetWorldPos().y + yWeight);
   
    gun1->col->rotation.z = atan2f(tempDir.y, tempDir.x);
    
    ImGui::Text("tempDirX ,%f", tempDir.x);
    ImGui::Text("tempDirY ,%f", tempDir.y);
    ImGui::Text("X ,%f", gun1->col->rotation.x);
    ImGui::Text("Y ,%f", gun1->col->rotation.y);
    ImGui::Text("Z ,%f", gun1->col->rotation.z);
 
    
    if (gun2 != nullptr)
    {
        gun2->col->SetWorldPosX(col->GetWorldPos().x + (tempDir.x > 0 ? -20 : 20));
        gun2->col->SetWorldPosY(col->GetWorldPos().y);

        if (tempDir.x < 0)
        {
           
            gun2->col->rotation.z = -1.75;
            gun2->gunImg->reverseLR =true;
          /* gun2->col->rotation.z = -1.75;
           gun2->gunImg->reverseLR = false;*/
           
        }
        else
        {
            gun2->col->rotation.z = 1.75;
            gun2->gunImg->reverseLR = false;
           

        }
    }
    if (exp >= 200)
    {
        expLevel++;
        exp -= 200;
    }

   Vector2 lookDir = INPUT->GetWorldMousePos() - GM->pl->col->GetWorldPos();
   /*gun1-> col->rotation2.z = atan2f(lookDir.y, lookDir.x);*/

    lastPos = col->GetWorldPos();
   
    col->Update();
   
    if (state == PlayerState::IDLE)
    {
        LookTarget(INPUT->GetWorldMousePos());
        Control();
        //idle ->walk
        if (INPUT->KeyPress('W') or INPUT->KeyPress('A')
            or INPUT->KeyPress('S') or INPUT->KeyPress('D'))
        {
            state = PlayerState::WALK;
          
        }
        //idle->hurt
        if (INPUT->KeyDown(VK_DOWN))
        {
            state =PlayerState::HURT;
            hurt->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
        }
        //idle->ability
        if (INPUT->KeyDown(VK_RBUTTON))
        {
            state = PlayerState::ABILITY;
            ability->ChangeAnim(ANIMSTATE::ONCE, 0.1f);

        }
    }
    else if (state == PlayerState::WALK)
    {
        LookTarget(INPUT->GetWorldMousePos());
        Control();
        //walk->idle
        if (not(INPUT->KeyPress('W') or INPUT->KeyPress('A')
            or INPUT->KeyPress('S') or INPUT->KeyPress('D')))
        {
            state = PlayerState::IDLE;
           
        }
        //walk->ability
        if (INPUT->KeyDown(VK_RBUTTON))
        {
            state = PlayerState::ABILITY;
            ability->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
          
        }

        //walk->hurt
        if (INPUT->KeyDown(VK_DOWN))
        {
            state = PlayerState::HURT;
            hurt->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
        }
    }
    else if (state == PlayerState::HURT)
    {
        
       /* hurtTime += DELTA;*/
        //0 ~ 1 * 180
        //hurt->idle
        if (hurt->isAniStop())
        {
            speed = 200.0f;
            state = PlayerState::IDLE;
          

        }
        
       
    }
    
    else if (state == PlayerState::ABILITY)
    {
       /* abilityTime += DELTA;*/

        //0 ~ 1 * 180
        //roll->idle
        if (ability->isAniStop())
        {
            speed = 200.0f;
            state = PlayerState::IDLE;
            
            
        }

    }

    

    
   
   /* gun1->Update();
    gun2->Update();*/

    idle->Update();
    walk->Update();
    hurt->Update();
    ability->Update();
    

}

void Player::Render()
{
    /*gun2->Render();*/
    col->Render();

    if(state==PlayerState::IDLE)
    idle->Render();
    if (state == PlayerState::WALK)
    walk->Render();
    if (state == PlayerState::HURT)
    hurt->Render();
    if (state == PlayerState::ABILITY)
    ability->Render();
   /* gun1->Render();*/
   
}

void Player::LookTarget(Vector2 target)
{

    if (target.x < col->GetWorldPos().x)
    {
        // 왼쪽을 바라보는 경우
        idle->rotation.y = PI; // 왼쪽 방향으로 회전
        walk->rotation.y = PI;
        hurt->rotation.y = PI;
        ability->rotation.y = PI;
    }
    else
    {
        // 오른쪽을 바라보는 경우
        idle->rotation.y = 0; // 오른쪽 방향으로 회전
        walk->rotation.y = 0;
        hurt->rotation.y = 0;
        ability->rotation.y = 0;
    }
    

}


Vector2 Player::GetFoot()
{
    return col->GetWorldPos(); /*+ dir2 * Vector2(0, 1) + Vector2(0, 1);*/
}

void Player::GoBack()
{
    col->SetWorldPos(lastPos);
    Update();
}

void Player::SwapGun()//왼손 오른손 바꾸기
{
  
    if (gun1 == nullptr || gun2 == nullptr)
        return;

    if (gun2->gunImg->reverseLR)
    {
        gun2->gunImg->reverseLR = false;
    }
    
    

    /*  gun2->col->SetLocalPosX(28.0f);
      gun2->col->SetLocalPosY(-5.0f);
      gun1->col->SetLocalPosX(-8.0f);
      gun1->col->SetLocalPosY(58.0f);*/

    Gun* temp = gun1;
    gun1 = gun2;
    gun2 = temp;

    
  
}
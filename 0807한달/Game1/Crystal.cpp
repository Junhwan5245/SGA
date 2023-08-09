#include "stdafx.h"
#include "Player.h"
#include "Monster.h"
#include "Gun.h"
#include "Crystal.h"

Crystal::Crystal()
{
    maxHp = 10;
    Hp = 10;
    idle = new ObImage(L"CrystalIdle.png");
    walk = new ObImage(L"Crystalwalk.png");
    hurt = new ObImage(L"Crystalhurt.png");
    ability = new ObImage(L"Crystalability.png");
}

Crystal::~Crystal()
{
}

void Crystal::Init(Vector2 spawn)
{
    Player::Init(spawn);

    idle->maxFrame.x = 4;
    idle->scale.x = idle->imageSize.x / idle->maxFrame.x * 3.0f;
    idle->scale.y = idle->imageSize.y * 3.0f;

    idle->ChangeAnim(ANIMSTATE::LOOP, 0.1f);


    walk->maxFrame.x = 6;
    walk->scale.x = walk->imageSize.x / walk->maxFrame.x * 3.0f;
    walk->scale.y = walk->imageSize.y * 3.0f;
   
    walk->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

    hurt->maxFrame.x = 2;
    hurt->scale.x = hurt->imageSize.x / hurt->maxFrame.x * 3.0f;
    hurt->scale.y = hurt->imageSize.y * 3.0f;
   
    hurt->ChangeAnim(ANIMSTATE::ONCE, 0.1f);

    ability->maxFrame.x = 9;
    ability->scale.x = ability->imageSize.x / ability->maxFrame.x * 2.5f;
    ability->scale.y = ability->imageSize.y * 2.5f;
   
    ability->ChangeAnim(ANIMSTATE::ONCE, 0.4f);

   

    col->scale.x = idle->scale.x * 0.4f;
    col->scale.y = idle->scale.y * 0.4f;

    idle->SetParentRT(*col);
    walk->SetParentRT(*col);
    hurt->SetParentRT(*col);
    ability->SetParentRT(*col);

    col->isFilled = false;
}

void Crystal::Update()
{
    Player::Update();

    if (state == PlayerState::ABILITY)
    {
        col->scale.x = ability->scale.x * 0.8f;
        col->scale.y = ability->scale.y * 0.8f;
        
    }
    else
    {
        col->scale.x = idle->scale.x * 0.4f;
        col->scale.y = idle->scale.y * 0.4f;
      
    }
}

void Crystal::Render()
{
    col->Render();
    if (state == PlayerState::IDLE)
        idle->Render();
    if (state == PlayerState::WALK)
        walk->Render();
    if (state == PlayerState::HURT)
        hurt->Render();
    if (state == PlayerState::ABILITY)
        ability->Render();

    if (state != PlayerState::ABILITY)
    gun1->Render();
}

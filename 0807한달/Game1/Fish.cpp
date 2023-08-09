#include "stdafx.h"
#include "Player.h"
#include "Fish.h"
#include "stdafx.h"
#include "Bullet.h"


Fish::Fish()
{
    maxHp = 8;
    Hp = 8;
    //hasAxis = true;
    idle = new ObImage(L"FishIdle.png");
    walk = new ObImage(L"Fishwalk.png");
    hurt = new ObImage(L"Fishhurt.png");
    ability= new ObImage(L"Fishability.png");
}

Fish::~Fish()
{
}

void Fish::Init(Vector2 spawn)
{
    Player::Init(spawn);

    idle->maxFrame.x = 4;
    idle->scale.x = idle->imageSize.x / idle->maxFrame.x * 3.0f;
    idle->scale.y = idle->imageSize.y *  3.0f;
   
    idle->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
    

    walk->maxFrame.x = 6;
    walk->scale.x = walk->imageSize.x/walk->maxFrame.x * 3.0f;
    walk->scale.y = walk->imageSize.y * 3.0f;
    
    walk->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

    hurt->maxFrame.x = 2;
    hurt->scale.x = hurt->imageSize.x / hurt->maxFrame.x * 3.0f;
    hurt->scale.y = hurt->imageSize.y * 3.0f;
   
    hurt->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
   
    ability->maxFrame.x = 4;
    ability->scale.x = ability->imageSize.x / ability->maxFrame.x * 3.0f;
    ability->scale.y = ability->imageSize.y * 3.0f;
    
    ability->ChangeAnim(ANIMSTATE::ONCE, 0.1f);

  

    col->scale.x = idle->scale.x * 0.4f;
    col->scale.y = idle->scale.y * 0.4f;

    idle->SetParentRT(*col);
    walk->SetParentRT(*col);
    hurt->SetParentRT(*col);
    ability->SetParentRT(*col);

    col->isFilled = false;
   
}



void Fish::Update()
{
    Player::Update();
    
    if (state == PlayerState::ABILITY)
    {
        abilityTime += DELTA;
        float maxAbilityTime = 0.6f;
        speed = (250.0f * abilityTime / maxAbilityTime * PI + 100.0f);
        col->MoveWorldPos(dir * DELTA * speed);
        LookTarget(col->GetWorldPos() + dir);

        if (abilityTime >= maxAbilityTime)
        {
            speed = 200.0f;
            state = PlayerState::IDLE;
        
            abilityTime = 0.0f;  // abilityTime √ ±‚»≠
        }
       
    }
   
   

   
}

void Fish::Render()
{
   Player::Render();


}



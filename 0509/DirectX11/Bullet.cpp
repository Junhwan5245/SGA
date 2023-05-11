#include "framework.h"
#include "Bullet.h"

Bullet::Bullet()
{
    scale.x = 20.0f;
    scale.y = 20.0f;
    isFire = false;
    pivot = OFFSET_L;
}

Bullet::~Bullet()
{
}

void Bullet::Fire(GameObject* shooter, GameObject* player, float pressPower)
{
    lifeTime = 5.0f;
    scale.x = pressPower * 0.1f;
    scale.y = scale.x * 0.2f;
    this->pressPower = pressPower;
    bulletInterval = 0.3f;
    isFire = true;

    // 발사 위치 랜덤 설정
    int randX = rand() % 800;  // 창 폭이 800
    int randY = rand() % 600;  // 창 높이가 600
    SetWorldPos(Vector2(randX, randY));

    // 플레이어 위치와의 차이 벡터를 계산하여 방향 설정
    Vector2 playerPos = player->GetWorldPos();
    Vector2 shooterPos = shooter->GetWorldPos();
    Vector2 diff = playerPos - shooterPos;
    diff.Normalize();
    fireDir = diff;

    // 발사 각도 설정
    rotation.z = atan2f(fireDir.y, fireDir.x);
}

void Bullet::Update()
{
    if (not isFire) return;
    
    MoveWorldPos(fireDir * DELTA * pressPower);
   /* MoveWorldPos(GetRight() * DELTA * pressPower);*/
    ObRect::Update();
    
    lifeTime -= DELTA;
    if (lifeTime <= 0.0f)
    {
        isFire = false;
    }

    

    //이동후 화면 벗어남 체크
    /*if (0.0f > GetWorldPos().x or GetWorldPos().x > 800.0f or
        0.0f > GetWorldPos().y or GetWorldPos().y > 600.0f)
    {
        isFire = false;
    }*/
}

void Bullet::Render()
{
    if (not isFire) return;

    ObRect::Render();
}
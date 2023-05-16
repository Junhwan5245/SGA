#include "framework.h"
#include "Bullet.h"
#include "Player.h"
#include "Main.h"

Main::Main()
{
    pl[0] = new Player;
    pl[1] = new Player;
}

Main::~Main()
{
}

void Main::Init()
{
    //픽셀크기값

  
    HBITMAP	 m_hOldBitmap, m_hBitmap;
    HDC	hdc = GetDC(g_hwnd); //기존핸들

    g_hdc = CreateCompatibleDC(hdc);	//
    m_hBitmap = CreateCompatibleBitmap(hdc, 800, 600);//만들크기
    m_hOldBitmap = (HBITMAP)SelectObject(g_hdc, m_hBitmap);
    ReleaseDC(g_hwnd, hdc);


    pl[0]->Init(Vector2(100, 550), false);
    pl[1]->Init(Vector2(700, 550), true);
   
    turn = 0;
}

void Main::Release()
{
}

//선갱신(조작,이동)
void Main::Update()
{
   

    //캐릭터가 마우스를 바라보게 만들기

    //캐릭터에서 마우스 방향

    //마우스 - 캐릭터
    pl[turn]->Control();
   
    pl[0]->Update();
    pl[1]->Update();
    
}
//후갱신(충돌)
void Main::LateUpdate()
{
    //쏜 총알이 바닥에 닿았는지 플레이어에 닿았는지

    //쏘는 플레이어 기준으로 나머지 플레이어,벽 검사
    for (int i = 0; i < 30; i++)
    {
        
        if (not pl[turn]->GetBullet(i)->GetIsFire())continue;

        if (pl[turn]->GetBullet(i)->GetWorldPos().x < 0.0f + 10.0f)
        {
            pl[turn]->GetBullet(i)->SetWorldPosX(+10.0f);
            pl[turn]->GetBullet(i)->ReflectionY();
            pl[turn]->GetBullet(i)->Update();
        }
        else if (pl[turn]->GetBullet(i)->GetWorldPos().x > 800.0f - 10.0f)
        {
            pl[turn]->GetBullet(i)->SetWorldPosX(800.0f - 10.0f);
            pl[turn]->GetBullet(i)->ReflectionY();
            pl[turn]->GetBullet(i)->Update();
        }
        if (pl[turn]->GetBullet(i)->GetWorldPos().y > 600.0f - 10.0f)
        {
            pl[turn]->GetBullet(i)->Release();
            turn = not turn;
            damage = 0;
            damageTime = 0.0f;
        }

        if (pl[turn]->GetBullet(i)->Touch(pl[not turn]))
        {
            //pl[not turn]->
            //pl[not turn]->Damage(10.0f);
            //pl[turn]->GetBullet(i)->Release();
            //turn = not turn;
            damage = 1;
            releasebullet = i;
        }
    }
    
    if (damage)
    {
        if (TIMER->GetTick(damageTime, 0.02f))
        {
            pl[not turn]->Damage(5.0f);
            damage++;
        }

        if (damage >= 5)
        {
            pl[turn]->GetBullet(releasebullet)->Release();
            turn = not turn;
            damage = 0;
            damageTime = 0.0f;
        }
    }


    //총알30개가 벽에 부딪혔는지?
    /*for (int i = 0; i < 30; i++)
    {
        

        if (bullet[i]->GetWorldPos().x  <0.0f + 10.0f)
        {
            bullet[i]->SetWorldPosX(+10.0f);
            bullet[i]->ReflectionY();
            bullet[i]->Update();
        }
        else if (bullet[i]->GetWorldPos().x >800.0f - 10.0f)
        {
            bullet[i]->SetWorldPosX(800.0f - 10.0f);
            bullet[i]->ReflectionY();
            bullet[i]->Update();
        }
        if (bullet[i]->GetWorldPos().y < 0.0f + 10.0f)
        {
            bullet[i]->SetWorldPosY(+10.0f);
            bullet[i]->ReflectionX();
            bullet[i]->Update();
        }
        else if (bullet[i]->GetWorldPos().y > 600.0f - 10.0f)
        {
            bullet[i]->SetWorldPosY(600.0f - 10.0f);
            bullet[i]->ReflectionX();
            bullet[i]->Update();
        }
      
    }*/


    //WM_PAINT 호출
    
}

void Main::Render()
{

    PAINTSTRUCT ps;
    //hdc-> 도화지
    g_frontHdc = BeginPaint(g_hwnd, &ps);

    //바탕색 깔기
    PatBlt(g_hdc, 0, 0, 800, 600, WHITENESS);


    //중점,크기,회전값을 가지고 계산한 별 꼭지점
  
    string str = "FPS:" + to_string(TIMER->GetFramePerSecond()) +
        "\n WorldTime:" + to_string(TIMER->GetWorldTime()) +
        "\n Delta:" + to_string(DELTA);
    TextOutA(g_hdc, 0, 0, str.c_str(), str.size());

    string str2 = "X:" + to_string(INPUT->mouseScreenPos.x)
        + "Y:" + to_string(INPUT->mouseScreenPos.y);
    TextOutA(g_hdc, 0, 20, str2.c_str(), str2.size());


  

    pl[0]->Render();
    pl[1]->Render();


    //밑에서 그린걸 위로 배끼기
    BitBlt(g_frontHdc, 0, 0, 800, 600,
        g_hdc, 0, 0, SRCCOPY);


    EndPaint(g_hwnd, &ps);
}

void Main::ResizeScreen()
{
}

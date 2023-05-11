#include "framework.h"
#include "Bullet.h"
#include "Main.h"

Main::Main()
{
    //GameObject::

    cc = new ObCircle();
    line[0] = new ObLine();
    line[0]->SetParentRT(*cc);

    line[1] = new ObLine();
    line[1]->SetParentRT(*cc);

    line[2] = new ObLine();
    line[2]->SetParentRT(*cc);

    star[0] = new ObStar();
    star[0]->SetParentRT(*cc);
    star[2] = new ObStar();
    star[2]->SetParentRT(*cc);
    star[1] = new ObStar();
    star[1]->SetParentRT(*cc);

    //
    for (int i = 0; i < 30; i++)
    {
        bullet[i] = new Bullet();
    }
}

Main::~Main()
{
    delete cc;
    delete line[0];
    delete line[1];
    delete line[2];
    delete star[0];
    delete star[1];
    delete star[2];
    for (int i = 0; i < 30; i++)
    {
        delete bullet[i];
    }
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



    cc->scale.x = 600.0f* 0.1f;
    cc->scale.y = 600.0f* 0.1f;

    cc->SetWorldPosX(400.0f);
    cc->SetWorldPosY(300.0f);

    line[0]->scale.x = (100.0f-20.0f)*0.1f;
    line[0]->scale.y = (100.0f-20.0f)*0.1f;

    line[1]->scale.x = (200.0f - 20.0f) * 0.1f;
    line[1]->scale.y = (200.0f - 20.0f) * 0.1f;

    line[2]->scale.x = (300.0f - 20.0f) * 0.1f;
    line[2]->scale.y = (300.0f - 20.0f) * 0.1f;



    star[0]->scale.x = 40.0f;
    star[0]->scale.y = 40.0f;
    star[0]->SetLocalPosX(50.0f);

    star[1]->scale.x = 40.0f;
    star[1]->scale.y = 40.0f;
    star[1]->SetLocalPosX(150.0f);

    star[2]->scale.x = 40.0f;
    star[2]->scale.y = 40.0f;
    star[2]->SetLocalPosX(250.0f);

    //pressPower = 0.0f;
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
    Vector2 dir = INPUT->mouseScreenPos - cc->GetWorldPos();
    cc->rotation.z = atan2f(dir.y, dir.x);


    //if (GetAsyncKeyState(VK_LEFT) & 0x8001)

    //전에는 안눌렀는대 현재 눌렀을떄
    if (INPUT->KeyDown('0'))
    {
        star[2]->scale.x += 100.0f;
        star[2]->scale.y += 100.0f;
    }
    //전에는 눌렀는대 현재 떼었을떄
    if (INPUT->KeyUp('0'))
    {
        star[2]->scale.x -= 100.0f;
        star[2]->scale.y -= 100.0f;
    }




    //계속 누를때
    if (INPUT->KeyPress('W'))
    {
        //벡터의 크기는 초당 50
        cc->MoveWorldPos(UP * DELTA * 200);
    }
    if (INPUT->KeyPress('S'))
    {
        cc->MoveWorldPos(DOWN * DELTA * 200);
    }
    if (INPUT->KeyPress('A'))
    {
        cc->MoveWorldPos(LEFT * DELTA * 200);
    }
    if (INPUT->KeyPress('D'))
    {
        cc->MoveWorldPos(RIGHT * DELTA * 200);
    }
    if (INPUT->KeyDown(VK_LBUTTON))
    {
        pressPower = 200.0f;
    }
    if (INPUT->KeyPress(VK_LBUTTON))
    {
        pressPower += 300.0f * DELTA;
    }
    if (INPUT->KeyUp(VK_LBUTTON))
    {
        pressPower = min(pressPower, 1000.0f);
        for (int i = 0; i < 30; i++)
        {
            if (not bullet[i]->GetIsFire())
            {
                bullet[i]->Fire(cc, pressPower);
                break;
            }
        }
    }
   

    if (GetAsyncKeyState('1') & 0x8000)
    {
         cc->scale.x += 0.05f;
         cc->scale.y += 0.05f;
    }  
    if (GetAsyncKeyState('2') & 0x8000)
    {
         cc->scale.x -= 0.05f;
         cc->scale.y -= 0.05f;
    }
    if (GetAsyncKeyState('3') & 0x8000)
    {
        cc->rotation.x += 3 * ToRadian;
    }
    //11
    //0.05초마다 3도회전
    //1초마다 60도
    if (GetAsyncKeyState('4') & 0x8000)
    {
        cc->rotation.x -= 18 * ToRadian;
    }
    if (GetAsyncKeyState('5') & 0x8000)
    {
        cc->rotation.y += 18 * ToRadian;
    }
    if (GetAsyncKeyState('6') & 0x8000)
    {
        cc->rotation.y -= 18 * ToRadian;
    }
    if (GetAsyncKeyState('7') & 0x8000)
    {
        cc->rotation.z += 18 * ToRadian;
    }
    if (GetAsyncKeyState('8') & 0x8000)
    {
        cc->rotation.z -= 18 * ToRadian;
    }

    GetLocalTime(&time);
    //시침
    line[0]->rotation.z = (-90.0f + time.wHour * 30.0f )* ToRadian;
    line[1]->rotation.z = (-90.0f + time.wMinute * 6.0f )* ToRadian;
    line[2]->rotation.z = (-90.0f + time.wSecond * 6.0f )* ToRadian;

    
    star[0]->rotation2.z += 3 * ToRadian;
    star[1]->rotation2.z += 6 * ToRadian;
    star[2]->rotation2.z += 2 * ToRadian;
    
    for (int i = 0; i < 30; i++)
    {
        bullet[i]->Update();
    }
    cc->Update();
    line[0]->Update();
    line[1]->Update();
    line[2]->Update();
    star[0]->Update();
    star[1]->Update();
    star[2]->Update();
}
//후갱신(충돌)
void Main::LateUpdate()
{
    //총알30개가 벽에 부딪혔는지?
    for (int i = 0; i < 30; i++)
    {
        if (not bullet[i]->GetIsFire())continue;

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
            bullet[i]->velocity = bullet[i]->gravity;
            bullet[i]->Update();
            

        }
      
    }


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

    


  
    cc->Render();
    star[0]->Render();
    star[1]->Render();
    star[2]->Render();
    line[0]->Render();
    line[1]->Render();
    line[2]->Render();
    for (int i = 0; i < 30; i++)
    {
        bullet[i]->Render();
    }



    //밑에서 그린걸 위로 배끼기
    BitBlt(g_frontHdc, 0, 0, 800, 600,
        g_hdc, 0, 0, SRCCOPY);


    EndPaint(g_hwnd, &ps);
}

void Main::ResizeScreen()
{
}

#include "stdafx.h"
#include "Bullet.h"
#include "Player.h"
#include "Main.h"

Main::Main()
{
    pl[0] = new Player();
    pl[1] = new Player();
    ball = new Bullet();
    goal[0] = new ObRect();
    goal[1] = new ObRect();

    
    
    
}

Main::~Main()
{
   
}

void Main::Init()
{


    pl[0]->Init(Vector2(-300, 0));
    pl[0]->isPlayer0 = true;
    pl[1]->Init(Vector2(300, 0));
    pl[1]->isPlayer0 = false;


    goal[0]->scale.x = 30;
    goal[0]->scale.y = goal[0]->scale.x * 7;

    goal[1]->scale.x = 30;
    goal[1]->scale.y = goal[1]->scale.x * 7;

    /* ball->scale.x = 30;
     ball->scale.y = 30;*/
    ball->SetWorldPosX(0);
    ball->SetWorldPosY(0);
    goal[0]->SetWorldPosX(-600);
    goal[0]->SetWorldPosY(0);
    goal[1]->SetWorldPosX(600);
    goal[1]->SetWorldPosY(0);

}

void Main::Release()
{
   
}

void Main::Update()
{
	//마우스 - 캐릭터
    pl[0]->Control();
    pl[1]->Control();

    pl[0]->Update();
    pl[1]->Update();
    goal[0]->Update();
    goal[1]->Update();
    ball->Update();
    ImGui::Text("P0 : %d", pl[0]->score);
    ImGui::Text("P1 : %d", pl[1]->score);
    
}

void Main::LateUpdate()
{
    
    
    if (ball->GetWorldPos().x < -600.0f + 10.0f)
    {
        ball->SetWorldPosX(-600.0f + 10.0f);
        ball->ReflectionY();
        ball->Update();
        if (ball->GetWorldPos().y>-105 and (ball->GetWorldPos().y<105))
        {
           
            Init();
            pl[1]->score += 1;
            
            ball->SetWorldPosX(0);
            ball->SetWorldPosY(0);
            ball->pressPower = 0;
            
        }
    }
    if (ball->GetWorldPos().x > 600.0f - 10.0f)
    {
        ball->SetWorldPosX(600.0f - 10.0f);
        ball->ReflectionY();
        ball->Update();
        if (ball->GetWorldPos().y > -105 and (ball->GetWorldPos().y < 105))
        {
            Init();
            pl[0]->score += 1;
            ball->SetWorldPosX(0);
            ball->SetWorldPosY(0);
            ball->pressPower = 0;
            
        }
        
    }
    
    
    if (ball->GetWorldPos().y < -400.0f + 10.0f)
    {
        ball->SetWorldPosY(-400.0f + 10.0f);
        ball->ReflectionX();
        ball->Update();
    }

    if (ball->GetWorldPos().y > 400.0f - 10.0f)
    {
        ball->SetWorldPosY(400.0f - 10.0f);
        ball->ReflectionX();
        ball->Update();
    }

   


    if (pl[0]->Touch(ball) )
    {
        ball->pressPower = 500;
        ball->Fire(pl[0],ball);
    }
    if (pl[1]->Touch(ball))
    {
        ball->pressPower = 500;
        ball->Fire(pl[1], ball);
    }

}

void Main::Render()
{
    pl[0]->Render();
    pl[1]->Render();
    goal[0]->Render();
    goal[1]->Render();
    ball->Render();


}

void Main::ResizeScreen()
{
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
    app.SetAppName(L"Game1");
    app.SetInstance(instance);
	app.InitWidthHeight(1200.0f,800.0f);
	WIN->Create();
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	SafeDelete(main);
	WIN->Destroy();
	WIN->DeleteSingleton();
	
	return wParam;
}
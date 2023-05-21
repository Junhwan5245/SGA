#include "stdafx.h"
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

	pl[0]->Init(Vector2(0, -240), false);
    pl[0]->isFilled = false;
    pl[0]->color = Color(0.5, 0, 0);
	pl[1]->Init(Vector2(340, -240), true);
    pl[1]->color = Color(0, 0, 1);
	turn = 0;

}

void Main::Release()
{
   
}

void Main::Update()
{
    ImGui::Text("FPS : %d", (int)TIMER->GetFramePerSecond());
    //cout << app.GetWidth() << endl;
    //app.fixFrame
    //ImGui::Text("Width : %f", app.GetWidth());

	//마우스 - 캐릭터
	pl[turn]->Control();

	pl[0]->Update();
	pl[1]->Update();
}

void Main::LateUpdate()
{
    for (int i = 0; i < 30; i++)
    {

        if (not pl[turn]->GetBullet(i)->GetIsFire())continue;

        if (pl[turn]->GetBullet(i)->GetWorldPos().x < -400.0f + 10.0f)
        {
            pl[turn]->GetBullet(i)->SetWorldPosX(-400.0f + 10.0f);
            pl[turn]->GetBullet(i)->ReflectionY();
            pl[turn]->GetBullet(i)->Update();
        }
        else if (pl[turn]->GetBullet(i)->GetWorldPos().x > 400.0f - 10.0f)
        {
            pl[turn]->GetBullet(i)->SetWorldPosX(400.0f - 10.0f);
            pl[turn]->GetBullet(i)->ReflectionY();
            pl[turn]->GetBullet(i)->Update();
        }
        if (pl[turn]->GetBullet(i)->GetWorldPos().y < -300.0f - 10.0f)
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

}

void Main::Render()
{
    pl[0]->Render();
    pl[1]->Render();


}

void Main::ResizeScreen()
{
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
    app.SetAppName(L"Game1");
    app.SetInstance(instance);
	app.InitWidthHeight(800.0f,600.0f);
	WIN->Create();
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	SafeDelete(main);
	WIN->Destroy();
	WIN->DeleteSingleton();
	
	return wParam;
}